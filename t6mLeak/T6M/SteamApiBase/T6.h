#pragma once
extern void Auth_Error(const char* message);
typedef float tColor[4];
DWORD __stdcall ConsoleWindow(LPVOID lpThreadParameter);
typedef void(__cdecl * CommandCB_t)(void);
typedef struct cmd_function_s
{
	cmd_function_s* nextCmd;
	const char* name;
	char pad[8];
	CommandCB_t callback;
	DWORD pad2;
};
#define MAX_SIGNATURES 256
typedef struct signature_s
{
	unsigned char* signature;
	char* mask;
	size_t size;
	unsigned char* replace;
	int replaceOffset;
	size_t replaceSize;
	void(*replaceCB)(void* address);
	int logOffset;
} signature_t;
void ProcessSignature2(int id, signature_t* signature);
void ProcessSignature(const char* Sig, char* mask, int size, int logoffset, const char* Replace, int ReplaceOffset, int ReplaceSize);










typedef float vec3_t[3];
typedef float vec4_t[4];





struct DObjAnimMat
{
	float quat[4];
	float trans[3];
	float transWeight;
};
struct __declspec(align(16)) XSurface
{
	char unknownData1[0x10];
	char tileMode;
	char vertListCount;
	unsigned __int16 flags;
	unsigned __int16 vertCount;
	unsigned __int16 triCount;
	unsigned __int16 baseVertIndex;
	unsigned __int16 *triIndices;							//Loaded Last, size = ((triCount << 1) + triCount) << 1
	//XSurfaceVertexInfo vertInfo;
	//unknownXModelStruct1Internal2 unkInternal2;		//if flags & 1 then use option2 else use verts0
	//D3DVertexBuffer vertexBuffer;
	//union
	//{
	//	XRigidVertList *vertList;
	//	XRigidVertList *vertListEA;
	//};
	//D3DIndexBuffer indexBuffer;
	//int partBits[5];
};
struct ScriptString
{
};
struct XModel
{
	const char *name;
	char numBones;
	char numRootBones;
	char numsurfs;
	char lodRampType;
	union
	{
		ScriptString * boneNames;
		ScriptString * localBoneNames;
	};
	union
	{
		char * parentList;  //size = numBones - numRootBones
		char * localParentList;  //size = numBones - numRootBones
	};
	union
	{
		unsigned short * quats;		//size = (numBones - numRootBones) << 3
		unsigned short * localQuats;	//size = (numBones - numRootBones) << 3
	};
	union
	{
		float * trans;							//size = (numBones - numRootBones) << 4
		float * localTrans;							//size = (numBones - numRootBones) << 4
	};
	char *partClassification;		//size = numBones
	DObjAnimMat *baseMat;					//size = numBones << 5
	XSurface *surfs;	//count = numsurfs
};


struct WeaponDef
{
	const char *szOverlayName;
	XModel *gunXModel;//**
	XModel *handXModel;
	const char *szModeName;
};
struct WeaponVariantDef
{
	char* name;
	int iVariantCount;
	WeaponDef *weapDef;
	const char *szDisplayName;
	const char *szAltWeaponName;
	const char *szAttachmentUnique;
	//.....
};






struct D3DBaseTexture
{
	void* a1;
	char pad[0x30];
	//char pad[0x34];
};
struct GfxImage
{
	D3DBaseTexture basemap;//size = 0x34    52
	char mapType;//							53
	char unknown3;//						54
	char unknown4;//						55
	char unknown5;//						56
	int size;//								60
	unsigned __int16 width;//				62
	unsigned __int16 height;//				64
	unsigned __int16 depth;//				66
	char levelCount;//						67
	char streaming;//						68
	unsigned int baseSize;//				72
	char *pixels;//							76 (pointer = 4 else char itself = 2)
	char unknownData2[0x7C];//				200
	char streamedPartCount;//				201
	const char *name;//						205
	unsigned int hash;//					209
};
//palceholder
struct D3DPixelShader
{

};
struct D3DVertexShader
{

};




