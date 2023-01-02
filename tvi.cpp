#include "stdafx.h"

_NT_BEGIN
#include "resource.h"
#include "../winZ/app.h"
#include "../winz/mdi.h"
#include "../winz/view.h"
#include "../inc/initterm.h"

HRESULT GetLastHresult(ULONG dwError = GetLastError())
{
	NTSTATUS status = RtlGetLastNtStatus();
	return RtlNtStatusToDosErrorNoTeb(status) == dwError ? HRESULT_FROM_NT(status) : HRESULT_FROM_WIN32(dwError);
}

int CustomMessageBox(HWND hWnd, PCWSTR lpText, PCWSTR lpszCaption, UINT uType)
{
	PCWSTR pszName = 0;

	switch (uType & MB_ICONMASK)
	{
	case MB_ICONINFORMATION:
		pszName = IDI_INFORMATION;
		break;
	case MB_ICONQUESTION:
		pszName = IDI_QUESTION;
		break;
	case MB_ICONWARNING:
		pszName = IDI_WARNING;
		break;
	case MB_ICONERROR:
		pszName = IDI_ERROR;
		break;
	}

	MSGBOXPARAMS mbp = {
		sizeof(mbp),
		hWnd,
		(HINSTANCE)&__ImageBase,
		lpText, 
		lpszCaption, 
		(uType & ~MB_ICONMASK)|MB_USERICON,
		MAKEINTRESOURCE(IDR_MENU1)
	};

	return MessageBoxIndirect(&mbp);
}

int ShowErrorBox(HWND hWnd, PCWSTR lpCaption, HRESULT dwError, UINT uType)
{
	int r = 0;
	LPCVOID lpSource = 0;
	ULONG dwFlags = FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS;

	if (dwError & FACILITY_NT_BIT)
	{
		dwError &= ~FACILITY_NT_BIT;
		dwFlags = FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS;

		static HMODULE ghnt;
		if (!ghnt && !(ghnt = GetModuleHandle(L"ntdll"))) return 0;
		lpSource = ghnt;
	}

	PWSTR lpText;
	if (FormatMessageW(dwFlags, lpSource, dwError, 0, (PWSTR)&lpText, 0, 0))
	{
		r = CustomMessageBox(hWnd, lpText, lpCaption, uType);
		LocalFree(lpText);
	}

	return r;
}

struct AUX 
{
	ULONG MaxLevel = 0;
	ULONG len = 0;
	ULONG cb;
	AUX(ULONG cb) : cb(cb) {}

	void Reset()
	{
		MaxLevel = 0, len = 0;
	}
};

PUCHAR IsValidTvi(ULONG level, PUCHAR buf, ULONG cb, AUX* p/*, PCSTR prefix*/)
{
	if (cb < 1)
	{
		return 0;
	}
	
	ULONG len = *buf++;
	
	if (len >= --cb)
	{
		return 0;
	}

	if (level > p->MaxLevel)
	{
		p->MaxLevel = level;
	}

	p->len += level + len + 2;

	//DbgPrint("%s%.*s\n", prefix, len, buf);

	buf += len, cb -= len, level++/*, prefix--*/;

	while (cb && *buf)
	{
		if (!(buf = IsValidTvi(level, buf, cb, p/*, prefix*/)) || !(cb = p->cb))
		{
			return 0;
		}
	}

	if (cb)
	{
		p->cb = cb - 1;
		return buf + 1;
	}

	return 0;
}

struct ED 
{
	PWSTR buf;
	ULONG cch;
};

const UCHAR* Dump(PCSTR prefix, const UCHAR* psz, ED* p)
{
	ULONG len = *psz++;
	int cch = swprintf_s(p->buf, p->cch, L"%S%.*S\r\n", prefix, len, psz);
	if (0 >= cch)
	{
		return 0;
	}
	psz += len;
	prefix--;
	p->buf += cch, p->cch -= cch;
	if (*psz)
	{
		do 
		{
			if (!(psz = Dump(prefix, psz, p)))
			{
				return 0;
			}
		} while (*psz);
	}

	return psz + 1;
}

class ZTviTree : public ZMDIChildFrame, public ZView
{
	enum { ID_TV = 1 };

	PCUCHAR _pszTvi;
	ULONG _cch;
	ULONG _maxlevel;

	virtual ZWnd* getWnd()
	{
		return this;
	}

	void Copy(HWND hWnd);

	static PUCHAR AddItems(HWND hwndTV, TVINSERTSTRUCT* tvis, PUCHAR psz)
	{
		tvis->item.lParam = (LPARAM)psz;
	
		if (HTREEITEM hItem = TreeView_InsertItem(hwndTV, tvis))
		{
			ULONG len = *psz++;
			psz += len;

			while (*psz)
			{
				tvis->hParent = hItem;
				if (!(psz = AddItems(hwndTV, tvis, psz)))
				{
					return 0;
				}
			}

			return psz + 1;
		}

		return 0;
	}

