// Globle.cpp: implementation of the CGloble class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "Globle.h"
#include "CmdHandle.h"
#include "Npc.h"
#include "Skill.h"
#include "Condition.h"
#include "Room.h"
#include "User.h"
#include "Item.h"
#include "Channel.h"
#include "../combat/Combatd.h"
#include "../std/FightRoom.h"
#include "CodeChange.h"

//---------------------------------------------------------
#ifdef _NTOS_
#include <process.h>
#include "io.h"
#else
#include <signal.h>
#include <unistd.h>
#include "dirent.h"
#endif

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#ifdef _SQL_
#include "../sql/sql.h"
#endif

#define HEARTBEAT_INTERVAL 2000000

#ifndef HAS_UALARM
#define SYSV_HEARTBEAT_INTERVAL  ((HEARTBEAT_INTERVAL+999999)/1000000)
#endif

CCmdHandle g_CommandHandler;

CChannel	g_Channel;		//Channel Object
CCombatd	g_Combatd;		//Combat Object

FILE * g_DebugFile;
BOOL	g_bReboot = FALSE;

int current_time;			//当前时间
int heart_beat_flag = 1;	//心跳标志
int	boot_time;				//启动时间

int	sys_server_id = 1;			//服务器编号	1-999
int	sys_server_port = 6600;		//服务器端口号  6600
char sys_server_name[64] = "阳光大陆";	//服务器名称
int	sys_server_charge = 0;			//是否收费
char sys_server_dbname[64] = "mud";	//服务器名称

MAP2SKILL g_SkillList;		//Skill List
MAP2CND   g_ConditionList;	//Condition List
MAP2ROOM g_RoomList;		//Room List
MAP2ITEM g_ItemList;		//Item List
MAP2NPC	g_NPCList;			//NPC List
MAP2USER g_UserList;		//User List

//-----------------------------------------------------------------
// 1.73 版本：修改心跳链表 改为映射。
typedef map<LONG, CContainer *, less<LONG> > MAP2HEARTBEAT;
MAP2HEARTBEAT g_HeartBeat;		//心跳链表
//-----------------------------------------------------------------

int g_CurrentAccount = 0;
LONG  g_LastDestructObject;		//上次被销毁的物件。

void Reload_Emote();

static void look_for_objects_to_swap()
{
	static int next_time = boot_time;

	if (current_time < next_time)
		return;		

	next_time = current_time + 900;

	iterator_room pos;
	
	output_error("reset room %ld>>", g_RoomList.size());
	for(pos = g_RoomList.begin(); pos != g_RoomList.end(); pos++)
	{
		( pos->second )->reset();
	}		
	output_error(">>");
}


#ifdef WIN32
void CDECL alarm_loop(void * ignore)
{
    while (1) 
	{
		Sleep(1000);
		heart_beat_flag = 1;
    }
}				/* alarm_loop() */

#else
// SIGALRM handler. 
void sigalrm_handler(int sig)
{
    heart_beat_flag = 1;
}	

#endif

void call_heart_beat()
{
#ifdef WIN32

	heart_beat_flag = 0;
    static long Win32Thread = -1;

	if (Win32Thread == -1) Win32Thread = _beginthread(
		(void (__cdecl *)(void *))
		alarm_loop, 256, 0);

#else

	//signal(SIGALRM, sigalrm_handler);
	//ualarm(HEARTBEAT_INTERVAL, 0);
    //alarm(SYSV_HEARTBEAT_INTERVAL);	/* defined in config.h */

#endif

	current_time = time(NULL);

	CContainer * obj;
	MAP2HEARTBEAT::iterator p, prep;
	
    for(p = g_HeartBeat.begin(); p != g_HeartBeat.end();)
	{
//		if(heart_beat_flag) break;

		prep = p; p++;

		obj = prep->second;

		if(obj)	
			obj->heart_beat();
		else	//删除该结点
			g_HeartBeat.erase(prep);
	}

	look_for_objects_to_swap();
	
 //   call_out();
}				

void User_Command_Loop()
{
	MAP2USER * list = users();
	iterator_user p;
	CUser * obj;

	for( p = list->begin(); p != list->end(); )
	{
		obj = p->second;
		p++;

		obj->HandleCommand();
	}
}

