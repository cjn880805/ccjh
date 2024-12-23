// FightRoom.h: interface for the CFightRoom class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIGHTROOM_H__9A32FEA0_72B4_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_FIGHTROOM_H__9A32FEA0_72B4_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../server/Item.h"

#define		MAXFIGHTERS		16
#define		FIGHT_NO_FLEE	1
#define		FIGHT_NO_JOIN	2
#define		FIGHT_LOCKED	3
//战斗精灵

class CFightRoom : public CItem  
{
public:
	bool is_bishi();
	void Begin_Fight(int flag = 0, int hp_check = 50);
	virtual void create(int nFlag = 0);
	void SetFightLevel(int lv);
	int Can_Join(int team, CChar * me = NULL);
	virtual void GetInfo(char * str, CChar * me);
	virtual void OnLeave(CContainer * me);
	int Do_Flee(CChar * me);
	char * GetTeamMsg(char * msg, int team);
	CChar * Select_Member(int team);
	void Leave_Team(CChar * obj);
	virtual LONG Query(int nAttr);
	void End_Fight();
	virtual void heart_beat();
	int Join_Team(CChar * ob, int Team);		//Join_Team(me, FIGHT_TEAM_A);
	CFightRoom();
	virtual ~CFightRoom();

	enum{
		FIGHT_TEAM_A = 0,
		FIGHT_TEAM_B,
	};

	int			m_Fighters_Max;			//一队最多的参战人数
	LONG		m_Turn_AP;				//在此房间里，普通攻击消耗：AP/回合。
	int			m_Turn_WP;				//在此房间里，等待时间：-WP/心跳
	int			m_Level;				//允许加入战斗的玩家最高等级

	typedef CChar * DTENEMY; 
	struct
	{
		DTENEMY obj[MAXFIGHTERS];
		LONG	num;
		LONG	fighter_num;
	}m_Team[2];			//两队成员

protected:
	LONG Query_Turn_WP(CChar * me);
	LONG Query_Turn_AP(CChar * me);

	bool		m_bFight;				//是否比试
	int			m_hpCheck;				//比试结束标志：当其中一方hp低于的百分值。
	
	int			m_tick;
	int			m_stop;
};

#endif // !defined(AFX_FIGHTROOM_H__9A32FEA0_72B4_11D4_98AB_0050BABC5212__INCLUDED_)