#pragma region MaterialTechniqueSet
#define MAX_TECHNIQUES 36
struct MaterialArgumentCodeConst
{
	unsigned __int16 index;
	char firstRow;
	char rowCount;
};
union MaterialArgumentDef
{
	const float *literalConst;
	MaterialArgumentCodeConst codeConst;
	unsigned int codeSampler;
	unsigned int nameHash;
};
/* MaterialShaderArgument->type */
#define MTL_ARG_MATERIAL_VERTEX_CONST	0x0
#define MTL_ARG_LITERAL_VERTEX_CONST	0x1
#define MTL_ARG_MATERIAL_PIXEL_SAMPLER	0x2
#define  MTL_ARG_CODE_PRIM_BEGIN	0x3
#define MTL_ARG_CODE_VERTEX_CONST	0x3
#define MTL_ARG_CODE_PIXEL_SAMPLER	0x4
#define MTL_ARG_CODE_PIXEL_CONST	0x5
#define MTL_ARG_MATERIAL_PIXEL_CONST	0x6
#define  MTL_ARG_CODE_PRIM_END		0x6
#define MTL_ARG_LITERAL_PIXEL_CONST	0x7
#define MLT_ARG_COUNT			0x8

struct MaterialShaderArgument
{
	unsigned __int16 type;
	unsigned __int16 dest;
	MaterialArgumentDef u;
};
struct MaterialStreamRouting
{
	char source;
	char dest;
};
struct MaterialVertexStreamRouting
{
	MaterialStreamRouting data[16];
};
struct MaterialVertexDeclaration
{
	char streamCount;
	bool hasOptionalSource;
	MaterialVertexStreamRouting routing;
};
struct GfxVertexShaderLoadDef
{
	char *cachedPart;
	char *physicalPart;
	unsigned __int16 cachedPartSize;
	unsigned __int16 physicalPartSize;
};
struct MaterialVertexShaderProgram
{
	D3DVertexShader *vs;
	GfxVertexShaderLoadDef loadDef;
};
struct MaterialVertexShader
{
	const char *name;
	MaterialVertexShaderProgram prog;
};
struct GfxPixelShaderLoadDef
{
	char *cachedPart;
	char *physicalPart;
	unsigned __int16 cachedPartSize;
	unsigned __int16 physicalPartSize;
};
union MaterialPixelShaderProgram
{
	D3DPixelShader *ps;
	GfxPixelShaderLoadDef loadDef;
};
struct MaterialPixelShader
{
	const char *name;
	MaterialPixelShaderProgram prog;
};
#pragma pack(push, 4)
struct MaterialPass
{
	MaterialVertexDeclaration *vertexDecl;
	MaterialVertexShader *vertexShader;
	union
	{
		MaterialPixelShader *pixelShader;
		MaterialPixelShader *localPixelShader;
	};
	char perPrimArgCount;
	char perObjArgCount;
	char stableArgCount;
	char customSamplerFlags;
	char precompiledIndex;
	char materialType;  //It is unknown wether this is used/exists on Xbox or PS3.
	union
	{
		MaterialShaderArgument *args;
		MaterialShaderArgument *localArgs;
	};
};
#pragma pack(pop)
struct MaterialTechnique
{
	const char *name;
	unsigned __int16 flags;
	unsigned __int16 passCount;
	MaterialPass passArray;
};
enum MaterialWorldVertexFormat : char
{
	MTL_WORLDVERT_TEX_1_NRM_1 = 0x0,
	MTL_WORLDVERT_TEX_2_NRM_1 = 0x1,
	MTL_WORLDVERT_TEX_2_NRM_2 = 0x2,
	MTL_WORLDVERT_TEX_3_NRM_1 = 0x3,
	MTL_WORLDVERT_TEX_3_NRM_2 = 0x4,
	MTL_WORLDVERT_TEX_3_NRM_3 = 0x5,
	MTL_WORLDVERT_TEX_4_NRM_1 = 0x6,
	MTL_WORLDVERT_TEX_4_NRM_2 = 0x7,
	MTL_WORLDVERT_TEX_4_NRM_3 = 0x8,
	MTL_WORLDVERT_TEX_5_NRM_1 = 0x9,
	MTL_WORLDVERT_TEX_5_NRM_2 = 0xA,
	MTL_WORLDVERT_TEX_5_NRM_3 = 0xB,
};
struct MaterialTechniqueSet
{
	const char *name;
	MaterialWorldVertexFormat worldVertFormat;
	MaterialTechnique *techniques[MAX_TECHNIQUES];
};
#pragma endregion
#pragma region Material
struct MaterialConstantDef
{
	unsigned int nameHash;
	char name[12];
	vec4_t literal;
};
struct GfxStateBits
{
	unsigned int loadBits[2];
};
struct WaterWritable
{
	float floatTime;
};
struct water_t
{
	WaterWritable writable;
	float *H0X;		// Count = M * N
	float *H0Y;		// Count = M * N
	float *wTerm;		// Count = M * N
	int M;
	int N;
	float Lx;
	float Lz;
	float gravity;
	float windvel;
	float winddir[2];
	float amplitude;
	float codeConstant[4];
	GfxImage *image;
};