MAP2USER * users()
{
	return & g_UserList;
}

void DrawMap()
{
	iterator_room p;
	FILE * fp;
	fp = fopen("map.txt", "wt");
	
	for(p = g_RoomList.begin(); p != g_RoomList.end(); p++)
		fprintf(fp, "\"%s\",\n", p->first.c_str());

	fclose(fp);		
}

void DumpObject()
{
	output_error("物件清单：%ld个", g_ItemList.size());

	MAP2ITEM::iterator p;
	
	for(p = g_ItemList.begin(); p != g_ItemList.end(); p++)
	{
		CContainer * obj = p->second;
		char env[80];

		if(! obj->environment()) strcpy(env, "(NULL)");
		else strcpy(env, (obj->environment())->name(1));
		output_error("%s(%ld)位于%s", obj->name(1), p->first, env);
	}

	output_error("NPC清单：%ld个", g_NPCList.size());

	MAP2NPC::iterator p2;
	
	for(p2 = g_NPCList.begin(); p2 != g_NPCList.end(); p2++)
	{
		CNpc * npc = p2->second;
		char env[80];

		if(! npc->environment()) strcpy(env, "(NULL)");
		else strcpy(env, (npc->environment())->name(1));
		output_error("%s(%ld)位于%s", npc->name(1), p2->first, env);
	}
}

void output_error(const char * fmt, ...)
{
	int b = 0, p = 0;
	char c;
	char s[8192];
	char buf[512];
	va_list		ap;

	va_start(ap, fmt);
	
	while((c = fmt[p++]))
	{
		if(c == '%')
		{
			int i = 0;
			c = fmt[p++];
			switch(c)
			{
			case 'l':
				p++;
			case 'd':
				sprintf(s, "%ld", va_arg( ap, long));
				break;
			case 's':
				sprintf(s, "%s", va_arg(ap, char * ));
				break;
			}
			while(s[i])
			{
				buf[b++] = s[i++];
				if(b == 511) break;
			}
		}
		else
			buf[b++] = c;

		if(b == 511) break;
	}
	buf[b] = 0;

	va_end(ap);

	//日志改为按日期文件分类 lanwood 2001-09-10

	FILE * fp;
	time_t t;
	char ti[80];
	struct tm * newtime;

	time(&t);
	newtime = localtime( &t ); 
	
	sprintf(ti, "log/%02d-%02d.txt", newtime->tm_mon + 1, newtime->tm_mday);
	if((fp = fopen(ti, "at")))
	{	        
		snprintf(ti, 80, "%d:%d:%d", newtime->tm_hour, newtime->tm_min, newtime->tm_sec);
		
		fprintf(fp, "(%s)%s\n", ti, buf);
		fclose(fp);
	}
}

#ifdef _NTOS_
#include "../include/LstSock.h"

BOOL InitSQLServer()
{
	return TRUE;
}

void DisconnectSQLServer()
{
}

int CheckLogin(const char * id, char * passwd);
BOOL VerifyUser(const char * userid, char * passwd)
{
	return CheckLogin(userid, passwd);
}

void CloseClient(int nSerial)
{
	if(g_Listen)
		g_Listen->CloseSocket(nSerial);
}

void OpenClient(int sockfd, LONG user)
{
	if(g_Listen)
		g_Listen->SetClient(sockfd, user);
}

//int SendToClient(LONG sock, char * msg)
int SendToClient(int nObjectid, int nSerial, const char * msg)
{
	if(! g_Listen) return 0;
	return g_Listen->SentToClient(nSerial, msg);
}

int SendToClientDirect(int sockfd, int nSerial, const char * msg)
{
	if(! g_Listen) return 0;
	return g_Listen->SentToClient(nSerial, msg);
}

#else

#include "../datastruct.h"
#include "../genconfig.h"

extern TClientInfo ClientInfo[NUM_CLIENT];
extern fd_set rset,wset;

#ifndef _SQL_

int CheckLogin(const char * id, char * passwd);
BOOL VerifyUser(const char * userid, char * passwd)
{
	return CheckLogin(userid, passwd);
}

#endif

