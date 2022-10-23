class <lambda_26359c74af5fd5aa6a5d4cf0c40b4807>
{
	static <lambda_invoker_cdecl>(unsigned __int64,void *);
};

struct AsanHeap
{
	AsanHeap(void *);
	static void operator delete(void *);
};

class DName
{
	void append<DNameNode>(DNameNode const *);
	void append<DNameStatusNode>(DNameStatusNode const *);
	void append<charNode>(charNode const *);
	void append<pcharNode>(pcharNode const *);
	void doPchar(char);
	void doPchar<0>(char const *,int);
	void doPchar<1>(char const *,int);
	void doPchar<2>(char const *,int);
public:
	DName & operator+=(DName const &);
	DName & operator+=(DNameStatus);
	DName & operator+=(StringLiteral const &);
	DName & operator+=(char);
	DName & operator=(DNameStatus);
	DName operator+(DName const &);
	DName operator+(DNameStatus);
	DName operator+(StringLiteral const &);
	DName operator+(char);
	DName(DName *);
	DName(StringLiteral const &);
	DName(__int64);
	DName(char const * &,char);
	DName(unsigned __int64);
	DName<0>(char const *,StringLifeSelector<0>);
	DName<1>(char const *,StringLifeSelector<1>);
	DName<2>(char const *,StringLifeSelector<2>);
};

struct DNameStatusNode
{
	virtual char * getString(char *,char *);
	virtual char getLastChar();
	virtual int length();
	virtual int raw_length();
};

namespace FH4
{
	class HandlerMap4
	{
		void DecompHandler();
	public:
		HandlerMap4(TryBlockMapEntry4 const *,unsigned __int64,int);
	};

	struct TryBlockMap4
	{
		TryBlockMap4(FuncInfo4 const *,unsigned __int64);
		void setBuffer(TryBlockMap4::iterator);
	};

	class UWMap4
	{
		void ReadEntry(unsigned char * *);
	public:
		static int getStateFromIterators(UWMap4::iterator const &,int,UWMap4::iterator const &,int,UWMap4::iterator const &);
		void getStartStop(int,int,UWMap4::iterator &,UWMap4::iterator &);
	};

	__int64 DecompFuncInfo(unsigned char *,FH4::FuncInfo4 &,unsigned __int64,int,bool);
	signed char const * const s_negLengthTab;
	unsigned char const * const s_shiftTab;
};

struct RecursiveScopedLock
{
	RecursiveScopedLock(__sanitizer::SpinMutex &,__sanitizer::atomic_uint32_t &);
	~RecursiveScopedLock();
};

struct Replicator
{
	DName operator[](int);
	Replicator & operator+=(DName const &);
};

class UnDecorator
{
	static DName composeDeclaration(DName const &);
	static DName getAddressOf();
	static DName getArgumentList();
	static DName getArgumentTypes();
	static DName getArrayAccess();
	static DName getArrayObject();
	static DName getArrayType(DName const &);
	static DName getBasedType();
	static DName getBasicDataType(DName const &);
	static DName getCallingConvention();
	static DName getDataIndirectType(DName const &,IndirectionKind,DName const &,int);
	static DName getDataType(DName *);
	static DName getDecoratedName();
	static DName getDimension(bool);
	static DName getDispatchTarget();
	static DName getECSUDataType();
	static DName getEnumType();
	static DName getExtendedDataIndirectType(IndirectionKind &,bool &,int);
	static DName getExternalDataType(DName const &);
	static DName getFloatingPoint(int);
	static DName getFunctionIndirectType(DName const &);
	static DName getLexicalFrame();
	static DName getMemberAccess();
	static DName getNoexcept();
	static DName getOperatorName(bool,bool *);
	static DName getPointerToMember();
	static DName getPrimaryDataType(DName const &);
	static DName getPtrRefDataType(DName const &,int);
	static DName getPtrRefType(DName const &,DName const &,IndirectionKind);
	static DName getRestrictionSpec();
	static DName getReturnType(DName *);
	static DName getScope();
	static DName getScopedName();
	static DName getSignedDimension();
	static DName getStringEncoding(PrefixKind,int);
	static DName getStringObject();
	static DName getSymbolName();
	static DName getTemplateArgumentList();
	static DName getTemplateName(bool);
	static DName getTemplateNonTypeArgument();
	static DName getTemplateTypeArgument();
	static DName getThrowTypes();
	static DName getUnionObject();
	static DName getVCallThunkType();
	static DName getValueObject();
	static DName getVdispMapType(DName const &);
	static DName getVfTableType(DName const &);
	static DName getZName(bool,bool);
	static DName parseDecoratedName();
	static Replicator * pArgList;
	static Replicator * pTemplateArgList;
	static Replicator * pZNameList;
	static bool fExplicitTemplateParams;
	static bool fGetTemplateArgumentList;
	static char * (* m_pGetParameter)(long);
	static char const * const gName;
	static char const * const name;
	static int getNumberOfDimensions();
	static int getTypeEncoding();
	static std::optional<unsigned __int64> getValue();
	static unsigned long disableFlags;
	static unsigned long m_CHPENameOffset;
	static unsigned long m_recursionLevel;
public:
	char * getUndecoratedName(char *,int);
	static StringLiteral UScore(Tokens);
};

struct _HeapManager
{
	void * getMemoryWithBuffer(unsigned __int64);
};

struct _LocaleUpdate
{
	_LocaleUpdate(__crt_locale_pointers * const);
};

struct __FrameHandler4
{
	static bool ExecutionInCatch(_xDISPATCHER_CONTEXT *,FH4::FuncInfo4 *);
	static int StateFromControlPc(FH4::FuncInfo4 *,_xDISPATCHER_CONTEXT *);
	static int StateFromIp(FH4::FuncInfo4 *,_xDISPATCHER_CONTEXT *,unsigned __int64);
	static std::pair<FH4::TryBlockMap4::iterator,FH4::TryBlockMap4::iterator> GetRangeOfTrysToCheck(FH4::TryBlockMap4 &,int,_xDISPATCHER_CONTEXT *,FH4::FuncInfo4 *,int);
	static unsigned __int64 * GetEstablisherFrame(unsigned __int64 *,_xDISPATCHER_CONTEXT *,FH4::FuncInfo4 *,unsigned __int64 *);
	static void * CxxCallCatchBlock(_EXCEPTION_RECORD *);
	static void FrameUnwindToEmptyState(unsigned __int64 *,_xDISPATCHER_CONTEXT *,FH4::FuncInfo4 *);
	static void FrameUnwindToState(unsigned __int64 *,_xDISPATCHER_CONTEXT *,FH4::FuncInfo4 *,int);
	static void UnwindNestedFrames(unsigned __int64 *,EHExceptionRecord *,_CONTEXT *,unsigned __int64 *,void *,FH4::FuncInfo4 *,int,int,FH4::HandlerType4 *,_xDISPATCHER_CONTEXT *,unsigned char);
};

struct __acrt_stdio_char_traits<char>
{
	static bool validate_stream_is_ansi_if_required(_iobuf * const);
};

namespace __asan
{
	struct AddressDescription
	{
		AddressDescription(unsigned __int64,unsigned __int64,bool);
		void Print(char const *);
	};

	struct Allocator
	{
		AsanChunk * GetAsanChunkByAddr(unsigned __int64);
		AsanChunkView FindHeapChunkByAddress(unsigned __int64);
		static unsigned __int64 ComputeUserRequestedAlignmentLog(unsigned __int64);
		unsigned __int64 AllocationSize(unsigned __int64);
		void * Allocate(unsigned __int64,unsigned __int64,__sanitizer::BufferedStackTrace *,AllocType,bool);
		void * Calloc(unsigned __int64,unsigned __int64,__sanitizer::BufferedStackTrace *);
		void * Reallocate(void *,unsigned __int64,__sanitizer::BufferedStackTrace *);
		void Deallocate(void *,unsigned __int64,unsigned __int64,__sanitizer::BufferedStackTrace *,AllocType);
		void InitLinkerInitialized(AllocatorOptions const &);
		void QuarantineChunk(AsanChunk *,void *,__sanitizer::BufferedStackTrace *);
		void RePoisonChunk(unsigned __int64);
		void SharedInitCode(AllocatorOptions const &);
	};

	struct AllocatorOptions
	{
		void CopyTo(Flags *,__sanitizer::CommonFlags *);
		void SetFrom(Flags const *,__sanitizer::CommonFlags const *);
	};

	struct AsanChunk
	{
		unsigned __int64 UsedSize(bool);
		void * AllocBeg(bool);
	};

	struct AsanChunkView
	{
		AllocType GetAllocType();
		__sanitizer::StackTrace GetAllocStack();
		__sanitizer::StackTrace GetFreeStack();
		bool IsValid();
		unsigned __int64 AllocTid();
		unsigned __int64 Beg();
		unsigned __int64 End();
		unsigned __int64 FreeTid();
		unsigned __int64 UsedSize();
		unsigned int GetAllocStackId();
		unsigned int GetFreeStackId();
		unsigned int UserRequestedAlignment();
	};

	struct AsanDeactivatedFlags
	{
		void OverrideFromActivationFlags();
	};

	struct AsanMapUnmapCallback
	{
		void OnMap(unsigned __int64,unsigned __int64);
		void OnUnmap(unsigned __int64,unsigned __int64);
	};

	struct AsanStats
	{
		AsanStats();
		void Clear();
		void MergeFrom(AsanStats const *);
		void Print();
	};

	class AsanThread
	{
		FakeStack * AsyncSignalSafeLazyInitFakeStack();
		void ClearShadowForThreadStackAndTLS();
		void SetThreadStackAndTls(AsanThread::InitOptions const *);
	public:
		bool AddrIsInStack(unsigned __int64);
		bool GetStackFrameAccessByAddr(unsigned __int64,AsanThread::StackFrameAccess *);
		static AsanThread * Create(unsigned long (*)(void *),void *,unsigned int,__sanitizer::StackTrace *,bool);
		static void TSDDtor(void *);
		unsigned __int64 GetStackVariableShadowStart(unsigned __int64);
		unsigned __int64 stack_bottom();
		unsigned __int64 stack_size();
		unsigned __int64 stack_top();
		unsigned long ThreadStart(unsigned __int64,__sanitizer::atomic_uintptr_t *);
		void Destroy();
		void FinishSwitchFiber(FakeStack *,unsigned __int64 *,unsigned __int64 *);
		void Init(AsanThread::InitOptions const *);
		void StartSwitchFiber(FakeStack * *,unsigned __int64,unsigned __int64);
	};

	struct AsanThreadContext
	{
		virtual void OnCreated(void *);
		virtual void OnFinished();
	};

	class AsanThreadIdAndName
	{
		void Init(unsigned int,char const *);
	public:
		AsanThreadIdAndName(AsanThreadContext *);
		AsanThreadIdAndName(unsigned int);
	};

	struct AsanThreadLocalMallocStorage
	{
		void CommitBack();
	};

	struct ErrorAllocTypeMismatch
	{
		void Print();
	};

