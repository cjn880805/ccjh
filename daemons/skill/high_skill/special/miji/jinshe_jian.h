
// jinshe_jian.h 金蛇剑法
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSjinshe_jian);

virtual void create()
{
	set_name( "金蛇剑法");

	Magic_t * magic;

	magic = add_magic("suo", do_suo);
	magic->name = "锁剑诀";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][80] = {
		{"$n不退反进，气走周天，手中的$W狠狠磕开了$N的$w。"},
		{"$n回剑自守，架住了$N的$w。"},
		{"$n手中的$W化作千百把，护住了全身。"},
		{"$n手中的$W自上削下，几乎将$N的$w削成两段。"},
	};

	static char unarmed_parry_msg[][80] = {
		{"$n使动$W，在身前布起了一道铜墙铁壁，封住了$N的攻势。"},
		{"$n一抖手中的$W，护住了全身。"},
		{"$n将$W往地上一刺，$W反弹起来，刚好直刺$N的双臂。"},
		{"$n举剑静立，一股内力从剑梢透出，逼开了$N。"},
	};
	if( weapon )
		return parry_msg[random(4)];
	else
		return unarmed_parry_msg[random(4)];
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,parry,force,damage;
		char damage_type[5];
	}action[] = {
		{"$N使一招「金光蛇影」，手中的$w在一弹指间已向$n的$l连刺数剑", 50, 100, 170, 50, "刺伤",},
		{"$N使一招「蛇影万道」，手中$w狂风骤雨般地向$n的$l连攻数剑", 100, 200, 200, 70, "刺伤",},
		{"$N身形一转，陡地贴地跃起，手中$w灵动夭跃，一招「雪地飞蛇」疾刺$n的$l", 100, 200, 170, 50, "刺伤",},
		{"$N身形一转，一招「金蛇吞信」，手中的$w从左肋下向$n的$l戳了过去", 100,200 , 200, 120, "刺伤",},
		{"$N手腕一抖，一招「金蛇狂舞」，$w挟著闪闪剑光，变幻无方逼向$n的$l", 100, 200, 300, 150, "刺伤",},
		{"$N心念电闪手腕疾振处，一招「灵蛇电闪」，$w以无法形容的速度直射$n的$l", 100, 200, 250, 200, "刺伤",},
		{"$N身形一矮，一招「蛇困愁城」，手中的$w由下往上刺向$n的$l", 100, 200, 300,300 , "刺伤",},
		{"$N手中$w剑光暴长，一招「金蛇化龙」，如千年蛇蝎往$n$l咬去", 100, 200, 300, 400, "刺伤",},
	};
 		
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if( (i - 1) * 10 < me->query_skill("jinshe_jian", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

int valid_learn(CChar * me)
{
	if(me->query_skill("jinshe_jian", 1) < 200)
		return notify_fail("你的修为太浅,无法领会其中奥义!");

	CContainer * ob;
	
	if(  me->query("max_mp") < 500 )
		return notify_fail("你的内力不够，没有办法练金蛇剑法。");
	
	if( !(ob = me->query_weapon())
		||	 DIFFERSTR(ob->querystr("skill_type"), "sword") )
		return notify_fail("你必须先找一把剑才能练剑法。");
	
	return notify_fail("金蛇剑法没法教授。");
	
}

int practice_skill(CChar * me)
{
	if(me->query_skill("jinshe_jian", 1) < 200)
		return notify_fail("你的修为太浅,无法领会其中奥义!");

	if(  me->query("hp") < 30
		||	 me->query("mp") < 15 )
		return notify_fail("你的内力或气不够，没有办法练习金蛇剑法。");
	me->receive_damage("hp", 30);
	me->add("mp", -15);
	tell_object(me,"你按著所学练了一遍金蛇剑法。", "practice");
	return 1;
}

//perform 
static int do_suo(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon, * weapon2;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(!target || !me->is_fighting(target))
        return notify_fail("「锁剑诀」只能对战斗中的对手使用。");

    if (! (weapon = me->query_weapon())
        ||  DIFFERSTR(weapon->querystr("id"), "jinshe_jian"))
		return notify_fail("你没用金蛇剑，不能使用绝招！");
	
    if( me->query("dex") < 20 || me->query("str") < 20 )
        return notify_fail("你的先天膂力身法孱弱, 不能使用「锁剑诀」！");
	
    int skill = me->query_skill("jinshe_jian",1);
	
    if (! (weapon2 = target->query_weapon()))
        return notify_fail("对方没有使用兵器，你用不了「锁剑诀」。");
	
    if( skill < 150)
        return notify_fail("你的金蛇剑法等级不够, 不能使用「锁剑诀」！");
	
    if( me->query("mp") < 300 )
        return notify_fail("你的内力不够，无法运用「锁剑诀」！");
	
    msg = "$N手中" "金蛇剑画出一道金光，斜刺一拉，「锁剑诀」！金蛇剑剑尖倒钩正好挂在$n的";
	msg += weapon2->name();
	msg += "上。";

	int damage = 10 + random(skill / 2);
    int ap = me->query_skill("sword")/3 + skill;
    int dp = target->query_skill("dodge")/2;
    if( dp < 1 )
        dp = 1;
    if( random(ap) > random(dp) )
    {
        me->add("mp",-50);
        msg += "$n顿时觉得眼前金光一闪，手腕一振，手中";
        msg += weapon2->name();
        msg += "脱手飞出！";
        me->start_busy(random(2));
        target->receive_damage("hp", damage);
        target->start_busy(2);
        weapon2->move(me->environment());
    }
    else
    {
        me->add("mp",-30);
        msg += "$n急运内力，将手中";
		msg += weapon2->name();
		msg += "斜斜顺势一送一搭，抽了回来。";
        me->start_busy(4);
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
