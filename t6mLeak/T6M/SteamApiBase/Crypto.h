class dw_Crypto
{
public:
	static BYTE globalKey[24];
	static bool cryptoInited;
	static void dw_init_crypto();
	static void dw_calculate_iv(unsigned int seed, BYTE* iv);
	static void dw_get_global_key(BYTE* key);
	static void dw_set_global_key(const BYTE* key);
	static void dw_decrypt_data(const char* ctext, BYTE* iv, BYTE* key, char* ptext, int len);
	static void __cdecl dw_encrypt_data(const char* ptext, BYTE* iv, BYTE* key, char* ctext, int len);
};