void CloseClient(int nSerial)
{
	//if(nSerial < 0) return;
	if(ClientInfo[nSerial].sockfd <= 0)return;
	FD_CLR(ClientInfo[nSerial].sockfd, &rset);
	FD_CLR(ClientInfo[nSerial].sockfd, &wset);
	close(ClientInfo[nSerial].sockfd);
	ClientInfo[nSerial].sockfd = -1;
	if(ClientInfo[nSerial].sendmsg)
	{
		free(ClientInfo[nSerial].sendmsg);
		ClientInfo[nSerial].sendmsg = NULL;
	}
	ClientInfo[nSerial].bLogin = false;
	ClientInfo[nSerial].szIPaddress[0] = 0;
	ClientInfo[nSerial].szBuf[0] = 0;
	ClientInfo[nSerial].nBufferPtr = 0;
	ClientInfo[nSerial].lObjectID = -1;
	return;
}

void OpenClient(int nID, LONG user)
{
}

int SendToClient(int nObjectid, int nSerial, const char * msg)
{
//	if(nSerial < 0) return 1;
//	if(nObjectid && ClientInfo[nSerial].lObjectID != nObjectid) return 1;
	if(ClientInfo[nSerial].sockfd <= 0)return 1;
	int nmsglen;
	char * tmpmsg;

	nmsglen = strlen(msg) + 1;
	if(ClientInfo[nSerial].sendmsg)
		nmsglen += strlen(ClientInfo[nSerial].sendmsg);
	tmpmsg = (char *)calloc(sizeof(char),nmsglen);
	if(!tmpmsg)return 1;
	if(ClientInfo[nSerial].sendmsg)
	{
		memcpy(tmpmsg, ClientInfo[nSerial].sendmsg, strlen(ClientInfo[nSerial].sendmsg)+1);
		memcpy(tmpmsg + strlen(ClientInfo[nSerial].sendmsg), msg, strlen(msg));
		free(ClientInfo[nSerial].sendmsg);
		ClientInfo[nSerial].sendmsg = NULL;
	}
	else
	{
		//ClientInfo[nSerial].sendline为NULL
		memcpy(tmpmsg, msg, nmsglen);
	}
	ClientInfo[nSerial].sendmsg = tmpmsg;


/*
sendagain:
	int n;
	fd_set wset;
	int nReady;
	FD_ZERO(&wset);
	FD_SET(ClientInfo[nnSerial].sockfd, &wset);
	nReady = select(ClientInfo[nnSerial].sockfd+1, NULL, &wset, NULL, NULL);
	if(nReady < 0)
	{
		if(errno == EINTR)
			goto sendagain;
		FD_CLR(ClientInfo[nnSerial].sockfd, &rset);
		close(ClientInfo[nnSerial].sockfd);
		ClientInfo[nnSerial].bLogin = false;
		ClientInfo[nnSerial].sockfd = -1;
		output_error("select error in SendToClient()!");
		return 1;
	}
	if(FD_ISSET(ClientInfo[nnSerial].sockfd, &wset))
	{
		if( (n = send(ClientInfo[nnSerial].sockfd, (const char*)&m_SendToUserMsg, sizeof(m_SendToUserMsg),0)) <= 0)
		//if( (n = writen(ClientInfo[nnSerial].sockfd, (const char*)&m_SendToUserMsg, sizeof(m_SendToUserMsg))) != sizeof(m_SendToUserMsg))
		{
			FD_CLR(ClientInfo[nnSerial].sockfd, &rset);
			close(ClientInfo[nnSerial].sockfd);
			ClientInfo[nnSerial].bLogin = false;
			ClientInfo[nnSerial].sockfd = -1;
			output_error("write error in SendToClient()!");
			return 1;
		}
	}
*/
	return 1;
}

int SendToClientDirect(int sockfd, int nSerial, const char * msg)
{
	write(sockfd,msg,strlen(msg));
	return 1;
}

#endif

void Init_Room_Mapping();