	struct ErrorAllocationSizeTooBig
	{
		void Print();
	};

	struct ErrorBadParamsToAnnotateContiguousContainer
	{
		void Print();
	};

	struct ErrorCallocOverflow
	{
		void Print();
	};

	struct ErrorDeadlySignal
	{
		ErrorDeadlySignal(unsigned int,__sanitizer::SignalContext const &);
		void Print();
	};

	struct ErrorDescription
	{
		void Print();
	};

	struct ErrorDoubleFree
	{
		void Print();
	};

	struct ErrorFreeNotMalloced
	{
		void Print();
	};

	struct ErrorGeneric
	{
		ErrorGeneric(unsigned int,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64,bool,unsigned __int64);
		void Print();
	};

	struct ErrorInvalidAlignedAllocAlignment
	{
		void Print();
	};

	struct ErrorInvalidAllocationAlignment
	{
		void Print();
	};

	struct ErrorInvalidPointerPair
	{
		void Print();
	};

	struct ErrorInvalidPosixMemalignAlignment
	{
		void Print();
	};

	struct ErrorMallocUsableSizeNotOwned
	{
		void Print();
	};

	struct ErrorNewDeleteTypeMismatch
	{
		void Print();
	};

	struct ErrorODRViolation
	{
		void Print();
	};

	struct ErrorOutOfMemory
	{
		void Print();
	};

	struct ErrorPvallocOverflow
	{
		void Print();
	};

	struct ErrorReallocArrayOverflow
	{
		void Print();
	};

	struct ErrorRssLimitExceeded
	{
		void Print();
	};

	struct ErrorSanitizerGetAllocatedSizeNotOwned
	{
		void Print();
	};

	struct ErrorStringFunctionMemoryRangesOverlap
	{
		void Print();
	};

	struct ErrorStringFunctionSizeOverflow
	{
		void Print();
	};

	struct FakeStack
	{
		FakeFrame * Allocate(unsigned __int64,unsigned __int64,unsigned __int64);
		static FakeStack * Create(unsigned __int64);
		unsigned __int64 AddrIsInFakeStack(unsigned __int64,unsigned __int64 *,unsigned __int64 *);
		void Destroy(int);
		void GC(unsigned __int64);
		void HandleNoReturn();
		void PoisonAll(unsigned char);
	};

	struct Flags
	{
		void SetDefaults();
	};

	struct GlobalAddressDescription
	{
		bool PointsInsideTheSameVariable(GlobalAddressDescription const &);
		void Print(char const *);
	};

	struct HeapAddressDescription
	{
		void Print();
	};

	struct QuarantineCallback
	{
		void Recycle(AsanChunk *);
	};

	class ScopedInErrorReport
	{
		static ErrorDescription current_error_;
	public:
		~ScopedInErrorReport();
	};

	struct ShadowAddressDescription
	{
		void Print();
	};

	struct StackAddressDescription
	{
		void Print();
	};