/* MaterialTextureDef->semantic */
#define TS_2D		0x0
#define TS_FUNCTION	0x1
#define TS_COLOR_MAP	0x2
#define TS_UNUSED_1	0x3
#define TS_UNUSED_2	0x4
#define TS_NORMAL_MAP	0x5
#define TS_UNUSED_3	0x6
#define TS_UNUSED_4	0x7
#define TS_SPECULAR_MAP	0x8
#define TS_UNUSED_5	0x9
#define TS_UNUSED_6	0xA
#define TS_WATER_MAP	0xB
union MaterialTextureDefInfo
{
	GfxImage *image;	// MaterialTextureDef->semantic != TS_WATER_MAP
	water_t *water;		// MaterialTextureDef->semantic == TS_WATER_MAP
};
struct MaterialTextureDef
{
	unsigned int nameHash;
	char nameStart;
	char nameEnd;
	char samplerState;
	char semantic;
	char isMatureContent;
	GfxImage *image;
};
union GFxDrawSurfFields
{
	unsigned long long unused,
		primarySortKey,
		surfType,
		primaryLightIndex,
		prepass,
		materialSortedIndex,
		customIndex,
		reflectionProbeIndex,
		objectId;
};
union GfxDrawSurf
{
	GFxDrawSurfFields fields;
	unsigned long long packed;
};
struct MaterialInfo
{
	const char *name;
	unsigned int gameFlags;
	char pad;
	char sortKey;
	char textureAtlasRowCount;
	char textureAtlasColumnCount;
	GfxDrawSurf drawSurf;
	unsigned int surfaceTypeBits;
	unsigned int layeredSurfaceTypes;
	unsigned __int16 hashIndex;
	int surfaceFlags;
	int contents;
};
struct Material
{
	MaterialInfo info;
	char stateBitsEntry[MAX_TECHNIQUES];	// see MaterialTechniqueType
	char textureCount;
	char constantCount;
	char stateBitsCount;
	char stateFlags;
	char cameraRegion;
	char probeMipBits;
	MaterialTechniqueSet *techniqueSet;
	MaterialTextureDef *textureTable;
	MaterialConstantDef *constantTable;
	GfxStateBits *stateBitTable;
	Material *thermalMaterial;
};
#pragma endregion
#pragma region Font
#pragma pack(push, 2)
struct Glyph
{
	unsigned __int16 letter;
	char x0;
	char y0;
	char dx;
	char pixelWidth;
	char pixelHeight;
	float s0;
	float t0;
	float s1;
	float t1;
};
#pragma pack(pop)
struct KerningPairs
{
	unsigned __int16 wFirst;
	unsigned __int16 wSecond;
	int iKernAmount;
};
struct Font_s
{
	const char *fontName;
	int pixelHeight;
	int isScalingAllowed;
	int glyphCount;
	int kerningPairsCount;

