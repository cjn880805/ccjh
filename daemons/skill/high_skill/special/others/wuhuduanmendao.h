//wuhuduanmendao.h 五虎断门刀

//coded by Fisho
//data: 2000-11-1

SKILL_BEGIN(CSWuHuDuanMenDao);

virtual void create()
{
	set_name( "五虎断门刀");
}

virtual CMapping * query_action(CChar *me)
{
	struct{
			char action[100];
			int force,dodge, parry ,damage;
			char damage_type[5];
	}action[11]={
		{"$N手中$w斜指，一招「直来直去」，反身一顿，一刀向$n的$l撩去",120 ,-10 , 5, 15, "割伤",},
		{"$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部", 130, -10, 10, 20, "割伤",},
		{"$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n", 140, -5, 5, 25, "割伤",},
		{"$N一招「力劈华山」，$w大开大阖，自上而下划出一个闪电，直劈向$n", 160,5 , 5, 30, "割伤",},
		{"$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸口", 180, 10, 5, 35, "割伤",},
		{"$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向$n", 210, 15, 15, 45, "割伤",},
		{"$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l", 240, 5, 15, 50, "劈伤",},
		{"$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，向$n的全身涌去", 280, 20, 10, 60, "刺伤",},
		{"$N右手后撤，手腕一翻，一招「壮士断腕」，顿时一道白光直斩向$n的手臂", 320,20 , 20,70 , "砍伤",},
		{"$N高高跃起，一招「人头落地」，手中$w直劈向$n的颈部", 320, 20, 20, 70, "劈伤",},
		{"$N贴地滑行，一招「断子绝孙」，手中$w直撩去$n的裆部", 350, 30,30 , 80, "割伤",},
	};
 		
	int zhaoshu, level;
	
	zhaoshu = 11;
	level  = me->query_skill("wuhuduanmendao",1);

	if (level < 60 )
		zhaoshu--;
	if (level < 50 )
		zhaoshu--;
	if (level < 40 )
		zhaoshu--;
	if (level < 30 )
		zhaoshu--;
	if (level < 20 )
		zhaoshu--;
	if (level < 10 )
		zhaoshu--;
	level = random(zhaoshu);

	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("damage", action[level].damage);
	
	return & m_actions;
}


virtual int valid_enable(string usage)
{ 
	return (usage == "blade") || (usage == "parry"); 
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");

	if (me->query_skill("blade", 1) < 20)
		return notify_fail("你的基本刀法火候太浅。");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon ;
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");

	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练五虎断门刀法。");

	me->receive_damage("hp", 30);
	return 1;
}

protected:
	CMapping m_actions;

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp

/**************************************
// wuhu-duanmendao.c 五虎断门刀

inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w斜指，一招「直来直去」，反身一顿，一刀向$n的$l撩去",
	"force" : 120,
        "dodge" : -10,
        "parry" : 5,
	"damage" : 15,
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
	"force" : 130,
        "dodge" : -10,
        "parry" : 10,
	"damage" : 20,
	"damage_type" : "割伤"
]),
([	"action" : "$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
	"force" : 140,
        "dodge" : -5,
        "parry" : 5,
	"damage" : 25,
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「力劈华山」，$w大开大阖，自上而下划出一个闪电，直劈向$n",
	"force" : 160,
        "dodge" : 5,
        "parry" : 5,
	"damage" : 30,
	"damage_type" : "割伤"
]),
([	"action" : "$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸口",
	"force" : 180,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 35,
	"damage_type" : "割伤"
]),
([	"action" : "$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向$n",
	"force" : 210,
        "dodge" : 15,
        "parry" : 15,
	"damage" : 45,
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
	"force" : 240,
        "dodge" : 5,
        "parry" : 15,
	"damage" : 50,
	"damage_type" : "劈伤"
]),
([	"action" : "$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，向$n的全身涌去",
	"force" : 280,
        "dodge" : 20,
        "parry" : 10,
	"damage" : 60,
	"damage_type" : "刺伤"
]),
([	"action" : "$N右手后撤，手腕一翻，一招「壮士断腕」，顿时一道白光直斩向$n的手臂",
	"force" : 320,
        "dodge" : 20,
        "parry" : 20,
	"damage" : 70,
	"damage_type" : "砍伤"
]),
([	"action" : "$N高高跃起，一招「人头落地」，手中$w直劈向$n的颈部",
	"force" : 320,
        "dodge" : 20,
        "parry" : 20,
	"damage" : 70,
	"damage_type" : "劈伤"
]),
([	"action" : "$N贴地滑行，一招「断子绝孙」，手中$w直撩去$n的裆部",
	"force" : 350,
        "dodge" : 30,
        "parry" : 30,
	"damage" : 80,
	"damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	if (me->query_skill("blade", 1) < 20)
		return notify_fail("你的基本刀法火候太浅。");
	return 1;
}

mapping query_action(object me, CContainer * weapon)
{
int zhaoshu, level;

zhaoshu = sizeof(action)-1;
level   =  me->query_skill("wuhu-duanmendao",1);

if (level < 60 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;
return action[random(zhaoshu)];
}

int practice_skill(object me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
	||  DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练五虎断门刀法。");
	me->receive_damage("hp", 30);
	return 1;
}
*****************************/