	struct __RuntimeFunctions<Msvcr100>
	{
		static unsigned __int64 (* pAlignedMsize)(void *,unsigned __int64,unsigned __int64);
		static unsigned __int64 (* pMsize)(void *);
		static unsigned __int64 (* pMsizeBase)(void *);
		static unsigned __int64 AlignedMsize(void *,unsigned __int64,unsigned __int64);
		static unsigned __int64 Msize(void *);
		static unsigned __int64 MsizeBase(void *);
		static void (* pAlignedFree)(void *);
		static void (* pFree)(void *);
		static void (* pFreeBase)(void *);
		static void * (* pAlignedOffsetRealloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pAlignedOffsetRecalloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pAlignedRealloc)(void *,unsigned __int64,unsigned __int64);
		static void * (* pAlignedRecalloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pExpand)(void *,unsigned __int64);
		static void * (* pExpandBase)(void *,unsigned __int64);
		static void * (* pRealloc)(void *,unsigned __int64);
		static void * (* pReallocBase)(void *,unsigned __int64);
		static void * (* pRecalloc)(void *,unsigned __int64,unsigned __int64);
		static void * (* pRecallocBase)(void *,unsigned __int64,unsigned __int64);
		static void * (* pRecallocCrt)(void *,unsigned __int64,unsigned __int64);
		static void * AlignedOffsetRealloc(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * AlignedOffsetRecalloc(void *,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * AlignedRealloc(void *,unsigned __int64,unsigned __int64);
		static void * AlignedRecalloc(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * Expand(void *,unsigned __int64);
		static void * ExpandBase(void *,unsigned __int64);
		static void * Realloc(void *,unsigned __int64);
		static void * ReallocBase(void *,unsigned __int64);
		static void * Recalloc(void *,unsigned __int64,unsigned __int64);
		static void * RecallocBase(void *,unsigned __int64,unsigned __int64);
		static void * RecallocCrt(void *,unsigned __int64,unsigned __int64);
		static void AlignedFree(void *);
		static void Free(void *);
		static void FreeBase(void *);
	};

	struct __RuntimeFunctions<Msvcr110>
	{
		static unsigned __int64 (* pAlignedMsize)(void *,unsigned __int64,unsigned __int64);
		static unsigned __int64 (* pMsize)(void *);
		static unsigned __int64 (* pMsizeBase)(void *);
		static unsigned __int64 AlignedMsize(void *,unsigned __int64,unsigned __int64);
		static unsigned __int64 Msize(void *);
		static unsigned __int64 MsizeBase(void *);
		static void (* pAlignedFree)(void *);
		static void (* pFree)(void *);
		static void (* pFreeBase)(void *);
		static void * (* pAlignedOffsetRealloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pAlignedOffsetRecalloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pAlignedRealloc)(void *,unsigned __int64,unsigned __int64);
		static void * (* pAlignedRecalloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pExpand)(void *,unsigned __int64);
		static void * (* pExpandBase)(void *,unsigned __int64);
		static void * (* pRealloc)(void *,unsigned __int64);
		static void * (* pReallocBase)(void *,unsigned __int64);
		static void * (* pRecalloc)(void *,unsigned __int64,unsigned __int64);
		static void * (* pRecallocBase)(void *,unsigned __int64,unsigned __int64);
		static void * (* pRecallocCrt)(void *,unsigned __int64,unsigned __int64);
		static void * AlignedOffsetRealloc(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * AlignedOffsetRecalloc(void *,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * AlignedRealloc(void *,unsigned __int64,unsigned __int64);
		static void * AlignedRecalloc(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * Expand(void *,unsigned __int64);
		static void * ExpandBase(void *,unsigned __int64);
		static void * Realloc(void *,unsigned __int64);
		static void * ReallocBase(void *,unsigned __int64);
		static void * Recalloc(void *,unsigned __int64,unsigned __int64);
		static void * RecallocBase(void *,unsigned __int64,unsigned __int64);
		static void * RecallocCrt(void *,unsigned __int64,unsigned __int64);
		static void AlignedFree(void *);
		static void Free(void *);
		static void FreeBase(void *);
	};

	struct __RuntimeFunctions<Msvcr120>
	{
		static unsigned __int64 (* pAlignedMsize)(void *,unsigned __int64,unsigned __int64);
		static unsigned __int64 (* pMsize)(void *);
		static unsigned __int64 (* pMsizeBase)(void *);
		static unsigned __int64 AlignedMsize(void *,unsigned __int64,unsigned __int64);
		static unsigned __int64 Msize(void *);
		static unsigned __int64 MsizeBase(void *);
		static void (* pAlignedFree)(void *);
		static void (* pFree)(void *);
		static void (* pFreeBase)(void *);
		static void * (* pAlignedOffsetRealloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pAlignedOffsetRecalloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pAlignedRealloc)(void *,unsigned __int64,unsigned __int64);
		static void * (* pAlignedRecalloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pExpand)(void *,unsigned __int64);
		static void * (* pExpandBase)(void *,unsigned __int64);
		static void * (* pRealloc)(void *,unsigned __int64);
		static void * (* pReallocBase)(void *,unsigned __int64);
		static void * (* pRecalloc)(void *,unsigned __int64,unsigned __int64);
		static void * (* pRecallocBase)(void *,unsigned __int64,unsigned __int64);
		static void * (* pRecallocCrt)(void *,unsigned __int64,unsigned __int64);
		static void * AlignedOffsetRealloc(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * AlignedOffsetRecalloc(void *,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * AlignedRealloc(void *,unsigned __int64,unsigned __int64);
		static void * AlignedRecalloc(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * Expand(void *,unsigned __int64);
		static void * ExpandBase(void *,unsigned __int64);
		static void * Realloc(void *,unsigned __int64);
		static void * ReallocBase(void *,unsigned __int64);
		static void * Recalloc(void *,unsigned __int64,unsigned __int64);
		static void * RecallocBase(void *,unsigned __int64,unsigned __int64);
		static void * RecallocCrt(void *,unsigned __int64,unsigned __int64);
		static void AlignedFree(void *);
		static void Free(void *);
		static void FreeBase(void *);
	};

	struct __RuntimeFunctions<Ntdll>
	{
		static unsigned __int64 (* pAlignedMsize)(void *,unsigned __int64,unsigned __int64);
		static unsigned __int64 (* pMsize)(void *);
		static unsigned __int64 (* pMsizeBase)(void *);
		static unsigned __int64 AlignedMsize(void *,unsigned __int64,unsigned __int64);
		static unsigned __int64 Msize(void *);
		static unsigned __int64 MsizeBase(void *);
		static void (* pAlignedFree)(void *);
		static void (* pFree)(void *);
		static void (* pFreeBase)(void *);
		static void * (* pAlignedOffsetRealloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pAlignedOffsetRecalloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pAlignedRealloc)(void *,unsigned __int64,unsigned __int64);
		static void * (* pAlignedRecalloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pExpand)(void *,unsigned __int64);
		static void * (* pExpandBase)(void *,unsigned __int64);
		static void * (* pRealloc)(void *,unsigned __int64);
		static void * (* pReallocBase)(void *,unsigned __int64);
		static void * (* pRecalloc)(void *,unsigned __int64,unsigned __int64);
		static void * (* pRecallocBase)(void *,unsigned __int64,unsigned __int64);
		static void * (* pRecallocCrt)(void *,unsigned __int64,unsigned __int64);
		static void * AlignedOffsetRealloc(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * AlignedOffsetRecalloc(void *,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * AlignedRealloc(void *,unsigned __int64,unsigned __int64);
		static void * AlignedRecalloc(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * Expand(void *,unsigned __int64);
		static void * ExpandBase(void *,unsigned __int64);
		static void * Realloc(void *,unsigned __int64);
		static void * ReallocBase(void *,unsigned __int64);
		static void * Recalloc(void *,unsigned __int64,unsigned __int64);
		static void * RecallocBase(void *,unsigned __int64,unsigned __int64);
		static void * RecallocCrt(void *,unsigned __int64,unsigned __int64);
		static void AlignedFree(void *);
		static void Free(void *);
		static void FreeBase(void *);
	};

	struct __RuntimeFunctions<Ucrtbase>
	{
		static unsigned __int64 (* pAlignedMsize)(void *,unsigned __int64,unsigned __int64);
		static unsigned __int64 (* pMsize)(void *);
		static unsigned __int64 (* pMsizeBase)(void *);
		static unsigned __int64 AlignedMsize(void *,unsigned __int64,unsigned __int64);
		static unsigned __int64 Msize(void *);
		static unsigned __int64 MsizeBase(void *);
		static void (* pAlignedFree)(void *);
		static void (* pFree)(void *);
		static void (* pFreeBase)(void *);
		static void * (* pAlignedOffsetRealloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pAlignedOffsetRecalloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pAlignedRealloc)(void *,unsigned __int64,unsigned __int64);
		static void * (* pAlignedRecalloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pExpand)(void *,unsigned __int64);
		static void * (* pExpandBase)(void *,unsigned __int64);
		static void * (* pRealloc)(void *,unsigned __int64);
		static void * (* pReallocBase)(void *,unsigned __int64);
		static void * (* pRecalloc)(void *,unsigned __int64,unsigned __int64);
		static void * (* pRecallocBase)(void *,unsigned __int64,unsigned __int64);
		static void * (* pRecallocCrt)(void *,unsigned __int64,unsigned __int64);
		static void * AlignedOffsetRealloc(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * AlignedOffsetRecalloc(void *,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * AlignedRealloc(void *,unsigned __int64,unsigned __int64);
		static void * AlignedRecalloc(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * Expand(void *,unsigned __int64);
		static void * ExpandBase(void *,unsigned __int64);
		static void * Realloc(void *,unsigned __int64);
		static void * ReallocBase(void *,unsigned __int64);
		static void * Recalloc(void *,unsigned __int64,unsigned __int64);
		static void * RecallocBase(void *,unsigned __int64,unsigned __int64);
		static void * RecallocCrt(void *,unsigned __int64,unsigned __int64);
		static void AlignedFree(void *);
		static void Free(void *);
		static void FreeBase(void *);
	};

	struct __RuntimeFunctions<Vcruntime140>
	{
		static unsigned __int64 (* pAlignedMsize)(void *,unsigned __int64,unsigned __int64);
		static unsigned __int64 (* pMsize)(void *);
		static unsigned __int64 (* pMsizeBase)(void *);
		static unsigned __int64 AlignedMsize(void *,unsigned __int64,unsigned __int64);
		static unsigned __int64 Msize(void *);
		static unsigned __int64 MsizeBase(void *);
		static void (* pAlignedFree)(void *);
		static void (* pFree)(void *);
		static void (* pFreeBase)(void *);
		static void * (* pAlignedOffsetRealloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pAlignedOffsetRecalloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pAlignedRealloc)(void *,unsigned __int64,unsigned __int64);
		static void * (* pAlignedRecalloc)(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * (* pExpand)(void *,unsigned __int64);
		static void * (* pExpandBase)(void *,unsigned __int64);
		static void * (* pRealloc)(void *,unsigned __int64);
		static void * (* pReallocBase)(void *,unsigned __int64);
		static void * (* pRecalloc)(void *,unsigned __int64,unsigned __int64);
		static void * (* pRecallocBase)(void *,unsigned __int64,unsigned __int64);
		static void * (* pRecallocCrt)(void *,unsigned __int64,unsigned __int64);
		static void * AlignedOffsetRealloc(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * AlignedOffsetRecalloc(void *,unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * AlignedRealloc(void *,unsigned __int64,unsigned __int64);
		static void * AlignedRecalloc(void *,unsigned __int64,unsigned __int64,unsigned __int64);
		static void * Expand(void *,unsigned __int64);
		static void * ExpandBase(void *,unsigned __int64);
		static void * Realloc(void *,unsigned __int64);
		static void * ReallocBase(void *,unsigned __int64);
		static void * Recalloc(void *,unsigned __int64,unsigned __int64);
		static void * RecallocBase(void *,unsigned __int64,unsigned __int64);
		static void * RecallocCrt(void *,unsigned __int64,unsigned __int64);
		static void AlignedFree(void *);
		static void Free(void *);
		static void FreeBase(void *);
	};

	__asan::AllocationOwnership CheckGlobalLocalHeapOwnership(void *,void * (*)(void *),int (*)(void *));
	__asan::AsanChunkView FindHeapChunkByAddress(unsigned __int64);
	__asan::AsanStats & GetCurrentThreadStats();
	__asan::AsanThread * CreateMainThread();
	__asan::AsanThread * FindThreadByStackAddress(unsigned __int64);
	__asan::AsanThread * GetCurrentThread();
	__asan::AsanThreadContext * GetThreadContextByTidLocked(unsigned int);
	__asan::FakeStack * GetTLSFakeStack();
	__asan::Flags asan_flags_dont_use_directly;
	__sanitizer::AddrHashMap<_PROCESS_HEAP_ENTRY,1031> * system_allocations;
	__sanitizer::QuarantineCache<__asan::QuarantineCallback> * GetQuarantineCache(__asan::AsanThreadLocalMallocStorage *);
	__sanitizer::SizeClassAllocator64LocalCache<__sanitizer::SizeClassAllocator64<__asan::AP64<__sanitizer::LocalAddressSpaceView> > > * GetAllocatorCache(__asan::AsanThreadLocalMallocStorage *);
	__sanitizer::ThreadRegistry & asanThreadRegistry();
	bool AlignedAllocatedPriorToAsanInit(void *);
	bool AllocatedPriorToAsanInit(void *);
	bool CanPoisonMemory();
	bool GetGlobalAddressInformation(unsigned __int64,unsigned __int64,__asan::GlobalAddressDescription *);
	bool GetHeapAddressInformation(unsigned __int64,unsigned __int64,__asan::HeapAddressDescription *);
	bool GetShadowAddressInformation(unsigned __int64,__asan::ShadowAddressDescription *);
	bool GetStackAddressInformation(unsigned __int64,unsigned __int64,__asan::StackAddressDescription *);
	bool HaveStackTraceBasedSuppressions();
	bool IsInterceptorSuppressed(char const *);
	bool IsODRViolationSuppressed(char const *);
	bool IsStackTraceSuppressed(__sanitizer::StackTrace const *);
	bool IsSystemHeapAddress(unsigned __int64,void *);
	bool ParseFrameDescription(char const *,__sanitizer::InternalMmapVector<__asan::StackVarDescr> *);
	bool PlatformUnpoisonStacks();
	bool asan_init_is_running;
	char const * MaybeDemangleGlobalName(char const *);
	int (* __intercept_seh)();
	int GetGlobalsForAddress(unsigned __int64,__asan_global *,unsigned int *,int);
	int IsTlsInitialized();
	int asan_inited;
	unsigned __int64 * AsanMappingProfile;
	unsigned __int64 FindDynamicShadowStart();
	unsigned __int64 asan_malloc_usable_size(void const *,unsigned __int64,unsigned __int64);
	unsigned __int64 kHighMemEnd;
	unsigned __int64 kMidMemBeg;
	unsigned __int64 kMidMemEnd;
	unsigned char * system_allocation_storage;
	unsigned int GetCurrentTidOrInvalid();
	unsigned int GetMallocContextSize();
	void (* __asan_tls_exit)(void *,unsigned long,void *);
	void (* __asan_tls_init)(void *,unsigned long,void *);
	void * AsanDoesNotSupportStaticLinkage();
	void * AsanTSDGet();
	void * GlobalLocalGenericFree(void * (*)(void *),int (*)(void *),void * (*)(void *),void *,__sanitizer::BufferedStackTrace &);
	void * ReAllocGlobalLocal(void * (*)(void *,unsigned __int64,unsigned int),unsigned __int64 (*)(void *),void * (*)(void *),void * (*)(unsigned int,unsigned __int64),void * (*)(void *),int (*)(void *),__asan_win_moveable::HeapCaller,void *,unsigned __int64,unsigned int,__sanitizer::BufferedStackTrace &);
	void * asan_calloc(unsigned __int64,unsigned __int64,__sanitizer::BufferedStackTrace *);
	void * asan_malloc(unsigned __int64,__sanitizer::BufferedStackTrace *);
	void * asan_memalign(unsigned __int64,unsigned __int64,__sanitizer::BufferedStackTrace *,__asan::AllocType);
	void * asan_realloc(void *,unsigned __int64,__sanitizer::BufferedStackTrace *);
	void * asan_recalloc(void *,unsigned __int64,unsigned __int64,__sanitizer::BufferedStackTrace *);
	void AppendToErrorMessageBuffer(char const *);
	void AsanActivate();
	void AsanApplyToGlobals(void (*)(__asan_global *,unsigned __int64),void const *);
	void AsanCheckDynamicRTPrereqs();
	void AsanCheckIncompatibleRT();
	void AsanDeactivate();
	void AsanInitFromRtl();
	void AsanOnDeadlySignal(int,void *,void *);
	void AsanPoisonOrUnpoisonIntraObjectRedzone(unsigned __int64,unsigned __int64,bool);
	void AsanSoftRssLimitExceededCallback(bool);
	void AsanTSDInit(void (*)(void *));
	void AsanTSDSet(void *);
	void CaptureSystemHeapAllocations();
	void DescribeThread(__asan::AsanThreadContext *);
	void FlushToDeadThreadStats(__asan::AsanStats *);
	void FlushUnneededASanShadowMemory(unsigned __int64,unsigned __int64);
	void GetAllocatorOptions(__asan::AllocatorOptions *);
	void InitializeAllocator(__asan::AllocatorOptions const &);
	void InitializeAsanInterceptors();
	void InitializeFlags();
	void InitializePlatformExceptionHandlers();
	void InitializePlatformInterceptors();
	void InitializeShadowMemory();
	void InitializeSuppressions();
	void OverrideFunctionsForEachCrt();
	void PlatformTSDDtor(void *);
	void PoisonShadow(unsigned __int64,unsigned __int64,unsigned char);
	void PrintAddressDescription(unsigned __int64,unsigned __int64,char const *);
	void PrintAddressSpaceLayout();
	void PrintGlobalLocation(__sanitizer::InternalScopedString *,__asan_global const &);
	void PrintGlobalNameIfASCII(__sanitizer::InternalScopedString *,__asan_global const &);
	void PrintInternalAllocatorStats();
	void PrintMemoryByte(__sanitizer::InternalScopedString *,char const *,unsigned char,bool,char const *);
	void ReInitializeAllocator(__asan::AllocatorOptions const &);
	void RemoveFromSystemHeapAllocationsMap(void *);
	void ReplaceSystemMalloc();
	void ReportAllocTypeMismatch(unsigned __int64,__sanitizer::BufferedStackTrace *,__asan::AllocType,__asan::AllocType);
	void ReportAllocationSizeTooBig(unsigned __int64,unsigned __int64,unsigned __int64,__sanitizer::BufferedStackTrace *);
	void ReportBadParamsToAnnotateContiguousContainer(unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64,__sanitizer::BufferedStackTrace *);
	void ReportCallocOverflow(unsigned __int64,unsigned __int64,__sanitizer::BufferedStackTrace *);
	void ReportDeadlySignal(__sanitizer::SignalContext const &);
	void ReportDoubleFree(unsigned __int64,__sanitizer::BufferedStackTrace *);
	void ReportFreeNotMalloced(unsigned __int64,__sanitizer::BufferedStackTrace *);
	void ReportGenericError(unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64,bool,unsigned __int64,unsigned int,bool);
	void ReportInvalidAllocationAlignment(unsigned __int64,__sanitizer::BufferedStackTrace *);
	void ReportMallocUsableSizeNotOwned(unsigned __int64,__sanitizer::BufferedStackTrace *);
	void ReportNewDeleteTypeMismatch(unsigned __int64,unsigned __int64,unsigned __int64,__sanitizer::BufferedStackTrace *);
	void ReportODRViolation(__asan_global const *,unsigned int,__asan_global const *,unsigned int);
	void ReportOutOfMemory(unsigned __int64,__sanitizer::BufferedStackTrace *);
	void ReportRssLimitExceeded(__sanitizer::BufferedStackTrace *);
	void ReportSanitizerGetAllocatedSizeNotOwned(unsigned __int64,__sanitizer::BufferedStackTrace *);
	void ReportStringFunctionMemoryRangesOverlap(char const *,char const *,unsigned __int64,char const *,unsigned __int64,__sanitizer::BufferedStackTrace *);
	void ReportStringFunctionSizeOverflow(unsigned __int64,unsigned __int64,__sanitizer::BufferedStackTrace *);
	void ReserveShadowMemoryRange(unsigned __int64,unsigned __int64,char const *);
	void SetCanPoisonMemory(bool);
	void SetCurrentThread(__asan::AsanThread *);
	void SetMallocContextSize(unsigned int);
	void SetTLSFakeStack(__asan::FakeStack *);
	void StopInitOrderChecking();
	void UnpoisonStack(unsigned __int64,unsigned __int64,char const *);
	void asan_delete(void *,unsigned __int64,unsigned __int64,__sanitizer::BufferedStackTrace *,__asan::AllocType);
	void asan_free(void *,__sanitizer::BufferedStackTrace *,__asan::AllocType);
};

struct __asan_InitDefine<4>
{
	__asan_InitDefine<4>();
	static int defined;
};

namespace __asan_win_moveable
{
	struct FixedMemoryMap
	{
		bool IsOwned(void *);
	};

	class MoveableMemoryMap
	{
		struct HandleReservation
		{
			~HandleReservation();
		};

		MoveableMemoryMap::MoveableAllocation * _NewMoveableAllocation(RecursiveScopedLock const &);
		MoveableMemoryMap::MoveableAllocation * _QueryPointerEntryMapping(void * const);
		_GetEntryQueryResult MoveableMemoryMap::_GetEntry(void * const,RecursiveScopedLock const &);
		void _AddPointerEntryMapping(MoveableMemoryMap::MoveableAllocation * const);
		void _DeactivateMoveableAllocation(MoveableMemoryMap::MoveableAllocation * const,RecursiveScopedLock const &);
		void _RemovePointerEntryMapping(MoveableMemoryMap::MoveableAllocation const * const);
	public:
		Result DecrementLockCount(void * const);
		Result HandleToPointer(void * const);
		Result Remove(void * const);
	};

	struct TentativeAllocation
	{
		~TentativeAllocation();
	};

	__asan_win_moveable::FixedMemoryMap & GetFixedMemoryMap();
	__asan_win_moveable::MoveableMemoryMap & GetMoveableMemoryMap();
	bool DecrementLockCount(void *,__sanitizer::BufferedStackTrace &);
	bool IsOwned(void *);
	unsigned __int64 GetAllocationSize(void *,__sanitizer::BufferedStackTrace &);
	void * Alloc(unsigned long,unsigned __int64,__sanitizer::BufferedStackTrace &);
	void * Free(void *,__sanitizer::BufferedStackTrace &);
	void * IncrementLockCount(void *,__sanitizer::BufferedStackTrace &);
	void * ReAllocate(void *,unsigned long,unsigned __int64,__asan_win_moveable::HeapCaller,__sanitizer::BufferedStackTrace &);
	void * ReallocMaybeZero(void * const,unsigned __int64,bool,__sanitizer::BufferedStackTrace &);
	void * ResolvePointerToHandle(void *,__sanitizer::BufferedStackTrace &);
};

namespace __crt_mbstring
{
	unsigned __int64 __c32rtomb_utf8(char *,UNKNOWN,_Mbstatet *);
	unsigned __int64 __mbrtoc32_utf8(UNKNOWN *,char const *,unsigned __int64,_Mbstatet *);
	unsigned __int64 __mbrtowc_utf8(wchar_t *,char const *,unsigned __int64,_Mbstatet *);
	unsigned __int64 __mbsrtowcs_utf8(wchar_t *,char const * *,unsigned __int64,_Mbstatet *);
};

namespace __crt_stdio_output
{
	struct formatting_buffer
	{
		bool ensure_buffer_is_big_enough<char>(unsigned __int64);
	};

	class output_adapter_common<char,stream_output_adapter<char> >
	{
	protected:
		void write_string_impl(char const * const,int,int * const,__crt_deferred_errno_cache &);
	};

	class output_processor<char,stream_output_adapter<char>,standard_base<char,stream_output_adapter<char> > >
	{
		bool parse_int_from_format_string(int * const);
		bool state_case_normal();
		bool state_case_normal_tchar(char);
		bool state_case_size();
		bool state_case_type();
		bool type_case_Z();
		bool type_case_a();
		bool type_case_c_tchar(char);
		bool type_case_integer(unsigned int,bool);
		bool type_case_n();
		bool type_case_s();
		bool write_stored_string_tchar(char);
		void type_case_integer_parse_into_buffer<unsigned __int64>(unsigned __int64,unsigned int,bool);
		void type_case_integer_parse_into_buffer<unsigned int>(unsigned int,unsigned int,bool);
	public:
		int process();
	};

	class output_processor<char,string_output_adapter<char>,format_validation_base<char,string_output_adapter<char> > >
	{
		bool parse_int_from_format_string(int * const);
		bool state_case_normal();
		bool state_case_normal_tchar(char);
		bool state_case_size();
		bool state_case_type();
		bool type_case_Z();
		bool type_case_a();
		bool type_case_c_tchar(char);
		bool type_case_integer(unsigned int,bool);
		bool type_case_n();
		bool type_case_s();
		bool write_stored_string_tchar(char);
		void type_case_integer_parse_into_buffer<unsigned __int64>(unsigned __int64,unsigned int,bool);
		void type_case_integer_parse_into_buffer<unsigned int>(unsigned int,unsigned int,bool);
	public:
		int process();
	};

	class output_processor<char,string_output_adapter<char>,standard_base<char,string_output_adapter<char> > >
	{
		bool parse_int_from_format_string(int * const);
		bool state_case_normal();
		bool state_case_normal_tchar(char);
		bool state_case_size();
		bool state_case_type();
		bool type_case_Z();
		bool type_case_a();
		bool type_case_c_tchar(char);
		bool type_case_integer(unsigned int,bool);
		bool type_case_n();
		bool type_case_s();
		bool write_stored_string_tchar(char);
		void type_case_integer_parse_into_buffer<unsigned __int64>(unsigned __int64,unsigned int,bool);
		void type_case_integer_parse_into_buffer<unsigned int>(unsigned int,unsigned int,bool);
	public:
		int process();
	};

	struct string_output_adapter<char>
	{
		void write_string(char const * const,int,int * const,__crt_deferred_errno_cache &);
	};

	__crt_stdio_output::spectre_mitigated_lookup_table<__crt_stdio_output::state_transition_pair,128> const format_validation_lookup_table_spectre;
	__crt_stdio_output::spectre_mitigated_lookup_table<__crt_stdio_output::state_transition_pair,128> const standard_lookup_table_spectre;
	unsigned __int64 to_integer_size(__crt_stdio_output::length_modifier);
	void crop_zeroes(char *,__crt_locale_pointers * const);
	void force_decimal_point(char *,__crt_locale_pointers * const);
	void write_multiple_characters<stream_output_adapter<char>,char>(__crt_stdio_output::stream_output_adapter<char> const &,char,int,int * const);
	void write_multiple_characters<string_output_adapter<char>,char>(__crt_stdio_output::string_output_adapter<char> const &,char,int,int * const);
};

namespace __crt_strtox
{
	unsigned __int64 divide(__crt_strtox::big_integer &,__crt_strtox::big_integer const &);
	unsigned long parse_integer<unsigned long,c_string_character_source<char> >(__crt_locale_pointers * const,__crt_strtox::c_string_character_source<char>,int,bool);
};

struct __crt_unique_heap_ptr<unsigned short,__crt_internal_free_policy>
{
	~__crt_unique_heap_ptr<unsigned short,__crt_internal_free_policy>();
};

namespace __interception
{
	_EXCEPTION_DISPOSITION (* real___C_specific_handler)(_EXCEPTION_RECORD *,void *,_CONTEXT *,_DISPATCHER_CONTEXT *);
	bool DisableXfgOnTarget(unsigned __int64);
	bool OverrideFunction(char const *,unsigned __int64,unsigned __int64 *,char const *);
	bool OverrideFunction(unsigned __int64,unsigned __int64,unsigned __int64 *,bool);
	bool OverrideFunctionWithHotPatch(unsigned __int64,unsigned __int64,unsigned __int64 *,bool);
	bool OverrideFunctionWithRedirectJump(unsigned __int64,unsigned __int64,unsigned __int64 *);
	bool OverrideFunctionWithTrampoline(unsigned __int64,unsigned __int64,unsigned __int64 *);
	char * (* real__strdup)(char const *);
	char * (* real_strcat)(char *,char const *);
	char * (* real_strchr)(char const *,int);
	char * (* real_strcpy)(char *,char const *);
	char * (* real_strncat)(char *,char const *,unsigned __int64);
	char * (* real_strncpy)(char *,char const *,unsigned __int64);
	char * (* real_strpbrk)(char const *,char const *);
	char * (* real_strstr)(char const *,char const *);
	char * (* real_strtok)(char *,char const *);
	double (* real_frexp)(double,int *);
	int (* real_GlobalUnlock)(void *);
	int (* real_LocalUnlock)(void *);
	int (* real_atoi)(char const *);
	int (* real_memcmp)(void const *,void const *,unsigned __int64);
	int (* real_sigaction)(int,__sanitizer::__sanitizer_sigaction const *,__sanitizer::__sanitizer_sigaction *);
	int (* real_strcmp)(char const *,char const *);
	int (* real_strncmp)(char const *,char const *,unsigned __int64);
	long (* real_atol)(char const *);
	long (* real_strtol)(char const *,char * *,int);
	long (*(* real_SetUnhandledExceptionFilter)(long (*)(_EXCEPTION_POINTERS *)))(_EXCEPTION_POINTERS *);
	unsigned __int64 (* real_GlobalSize)(void *);
	unsigned __int64 (* real_LocalSize)(void *);
	unsigned __int64 (* real_RtlSizeHeap)(void *,unsigned long,void *);
	unsigned __int64 (* real_strcspn)(char const *,char const *);
	unsigned __int64 (* real_strlen)(char const *);
	unsigned __int64 (* real_strnlen)(char const *,unsigned __int64);
	unsigned __int64 (* real_strspn)(char const *,char const *);
	unsigned __int64 (* real_wcslen)(wchar_t const *);
	unsigned __int64 (* real_wcsnlen)(wchar_t const *,unsigned __int64);
	unsigned __int64 GetPageSizeCached();
	unsigned __int64 InternalGetProcAddress(void *,char const *);
	unsigned long (* real_RtlFreeHeap)(void *,unsigned long,void *);
	void (* real_RaiseException)(unsigned long,unsigned long,unsigned long,unsigned __int64 const *);
	void (* real_RtlRaiseException)(_EXCEPTION_RECORD *);
	void (* real_longjmp)(void *,int);
	void * (* real_CreateThread)(_SECURITY_ATTRIBUTES *,unsigned __int64,unsigned long (*)(void *),void *,unsigned long,unsigned long *);
	void * (* real_GlobalAlloc)(unsigned int,unsigned __int64);
	void * (* real_GlobalFree)(void *);
	void * (* real_GlobalHandle)(void *);
	void * (* real_GlobalLock)(void *);
	void * (* real_GlobalReAlloc)(void *,unsigned __int64,unsigned int);
	void * (* real_LocalAlloc)(unsigned int,unsigned __int64);
	void * (* real_LocalFree)(void *);
	void * (* real_LocalHandle)(void *);
	void * (* real_LocalLock)(void *);
	void * (* real_LocalReAlloc)(void *,unsigned __int64,unsigned int);
	void * (* real_RtlAllocateHeap)(void *,unsigned long,unsigned __int64);
	void * (* real_RtlDestroyHeap)(void *);
	void * (* real_RtlReAllocateHeap)(void *,unsigned long,void *,unsigned __int64);
	void * (* real_memchr)(void const *,int,unsigned __int64);
	void * (* real_memcpy)(void *,void const *,unsigned __int64);
	void * (* real_memmove)(void *,void const *,unsigned __int64);
	void * (* real_memset)(void *,int,unsigned __int64);
};

namespace __sancov
{
	struct SancovFlags
	{
		void SetDefaults();
	};

	__sancov::SancovFlags sancov_flags_dont_use_directly;
	void InitializeSancovFlags();
};

namespace __sanitizer
{
	class AddrHashMap<AsanHeap *,37>
	{
		struct Handle
		{
			AsanHeap * & operator*();
			AsanHeap * const & operator*();
			Handle(AddrHashMap<AsanHeap *,37> *,unsigned __int64,bool,bool);
			bool created();
			bool exists();
			~Handle();
		};

		unsigned __int64 calcHash(unsigned __int64);
		void acquire(AddrHashMap<AsanHeap *,37>::Handle *);
		void release(AddrHashMap<AsanHeap *,37>::Handle *);
	public:
		AddrHashMap<AsanHeap *,37>();
	};

	class AddrHashMap<AsanHeapMemoryNode *,4099>
	{
		struct Handle
		{
			AsanHeapMemoryNode * & operator*();
			Handle(AddrHashMap<AsanHeapMemoryNode *,4099> *,unsigned __int64,bool,bool);
			bool exists();
			~Handle();
		};

		unsigned __int64 calcHash(unsigned __int64);
		void acquire(AddrHashMap<AsanHeapMemoryNode *,4099>::Handle *);
		void release(AddrHashMap<AsanHeapMemoryNode *,4099>::Handle *);
	public:
		AddrHashMap<AsanHeapMemoryNode *,4099>();
	};

	class AddrHashMap<_PROCESS_HEAP_ENTRY,1031>
	{
		struct Handle
		{
			Handle(AddrHashMap<_PROCESS_HEAP_ENTRY,1031> *,unsigned __int64,bool,bool);
			_PROCESS_HEAP_ENTRY & operator*();
			bool exists();
			~Handle();
		};

		unsigned __int64 calcHash(unsigned __int64);
		void acquire(AddrHashMap<_PROCESS_HEAP_ENTRY,1031>::Handle *);
		void release(AddrHashMap<_PROCESS_HEAP_ENTRY,1031>::Handle *);
	public:
		AddrHashMap<_PROCESS_HEAP_ENTRY,1031>();
	};

	class AddrHashMap<__asan_win_moveable::MoveableMemoryMap::MoveableAllocation *,11>
	{
		struct Handle
		{
			Handle(AddrHashMap<__asan_win_moveable::MoveableMemoryMap::MoveableAllocation *,11> *,unsigned __int64,bool,bool);
			__asan_win_moveable::MoveableMemoryMap::MoveableAllocation * & operator*();
			bool created();
			bool exists();
			~Handle();
		};

		unsigned __int64 calcHash(unsigned __int64);
		void acquire(AddrHashMap<__asan_win_moveable::MoveableMemoryMap::MoveableAllocation *,11>::Handle *);
		void release(AddrHashMap<__asan_win_moveable::MoveableMemoryMap::MoveableAllocation *,11>::Handle *);
	public:
		AddrHashMap<__asan_win_moveable::MoveableMemoryMap::MoveableAllocation *,11>();
	};

	class AddrHashMap<bool,11>
	{
		struct Handle
		{
			Handle(AddrHashMap<bool,11> *,unsigned __int64,bool,bool);
			bool created();
			bool exists();
			~Handle();
		};

		unsigned __int64 calcHash(unsigned __int64);
		void acquire(AddrHashMap<bool,11>::Handle *);
		void release(AddrHashMap<bool,11>::Handle *);
	public:
		AddrHashMap<bool,11>();
	};

	struct AddressInfo
	{
		AddressInfo();
		void Clear();
		void FillModuleInfo(char const *,unsigned __int64,ModuleArch);
	};

	struct BlockingMutex
	{
		BlockingMutex();
		void CheckLocked();
		void Lock();
		void Unlock();
	};

	class BufferedStackTrace
	{
		unsigned __int64 LocatePcInTrace(unsigned __int64);
		void PopStackFrames(unsigned __int64);
		void UnwindImpl(unsigned __int64,unsigned __int64,void *,bool,unsigned int);
		void UnwindSlow(unsigned __int64,unsigned int);
		void UnwindSlow(unsigned __int64,void *,unsigned int);
	public:
		BufferedStackTrace();
		void Unwind(unsigned __int64,unsigned __int64,void *,bool,unsigned int);
		void Unwind(unsigned int,unsigned __int64,unsigned __int64,void *,unsigned __int64,unsigned __int64,bool);
	};

	struct CombinedAllocator<SizeClassAllocator32<AP32>,LargeMmapAllocatorPtrArrayStatic>
	{
		void * Allocate(SizeClassAllocator32LocalCache<SizeClassAllocator32<AP32> > *,unsigned __int64,unsigned __int64);
		void Deallocate(SizeClassAllocator32LocalCache<SizeClassAllocator32<AP32> > *,void *);
	};

	struct CombinedAllocator<SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> >,LargeMmapAllocatorPtrArrayDynamic>
	{
		unsigned __int64 GetActuallyAllocatedSize(void *);
		void * Allocate(SizeClassAllocator64LocalCache<SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> > > *,unsigned __int64,unsigned __int64);
		void * GetMetaData(void const *);
		void Deallocate(SizeClassAllocator64LocalCache<SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> > > *,void *);
		void ForEachChunk(void (*)(unsigned __int64,void *),void *);
		void ForceLock();
		void ForceUnlock();
	};

	struct CommonFlags
	{
		void CopyFrom(CommonFlags const &);
		void SetDefaults();
	};

	struct DataInfo
	{
		DataInfo();
		void Clear();
	};

	struct FlagHandler<bool>
	{
		virtual bool Format(char *,unsigned __int64);
		virtual bool Parse(char const *);
	};

	struct FlagHandler<char const *>
	{
		virtual bool Format(char *,unsigned __int64);
		virtual bool Parse(char const *);
	};

	struct FlagHandler<int>
	{
		virtual bool Format(char *,unsigned __int64);
		virtual bool Parse(char const *);
	};

	struct FlagHandler<unsigned __int64>
	{
		virtual bool Format(char *,unsigned __int64);
		virtual bool Parse(char const *);
	};

	struct FlagHandlerInclude
	{
		virtual bool Format(char *,unsigned __int64);
		virtual bool Parse(char const *);
	};

	class FlagParser
	{
		bool is_space(char);
		bool run_handler(char const *,char const *);
		char * ll_strndup(char const *,unsigned __int64);
		void fatal_error(char const *);
		void parse_flag(char const *);
		void parse_flags(char const *);
		void skip_whitespace();
	public:
		FlagParser();
		bool ParseFile(char const *,bool);
		static LowLevelAllocator Alloc;
		void ParseString(char const *,char const *);
		void ParseStringFromEnv(char const *);
		void PrintFlagDescriptions();
		void RegisterHandler(char const *,FlagHandlerBase *,char const *);
	};

	struct GenericScopedLock<BlockingMutex>
	{
		~GenericScopedLock<BlockingMutex>();
	};

	struct GenericScopedLock<StaticSpinMutex>
	{
		~GenericScopedLock<StaticSpinMutex>();
	};

	struct GenericScopedLock<ThreadRegistry>
	{
		~GenericScopedLock<ThreadRegistry>();
	};

	struct InternalMmapVector<__asan::StackVarDescr>
	{
		~InternalMmapVector<__asan::StackVarDescr>();
	};

	struct InternalMmapVector<char>
	{
		~InternalMmapVector<char>();
	};

	class InternalMmapVectorNoCtor<LoadedModule>
	{
		void Realloc(unsigned __int64);
	};

	class InternalMmapVectorNoCtor<Suppression>
	{
		void Realloc(unsigned __int64);
	};

	class InternalMmapVectorNoCtor<__asan::DynInitGlobal>
	{
		void Realloc(unsigned __int64);
	};

	class InternalMmapVectorNoCtor<__asan::GlobalRegistrationSite>
	{
		void Realloc(unsigned __int64);
	};

	struct InternalMmapVectorNoCtor<__asan::StackVarDescr>
	{
		void push_back(__asan::StackVarDescr const &);
	};

	class InternalMmapVectorNoCtor<char const *>
	{
		void Realloc(unsigned __int64);
	};

	struct InternalMmapVectorNoCtor<char>
	{
		void reserve(unsigned __int64);
	};

	struct InternalMmapVectorNoCtor<unsigned __int64>
	{
		void reserve(unsigned __int64);
	};

	struct InternalMmapVectorNoCtor<wchar_t>
	{
		void reserve(unsigned __int64);
	};

	struct InternalScopedString
	{
		InternalScopedString(unsigned __int64);
		void append(char const *,...);
		~InternalScopedString();
	};

	struct IntrusiveList<AsanHeapMemoryNode>
	{
		void push_back(AsanHeapMemoryNode *);
	};

	class LLVMSymbolizer
	{
		char const * FormatAndSendCommand(char const *,char const *,unsigned __int64,ModuleArch);
	public:
		LLVMSymbolizer(char const *,LowLevelAllocator *);
		virtual bool SymbolizeData(unsigned __int64,DataInfo *);
		virtual bool SymbolizeFrame(unsigned __int64,FrameInfo *);
		virtual bool SymbolizePC(unsigned __int64,SymbolizedStack *);
	};

	class LLVMSymbolizerProcess
	{
		virtual bool ReachedEndOfOutput(char const *,unsigned __int64);
		virtual void GetArgV(char const *,char const * (&)[6]);
	};

	struct LargeMmapAllocator<NoOpMapUnmapCallback,LargeMmapAllocatorPtrArrayStatic,LocalAddressSpaceView>
	{
		void * Allocate(AllocatorStats *,unsigned __int64,unsigned __int64);
	};

	class LargeMmapAllocator<__asan::AsanMapUnmapCallback,LargeMmapAllocatorPtrArrayDynamic,LocalAddressSpaceView>
	{
		void * GetUser(LargeMmapAllocator<__asan::AsanMapUnmapCallback,LargeMmapAllocatorPtrArrayDynamic,LocalAddressSpaceView>::Header const *);
	public:
		void * Allocate(AllocatorStats *,unsigned __int64,unsigned __int64);
		void * GetBlockBegin(void const *);
		void * GetBlockBeginFastLocked(void *);
		void Deallocate(AllocatorStats *,void *);
	};

	class ListOfModules
	{
		void clear();
	public:
		void fallbackInit();
		void init();
	};

	struct LoadedModule
	{
		bool containsAddress(unsigned __int64);
		void addAddressRange(unsigned __int64,unsigned __int64,bool,bool,char const *);
		void clear();
		void set(char const *,unsigned __int64);
	};

	struct LowLevelAllocator
	{
		void * Allocate(unsigned __int64);
	};

	class Quarantine<__asan::QuarantineCallback,__asan::AsanChunk>
	{
		void DoRecycle(QuarantineCache<__asan::QuarantineCallback> *,__asan::QuarantineCallback);
		void Recycle(unsigned __int64,__asan::QuarantineCallback);
	public:
		void Drain(QuarantineCache<__asan::QuarantineCallback> *,__asan::QuarantineCallback);
		void DrainAndRecycle(QuarantineCache<__asan::QuarantineCallback> *,__asan::QuarantineCallback);
		void Put(QuarantineCache<__asan::QuarantineCallback> *,__asan::QuarantineCallback,__asan::AsanChunk *,unsigned __int64);
	};

	struct QuarantineCache<__asan::QuarantineCallback>
	{
		void MergeBatches(QuarantineCache<__asan::QuarantineCallback> *);
		void Transfer(QuarantineCache<__asan::QuarantineCallback> *);
	};

	class RWMutex
	{
		void LockSlow();
		void ReadLockSlow();
	};

	class ReportFile
	{
		void ReopenIfNecessary();
	public:
		void SetReportPath(char const *);
		void Write(char const *,unsigned __int64);
	};

	struct ReservedAddressRange
	{
		unsigned __int64 Init(unsigned __int64,char const *,unsigned __int64);
		unsigned __int64 InitAligned(unsigned __int64,unsigned __int64,char const *);
		unsigned __int64 Map(unsigned __int64,unsigned __int64,char const *);
		unsigned __int64 MapOrDie(unsigned __int64,unsigned __int64,char const *);
	};

	struct ScopedErrorReportLock
	{
		ScopedErrorReportLock();
		static void CheckLocked();
		~ScopedErrorReportLock();
	};

	class SignalContext
	{
		SignalContext::WriteFlag GetWriteFlag();
		bool IsMemoryAccess();
		bool IsTrueFaultingAddress();
		unsigned __int64 GetAddress();
		void InitPcSpBp();
	public:
		bool IsStackOverflow();
		char const * Describe();
		int GetType();
		static void DumpAllRegisters(void *);
	};

	class SizeClassAllocator32<AP32>
	{
		bool PopulateFreeList(AllocatorStats *,SizeClassAllocator32LocalCache<SizeClassAllocator32<AP32> > *,SizeClassAllocator32<AP32>::SizeClassInfo *,unsigned __int64);
		unsigned __int64 AllocateRegion(AllocatorStats *,unsigned __int64);
	public:
		SizeClassAllocator32<AP32>::TransferBatch * AllocateBatch(AllocatorStats *,SizeClassAllocator32LocalCache<SizeClassAllocator32<AP32> > *,unsigned __int64);
		unsigned __int64 GetSizeClass(void const *);
		void DeallocateBatch(AllocatorStats *,unsigned __int64,SizeClassAllocator32<AP32>::TransferBatch *);
	};

	class SizeClassAllocator32LocalCache<SizeClassAllocator32<AP32> >
	{
		bool Refill(SizeClassAllocator32LocalCache<SizeClassAllocator32<AP32> >::PerClass *,SizeClassAllocator32<AP32> *,unsigned __int64);
		void Drain(SizeClassAllocator32LocalCache<SizeClassAllocator32<AP32> >::PerClass *,SizeClassAllocator32<AP32> *,unsigned __int64);
		void InitCache(SizeClassAllocator32LocalCache<SizeClassAllocator32<AP32> >::PerClass *);
	public:
		void * Allocate(SizeClassAllocator32<AP32> *,unsigned __int64);
		void Deallocate(SizeClassAllocator32<AP32> *,unsigned __int64,void *);
	};

	class SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> >
	{
		struct PackedCounterArray<SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> >::MemoryMapper>
		{
			PackedCounterArray<SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> >::MemoryMapper>(unsigned __int64,unsigned __int64,SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> >::MemoryMapper *);
			~PackedCounterArray<SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> >::MemoryMapper>();
		};

		bool EnsureFreeArraySpace(SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> >::RegionInfo *,unsigned __int64,unsigned __int64);
		bool IsRegionExhausted(SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> >::RegionInfo *,unsigned __int64,unsigned __int64);
		bool PopulateFreeArray(AllocatorStats *,unsigned __int64,SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> >::RegionInfo *,unsigned __int64);
		void MaybeReleaseToOS(unsigned __int64,bool);
	public:
		bool GetFromAllocator(AllocatorStats *,unsigned __int64,unsigned int *,unsigned __int64);
		bool PointerIsMine(void const *);
		static unsigned __int64 ClassIdToSize(unsigned __int64);
		static void FillMemoryProfile(unsigned __int64,unsigned __int64,bool,unsigned __int64 *,unsigned __int64);
		static void ReleaseFreeMemoryToOS<SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> >::MemoryMapper>(unsigned int *,unsigned __int64,unsigned __int64,unsigned __int64,SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> >::MemoryMapper *);
		void * GetBlockBegin(void const *);
		void ForceReleaseToOS();
		void PrintStats();
		void ReturnToAllocator(AllocatorStats *,unsigned __int64,unsigned int const *,unsigned __int64);
	};

	class SizeClassAllocator64LocalCache<SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> > >
	{
		bool Refill(SizeClassAllocator64LocalCache<SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> > >::PerClass *,SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> > *,unsigned __int64);
		void Drain(SizeClassAllocator64LocalCache<SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> > >::PerClass *,SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> > *,unsigned __int64,unsigned __int64);
		void InitCache(SizeClassAllocator64LocalCache<SizeClassAllocator64<__asan::AP64<LocalAddressSpaceView> > >::PerClass *);
	};

	struct SizeClassMap<3,4,8,17,128,16>
	{
		static unsigned __int64 ClassID(unsigned __int64);
	};

	class StackDepotBase<StackDepotNode,1,20>
	{
		static StackDepotNode * find(StackDepotNode *,StackTrace,unsigned int);
		static StackDepotNode * lock(atomic_uintptr_t *);
		static void unlock(atomic_uintptr_t *,StackDepotNode *);
	public:
		StackDepotHandle Put(StackTrace,bool *);
		StackTrace Get(unsigned int);
	};

	struct StackDepotHandle
	{
		unsigned int id();
	};

	struct StackTrace
	{
		static unsigned __int64 GetCurrentPc();
		static unsigned __int64 GetNextInstructionPc(unsigned __int64);
		void Print();
	};

	class StaticSpinMutex
	{
		void LockSlow();
	};

	struct SuppressionContext
	{
		SuppressionContext(char const * * const,int);
		bool HasSuppressionType(char const *);
		bool Match(char const *,char const *,Suppression * *);
		void Parse(char const *);
		void ParseFromFile(char const *);
	};

	class SymbolizedStack
	{
		SymbolizedStack();
	public:
		static SymbolizedStack * New(unsigned __int64);
		void ClearAll();
	};

	class Symbolizer
	{
		struct ModuleNameOwner
		{
			char const * GetOwnedCopy(char const *);
		};

		struct SymbolizerScope
		{
			SymbolizerScope(Symbolizer const *);
			~SymbolizerScope();
		};

		Symbolizer(IntrusiveList<SymbolizerTool>);
		bool FindModuleNameAndOffsetForAddress(unsigned __int64,char const * *,unsigned __int64 *,ModuleArch *);
		char const * PlatformDemangle(char const *);
		static LowLevelAllocator symbolizer_allocator_;
		static StaticSpinMutex init_mu_;
		static Symbolizer * PlatformInit();
		static Symbolizer * symbolizer_;
		void LateInitializeTools();
	public:
		LoadedModule const * FindModuleForAddress(unsigned __int64);
		SymbolizedStack * SymbolizePC(unsigned __int64);
		bool GetModuleNameAndOffsetForPC(unsigned __int64,char const * *,unsigned __int64 *);
		bool SymbolizeData(unsigned __int64,DataInfo *);
		char const * Demangle(char const *);
		static Symbolizer * GetOrInit();
		static void LateInitialize();
		void RefreshModules();
	};

	class SymbolizerProcess
	{
		bool Restart();
		bool WriteToSymbolizer(char const *,unsigned __int64);
		char const * SendCommandImpl(char const *);
		virtual bool ReachedEndOfOutput(char const *,unsigned __int64);
		virtual void GetArgV(char const *,char const * (&)[6]);
	protected:
		virtual bool ReadFromSymbolizer(char *,unsigned __int64);
		virtual bool StartSymbolizerSubprocess();
		virtual char * * GetEnvP();
	public:
		SymbolizerProcess(char const *,bool);
		char const * SendCommand(char const *);
	};

	struct SymbolizerTool
	{
		virtual bool SymbolizeFrame(unsigned __int64,FrameInfo *);
		virtual char const * Demangle(char const *);
		virtual void Flush();
		virtual void LateInitialize();
	};

	struct ThreadContextBase
	{
		ThreadContextBase(unsigned int);
		virtual void OnCreated(void *);
		virtual void OnDead();
		virtual void OnDetached(void *);
		virtual void OnFinished();
		virtual void OnJoined(void *);
		virtual void OnReset();
		virtual void OnStarted(void *);
		void Reset();
		void SetCreated(unsigned __int64,unsigned __int64,bool,unsigned int,void *);
		void SetDead();
		void SetDestroyed();
		void SetFinished();
		void SetName(char const *);
		void SetStarted(unsigned __int64,ThreadType,void *);
	};

	class ThreadRegistry
	{
		ThreadContextBase * QuarantinePop();
		void QuarantinePush(ThreadContextBase *);
	public:
		ThreadContextBase * FindThreadContextLocked(bool (*)(ThreadContextBase *,void *),void *);
		ThreadRegistry(ThreadContextBase * (*)(unsigned int),unsigned int,unsigned int,unsigned int);
		unsigned int CreateThread(unsigned __int64,bool,unsigned int,void *);
		void FinishThread(unsigned int);
		void RunCallbackForEachThreadLocked(void (*)(ThreadContextBase *,void *),void *);
		void StartThread(unsigned int,unsigned __int64,ThreadType,void *);
	};

	AsanHeap & immortalize<AsanHeap,void *>(void *);
	AsanHeapMap & immortalize<AsanHeapMap>();
	__asan_win_moveable::FixedMemoryMap & immortalize<__asan_win_moveable::FixedMemoryMap>();
	__asan_win_moveable::MoveableMemoryMap & immortalize<__asan_win_moveable::MoveableMemoryMap>();
	__int64 internal_atoll(char const *);
	__int64 internal_simple_strtoll(char const *,char const * *,int);
	__interception::SYSTEM_INFO_immortal & immortalize<__interception::SYSTEM_INFO_immortal>();
	__interception::ZwSetInformationVirtualMemory_immortal & immortalize<__interception::ZwSetInformationVirtualMemory_immortal>();
	__sanitizer::CombinedAllocator<__sanitizer::SizeClassAllocator32<__sanitizer::AP32>,__sanitizer::LargeMmapAllocatorPtrArrayStatic> * internal_allocator();
	__sanitizer::CommonFlags common_flags_dont_use;
	__sanitizer::CommonFlags const * common_flags();
	__sanitizer::DTLS * DTLS_Get();
	__sanitizer::InternalMmapVectorNoCtor<void (*)()> atexit_functions;
	__sanitizer::PersistentAllocator thePersistentAllocator;
	__sanitizer::ReportFile report_file;
	__sanitizer::StackDepotStats * StackDepotGetStats();
	__sanitizer::StackTrace StackDepotGet(unsigned int);
	__sanitizer::StaticSpinMutex report_file_mu;
	__sanitizer::UnknownFlags unknown_flags;
	__sanitizer::_MEMORY_REGION_INFORMATION QueryVirtualMemory(void *);
	__sanitizer::atomic_uint32_t current_verbosity;
	bool AddDieCallback(void (*)());
	bool AllocatorMayReturnNull();
	bool ColorizeReports();
	bool DontDumpShadowMemory(unsigned __int64,unsigned __int64);
	bool FileExists(char const *);
	bool IsAbsolutePath(char const *);
	bool IsAccessibleMemoryRange(unsigned __int64,unsigned __int64);
	bool IsHandledDeadlyException(unsigned long);
	bool IsPathSeparator(char);
	bool IsProcessTerminating();
	bool MemoryRangeIsAvailable(unsigned __int64,unsigned __int64);
	bool MmapFixedNoReserve(unsigned __int64,unsigned __int64,char const *);
	bool MmapFixedSuperNoReserve(unsigned __int64,unsigned __int64,char const *);
	bool ParseBool(char const *,bool *);
	bool ReadFileToBuffer(char const *,char * *,unsigned __int64 *,unsigned __int64 *,unsigned __int64,unsigned int *);
	bool ReadFromFile(void *,void *,unsigned __int64,unsigned __int64 *,unsigned int *);
	bool TemplateMatch(char const *,char const *);
	bool WriteToFile(void *,void const *,unsigned __int64,unsigned __int64 *,unsigned int *);
	bool mem_is_zero(char const *,unsigned __int64);
	char * * GetArgv();
	char * * GetEnviron();
	char * FindPathToBinary(char const *);
	char * internal_strchr(char const *,int);
	char * internal_strchrnul(char const *,int);
	char * internal_strdup(char const *);
	char * internal_strncat(char *,char const *,unsigned __int64);
	char * internal_strncpy(char *,char const *,unsigned __int64);
	char * internal_strrchr(char const *,int);
	char * internal_strstr(char const *,char const *);
	char const * ExtractSptr(char const *,char const *,__int64 *);
	char const * ExtractToken(char const *,char const *,char * *);
	char const * ExtractUptr(char const *,char const *,unsigned __int64 *);
	char const * GetEnv(char const *);
	char const * GetProcessName();
	char const * StripModuleName(char const *);
	char const * StripPathPrefix(char const *,char const *);
	char const * const PrimaryAllocatorName;
	char const * const SanitizerToolName;
	char const * const SecondaryAllocatorName;
	int (* QueryVirtualMemoryInformation)(void *,void const *,WIN32_MEMORY_INFORMATION_CLASS,void *,unsigned __int64,unsigned __int64 *);
	int (* StackWalk64)(unsigned long,void *,void *,_tagSTACKFRAME64 *,void *,int (*)(void *,unsigned __int64,void *,unsigned long,unsigned long *),void * (*)(void *,unsigned __int64),unsigned __int64 (*)(void *,unsigned __int64),unsigned __int64 (*)(void *,void *,_tagADDRESS64 *));
	int (* SymCleanup)(void *);
	int (* SymFromAddr)(void *,unsigned __int64,unsigned __int64 *,_SYMBOL_INFO *);
	int (* SymGetLineFromAddr64)(void *,unsigned __int64,unsigned long *,_IMAGEHLP_LINE64 *);
	int (* SymGetSearchPathW)(void *,wchar_t *,unsigned long);
	int (* SymInitialize)(void *,char const *,int);
	int (* SymSetSearchPathW)(void *,wchar_t const *);
	int (* __run_atexit)();
	int Atexit(void (*)());
	int Max<int>(int,int);
	int VSNPrintf(char *,int,char const *,char *);
	int immortalize_impl<AsanHeap,void *>(_RTL_RUN_ONCE *,void *,void * *);
	int immortalize_impl<AsanHeapMap>(_RTL_RUN_ONCE *,void *,void * *);
	int immortalize_impl<__asan_win_moveable::FixedMemoryMap>(_RTL_RUN_ONCE *,void *,void * *);
	int immortalize_impl<__asan_win_moveable::MoveableMemoryMap>(_RTL_RUN_ONCE *,void *,void * *);
	int immortalize_impl<__interception::SYSTEM_INFO_immortal>(_RTL_RUN_ONCE *,void *,void * *);
	int immortalize_impl<__interception::ZwSetInformationVirtualMemory_immortal>(_RTL_RUN_ONCE *,void *,void * *);
	int internal_memcmp(void const *,void const *,unsigned __int64);
	int internal_snprintf(char *,unsigned __int64,char const *,...);
	int internal_strcmp(char const *,char const *);
	int internal_strncmp(char const *,char const *,unsigned __int64);
	signed char Max<signed char>(signed char,signed char);
	signed char Min<signed char>(signed char,signed char);
	unsigned __int64 (* SymGetModuleBase64)(void *,unsigned __int64);
	unsigned __int64 FindAvailableMemoryRange(unsigned __int64,unsigned __int64,unsigned __int64,unsigned __int64 *,unsigned __int64 *);
	unsigned __int64 GetMaxUserVirtualAddress();
	unsigned __int64 GetMmapGranularity();
	unsigned __int64 GetPageSize();
	unsigned __int64 GetThreadSelf();
	unsigned __int64 GetTid();
	unsigned __int64 Log2(unsigned __int64);
	unsigned __int64 Max<unsigned __int64>(unsigned __int64,unsigned __int64);
	unsigned __int64 Min<unsigned __int64>(unsigned __int64,unsigned __int64);
	unsigned __int64 MonotonicNanoTime();
	unsigned __int64 MostSignificantSetBitIndex(unsigned __int64);
	unsigned __int64 NanoTime();
	unsigned __int64 PageSizeCached;
	unsigned __int64 ReadBinaryName(char *,unsigned __int64);
	unsigned __int64 ReadBinaryNameCached(char *,unsigned __int64);
	unsigned __int64 ReadLongProcessName(char *,unsigned __int64);
	unsigned __int64 RoundUpTo(unsigned __int64,unsigned __int64);
	unsigned __int64 RoundUpToPowerOfTwo(unsigned __int64);
	unsigned __int64 internal_getpid();
	unsigned __int64 internal_sched_yield();
	unsigned __int64 internal_strcspn(char const *,char const *);
	unsigned __int64 internal_strlcat(char *,char const *,unsigned __int64);
	unsigned __int64 internal_strlcpy(char *,char const *,unsigned __int64);
	unsigned __int64 internal_strlen(char const *);
	unsigned __int64 internal_strnlen(char const *,unsigned __int64);
	unsigned __int64 stoptheworld_tracer_pid;
	unsigned __int64 stoptheworld_tracer_ppid;
	unsigned int Max<unsigned int>(unsigned int,unsigned int);
	unsigned int Min<unsigned int>(unsigned int,unsigned int);
	unsigned int NumberOfCPUsCached;
	unsigned int StackDepotPut(__sanitizer::StackTrace);
	unsigned int atomic_fetch_add(__sanitizer::atomic_uint32_t volatile *,unsigned int,__sanitizer::memory_order);
	unsigned long (* SymSetOptions)(unsigned long);
	unsigned long (* UnDecorateSymbolName)(char const *,char *,unsigned long,unsigned long);
	void * (* SymFunctionTableAccess64)(void *,unsigned __int64);
	void * InternalAlloc(unsigned __int64,__sanitizer::SizeClassAllocator32LocalCache<__sanitizer::SizeClassAllocator32<__sanitizer::AP32> > *,unsigned __int64);
	void * MmapAlignedOrDieOnFatalError(unsigned __int64,unsigned __int64,char const *);
	void * MmapFixedNoAccess(unsigned __int64,unsigned __int64,char const *);
	void * MmapFixedOrDie(unsigned __int64,unsigned __int64,char const *);
	void * MmapFixedOrDieOnFatalError(unsigned __int64,unsigned __int64,char const *);
	void * MmapNoAccess(unsigned __int64);
	void * MmapNoReserveOrDie(unsigned __int64,char const *);
	void * MmapOrDie(unsigned __int64,char const *,bool);
	void * MmapOrDieOnFatalError(unsigned __int64,char const *);
	void * OpenFile(char const *,__sanitizer::FileAccessMode,unsigned int *);
	void * internal_memchr(void const *,int,unsigned __int64);
	void * internal_memcpy(void *,void const *,unsigned __int64);
	void * internal_memmove(void *,void const *,unsigned __int64);
	void * internal_memset(void *,int,unsigned __int64);
	void Abort();
	void AndroidLogInit();
	void CacheBinaryName();
	void CatastrophicErrorWrite(char const *,unsigned __int64);
	void CheckASLR();
	void CheckFailed(char const *,int,char const *,unsigned __int64,unsigned __int64);
	void CloseFile(void *);
	void DTLS_Destroy();
	void DecreaseTotalMmap(unsigned __int64);
	void Die();
	void DisableCoreDumperIfNecessary();
	void DumpProcessMap();
	void GetMemoryProfile(void (*)(unsigned __int64,unsigned __int64,bool,unsigned __int64 *,unsigned __int64),unsigned __int64 *,unsigned __int64);
	void GetThreadStackAndTls(bool,unsigned __int64 *,unsigned __int64 *,unsigned __int64 *,unsigned __int64 *);
	void GetThreadStackTopAndBottom(bool,unsigned __int64 *,unsigned __int64 *);
	void InitTlsSize();
	void InitializeCommonFlags(__sanitizer::CommonFlags *);
	void InitializeCoverage(bool,char const *);
	void InitializeDbgHelpIfNeeded();
	void InitializePlatformEarly();
	void InstallDeadlySignalHandlers(void (*)(int,void *,void *));
	void InternalFree(void *,__sanitizer::SizeClassAllocator32LocalCache<__sanitizer::SizeClassAllocator32<__sanitizer::AP32> > *);
	void LogFullErrorReport(char const *);
	void MaybeReexec();
	void MaybeStartBackgroudThread();
	void ParseSymbolizeDataOutput(char const *,__sanitizer::DataInfo *);
	void ParseSymbolizePCOutput(char const *,__sanitizer::SymbolizedStack *);
	void PlatformPrepareForSandboxing(__sanitizer_sandbox_arguments *);
	void PrintCmdline();
	void PrintHintAllocatorCannotReturnNull();
	void PrintModuleMap();
	void Printf(char const *,...);
	void RawWrite(char const *);
	void RegisterCommonFlags(__sanitizer::FlagParser *,__sanitizer::CommonFlags *);
	void RegisterIncludeFlags(__sanitizer::FlagParser *,__sanitizer::CommonFlags *);
	void ReleaseMemoryPagesToOS(unsigned __int64,unsigned __int64);
	void RemoveANSIEscapeSequencesFromString(char *);
	void RenderData(__sanitizer::InternalScopedString *,char const *,__sanitizer::DataInfo const *,char const *);
	void RenderFrame(__sanitizer::InternalScopedString *,char const *,int,__sanitizer::AddressInfo const &,bool,char const *,char const *);
	void RenderModuleLocation(__sanitizer::InternalScopedString *,char const *,unsigned __int64,__sanitizer::ModuleArch,char const *);
	void RenderSourceLocation(__sanitizer::InternalScopedString *,char const *,int,int,bool,char const *);
	void Report(char const *,...);
	void ReportDeadlySignal(__sanitizer::SignalContext const &,unsigned int,void (*)(__sanitizer::SignalContext const &,void const *,__sanitizer::BufferedStackTrace *),void const *);
	void ReportErrorSummary(char const *,__sanitizer::AddressInfo const &,char const *);
	void ReportErrorSummary(char const *,__sanitizer::StackTrace const *,char const *);
	void ReportErrorSummary(char const *,char const *);
	void ReportMmapFailureAndDie(unsigned __int64,char const *,char const *,unsigned int,bool);
	void ReportUnrecognizedFlags();
	void RunFreeHooks(void const *);
	void RunMallocHooks(void const *,unsigned __int64);
	void SetAbortMessage(char const *);
	void SetAllocatorMayReturnNull(bool);
	void SetAllocatorOutOfMemory();
	void SetAlternateSignalStack();
	void SetCheckFailedCallback(void (*)(char const *,int,char const *,unsigned __int64,unsigned __int64));
	void SetErrnoToENOMEM();
	void SetLowLevelAllocateCallback(void (*)(unsigned __int64,unsigned __int64));
	void SetLowLevelAllocateMinAlignment(unsigned __int64);
	void SetPrintfAndReportCallback(void (*)(char const *));
	void SetSoftRssLimitExceededCallback(void (*)(bool));
	void SetUserDieCallback(void (*)());
	void SleepForSeconds(int);
	void Sort<unsigned __int64,CompareLess<unsigned __int64> >(unsigned __int64 *,unsigned __int64,__sanitizer::CompareLess<unsigned __int64>);
	void SubstituteForFlagValue(char const *,char *,unsigned __int64);
	void Swap<long (*)(_EXCEPTION_POINTERS *)>(long (*&)(_EXCEPTION_POINTERS *),long (*&)(_EXCEPTION_POINTERS *));
	void Swap<unsigned __int64>(unsigned __int64 &,unsigned __int64 &);
	void Trap();
	void UnmapOrDie(void *,unsigned __int64);
	void UnsetAlternateSignalStack();
	void UpdateProcessName();
	void internal__exit(int);
};

namespace __ubsan
{
	struct Diag
	{
		Diag & operator<<(Range const &);
		Diag & operator<<(TypeDescriptor const &);
		Diag & operator<<(TypeName);
		Diag & operator<<(Value const &);
		Diag & operator<<(char const *);
		Diag & operator<<(unsigned __int64);
		Diag & operator<<(void const *);
		~Diag();
	};

	struct Flags
	{
		void SetDefaults();
	};

	struct ScopedReport
	{
		struct Initializer
		{
			Initializer();
		};

		ScopedReport(ReportOptions,Location,ErrorType);
		~ScopedReport();
	};

	struct TypeDescriptor
	{
		unsigned int getIntegerBitWidth();
	};

	struct UndefinedBehaviorReport
	{
		UndefinedBehaviorReport(char const *,Location &,__sanitizer::InternalScopedString &);
	};

	struct Value
	{
		__int64 getSIntValue();
		long double getFloatValue();
		unsigned __int64 getPositiveIntValue();
		unsigned __int64 getUIntValue();
	};

	__sanitizer::SymbolizedStack * getSymbolizedLocation(unsigned __int64);
	__ubsan::DynamicTypeInfo getDynamicTypeInfoFromObject(void *);
	__ubsan::DynamicTypeInfo getDynamicTypeInfoFromVtable(void *);
	__ubsan::Flags ubsan_flags;
	bool IsPCSuppressed(__ubsan::ErrorType,unsigned __int64,char const *);
	bool IsVptrCheckSuppressed(char const *);
	bool checkDynamicType(void *,void *,unsigned __int64);
	bool checkTypeInfoEquality(void const *,void const *);
	bool ignoreReport(__ubsan::SourceLocation,__ubsan::ReportOptions,__ubsan::ErrorType);
	char const * * TypeCheckKinds;
	char const * GetSanititizerToolName();
	char const * MaybeCallUbsanDefaultOptions();
	char const * getObjCClassName(unsigned __int64);
	void InitAsPlugin();
	void InitAsStandalone();
	void InitAsStandaloneIfNecessary();
	void InitializeFlags();
	void InitializeSuppressions();
	void RegisterUbsanFlags(__sanitizer::FlagParser *,__ubsan::Flags *);
	void RegisterUndefinedBehaviorReport(__ubsan::UndefinedBehaviorReport *);
};

namespace __vcasan
{
	struct EXCEPTION_SANITIZER_ERROR
	{
		EXCEPTION_SANITIZER_ERROR(char const *,char const *);
		~EXCEPTION_SANITIZER_ERROR();
	};

	__vcasan::VSErrorReportingInit __asan_error_init_dummy;
	bool VcAsanStrdup(unsigned short * *,unsigned short const *);
	unsigned long GetAsanShortMessageFromDescription(char const *,unsigned short * *);
	unsigned short * g_wszVcAsanCaptureDumpEnvVar;
	unsigned short * g_wszVcAsanCustomDataEnvVar;
	unsigned short * g_wszVcAsanDebuggingEnvVar;
	unsigned short * g_wszVcAsanDefaultDumpName;
	void OnAsanReport(char const *,char const *,bool);
	void ReportCallback(char const *);
};

struct charNode
{
	virtual char * getString(char *,char *);
	virtual char getLastChar();
	virtual int length();
	virtual int raw_length();
};

struct pDNameNode
{
	virtual char * getString(char *,char *);
	virtual char getLastChar();
	virtual int length();
	virtual int raw_length();
};

struct pairNode
{
	virtual char * getString(char *,char *);
	virtual char getLastChar();
	virtual int length();
	virtual int raw_length();
};

struct pcharNode
{
	pcharNode<0>(char const *,int,StringLifeSelector<0>);
	pcharNode<2>(char const *,int,StringLifeSelector<2>);
	virtual char * getString(char *,char *);
	virtual char getLastChar();
	virtual int length();
	virtual int raw_length();
};

namespace std
{
	struct bad_exception
	{
		bad_exception();
		bad_exception(bad_exception const &);
		virtual ~bad_exception();
	};

	struct exception
	{
		exception(exception const &);
		virtual char const * what();
	};

};

AsanHeap * GetDefaultHeap();
AsanHeapMap * GetAsanHeapMap();
_EXCEPTION_DISPOSITION __InternalCxxFrameHandler<__FrameHandler4>(EHExceptionRecord *,unsigned __int64 *,_CONTEXT *,_xDISPATCHER_CONTEXT *,FH4::FuncInfo4 *,int,unsigned __int64 *,unsigned char);
__asan_InitDefine<4> init_delete_scalar;
__type_info_node __type_info_root_node;
int MemcmpInterceptorCommon(void *,int (*)(void const *,void const *,unsigned __int64),void const *,void const *,unsigned __int64);
int SharedUnlock(void *,int (*)(void *),__sanitizer::BufferedStackTrace &);
int TypeMatchHelper<__FrameHandler3>(_s_HandlerType const *,_s_CatchableType const *,_s_ThrowInfo const *);
int TypeMatchHelper<__FrameHandler4>(FH4::HandlerType4 *,_s_CatchableType const *,_s_ThrowInfo const *);
int _CallSETranslator<__FrameHandler4>(EHExceptionRecord *,unsigned __int64 *,_CONTEXT *,_xDISPATCHER_CONTEXT *,FH4::FuncInfo4 *,unsigned long,unsigned __int64 *,int);
int __acrt_mbs_to_wcs_cp<__crt_win32_buffer_internal_dynamic_resizing>(char const * const,__crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing> &,unsigned int);
unsigned __int64 __asan_GetCurrentPc();
unsigned __int64 __sancov_lowest_stack;
void * (* __WinRTOutOfMemoryExceptionCallback)();
void * SharedLock(void *,void * (*)(void *),__sanitizer::BufferedStackTrace &);
void * operator new(unsigned __int64,_HeapManager &,int);
void _CallMemberFunction0(void * const,void * const);
void _CallMemberFunction1(void * const,void * const,void * const);
void _CallMemberFunction2(void * const,void * const,void * const,int);
void __acrt_stdio_free_stream(__crt_stdio_stream);
void __empty_global_delete(void *,unsigned __int64);
void __global_delete(void *,unsigned __int64);
void ep(int);
void operator delete(void *);
void operator delete(void *,unsigned __int64);
void ubsan_GetStackTrace(__sanitizer::BufferedStackTrace *,unsigned __int64,unsigned __int64,unsigned __int64,void *,bool);