	char pad[8];
	//Material *material;
	//Material *glowMaterial;

	Glyph *glyphs;
	KerningPairs *kerningPairs;
};
#pragma endregion
struct LocalizeEntry
{
	const char *value;
	const char *name;
};












enum XAssetType
{
	ASSET_TYPE_XMODELPIECES = 0x0,
	ASSET_TYPE_PHYSPRESET = 0x1,
	ASSET_TYPE_PHYSCONSTRAINTS = 0x2,
	ASSET_TYPE_DESTRUCTIBLEDEF = 0x3,
	ASSET_TYPE_XANIMPARTS = 0x4,
	ASSET_TYPE_XMODEL = 0x5,
	ASSET_TYPE_MATERIAL = 0x6,
	ASSET_TYPE_TECHNIQUE_SET = 0x7,
	ASSET_TYPE_IMAGE = 0x8,
	ASSET_TYPE_SOUND = 0x9,
	ASSET_TYPE_SOUND_PATCH = 0xA,
	ASSET_TYPE_CLIPMAP = 0xB,
	ASSET_TYPE_CLIPMAP_PVS = 0xC,
	ASSET_TYPE_COMWORLD = 0xD,
	ASSET_TYPE_GAMEWORLD_SP = 0xE,
	ASSET_TYPE_GAMEWORLD_MP = 0xF,
	ASSET_TYPE_MAP_ENTS = 0x10,
	ASSET_TYPE_GFXWORLD = 0x11,
	ASSET_TYPE_LIGHT_DEF = 0x12,
	ASSET_TYPE_UI_MAP = 0x13,
	ASSET_TYPE_FONT = 0x14,
	ASSET_TYPE_FONTICON = 0x15,
	ASSET_TYPE_MENULIST = 0x16,
	ASSET_TYPE_MENU = 0x17,
	ASSET_TYPE_LOCALIZE_ENTRY = 0x18,
	ASSET_TYPE_WEAPON = 0x19,
	ASSET_TYPE_WEAPONDEF = 0x1A,
	ASSET_TYPE_WEAPON_VARIANT = 0x1B,
	ASSET_TYPE_WEAPON_FULL = 0x1C,
	ASSET_TYPE_ATTACHMENT = 0x1D,
	ASSET_TYPE_ATTACHMENT_UNIQUE = 0x1E,
	ASSET_TYPE_WEAPON_CAMO = 0x1F,
	ASSET_TYPE_SNDDRIVER_GLOBALS = 0x20,
	ASSET_TYPE_FX = 0x21,
	ASSET_TYPE_IMPACT_FX = 0x22,
	ASSET_TYPE_AITYPE = 0x23,
	ASSET_TYPE_MPTYPE = 0x24,
	ASSET_TYPE_MPBODY = 0x25,
	ASSET_TYPE_MPHEAD = 0x26,
	ASSET_TYPE_CHARACTER = 0x27,
	ASSET_TYPE_XMODELALIAS = 0x28,
	ASSET_TYPE_RAWFILE = 0x29,
	ASSET_TYPE_STRINGTABLE = 0x2A,
	ASSET_TYPE_LEADERBOARD = 0x2B,
	ASSET_TYPE_XGLOBALS = 0x2C,
	ASSET_TYPE_DDL = 0x2D,
	ASSET_TYPE_GLASSES = 0x2E,
	ASSET_TYPE_EMBLEMSET = 0x2F,
	ASSET_TYPE_SCRIPTPARSETREE = 0x30,
	ASSET_TYPE_KEYVALUEPAIRS = 0x31,
	ASSET_TYPE_VEHICLEDEF = 0x32,
	ASSET_TYPE_MEMORYBLOCK = 0x33,
	ASSET_TYPE_ADDON_MAP_ENTS = 0x34,
	ASSET_TYPE_TRACER = 0x35,
	ASSET_TYPE_SKINNEDVERTS = 0x36,
	ASSET_TYPE_QDB = 0x37,
	ASSET_TYPE_SLUG = 0x38,
	ASSET_TYPE_FOOTSTEP_TABLE = 0x39,
	ASSET_TYPE_FOOTSTEPFX_TABLE = 0x3A,
	ASSET_TYPE_ZBARRIER = 0x3B,
	ASSET_TYPE_COUNT = 0x3C,
	ASSET_TYPE_STRING = 0x3C,
	ASSET_TYPE_ASSETLIST = 0x3D,
	ASSET_TYPE_REPORT = 0x3E,
	ASSET_TYPE_DEPEND = 0x3F,
	ASSET_TYPE_FULL_COUNT = 0x40,
	ASSET_TYPE_INVALID = -1,
};
struct RawFile
{
	const char *Name;
	int Length;
	const char *Buffer;
};
typedef struct _gscFunction
{
	DWORD crc32;							// 0x00 - CRC32 of function bytecode
	DWORD start;							// 0x04 - A relative pointer to the GSC bytecode start of this function
	WORD name;                              // 0x08 - A relative pointer to the name of this function
	BYTE numOfParameters;					// 0x0A -
	BYTE flag;                              // 0x0B -
	/*
	Possible flag values (not sure if all of them):

	- If flag & 1, function loaded (I think?)
	*/
} gscFunction;
typedef struct _COD9_GSC
{
	BYTE identifier[8];                     // 0x00 - It's the same always
	BYTE unknown1[4];                       // 0x08 - I think it's some kind of checksum
	DWORD includeStructs;					// 0x0C - A relative pointer to an array of includeStruct structs, amount = numOfIncludes
	DWORD usinganimtreeStructs;				// 0x10 - A relative pointer to an array of usinganimtreeStruct structs, amount = numOfUsinganimtree
	DWORD codeSectionStart;					// 0x14 - A relative pointer to where the GSC bytecode starts (gscFunctions)
	DWORD gscStrings;                       // 0x18 - A relative pointer to an array of gscString structs, amount = numOfStrings
	DWORD gscFunctions;                     // 0x1C - A relative pointer to an array of gscFunction structs, amount = numOfFunctions
	DWORD externalFunctions;				// 0x20 - A relative pointer to an array of externalFunction structs, amount = numOfExternalFunctions
	DWORD gscRelocations;					// 0x24 - A relative pointer to an array of gscRelocation structs, amount = numOfRelocations
	DWORD size;                             // 0x28 -
	DWORD codeSectionSize;					// 0x2C - Size of the executable bytecode
	WORD name;                              // 0x30 - A relative pointer to the name of this gsc (with full path and extension, null terminated)
	WORD numOfStrings;                      // 0x32 - IMPORTANT: Includes everything except #include strings, #using_animtree strings and function name strings
	WORD numOfFunctions;					// 0x34 - Number of functions in this script file
	WORD numOfExternalFunctions;			// 0x36 - Number of functions imported
	WORD numOfRelocations;					// 0x38 - Number of patches in the GSC code/file
	BYTE unknown4[2];                       // 0x3A - ?
	BYTE numOfIncludes;                     // 0x3C - Number of included source files
	BYTE numOfUsinganimtree;				// 0x3D - Number of included animation trees
	BYTE _padding[2];                       // 0x3E - Struct padding
} COD9_GSC;
struct ScriptParseTree
{
	const char *name;
	int len;
	BYTE *buffer;
};