	virtual HWND CreateView(HWND hWndParent, int nWidth, int nHeight, PVOID lpCreateParams)
	{
		if (HWND hwnd = CreateWindowExW(0, WC_TREEVIEW, 0, WS_CHILD|WS_VISIBLE|
			TVS_LINESATROOT|TVS_HASLINES|TVS_HASBUTTONS|TVS_DISABLEDRAGDROP|
			TVS_TRACKSELECT|TVS_EDITLABELS, 0, 0, nWidth, nHeight, hWndParent, (HMENU)ID_TV, 0, 0))
		{
			if (ZFont* font = ZGLOBALS::getFont())
			{
				if (HFONT hFont = font->getFont())
				{
					SendMessage(hwnd, WM_SETFONT, (WPARAM)hFont, 0);
				}
			}

			TVINSERTSTRUCT tvis = { 0, TVI_LAST, { TVIF_PARAM|TVIF_TEXT } };
			tvis.item.pszText = LPSTR_TEXTCALLBACK;
			AddItems(hwnd, &tvis, (PUCHAR)lpCreateParams);
			return hwnd;
		}

		return 0;
	}

	virtual LRESULT OnNotify(LPNMHDR lpnm)
	{
		if (lpnm->idFrom != ID_TV)
		{
			return 0;
		}

		switch (lpnm->code)
		{
		case NM_RCLICK:
			if (HMENU hmenu = LoadMenu((HINSTANCE)&__ImageBase, MAKEINTRESOURCE(IDR_MENU2)))
			{
				POINT pt;
				GetCursorPos(&pt);

				HMENU hSubMenu = GetSubMenu(hmenu, 0);

				switch (TrackPopupMenu(hSubMenu, TPM_RETURNCMD, pt.x, pt.y, 0, lpnm->hwndFrom, 0))
				{
				case ID_0_COPY:
					Copy(lpnm->hwndFrom);
					break;
				}
			}

			return TRUE;

		case TVN_GETDISPINFOW:
			if (reinterpret_cast<NMTVDISPINFOW*>(lpnm)->item.mask & TVIF_TEXT)
			{
				PSTR psz = (PSTR)reinterpret_cast<NMTVDISPINFOW*>(lpnm)->item.lParam;
				ULONG len = *(PUCHAR)psz++;

				if (ULONG cchTextMax = reinterpret_cast<NMTVDISPINFOW*>(lpnm)->item.cchTextMax)
				{
					PWSTR pszText = reinterpret_cast<NMTVDISPINFOW*>(lpnm)->item.pszText;
					pszText[MultiByteToWideChar(CP_UTF8, 0, psz, len, pszText, cchTextMax - 1)] = 0;
				}
			}
			break;
		}
		return 0;
	}
public:
	ZTviTree(ZDocument* pDoc, PCUCHAR pszTvi, ULONG cch, ULONG maxlevel) : ZView(pDoc), _pszTvi(pszTvi), _cch(cch), _maxlevel(maxlevel)
	{
	}
};

PCWSTR PathGetFileName(PCWSTR lpFileName)
{
	PWSTR name = wcsrchr(lpFileName, '\\'), name2 = wcsrchr(lpFileName, '/');

	if (name < name2)
	{
		name = name2;
	}

	return name ? name + 1 : lpFileName;
}

class ZTviDoc : public ZDocument
{
	PSTR _pszTvi = 0;

	~ZTviDoc()
	{
		if (_pszTvi)
		{
			delete [] _pszTvi;
		}
	}

	virtual BOOL IsCmdEnabled(WORD /*cmd*/)
	{
		return false;
	}

	virtual LRESULT OnCmdMsg(WPARAM /*wParam*/, LPARAM /*lParam*/)
	{
		return 0;
	}

public:

	HRESULT Open(HWND hwnd)
	{
		HRESULT hr;

		OPENFILENAMEW ofn = { sizeof(ofn) };

		if (ofn.lpstrFile = new WCHAR[0x8000])
		{
			*ofn.lpstrFile = 0;
			ofn.hwndOwner = hwnd;
			ofn.nMaxFile = 0x8000;
			ofn.lpstrFilter = L"TVI Files\0*.tvi\0";
			ofn.lpstrDefExt = L"tvi";
			ofn.Flags = OFN_DONTADDTORECENT|OFN_ENABLESIZING|
				OFN_EXPLORER|OFN_FORCESHOWHIDDEN|OFN_NOVALIDATE|
				OFN_PATHMUSTEXIST|OFN_HIDEREADONLY|OFN_FILEMUSTEXIST;

			if (GetOpenFileNameW(&ofn))
			{
				hr = Open(ofn.lpstrFile);
			}
			else
			{
				hr = HRESULT_FROM_WIN32(ERROR_CANCELLED);
			}

			delete [] ofn.lpstrFile;
		}
		else
		{
			hr = E_OUTOFMEMORY;
		}

		return hr;
	}

