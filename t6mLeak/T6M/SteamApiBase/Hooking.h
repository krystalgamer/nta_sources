#define QCALL(a, v, AddCall) Hook::Quick::Call((void*)(a), (uint32_t)(v), (AddCall))
#define QPATCH_JUMP Hook::Quick::CallPatch::PATCH_JUMP
#define QPATCH_CALL Hook::Quick::CallPatch::PATCH_CALL
#define QNOP(a, v) Hook::Quick::NOP((void*)(a), (v))
#define QMOV(a, v) *(BYTE*)a = 0xB8; *(DWORD*)(a + 1) = v;


class Hook
{
public:
	class Stomp
	{
	public:
		uint8_t _OriginalCode[5];
		uint8_t _ByteCount;
		uint8_t *_Place;
		void *_Hook;
		bool _Jump;

		void Initialize(uintptr_t Place, void *HookToInstall = NULL, uint8_t ByteCount = 5, bool useJump = true);
		void InstallHook(void *HookToInstall = NULL);
		void ReleaseHook();
		static void PermanentHook(uintptr_t Place, void *HookToInstall);
	};
	class IAT
	{
	public:
		static size_t GetIATAddress(const char* ModuleName, const char* FunctionName, uint64_t ImgBase);
		static size_t WriteIATAddress(const char* ModuleName, const char* FunctionName, uint64_t ImgBase, void *NewProc);
	};
	class Quick
	{
	public:
		enum class CallPatch
		{
			PATCH_CALL,
			PATCH_JUMP,
			PATCH_NOTHING
		};
		static void Patch(void *Address, uint64_t Data, uint32_t ByteCount);
		static void NOP(void *Address, uint32_t Length);
		static void Call(void *Address, uint32_t Data, CallPatch PatchType);
	};
	class Call
	{
	public:
		uint8_t _OriginalCode[5];
		uint8_t *_Place;
		void *_Original;
		void *_Hook;

		void Initialize(uint32_t Place, void *HookToInstall = NULL);
		void InstallHook(void *HookToInstall = NULL);
		void ReleaseHook();
		static void PermanentHook(uint32_t Place, void *HookToInstall);
	};
};