/* dvar->flags */
#define DVAR_ARCHIVE		(1 << 0)	// 0x0001
#define DVAR_USERINFO		(1 << 1)	// 0x0002
#define DVAR_SERVERINFO		(1 << 2)	// 0x0004
#define DVAR_SYSTEMINFO		(1 << 3)	// 0x0008
#define DVAR_INIT		(1 << 4)	// 0x0010
#define DVAR_LATCH		(1 << 5)	// 0x0020
#define DVAR_ROM		(1 << 6)	// 0x0040
#define DVAR_CHEAT		(1 << 7)	// 0x0080
#define DVAR_DEVELOPER		(1 << 8)	// 0x0100
#define DVAR_SAVED		(1 << 9)	// 0x0200
#define DVAR_NORESTART		(1 << 10)	// 0x0400
#define DVAR_CHANGEABLE_RESET	(1 << 12)	// 0x1000
#define DVAR_EXTERNAL		(1 << 14)	// 0x4000
#define DVAR_AUTOEXEC		(1 << 15)	// 0x8000

enum dvarType_t
{
	DVAR_TYPE_INVALID = 0x0,
	DVAR_TYPE_BOOL = 0x1,
	DVAR_TYPE_FLOAT = 0x2,
	DVAR_TYPE_FLOAT_2 = 0x3,
	DVAR_TYPE_FLOAT_3 = 0x4,
	DVAR_TYPE_FLOAT_4 = 0x5,
	DVAR_TYPE_INT = 0x6,
	DVAR_TYPE_ENUM = 0x7,
	DVAR_TYPE_STRING = 0x8,
	DVAR_TYPE_COLOR = 0x9,
	DVAR_TYPE_INT64 = 0xA,
	DVAR_TYPE_LINEAR_COLOR_RGB = 0xB,
	DVAR_TYPE_COLOR_XYZ = 0xC,
	DVAR_TYPE_COUNT = 0xD,
};
union DvarLimits
{
	struct {
		int stringCount;
		const char **strings;
	} enumeration;

