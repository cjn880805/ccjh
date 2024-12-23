// Combatd.h	//ս��ģ��
//
//////////////////////////////////////////////////////////////////////

#if !defined(_COMBATD_H)
#define _COMBATD_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../server/Container.h"

class CChar;

class CCombatd : public CContainer  
{
public:
	unsigned long Skill_Power(CChar * ob, const char * skill, int usage);
	void Announce(CChar * me, char * event);
	void bash_weapon(CChar * me, CChar * victim, CContainer * weapon, LONG damage);
	void throw_weapon(CChar * me, CChar * victim, CContainer * weapon, LONG damage);
	void Do_Attack(CChar * me, CChar * victim, int flag);
	int Victim_Lose(CChar * killer, CChar * victim);
	void Victim_Penalty(CChar * victim);
	int NK_Gain(CChar * killer, CChar * victim);
	void PK_reward(CChar * killer, CChar * victim);
	void Killer_Reward(CChar * killer, CChar * victim);
	void fight(CChar * me, CChar * victim);
	
	static void start_berserk(CContainer * ob, LONG target, LONG param2);
	static void start_hatred(CContainer * ob, LONG target, LONG param2);
	static void start_vendetta(CContainer * ob, LONG target, LONG param2);
	static void start_aggressive(CContainer * ob, LONG target, LONG param2);

	void auto_fight(CChar * me, CChar * obj, string type);
	const char * damage_msg(int damage, string type);
	const char * eff_status_msg(int ratio);

	CCombatd();
	virtual ~CCombatd(){};


public:
	static void Reward_Money(CChar * me, LONG money);
	static void Reward_Level_Exp(CChar * me, int level);
	//ATTACK
	enum{
		TYPE_QUICK = 0,					//��������������������
		TYPE_REGULAR,					//��ͨ������������
		TYPE_RIPOSTE,					//������
		TYPE_NORMAL,					//�Ӵ���������
		TYPE_REMOTE,					//Զ�̹���
		TYPE_MAGIC,						//ħ������
	};

protected:
	CMapping	room_decode;

};

#endif //
