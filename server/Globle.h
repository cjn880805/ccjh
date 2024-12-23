// Globle.h: interface for the CGloble class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLOBLE_H__66102AA1_6EF7_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_GLOBLE_H__66102AA1_6EF7_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../combat/MudConfig.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <string>
#include <map>

#ifndef _NTOS_
#include <stdarg.h>
#endif

using namespace std;

class CCmdHandle;
class CContainer;
class CItem;
class CNpc;
class CSkill;
class CCondition;
class Ccorps;
class CRoom;
class CUser;
class CChar;
class CChannel;
class CCombatd;
class CFightRoom;

//全局

//客户端接受指令
enum{
		GOTOROOM = 10,
		ADDOBJECT,
		REMOVEOBJECT,
		RTNSKILL,
		RTNITEM,
		RTNINFO,
		DOWNSKILL,			//下载技能
		DOWNOBJECT,			//下载物件
		LOGINUSER,			//登录
		NOTIFY,				//通知消息
		WAKEUP,				//唤醒
		DOWNEMOTE,			//下载表情
		COMMON_ATTACK,		//普通攻击
		//RTNSTATUS,			//战斗状态
		STATE,				//指定状态
		ADDDOOR,			//增加出口
		SENDUSER,			//发布用户信息
		VENDOR_LIST,		//商人货品清单
		QUESTION,			//问题
		DOWNMAGIC,			//下法术
		NOTIFY_FAIL,		//指令执行失败通知
		BULLET,				//公告版
		TELLOBJECT,			//私聊
		LOCATION,			//定位		1.7版本
		USERLIST,			//用户列表	1.71版本
		DOWNUSER,			//下载用户资料 1.72版本
		MAGICCAST,			//魔法效果
		SYN_AP,				//同步ＡＰ
		SENDTABLE,			//发送表信息
		CONTROLNPC,			//控制NPC标记
		ADDLOG,				//增加日志
};

//Equip Position 左右手区别角色的装备位置。手指武器可装备位置，可佩带在左右手上。
enum{
	WIELD_NONE = 0,
	WIELD_HEAD,			//头	头盔
	WIELD_LEFT_ERR,		//左耳
	WIELD_RIGHT_ERR,	//右耳
	WIELD_ERR,			//耳	魔法物
	WIELD_NECK,			//颈	项圈
	WIELD_LEFT_HAND,	//左手	盾牌，箭袋
	WIELD_RIGHT_HAND,	//右手	通常用来装备武器
	WIELD_HAND,			//手
	WIELD_LEFT_WRIST,	//左腕	手环可以戴在左右腕上。
	WIELD_RIGHT_WRIST,	//右腕
	WIELD_WRIST,		//腕
	WIELD_ARMOR,		//铠甲
	WIELD_WAIST,		//腰带
	WIELD_BOOT,			//靴子
	WIELD_MANTLE,		//斗篷
	WIELD_ARMOR_HANDS,	//手套
	WIELD_BOTH_HAND,	//双手
	WIELD_RING,			//指环
	WIELD_CLOTH,		//衣服
};

typedef map<string, CSkill *, less<string> > MAP2SKILL;
typedef MAP2SKILL::iterator iterator_skill;
typedef map<string, CCondition *, less<string> > MAP2CND;
typedef MAP2CND::iterator iterator_condition;
typedef map<string, CRoom *, less<string> > MAP2ROOM;
typedef MAP2ROOM::iterator iterator_room;
typedef map<LONG, CContainer *, less<LONG> > MAP2ITEM;
typedef MAP2ITEM::iterator iterator_item;
typedef map<LONG, CNpc *, less<LONG> > MAP2NPC;
typedef MAP2NPC::iterator iterator_npc;
typedef map<LONG, CUser *, less<LONG> > MAP2USER;
typedef MAP2USER::iterator iterator_user;

extern MAP2USER g_UserList;		//User List
extern CChannel g_Channel;		//Channel Object
extern CCombatd g_Combatd;		//Combatd Object
extern CCmdHandle g_CommandHandler;

extern LONG  g_LastDestructObject;		//上次被销毁的物件。

//Common Functions
MAP2USER * users();
LONG random(LONG nSeed);
double urandom(double nSeed);
void analyse_string(char * Comm, char * arg, int nLen);
char * GetValue(const char * pCmdStr, const char * pKeyWord, char * pValue, int nValueLen);
void replace_string(char * msg, const char * oldstr, const char * newstr, int nLen);
int CheckValidChar(char * arg);								//检查合法字符
void output_error(const char * fmt, ...);
CChar * FindMaster(CChar * me);
int wizardp(CChar *me);
int userp(CContainer * me);
int living(CContainer * me);
int wiz_level(CChar * me);

//Handle Objects Functions
CContainer * load_item(const char * base_name);
CNpc * load_npc(const char * base_name);
CRoom * load_room(const char * base_name);
CSkill * load_skill(const char * base_name);
CCondition * load_condition(const char * base_name);
CUser * add_user();

void destruct(CContainer * me);

CContainer * find_object(LONG nID, int nFlag = 0);
CContainer * find_item(LONG nID);
CNpc * find_npc(LONG nID);
CUser * find_player(LONG nID);
CUser * find_online(const char * id);

int Init_Game(const char * ipaddress, const char * name, const char * password);
void Exit_Game();
int OnLogin(int nSerial, int sockfd, char *arg);
void Message(const char * channel, const char * chat, MAP2USER * ulist, CContainer * me = NULL, CContainer * who = NULL);
void MessageVision(CContainer * me, const char * room, const char * chatmsg, CContainer * exclude = NULL, CContainer * exclude2 = NULL);
void message_vision(const char * msg, CContainer * me, CContainer * you = NULL);
void message_channel(const char * channel, const char * msg, CChar * me, CContainer * you = NULL);
void tell_object(CContainer * ob, const char * str, const char * channel = "system");
void tell_room(CContainer * ob, const char * str, CChar * exclude = NULL, const char * channel = "system");
int notify_fail(const char * fmt, ...);
char * chinese_number(signed long int i, char * msg);

void heart_beat();

//Addition Functions
char * GetIP(CChar * me);
CContainer * RandomGetItem(CContainer * me, int nType, CContainer * exclude = NULL);
char * DecodeStr(char * msg);

void OnSendOnline(CUser * me);

const char * query_rank(CChar * ob);
const char * query_respect(CChar * ob);
const char * query_rude(CChar * ob);
const char * query_self(CChar * ob);
const char * query_self_rude(CChar * ob);
const char * query_close(CChar * me, CChar * ob);
const char * query_self_close(CChar * me, CChar * ob);
const char * gender_self(string sex);
const char * gender_pronoun(string sex);

char * snprintf(char * buf, int len, const char * fmt, ...);
CFightRoom * Do_BiShi(CChar * me, CChar * victim, char * name, int check = 50);


extern int	current_time;			//当前时间
extern int	heart_beat_flag;		//心跳标志
extern int	boot_time;				//启动时间

extern	int	sys_server_id;			//服务器编号	1-999
extern	int	sys_server_port;		//服务器端口号  6600
extern	char sys_server_name[64];	//服务器名称
extern	int	sys_server_charge;			//服务器是否收费
extern	char sys_server_dbname[64];	//服务器数据库名称

void destruct_debug(CContainer * me, const char * function);

#define DESTRUCT_OB(ob, func)		destruct_debug(ob, func)

#endif // !defined(AFX_GLOBLE_H__66102AA1_6EF7_11D4_98AB_0050BABC5212__INCLUDED_)