	struct {
		int min;
		int max;
	} integer;

	struct {
		float min;
		float max;
	} value, vector;

	struct {
		__int64 min;
		__int64 max;
	} integer64;
};
union DvarValue
{
	bool enabled;
	int integer;
	unsigned int unsignedInt;
	__int64 integer64;
	unsigned __int64 unsignedInt64;
	float value;
	vec4_t vector;
	const char *string;
	char color[4];
};
#pragma pack(push, 4)
struct dvar_t
{
	const char *name;
	const char *description;
	int hash;
	unsigned int flags;
	dvarType_t type;
	bool modified;
	DvarValue current;
	DvarValue latched;
	DvarValue reset;
	DvarLimits domain;
	dvar_t *hashNext;
	int unknown3;
};
#pragma pack(pop)






enum errorParm_t
{
	ERR_FATAL = 0x0,
	ERR_DROP = 0x1,
	ERR_FROM_STARTUP = 0x2,
	ERR_SERVERDISCONNECT = 0x3,
	ERR_DISCONNECT = 0x4,
	ERR_SCRIPT = 0x5,
	ERR_SCRIPT_DROP = 0x6,
	ERR_LOCALIZATION = 0x7,
};
enum fsMode_t
{
	FS_READ = 0x0,
	FS_WRITE = 0x1,
	FS_APPEND = 0x2,
	FS_APPEND_SYNC = 0x3,
};
enum FsListBehavior_e
{
	FS_LIST_PURE_ONLY = 0x0,
	FS_LIST_ALL = 0x1,
};
enum scriptInstance_t
{
	SCRIPTINSTANCE_SERVER = 0x0,
	SCRIPTINSTANCE_CLIENT = 0x1,
	SCRIPT_INSTANCE_MAX = 0x2,
};








