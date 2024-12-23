//murong_sword.h Ľ�ݽ���

//coded by Fisho
//data: 2000-11-27

SKILL_BEGIN(CSmurong_sword);

virtual void create()
{
	set_name( "Ľ�ݽ���");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int force,dodge, damage ;
			char damage_type[5];
	}action[]={
		{"$Nһ�С���Ҷ������������$w������$n��$l", 80, -3, 200, "����",},
		{"$N������ǰ��һ�С���ͤ��һư����$n���ʺ���ȥ", 90, -5, 250, "����",},
		{"$Nʹ���������δ����������ĵ�����������˷�����$n��", 100, -10, 220, "����",},
		{"$Nһ�С����������ԡ�������$w������Ϣ��ͻ��ָ��$n��$l", 120, -5, 200, "����",},
	};
		
	int level = random(4);

	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
		
	return & m_actions;
}


virtual int valid_enable(string usage) 
{ 
	return usage=="sword" ||  usage=="parry"; 
}


virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 70)
		return notify_fail("�������������");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("�������������Ľ�ݽ�����");
	me->receive_damage("hp", 20);
	return 1;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp

/**************************************
//zhongping-qiang.c ��ƽǹ��

//#include "ansi.h"

inherit SKILL;

mapping *action = ({
([	"action": "$N˫��һ�𣬾���ǰ�죬ʹ��һ�С���ƽ�޵С�������$wƽƽֱ��������$n��$l",
	"force" : 100,
	"dodge": -3,
	"damage": 280,
	"skill_name" : "��ƽ�޵�",
	"damage_type": "����"
]),
([	"action": "$N����$w������ת���������������¶ף�����һ�С�ҹ��̽����������$n��$l��ȥ",
	"force" : 140,
	"dodge": -5,
	"damage": 250,
	"skill_name" : "ҹ��̽��",
	"damage_type": "����"
]),
([	"action": "$N����$w������һ��ǹ����һ�С����߳�������$n������ȥ",
	"force" : 180,
	"dodge": -10,
	"damage": 220,
	"skill_name" : "���߳���",
	"damage_type": "����"
]),
([	"action": "$Nһ�С�������ǹ��������$w����СȦ��ȥ$n�ĺ��У�����$w΢̧��ָ��$n��$l",
	"force" : 220,
	"dodge": -5,
	"damage": 200,
	"skill_name" : "������ǹ",
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="club" ||  usage=="parry"; }

mapping query_action(object me, CContainer * weapon)
{
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if (me->query("max_mp") < 70)
		return notify_fail("�������������");
	return 1;
}

int practice_skill(object me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
	||  DIFFERSTR(weapon->querystr("skill_type"), "club"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("���������������ƽǹ����");
	me->receive_damage("hp", 20);
	return 1;
}

*****************************/
