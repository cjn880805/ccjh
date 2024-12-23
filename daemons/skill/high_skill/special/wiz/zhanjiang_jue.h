//zhanjiang_jue.h 斩将诀

//coded by oho
//data: 2001-4-17

SKILL_BEGIN(CSzhanjiang_jue);

virtual void create()
{
	set_name( "斩将诀");
	Magic_t * magic;

	magic = add_magic("killyou", do_ding);
	magic->name = "千军斩将";
	magic->mp = 550;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][80] = {
		{"$n猛力一刺，以力胜巧，手中的$W狠狠磕开了$N的攻击。"},
		{"$n猛力一挡，以力胜巧，架开了$N的$w。"},
		{"$n轻轻一挑，将$N的$w挑开。"},
		{"$n跃马而起，借力猛刺，将$N硬是震退几步。"},
	};

	static char unarmed_parry_msg[][80] = {
		{"$n居高临下，猛地向$N要害一刺，$N只好回招防守。"},
		{"$n一拍爱马，那马人立起来，挡开了$N的攻击。"},
		{"$n不顾对方攻击，策马猛冲，将$N硬生生撞开一旁，踉跄几步才站稳。"},
		{"$n从背后拔出斩马刀来，用力一劈，震开了$N。"},
	};
	if( weapon )
		return parry_msg[random(4)];
	else
		return unarmed_parry_msg[random(4)];
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int force,dodge, damage, lvl;		
	}action[]={
		{"$N策马猛冲，$w带起一道银光划过$n的身体", 380, -10, 342,0,},		
		{"$N双腿一夹，坐下马向$n一跃，手中$w也同时借着马力势不可当地刺向$n", 300, -3, 348,50,},
		{"$N跃马而起向$n踩去，手中$w自下向$n的咽喉猛刺", 340, -5, 500,150 },
		{"$N策马冲过$n身边，忽然$w交左手，右手拔出斩马刀来，两种兵器左掠右劈地攻向$n。", 420, -5, 550,300},
	};
		
	int level = 0;

	for(int i=4; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("zhanjiang_jue", 1))
		{
			//必须装到招架上
			level = random(i);
			if( EQUALSTR(me->query_skill_mapped("parry"), "zhanjiang_jue") )
			{
				m_actions.set("action", action[level].action);
//				m_actions.set("force", action[level].force);
				m_actions.set("dodge", action[level].dodge);
				m_actions.set("damage", action[level].damage);
			}
			else
			{
				m_actions.set("action", action[level].action);
				m_actions.set("force", 1);
				m_actions.set("dodge", 1);
				m_actions.set("damage", 1);
			}
			break;
		}
	}		
	return & m_actions;
}


virtual int valid_enable(string usage) 
{ 
	return usage=="club" ||  usage=="parry" ||  usage=="sword"  ||  usage=="blade";
}

int valid_learn(CChar * me)
{	
	if(me->query_skill("zhanjiang_jue", 1) < 240)
		return notify_fail("你的修为太浅,无法领会其中奥义!");
	
	if (me->query("max_mp") < 70)
		return notify_fail("你的内力不够。");
	
	if(me->query("str") < 25 || me->query_str() < 40)
		return notify_fail("你的力量如此的差,练斩将诀有什么用？回家种田去吧！。");
	
	return notify_fail("壮志饥餐胡虏肉，笑谈渴饮匈奴血。");
}

int practice_skill(CChar * me)
{
	if(me->query_skill("zhanjiang_jue", 1) < 240)
		return notify_fail("你的修为太浅,无法领会其中奥义!");

	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
		|| (DIFFERSTR(weapon->querystr("skill_type"), "club")
		 && DIFFERSTR(weapon->querystr("skill_type"), "sword")
		 && DIFFERSTR(weapon->querystr("skill_type"), "blade")) )
		return notify_fail("你使用的武器不对。");

			if ( me->query_skill("zhongpingqiang", 1) < 100)
		return notify_fail("你的中平枪还不熟练，无法练习斩将诀。");
			if ( me->query_skill("wuhuduanmendao", 1) < 100)
		return notify_fail("你的五虎断门刀还不熟练，无法练习斩将诀。");
		        if ( me->query_skill("changquan", 1) < 100)
		return notify_fail("你的长拳还不熟练，无法练习斩将诀。");
	if (me->query("hp") < 200)
		return notify_fail("你的体力如此的差，练斩将诀有什么用？回家种田去吧！");
	me->receive_damage("hp", 50);
	return 1;
}

//perform 
static int do_ding(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("千军斩将只能对战斗中的敌军使用。");

	if(me->query_skill("zhanjiang_jue", 1) < 300)
		return notify_fail("你的武技不够娴熟，不能使用千军斩将。");
	weapon = me->query_weapon();
    if (! weapon
		||  (DIFFERSTR(weapon->querystr("skill_type"), "club")
		&& DIFFERSTR(weapon->querystr("skill_type"), "sword")
		&& DIFFERSTR(weapon->querystr("skill_type"), "blade")))
		return notify_fail("你使用的武器不对。");
	
    if(  me->query_skill("zhongpingqiang", 1) < 100 &&
		me->query_skill("wuhuduanmendao", 1) < 100 )
		return notify_fail("你的武技不够娴熟，不能使用千军斩将。");

	if(EQUALSTR(weapon->querystr("skill_type"), "club") && DIFFERSTR(me->query_skill_mapped("club"), "zhanjiang_jue"))
		return notify_fail("手中有刀，刀法何在？");
	if(EQUALSTR(weapon->querystr("skill_type"), "sword") &&	DIFFERSTR(me->query_skill_mapped("sword"), "zhanjiang_jue"))
		return notify_fail("手中有剑，剑法何在？");
	if(EQUALSTR(weapon->querystr("skill_type"), "blade") &&	DIFFERSTR(me->query_skill_mapped("blade"), "zhanjiang_jue"))
		return notify_fail("手中有枪，枪法何在？");

//	if( EQUALSTR(me->query_skill_mapped("parry"), "zhanjiang_jue") )
//		return notify_fail("一心只求招架，何以展现冲杀疆场、千军斩将的不世豪情？");

    if(  me->query("mp" ) < 200 )
		return notify_fail("你现在内力太弱，不能使用千军斩将。");
	
    msg =   "$N大喝一声，人马合一，如战神下凡一般和$n擦身而过。\n" ;
	
    if (random(me->query_skill("force")) > target->query_skill("force")/2 )
    {
		me->start_busy(2);
		
		int damage =  me->query_skill("zhongpingqiang", 2) +  me->query_skill("wuhuduanmendao",2);
		//(全真剑法级别+基本内功)
		
		damage = damage/3 + random(damage/2);
		
		target->receive_damage("hp", damage);
		target->start_busy(4);
		me->add("mp", -100);
		
		msg +=  "$n高高飞起，身上七八条伤痕同时狂喷出数尺高的鲜血，身体跌出一丈开外" ;
    }
    else
    {
		me->start_busy(3);
		msg +=  "可是$p看破了$P的企图，斜跃避开。" ;
    }

    message_vision(msg.c_str(), me, target);
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