int Init_Game(const char * ipaddress, const char * name, const char * password)	//初始化游戏
{
/*
#ifndef WIN32	//加密版本! 先将目录下的日志文件改名为密码 程序启动后会自动改文件名为日志.

	time_t ct;
	time(&ct);
	while(1)
	{
		time_t t;
		time(&t);
		if(ct != t)
		{
			FILE * tp = fopen("ccjhwwdz", "rb");
			if(tp)
			{				
				fclose(tp);
				rename("ccjhwwdz", "lastlog.txt");
				break;
			}
			
			ct = t;
			fprintf(stderr, "%s", "out!");
		}
	}
#endif
*/
	//读入配置文件
	FILE * fp = fopen("data/config.txt", "rt");
	if(fp)
	{
		fscanf(fp, "%d", &sys_server_port);
		fscanf(fp, "%s", sys_server_name);
		fscanf(fp, "%d", &sys_server_id);
		fscanf(fp, "%d", &sys_server_charge);
		fscanf(fp, "%s", sys_server_dbname);
		fclose(fp);
	}		
	
	//激活随机函数
	srand( (unsigned)time( NULL ) );

	current_time = boot_time = time(NULL);

	//增加内码转换
	init_code();

#ifdef _NTOS_
	struct _finddata_t c_file;
    long hFile;

    /* Find first .c file in current directory */
    if( (hFile = _findfirst( "data/user/*.o", &c_file )) == -1L )
       return 0;
  
	do{
		int n = atol(c_file.name);
		if(n > g_CurrentAccount) g_CurrentAccount = n;
       
	} while( _findnext( hFile, &c_file ) == 0 );

    _findclose( hFile );
#else

#ifdef _SQL_
	if(! InitSQLServer(ipaddress, name, password))
		return 0;
	if(! InitChargeServer(ipaddress, name, password))
		return 0;
#else
	DIR * pDirent;
	struct dirent * dir;

	if(! (pDirent = opendir("data/user")) )
	{
		output_error("打开目录错误！");
		return 0;
	}

	while( (dir = readdir(pDirent)) )
	{
		int n = atol(dir->d_name);
		if(n > g_CurrentAccount) g_CurrentAccount = n;	
	}

	closedir(pDirent);
#endif
#endif
	//建立房间区域映射
	Init_Room_Mapping();

	//载入emote.o
	g_Channel.create();

//	LoadDataBase();

	return 1;
}

void Heart_Beat_Release();
void Item_Release();
void User_Release();
void NPC_Release();
void Room_Release();
void Skill_Release();
void Condition_Release();

void Exit_Game()		//结束游戏
{
	Heart_Beat_Release();
	User_Release();
	NPC_Release();
	Item_Release();
	Room_Release();
	Skill_Release();
	Condition_Release();

#ifdef _NTOS_
	//关闭通讯
	if(g_Listen)
		g_Listen->Close();
#endif
}

void DisConnectDatabase()
{
#ifdef _SQL_
	DisconnectSQLServer();
	DisconnectChargeServer();
#endif
}

void Set_Heart_Beat(CContainer * obj, int nFlag)
{
	MAP2HEARTBEAT::iterator p;
	LONG id = obj->object_id();
	p = g_HeartBeat.find(id);

	if(nFlag)	//加入心跳
	{
		if( p != g_HeartBeat.end())	 return;

		//增加心跳结点
		g_HeartBeat[id] = obj;
	}
	else
	{
		if(p == g_HeartBeat.end()) return;
		p->second = 0;		//并不真正销毁		
	}
}

void Heart_Beat_Release()
{
//	g_HeartBeat.clear();
}

void Remove_User(LONG nID);
void Remove_NPC(LONG nID);
void Remove_Item(LONG nID);
void Remove_Room(string room_name);

void destruct_debug(CContainer * me, const char * function)
{
	if(! me) return;

	//char env[40] = "(NULL)";
	//if(me->environment()) strncpy(env, (me->environment())->name(), 30)[30] = 0;
	//output_error("DESTRUCT: #OBJ=%ld, NAME=%s, ENV=%s FUN=%s\n", me->object_id(), me->name(), env, function);

	destruct(me);
}

//毁灭某物品
void destruct(CContainer * me)
{
	if(! me) return;	//add by lanwood 2001-02-28
	
	me->set_heart_beat(0);			//停止心跳
	me->move(NULL);
	me->Clean_Up();

	g_LastDestructObject = me->object_id();

	if( me->Query(CUser::IS_USER) )	//IF USER Remove it from User list
	{
		Remove_User(g_LastDestructObject);
		g_Channel.remove_snoop((CChar *)me); //从监听链表中删除		
		g_Channel.loginlist.add(GetIP((CChar *)me), -1); //从地址列表中删除
		((CUser *)me)->SetOnlineFlag(0);	//设置成0
	}
	else if( me->Query(CNpc::IS_NPC) )	//是NPC，Remove from NPC list
	{
		Remove_NPC(g_LastDestructObject);
	}
	else if( me->Query(CChar::IS_ROOM))	//是房间，从房间链表中删除
	{
		Remove_Room(me->querystr("base_name"));
	}
	else 
	{
		Remove_Item(g_LastDestructObject);
	}

	me->destructed();
	delete me;	
}