	HRESULT Open(PCWSTR lpFileName)
	{
		HANDLE hFile = CreateFileW(lpFileName, FILE_GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);

		if (hFile == INVALID_HANDLE_VALUE)
		{
			return GetLastHresult();
		}

		FILE_STANDARD_INFORMATION fsi;
		IO_STATUS_BLOCK iosb;

		NTSTATUS status = NtQueryInformationFile(hFile, &iosb, &fsi, sizeof(fsi), FileStandardInformation);
		
		if (0 <= status)
		{
			if (fsi.EndOfFile.QuadPart - 1 < 0x1000000)
			{
				if (PSTR buf = new char[fsi.EndOfFile.LowPart])
				{
					if (0 <= (status = NtReadFile(hFile, 0, 0, 0, &iosb, buf, fsi.EndOfFile.LowPart, 0, 0)))
					{
						AUX a((ULONG)iosb.Information);

						//char prefix[65];
						//memset(prefix, '\t', _countof(prefix)-1);
						//prefix[_countof(prefix) - 1]=0;

						ULONG i = 8;
						PUCHAR pb = (PUCHAR)buf, pc;
						do 
						{
							a.Reset();
							if (pc = IsValidTvi(0, pb, a.cb, &a/*, prefix + _countof(prefix) - 1*/))
							{
								if (ZTviTree* p = new ZTviTree(this, pb, a.len + 1, a.MaxLevel))
								{
									p->Create(PathGetFileName(lpFileName), pb);
									p->Release();
								}

							}
							else
							{
								status = STATUS_INVALID_IMAGE_FORMAT;
								break;
							}

							if (!--i)
							{
								break;
							}

						} while (pb = pc, a.cb);

						_pszTvi = buf, buf = 0;
					}

					if (buf) delete [] buf;
				}
				else
				{
					status = STATUS_NO_MEMORY;
				}
			}
			else
			{
				status = STATUS_FILE_TOO_LARGE;
			}
		}

		NtClose(hFile);

		return HRESULT_FROM_NT(status);
	}
};

void ZTviTree::Copy(HWND hwnd)
{
	if (ULONG cch = _cch)
	{
		if (OpenClipboard(hwnd))
		{
			EmptyClipboard();
			if (HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, cch * sizeof(WCHAR)))
			{
				ED e { (PWSTR)GlobalLock(hg), cch };
				ULONG maxlevel = _maxlevel;
				PSTR prefix = (PSTR)alloca(maxlevel + 1);
				memset(prefix, '\t', maxlevel);
				prefix[maxlevel] = 0;
				PCUCHAR psz = Dump(prefix + maxlevel, (PCUCHAR)_pszTvi, &e);

				GlobalUnlock(hg);
				if (!psz || !SetClipboardData(CF_UNICODETEXT, hg)) GlobalFree(hg);
			}
			CloseClipboard();
		}
	}
}

class ZMainWnd : public ZMDIFrameWnd
{
	virtual LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		enum { cmd_open = '\v\v\v\v' };

		switch (uMsg)
		{
		case WM_COMMAND:
			switch (wParam)
			{
			case ID_EXIT:
				DestroyWindow(hwnd);
				break;
			case ID_OPEN:
				lParam = E_OUTOFMEMORY;
				if (ZTviDoc* p = new ZTviDoc)
				{
					lParam = p->Open(hwnd);
					p->Release();
				}
				if (0 > lParam)
				{
					ShowErrorBox(hwnd, L"Fail Open Document", (HRESULT)lParam, MB_OK);
				}
				break;
			}
			break;
		case WM_CREATE:
			if (PWSTR psz = wcschr(GetCommandLineW(), '\v'))
			{
				PostMessageA(hwnd, WM_APP, cmd_open, (LPARAM)(1 + psz));
			}
			break;
		case WM_APP:
			if (wParam == cmd_open)
			{
				if (ZTviDoc* p = new ZTviDoc)
				{
					lParam = p->Open((PWSTR)lParam);
					p->Release();
				}
				if (0 > lParam)
				{
					ShowErrorBox(hwnd, L"Fail Open Document", (HRESULT)lParam, MB_OK);
				}
			}
		}
		return __super::WindowProc(hwnd, uMsg, wParam, lParam);
	}

	virtual PCUNICODE_STRING getPosName()
	{
		STATIC_UNICODE_STRING_(sMainWnd);
		return &sMainWnd;
	}
};

