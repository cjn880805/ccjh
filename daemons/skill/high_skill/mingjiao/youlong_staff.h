//youlong_staff.h 游龙杖法

//coded by Fisho
//data: 2000-11-29

SKILL_BEGIN(CSyoulong_staff);

virtual void create()
{
	set_name( "游龙杖法");
	set("valid_force", "shenghuo_shengong");

	Magic_t * magic;

	magic = add_magic("chuanyun", do_chuanyun);
	magic->name = "游龙穿云";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar *me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int  force,dodge, damage,lvl;
			char damage_type[5];
	}action[]={
		{"$N惊叱一声，双手并举，寒光陡飞，霎时人杖合一，凌空直向$n飞去。",  10,-45,  220, 10,"挫伤",},
		{"$N手中杖影乍迸，卷起万重电光，「云龙突现」轰然横扫。", 20,-45,  250, 25,"挫伤",},
		{"$N使出一招「银龙三现」，手中$w挽出团团雪花，三隐三现，杖杖不离$n的$l！", 30,-40,  270, 40,"挫伤",},
		{"$N手中$w一晃，竟幻然为双，一招「双龙戏水」，分别袭向$n的两处要害！",  40,-50,  340, 60,"挫伤",},
		{"$N手中$w抡动，过处带起阵阵啸声，一招「虎啸龙吟」，直奔$n的$l打去！",  50,-60,  380, 85,"挫伤",},
		{"$N身形连转，手中$w一招「银龙翻身」，连连向$n的$l扫去！",  60,-50,  450, 120,"挫伤",},
		{"$N杖式一变，杀机四布，展开了游龙杖有去无回的杀招「龙啸九天」。", 70,-80,  650, 250,"挫伤",},
	};
	for(int i = 7; i > 0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("youlong_staff", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	if (me->query_temp("teapot/youlong"))
	{
			m_actions.set("action", "$HIY$N跃起三丈，身在半空，招式陡变，「游龙穿云」如惊涛骇浪，卷转电擎而落。$COM");
			m_actions.set("force", 100);
			m_actions.set("dodge", -60);
			m_actions.set("damage", 700);
	}

	return & m_actions;
}

virtual int valid_enable(string usage)
{ 
	return (usage == "staff") || (usage == "parry"); 
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");

	if ( DIFFERSTR(me->querystr("family/family_name"), "明教"))
		return	notify_fail("游龙杖法必须是明教弟子方可以学习。");

	if(!me->query("mj/youlong_staff"))
		return notify_fail("没有得到明师指点，怎能学得龙王不传绝技呢？");

	if (me->query_skill("staff", 1) < 30)
		return notify_fail("你的基本杖法太差了练不了游龙杖法。");

	if(me->query("mj/youlong_staff")*50<me->query_skill("youlong_staff", 1))
		return notify_fail("你只觉的体内真气翻腾，无法静下心来继续学习。");

 	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon ;
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("你使用的武器不对。");

	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练游龙杖法。");

	if ( DIFFERSTR(me->querystr("family/family_name"), "明教"))
		return	notify_fail("游龙杖法必须是明教弟子方可以练习。");

	if (me->query_skill("staff", 1) < me->query_skill("youlong_staff", 1))
		return notify_fail("你的基本杖法火候不够，不能继续修炼游龙杖法了。");

	if(me->query("mj/youlong_staff")*50<me->query_skill("youlong_staff", 1))
		return notify_fail("你只觉的体内真气翻腾，无法静下心来继续练习。");

	me->receive_damage("hp", 20);
	return 1;
}

static int do_chuanyun(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon ;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("「游龙穿云」只能对战斗中的对手使用。");

	if ( DIFFERSTR(me->querystr("family/family_name"), "明教"))
		return	notify_fail("「游龙穿云」必须是明教弟子方可以使用。");

	if (! (weapon = me->query_weapon())	|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("你使用的武器不对。");

	if (me->query("mp")<400)
		return notify_fail("你的内力修为不足，无法运足「游龙穿云」的内力。");

	if (me->query_skill("shenghuo_shengong", 1) <200)	
		return notify_fail("你的圣火心法火候太浅。");

	if (me->query_skill("youlong_staff", 1) < 199)	
		return notify_fail("你的游龙杖法火候太浅。");

	if(EQUALSTR(target->query_skill_mapped("sword"), "lonely_sword") && EQUALSTR(target->querystr("family/family_name"), "华山派") )
	{
		string msg;
		msg = "\n$HIY$N跃起三丈，身在半空，招式陡变，「游龙穿云」如惊涛骇浪，卷转电擎而落。$COM";
		msg+= "$HIY$n脸上突现笑容，似乎已看破$N的武功招式，胸有成竹地一剑刺向$N的$l，顿时$N方寸大乱。\n" ;
		me->start_busy(2);
		me->add("mp",-250);
		message_vision(msg.c_str(), me, target);
	}
	else if(random(me->query("combat_exp")) > target->query("combat_exp")/3)
	{
		me->set_temp("teapot/youlong",1);
		g_Combatd.Do_Attack(me,target,CCombatd::TYPE_REGULAR);
		me->delete_temp("teapot/youlong");
		target->start_busy(random(2));
		me->start_busy(random(2));
		me->add("mp",-250);
	}
	else
	{
		me->set_temp("teapot/youlong",1);
		g_Combatd.Do_Attack(me,target,CCombatd::TYPE_REGULAR);
		me->delete_temp("teapot/youlong");
		me->start_busy(random(2));
		me->add("mp",-250);
	}
    return 1;
}


SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp





