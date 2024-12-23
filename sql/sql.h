BOOL Select_Game_Database();	//选择游戏数据库
BOOL InitSQLServer(const char * ipaddress, const char * name, const char * password);
BOOL  Restore_Data();
BOOL VerifyUser(const char * userid, char * passwd);
void DisconnectSQLServer();

BOOL InitChargeServer(const char * ipaddress, const char * name, const char * password);
void DisconnectChargeServer();
double Game_Count();
double Charge_Card(CChar * me, const char * cardno, double resume);
double Verify_Card(const char * cardno, const char * password, int & month);

void OnUserOut(CUser * me);
double Valid_Enter_Game(CUser * me, const char * cardno, const char * password);
int	paihangbang(CContainer * me);