//doangyangdaofa.h 五虎断门刀

//coded by xiao wu
//data: 2000-3-28

SKILL_BEGIN(CSdongyangdaofa);

virtual void create()
{
	set_name( "东洋刀法");
}

virtual CMapping * query_action(CChar *me)
{
	struct{
			char action[255];
			int force,dodge, parry ,damage;
			char damage_type[5];
	}action[11]={
		{"$N平举手中$w，一招「牙突」，向$n的$l猛然刺去",120 ,-10 , 5, 15, "割伤",},
		{"$N上前一步，$w斜批，忽然一招「燕返」变向上撩$n的颈部", 130, -10, 10, 20, "割伤",},
		{"$N挥舞$w，使出一招「百鬼夜袭」，上劈下撩，左挡右开，齐齐罩向$n", 140, 15, 15, 45, "割伤",},
		{"$N等待$n的影子进入自己脚下那一霎那，猛然跃起一招「天狗抄」，$w一卷，向$n当头斩下", 150, -5, 5, 25, "割伤",},
		{"$N凝神细听$n的心音，在$n的心跳声的间歇中突然上步，一招「水月」无声无息的劈向$n的颈部", 160,5 , 5, 30, "割伤",},
		{"$N挥刀入鞘，背对$n，倾听对方的动静，突然一招「丸太斩」，上步回身扭腰撞肘出刀，$w挟着风声高速劈向$n的$l", 180, 10, 5, 35, "割伤",},
		{"$N$N退后几步，运气凝神，$w一沉，突然一招「镰鼬」，双手持刃挥出一道无形刀气，飞向$n的胸口", 240, 5, 15, 50, "劈伤",},
		{"$N高举$w，一招「鬼介错」，挥出一道流光般的刀影，向$n的颈部飞去", 280, 20, 10, 60, "刺伤",},
		{"$N双手将$w一举，身形突然不见，随即竟在$n背后出现，一招「髓切」直斩向$n的后心", 320,20 , 20,70 , "砍伤",},
		{"$N结了一个手印，喝道“临！”突然分出四个人影同时举起手中$w直劈向$n", 320, 20, 20, 70, "劈伤",},
		{"$N突然消失，从$n脚下破土而出，手中$w直撩去$n的裆部", 350, 30,30 , 80, "割伤",},
	};
 		
	int zhaoshu, level;
	
	zhaoshu = 11;
	level  = me->query_skill("dongyangdaofa",1);

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
		return notify_fail("你的体力不够练东洋刀法。");

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

