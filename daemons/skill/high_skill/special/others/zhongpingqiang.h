//zhongpingqiang.h 中平枪法

//coded by Fisho
//data: 2000-11-27

SKILL_BEGIN(CSZhongPingQiang);

virtual void create()
{
	set_name( "中平枪法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int force,dodge, damage ;
			char damage_type[5];
	}action[]={
		{"$N双手一别，尽力前伸，使出一招「中平无敌」，手中$w平平直出，刺向$n的$l", 100, -5, 250, "刺伤",},
		{"$N手中$w盘旋回转，风响阵阵，屈身下蹲，反手一招「夜叉探海」自下向$n的$l刺去", 140, -5, 220, "刺伤",},
		{"$N举起$w，抖出一朵枪花，一招「灵蛇出洞」向$n分心扎去", 180, -10, 200, "刺伤",},
		{"$N一招「反身拿枪」，手中$w划个小圈消去$n的后招，而后$w微抬，指向$n的$l", 220, -5, 180, "刺伤",},
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
	return usage=="club" ||  usage=="parry"; 
}


virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 70)
		return notify_fail("你的内力不够。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "club"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练中平枪法。");
	me->receive_damage("hp", 20);
	return 1;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp

/**************************************
//zhongping-qiang.c 中平枪法

//#include "ansi.h"

inherit SKILL;

mapping *action = ({
([	"action": "$N双手一别，尽力前伸，使出一招「中平无敌」，手中$w平平直出，刺向$n的$l",
	"force" : 100,
	"dodge": -3,
	"damage": 280,
	"skill_name" : "中平无敌",
	"damage_type": "刺伤"
]),
([	"action": "$N手中$w盘旋回转，风响阵阵，屈身下蹲，反手一招「夜叉探海」自下向$n的$l刺去",
	"force" : 140,
	"dodge": -5,
	"damage": 250,
	"skill_name" : "夜叉探海",
	"damage_type": "刺伤"
]),
([	"action": "$N举起$w，抖出一朵枪花，一招「灵蛇出洞」向$n分心扎去",
	"force" : 180,
	"dodge": -10,
	"damage": 220,
	"skill_name" : "灵蛇出洞",
	"damage_type": "刺伤"
]),
([	"action": "$N一招「反身拿枪」，手中$w划个小圈消去$n的后招，而后$w微抬，指向$n的$l",
	"force" : 220,
	"dodge": -5,
	"damage": 200,
	"skill_name" : "反身拿枪",
	"damage_type": "刺伤"
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
		return notify_fail("你的内力不够。");
	return 1;
}

int practice_skill(object me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
	||  DIFFERSTR(weapon->querystr("skill_type"), "club"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练中平枪法。");
	me->receive_damage("hp", 20);
	return 1;
}

*****************************/
