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

//ȫ��

//�ͻ��˽���ָ��
enum{
		GOTOROOM = 10,
		ADDOBJECT,
		REMOVEOBJECT,
		RTNSKILL,
		RTNITEM,
		RTNINFO,
		DOWNSKILL,			//���ؼ���
		DOWNOBJECT,			//�������
		LOGINUSER,			//��¼
		NOTIFY,				//֪ͨ��Ϣ
		WAKEUP,				//����
		DOWNEMOTE,			//���ر���
		COMMON_ATTACK,		//��ͨ����
		//RTNSTATUS,			//ս��״̬
		STATE,				//ָ��״̬
		ADDDOOR,			//���ӳ���
		SENDUSER,			//�����û���Ϣ
		VENDOR_LIST,		//���˻�Ʒ�嵥
		QUESTION,			//����
		DOWNMAGIC,			//�·���
		NOTIFY_FAIL,		//ָ��ִ��ʧ��֪ͨ
		BULLET,				//�����
		TELLOBJECT,			//˽��
		LOCATION,			//��λ		1.7�汾
		USERLIST,			//�û��б�	1.71�汾
		DOWNUSER,			//�����û����� 1.72�汾
		MAGICCAST,			//ħ��Ч��
		SYN_AP,				//ͬ������
		SENDTABLE,			//���ͱ���Ϣ
		CONTROLNPC,			//����NPC���
		ADDLOG,				//������־
};

//Equip Position �����������ɫ��װ��λ�á���ָ������װ��λ�ã���������������ϡ�
enum{
	WIELD_NONE = 0,
	WIELD_HEAD,			//ͷ	ͷ��
	WIELD_LEFT_ERR,		//���
	WIELD_RIGHT_ERR,	//�Ҷ�
	WIELD_ERR,			//��	ħ����
	WIELD_NECK,			//��	��Ȧ
	WIELD_LEFT_HAND,	//����	���ƣ�����
	WIELD_RIGHT_HAND,	//����	ͨ������װ������
	WIELD_HAND,			//��
	WIELD_LEFT_WRIST,	//����	�ֻ����Դ����������ϡ�
	WIELD_RIGHT_WRIST,	//����
	WIELD_WRIST,		//��
	WIELD_ARMOR,		//����
	WIELD_WAIST,		//����
	WIELD_BOOT,			//ѥ��
	WIELD_MANTLE,		//����
	WIELD_ARMOR_HANDS,	//����
	WIELD_BOTH_HAND,	//˫��
	WIELD_RING,			//ָ��
	WIELD_CLOTH,		//�·�
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

extern LONG  g_LastDestructObject;		//�ϴα����ٵ������

//Common Functions
MAP2USER * users();
LONG random(LONG nSeed);
double urandom(double nSeed);
void analyse_string(char * Comm, char * arg, int nLen);
char * GetValue(const char * pCmdStr, const char * pKeyWord, char * pValue, int nValueLen);
void replace_string(char * msg, const char * oldstr, const char * newstr, int nLen);
int CheckValidChar(char * arg);								//���Ϸ��ַ�
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


extern int	current_time;			//��ǰʱ��
extern int	heart_beat_flag;		//������־
extern int	boot_time;				//����ʱ��

extern	int	sys_server_id;			//���������	1-999
extern	int	sys_server_port;		//�������˿ں�  6600
extern	char sys_server_name[64];	//����������
extern	int	sys_server_charge;			//�������Ƿ��շ�
extern	char sys_server_dbname[64];	//���������ݿ�����

void destruct_debug(CContainer * me, const char * function);

#define DESTRUCT_OB(ob, func)		destruct_debug(ob, func)

#endif // !defined(AFX_GLOBLE_H__66102AA1_6EF7_11D4_98AB_0050BABC5212__INCLUDED_)