void zmain()
{
	ZGLOBALS globals;
	ZApp app;
	ZRegistry reg;
	ZFont font(TRUE);
	
	if (0 <= reg.Create(L"Software\\{AB188E71-FEB0-49b1-8B94-C646B20A9948}") && font.Init())
	{
		HWND hwnd = 0;

		if (ZMainWnd* p = new ZMainWnd)
		{
			hwnd = p->ZSDIFrameWnd::Create(L"TVI View", (HINSTANCE)&__ImageBase, MAKEINTRESOURCE(IDR_MENU1));//

			p->Release();
		}

		if (hwnd)
		{
			app.Run();
		}
	}
}

struct XKey 
{
	XKey* next;
	XKey* child;
	PCWSTR Name;
	const void* pvData;
	ULONG cbData;
	ULONG Type;

	XKey(PCWSTR Name, XKey* next, XKey* child, const void* pvData, ULONG cbData, ULONG Type)
		: next(next), child(child), Name(Name), pvData(pvData), cbData(cbData), Type(Type)
	{
	}

	NTSTATUS Create(HANDLE hKey, PUNICODE_STRING ObjectName, PCSTR prefix)
	{
		OBJECT_ATTRIBUTES oa = { sizeof(oa), hKey, ObjectName, OBJ_CASE_INSENSITIVE };

		NTSTATUS status = ZwCreateKey(&hKey, KEY_ALL_ACCESS, &oa, 0, 0, 0, 0);

		//DbgPrint("%s[%wZ] = %x\r\n", prefix, ObjectName, status);

		if (0 <= status)
		{
			if (XKey* p = child)
			{
				--prefix;
				do
				{
					if (0 > (status = p->Create(hKey, prefix)))
					{
						break;
					}

				} while (p = p->next);
			}

			NtClose(hKey);
		}

		return status;
	}

	NTSTATUS Create(HANDLE hKey, PCSTR prefix)
	{
		UNICODE_STRING ObjectName;
		RtlInitUnicodeString(&ObjectName, Name);

		return pvData ? ZwSetValueKey(hKey, &ObjectName, 0, Type, const_cast<void*>(pvData), cbData) : Create(hKey, &ObjectName, prefix);
	}
};

HRESULT RegisterTVI()
{
	STATIC_WSTRING(suffix, "\"\v%1");
	HRESULT hr;
	PVOID stack = alloca(sizeof(suffix));
	PWSTR szExePath;
	ULONG cb = 0x20, cch = 0;
	do 
	{
		szExePath = (PWSTR)alloca(cb <<= 1);
		cch = GetModuleFileNameW(0, szExePath + 1, RtlPointerToOffset(szExePath + 1, stack) / sizeof(WCHAR));
	} while ((hr = GetLastError()) == ERROR_INSUFFICIENT_BUFFER);

	*szExePath = '\"';
	wcscpy(szExePath + 1 + cch, suffix);

	if (0 <= hr)
	{
		UNICODE_STRING RegistryPath;
		if (0 <= (hr = RtlFormatCurrentUserKeyPath(&RegistryPath)))
		{
			PWSTR psz = 0;
			cch = 0;
			while (0 < (cch = _snwprintf(psz, cch, L"%wZ\\Software\\Classes\\.tvi", &RegistryPath)))
			{
				if (psz)
				{
					// (PCWSTR Name, XKey* next, XKey* child, const void* pvData, ULONG cbData, ULONG Type)
					XKey Default(0, 0, 0, szExePath, (ULONG)wcslen(szExePath) * sizeof(WCHAR), REG_SZ);
					XKey command(L"command", 0, &Default, 0, 0, REG_NONE);
					XKey open(L"open", 0, &command, 0, 0, REG_NONE);
					XKey shell(L"shell", 0, &open, 0, 0, REG_NONE);
					XKey tvi(psz, 0, &shell, 0, 0, REG_NONE);
					//XKey Classes(L"Classes", 0, &tvi, 0, 0, REG_NONE);
					//XKey User(0, 0, &tvi, 0, 0, REG_NONE);

					char prefix[] = "\t\t\t\t\t\t\t";
					hr = tvi.Create(0, prefix + _countof(prefix) - 1);
					break;
				}

				psz = (PWSTR)alloca(++cch * sizeof(WCHAR));
			}

			RtlFreeUnicodeString(&RegistryPath);
		}
	}

	return hr;
}

void WINAPI ep(void*)
{
	RegisterTVI();
	initterm();
	zmain();
	destroyterm();
	ExitProcess(0);
}

_NT_END