//在系统中搜寻某物品 nFlag = 1, Search for charactor, nFlag = 0, Search all objects
CContainer * find_object(LONG nID, int nFlag)
{
	CContainer * it = 0;

	it = find_npc(nID);
	if(!it) it = find_player(nID);
	if(! nFlag) if(!it) it = find_item(nID);

	return it;
}

CContainer * find_item(LONG nID)
{
	iterator_item p;
	p = g_ItemList.find(nID);
	if( p == g_ItemList.end() )
		return 0;

	return p->second;
}

CContainer * Create_Item(string base_name);
CContainer * load_item(const char * base_name)
{
	CContainer * t;

	t = Create_Item(base_name);
	if(! t)
	{
		output_error("物件%s创建失败！", base_name);
		return 0;
	}

	t->set("base_name", base_name);
	t->create();
	t->setup();
	g_ItemList[t->object_id()] = t;

	//---------------------DEBUG-------------------------
//	output_error("create(ITEM):#OBJ=%ld, NAME=%s", t->object_id(), t->name());
	//----------------------------------------------------

	return t;
}

void Item_Release()
{
	iterator_item p;
	CContainer * item;
	
	for( p = g_ItemList.begin(); p != g_ItemList.end(); p++)
	{
		item = p->second;
		item->set_heart_beat(0);
		item->move(NULL);
		item->Clean_Up();		
		delete item;
	}
	
	g_ItemList.clear();
}

//从链表中删除
void Remove_Item(LONG nItem)
{
	g_ItemList.erase(nItem);
}

//随机NPC，为万劫的任务增加
CNpc * random_npc()
{
	MAP2NPC::iterator p2;
	int i = 0;

	int index = random(g_NPCList.size());
	
	for(p2 = g_NPCList.begin(); p2 != g_NPCList.end(); p2++)
	{
		CNpc * npc = p2->second;
		if(i == index) return npc;	
		i++;
	}

	return 0;
}

CNpc * find_npc(LONG nID)
{
	iterator_npc p;

	p = g_NPCList.find(nID);
	if( p == g_NPCList.end())
		return 0;
	return p->second;
}

void NPC_Release()
{
	iterator_npc p;
	CNpc * npc;

	for(p = g_NPCList.begin(); p != g_NPCList.end(); )
	{
		npc = p->second;
		LONG npcid = p->first;

		p++;
		
		npc->set_heart_beat(0);
		npc->move(NULL);

		if(g_LastDestructObject == npcid)	//已经在move中销毁
			continue;

		npc->Clean_Up();
		delete npc;
	}	

	g_NPCList.clear();
}

//从链表中删除
void Remove_NPC(LONG nID)
{
	g_NPCList.erase(nID);
}

CNpc * Create_NPC(string base_name);
CNpc * load_npc(const char * base_name)
{
	CNpc * npc = NULL;

	npc = Create_NPC(base_name);
	
	npc->set("base_name", base_name);	
	//-------创建时，NPC无负重，将无法执行装入物品程式。因此先将其设置为set("infinity", 1);---
	npc->set("infinity", 1);
	npc->create();
	npc->setup();
	npc->del("infinity");

	g_NPCList[npc->object_id()] = npc;

	//---------------------DEBUG-------------------------
//	output_error("create(NPC):#OBJ=%ld, NAME=%s", npc->object_id(), npc->name());
	//----------------------------------------------------
	return npc;
}

LONG random(LONG nSeed)
{
	if(nSeed <= 0)
	{
//		output_error("随机函数除零错误！");
		return 0;
	}
	static double fRandMax = (double)RAND_MAX + 1.0;

	double f;
	f = (double) rand() / fRandMax; 
	f *= nSeed;
	return (LONG)f;
}

