// Channel.h: interface for the CChannel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHANNEL_H__310C5FC2_D1B4_11D4_98AC_0050BABC5212__INCLUDED_)
#define AFX_CHANNEL_H__310C5FC2_D1B4_11D4_98AC_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Container.h"


class CUser;

class CChannel : public CContainer  
{
public:
	long query_score_bbs(const char * id);
	void filter_list(MAP2USER * list, CMapping * ch, const char * str, int party = 0);

	int family_listener(CUser * ppl, const char * str, int party = 0);
	int filter_listener(CUser * ppl, CMapping * ch);

	char * do_emote(CChar * me, CChar * target, const char * verb, int channel_emote, const char * who = NULL);
	int do_channel(CContainer * me, CChar * who, const char * arg1, const char * arg2);
	void DownLoadEmote(CUser * me);
	void create();
	CChannel();
	virtual ~CChannel();

public:
	int filter_ip(const char * ip);
	int check_channel_msg(CChar * me, const char * verb, const char * msg, const char * block_key);
	void ReleaseMe();
	void remove_snoop(CChar * me);
	void do_snooping(CChar * victim, char * msg);
	CChar * query_snooping(CChar * me);
	void snoop(CChar * me, CChar * victim = NULL);

	void update_friends(const char * master, const char * id, const char * name, int relative);
	CMapping * query_friends(const char * id);

	void update_relative(const char * me, const char * target, LONG pt, int flag = -1);
	CMapping * query_relative(const char * me, const char * target);

	void update_recruit(const char * master, const char * id, const char * name, LONG exp, int apprentice);
	CMapping * query_recruit(const char * id);

	void SaveFriends();
	void SaveRelative();
	void SaveRecruitExp();
	void register_relay_channel(const char * channel, CContainer * ob);

	//投票用
	CMapping voted_players;
	CMapping votes_casted;

	//黑名单
	CMapping banlist;

	//IP地址记录
	CMapping loginlist;

	//IP地址登陆控制
	CMapping loginlimit;

	//场景控制	

protected:
	CMapping	semote;
	CMapping	channels;

	typedef struct _snoop{
		CChar * listener;	//监听者
		CChar * victim;		//被监听者

	}snoop_t;

	CList <snoop_t *, snoop_t *> snoop_list;		//监听链表

	//收徒用
	CMapping recruit_exp;
	
	//江湖亲密度
	CMapping relative;	

	//好友名单
	CMapping friends;
};

#define MAX_ROOM_NUM	1475
extern char global_room_name[MAX_ROOM_NUM][40];
/*
#define MAX_WEAPON_NUM	78
#define MAX_FOOD_NUM	154
#define MAX_CLOTH_NUM	171
extern char global_weapon_name[MAX_WEAPON_NUM][40];
extern char global_cloth_name[MAX_CLOTH_NUM][40];
extern char global_food_name[MAX_FOOD_NUM][40];
*/
#endif // !defined(AFX_CHANNEL_H__310C5FC2_D1B4_11D4_98AC_0050BABC5212__INCLUDED_)