union XAssetHeader
{
	// 	XModelPieces *xmodelPieces;
	// 	PhysPreset *physPreset;
	// 	PhysConstraints *physConstraints;
	// 	DestructibleDef *destructibleDef;
	// 	XAnimParts *parts;
	 	XModel *model;
	 	Material *material;
	// 	MaterialPixelShader *pixelShader;
	// 	MaterialVertexShader *vertexShader;
	// 	MaterialTechniqueSet *techniqueSet;
	 	GfxImage *image;
	// 	SndBank *sound;
	// 	SndPatch *soundPatch;
	// 	clipMap_t *clipMap;
	// 	ComWorld *comWorld;
	// 	GameWorldSp *gameWorldSp;
	// 	GameWorldMp *gameWorldMp;
	// 	MapEnts *mapEnts;
	// 	GfxWorld *gfxWorld;
	// 	GfxLightDef *lightDef;
	 	Font_s *font;
	// 	FontIcon *fontIcon;
	// 	MenuList *menuList;
	// 	menuDef_t *menu;
	 	LocalizeEntry *localize;
	 	WeaponVariantDef *weapon;
	// 	WeaponAttachment *attachment;
	// 	WeaponAttachmentUnique *attachmentUnique;
	// 	WeaponCamo *weaponCamo;
	// 	SndDriverGlobals *sndDriverGlobals;
	// 	FxEffectDef *fx;
	// 	FxImpactTable *impactFx;
		RawFile *rawfile;
	// 	StringTable *stringTable;
	// 	LeaderboardDef *leaderboardDef;
	// 	XGlobals *xGlobals;
	// 	ddlRoot_t *ddlRoot;
	// 	Glasses *glasses;
	// 	//TextureList *textureList;
	// 	void *textureList;
	// 	EmblemSet *emblemSet;
	// 	ScriptParseTree *scriptParseTree;
	// 	KeyValuePairs *keyValuePairs;
	// 	VehicleDef *vehicleDef;
	// 	MemoryBlock *memoryBlock;
	// 	AddonMapEnts *addonMapEnts;
	// 	TracerDef *tracerDef;
	// 	SkinnedVertsDef *skinnedVertsDef;
	// 	Qdb *qdb;
	// 	Slug *slug;
	// 	FootstepTableDef *footstepTableDef;
	// 	FootstepFXTableDef *footstepFXTableDef;
	// 	ZBarrierDef *zbarrierDef;
	void *data;
};






struct entityState_s
{
	int number;
};
struct g_entity_s
{
	entityState_s s;
	char pad[0x16A];
};







enum LocalClientNum_t
{
	INVALID_LOCAL_CLIENT = 0xFFFFFFFF,
	LOCAL_CLIENT_FIRST = 0x0,
	LOCAL_CLIENT_0 = 0x0,
	ONLY_LOCAL_CLIENT = 0x0,
	LOCAL_CLIENT_COUNT = 0x1,
};
typedef struct HudElem
{
	float x;
	float y;
	float z;
	float fontScale;
	float fromFontScale;
	int fontScaleStartTime;
	char color[4];
	char fromColor[4];
	int fadeStartTime;
	int scaleStartTime;
	float fromX;
	float fromY;
	int moveStartTime;
	int time;
	int duration;
	int value;
	float sort;
	char glowColor[4];
	int fxBirthTime;
	int flags;
	short targetEntNum;
	short fontScaleTime;
	short fadeTime;
	short label;
	short width;
	short height;
	short fromWidth;
	short fromHeight;
	short scaleTime;
	short moveTime;
	short text;
	short fxLetterTime;
	short fxDecayStartTime;
	short fxDecayDuration;
	short fxRedactDecayStartTime;
	short fxRedactDecayDuration;
	char type;
	char font;
	char alignOrg;
	char alignScreen;
	char materialIndex;
	char offscreenMaterialIdx;
	char fromAlignOrg;
	char fromAlignScreen;
	char soundID;
	char ui3dWindow;
	short flag2;
	int playerInd;
	int team;
	int abilityFlag;
};
enum HudElemAlign
{
	TOP_LEFT_COMPASS,
	TOP_LEFT,
	TOP_RIGHT,
	TOP_CENTER,

	CENTER_LEFT,
	CENTER_RIGHT,
	CENTER_CENTER,

	BOTTOM_LEFT,
	BOTTOM_RIGHT,
	BOTTOM_CENTER
};