double urandom(double nSeed)
{
	if(nSeed <= 0)
	{
//		output_error("随机函数除零错误！");
		return 0;
	}
	static double fRandMax = (double)RAND_MAX + 1.0;

	double f;
	f = (double) rand() / fRandMax; 
	f *= nSeed;
	return f;
}

CSkill * Create_Skill(string skill_name);

CSkill * load_skill(const char * base_name)
{
	iterator_skill p;
	p = g_SkillList.find(base_name);
	if( p == g_SkillList.end() )
	{
		CSkill * sk = Create_Skill(base_name);
		if(! sk) return 0;
		sk->set("base_name", base_name);
		sk->create();
		g_SkillList[base_name] = sk;
		return sk;
	}
	
	return p->second;
}

CCondition * Create_Condition(string base_name);

CCondition * load_condition(const char * base_name)
{
	iterator_condition p;
	p = g_ConditionList.find(base_name);
	if( p == g_ConditionList.end() )
	{
		CCondition * cnd = Create_Condition(base_name);
		if(! cnd) return 0;
		cnd->set("base_name", base_name);
		g_ConditionList[base_name] = cnd;
		return cnd;
	}
	
	return p->second;
}


void Skill_Release()
{
	iterator_skill p;
	for(p = g_SkillList.begin(); p != g_SkillList.end(); p++)
		delete p->second;

	g_SkillList.clear();
}

void Condition_Release()
{
	iterator_condition p;
	for(p = g_ConditionList.begin(); p != g_ConditionList.end(); p++)
		delete p->second;

	g_ConditionList.clear();
}

void Room_Release()
{
	iterator_room p;
	for(p = g_RoomList.begin(); p != g_RoomList.end(); p++)
	{
		(p->second)->set_heart_beat(0);
		delete p->second;
	}

	g_RoomList.clear();
}

CRoom * Create_Room(string base_name);

//从链表中删除
void Remove_Room(string room_name)
{
	g_RoomList.erase(room_name);
}

//载入房间
CRoom * load_room(const char * base_name)
{
	iterator_room p;
	
	p = g_RoomList.find(base_name);
	if( p == g_RoomList.end())
	{
		CRoom * r;
		r = Create_Room(base_name);
	
		g_RoomList[base_name] = r;
		r->set("base_name", base_name);
		r->create();
		r->setup();
		return r;
	}
	
	return p->second;
}

//返回区域内房间

CUser * find_player(LONG nID)
{
	iterator_user p;

	p = g_UserList.find(nID);
	if( p == g_UserList.end())
		return 0;

	return p->second;
}

void DropAll(CChar * me);

void User_Release()
{
	iterator_user p;
	CUser * user;

	for(p = g_UserList.begin(); p != g_UserList.end(); p++)
	{
		user = p->second;
		
		DropAll(user);
		user->SaveToServer();			//给存盘
		user->SetOnlineFlag(0);	//设置成0

		user->Offline();
		user->set_heart_beat(0);
		user->move(NULL);
		user->Clean_Up();
	}

	for(p = g_UserList.begin(); p != g_UserList.end(); p++)
	{	
		user = p->second;
		delete user;
	}

	g_UserList.clear();
}

//从链表中删除
void Remove_User(LONG nID)
{
	g_UserList.erase(nID);
}

//增加一位玩家
CUser * add_user()
{
	CUser * t = new CUser();
	if(t) g_UserList[t->object_id()] = t;
	return t;
}

//随机取物品栏某物
CContainer * RandomGetItem(CContainer * me, int nType, CContainer * exclude)
{
	DTItemList * t;
	POSITION p;
	typedef CContainer * PCONTAINER;
	PCONTAINER obj, item[50];
	int num = 0;
	
	if(! me) return 0;

	t = me->Get_ItemList();
	p = t->GetHeadPosition();
	while(p)
	{
		obj = t->GetNext(p);
		if(! obj->Query(nType)) continue;
		if(obj == exclude) continue;
		item[num++] = obj;
		if(num==50) break;		//不许越界
	}
	if(num)	return item[random(num)];

	return 0;
}

int living(CContainer * me)
{
	return me->Query(CChar::IS_LIVING);
}

int wiz_level(CChar * me)
{
	return me->query("grant");
}

