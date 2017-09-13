class dw_match
{
public:
	static PMSID sid;
	static void register_match_session(bdByteBuffer& data);
	static void update_match_session(bdByteBuffer& data);
	static void find_match_session_fromid(bdByteBuffer& data);
	static void find_match_sessions(bdByteBuffer& data);
	static void inviteto_match_session(bdByteBuffer& data);
	static void submit_performance(bdByteBuffer& data);
	static void get_performance_values(bdByteBuffer& data);
	static void find_match_session_paged(bdByteBuffer& data);
	static void find_match_sessions_byentityIDs(bdByteBuffer& data);
	static void update_match_session_players(bdByteBuffer& data);
	static void delete_match_session(bdByteBuffer& data);
	static void match_packet_received(int type, const char* buf, int len);
};