CFightRoom * Do_BiShi(CChar * me, CChar * victim, char * name, int check)
{
	CFightRoom * room = (CFightRoom *)load_item("fight_room");			//载入战斗精灵
	room->set_name(name);
	room->set_temp("map/ex", me->query_temp("map/ex"));
	room->set_temp("map/ey", me->query_temp("map/ey"));

	room->move(me->environment());

	me->move(room);
	room->Join_Team(me, CFightRoom::FIGHT_TEAM_A);		//加入战队

	victim->move(room);
	room->Join_Team(victim, CFightRoom::FIGHT_TEAM_B);

	room->Begin_Fight(1, check);	//比试
	return room;
}
//-------------------------------------------------------------------------------------
void analyse_string(char * Comm, char * arg, int nLen)	//分析指令
{	
	register int p=0, a=0;

	while(Comm[p] && Comm[p] != ' ')
		p++;
	
	if(Comm[p]==' ')
	{
		Comm[p] = 0;	//将命令分离
		p++;

		while(Comm[p] && a < nLen - 1)
		{
			arg[a++]=Comm[p++];			
		}
	}
	
	arg[a] = 0;
}

char * GetValue(const char * pCmdStr, const char * pKeyWord, char * pValue, int nValueLen)
{
	char szKeyWord[80];
	char * pKey;
	int nCopyLen;

	pValue[0] = 0;

	snprintf(szKeyWord, 80, "&%s=", pKeyWord); 
	pKey = strstr(pCmdStr, szKeyWord);

	if( ! pKey)	return pValue;

	pKey += strlen(szKeyWord);

	nCopyLen = strchr( pKey, '&') - pKey;

	if( nCopyLen <= 0 ) return pValue;
		
	if( nCopyLen > nValueLen - 1 )	nCopyLen = nValueLen - 1;

	strncpy(pValue, pKey, nCopyLen )[nCopyLen] = 0; 

	return pValue;
}

char * snprintf(char * buf, int len, const char * fmt, ...)
{
	int b = 0, p = 0;
	char c;
	char s[8192];
	va_list		ap;

	va_start(ap, fmt);
	
	while((c = fmt[p++]))
	{
		if(c == '%')
		{
			int i = 0;
			c = fmt[p++];
			switch(c)
			{
			case 'l':
				p++;
			case 'd':
				sprintf(s, "%ld", va_arg( ap, long));
				break;
			case 's':
				const char * chPtr = va_arg(ap, char * );
				if(chPtr)
					sprintf(s, "%s", chPtr);
				break;
			}
			while(s[i])
			{
				buf[b++] = s[i++];
				if(b >= len - 1) break;
			}
		}
		else
			buf[b++] = c;

		if(b >= len - 1) break;
	}
	buf[b] = 0;

	va_end(ap);

	if(c) 
	{
 		//Debug
		output_error("字符串越界: fmt=%s;buf=%s\n", fmt, buf);
	}

	return buf;
}

//复制一份链表
void CopyList(DTItemList * dest, DTItemList * src)
{
	POSITION p;
	CContainer * obj;

	p = src->GetHeadPosition();
	while(p)
	{
		obj = src->GetNext(p);
		dest->AddTail(obj);
	}
}

//译码
char * DecodeStr(char * msg)
{
	int p = 0, t = 0;
	const char * decode = "\15L\26A\18N\12W\25O\33O\6D";

	int len = strlen(decode); 
	while(msg[p])
	{
		if(msg[p] != ' '&& msg[p]!='\n' && msg[p] !='\t') 
		{
			msg[p] ^= decode[t];
			if(msg[p] == '\t')	//不能采用\t
				msg[p] = '\t' ^ decode[t];
			if(msg[p] == '\n')	//不能采用\n
				msg[p] = '\n' ^ decode[t];
			if(msg[p] == ' ')	//不能采用\n
				msg[p] = ' ' ^ decode[t];
			if(msg[p] == 0)
				msg[p] = 0 ^ decode[t];
		}
				
		p++; t++;
		if(t >= len) t = 0;
	}
	return msg;
}

int valid_string(const char * msg)
{
	register int p = 0;
	//检查字符串里不能有引号
	while(msg[p])
	{
		if( msg[p] == '\"')
			return notify_fail("不能含有引号!");
		p++;
	}

	return 1;
}