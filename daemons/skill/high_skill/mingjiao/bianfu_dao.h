//bianfu_dao.h 游龙杖法

//coded by Fisho
//data: 2000-11-29

SKILL_BEGIN(CSbianfu_dao);

virtual void create()
{
	set_name( "蝙蝠刀法");
	set("valid_force", "shenghuo_shengong");

	Magic_t * magic;

	magic = add_magic("xuefu", do_xuefu);
	magic->name = "血海蝠影";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar *me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int  force,dodge, damage,lvl;
	}action[]={
		{"$N一招看似平淡无奇的「空山灵雨」，$w变的如一团雨丝向$n落去！",  10,-40,  140, 10,},
		{"$N天人合一，内外交融，手中$w象幽灵般刺向$n的$l！", 20,-45,  200, 45,},
		{"$N手中的$w幻出一片刀花，分刺$n的身法中的数处破绽。", 30,-35,  220, 85,},
		{"$N飞身而起，手中的$w幻出一片刀光，，忽然反手一刀横斩$n的$l！",  40,-15, 300, 95,},
		{"$N手中的$w光芒暴长，使出「谁是英雄」，如雷霆万钧砍向$n的$l！",  50,-15, 480, 145,},
	};
	for(int i = 5; i > 0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("bianfu_dao", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
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

	if ( DIFFERSTR(me->querystr("family/family_name"), "明教"))
		return	notify_fail("蝙蝠刀法必须是明教弟子方可以学习。");

	if(!me->query("mj/bianfu_dao"))
		return notify_fail("没有得到明师指点，怎能学得蝠王不传绝技呢？");

	if (me->query_skill("blade", 1) < 30)
		return notify_fail("你的基本刀法太差了练不了蝙蝠刀法。");

	if(me->query("mj/bianfu_dao")*50<me->query_skill("bianfu_dao", 1))
		return notify_fail("你只觉的体内真气翻腾，无法静下心来继续学习。");

 	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon ;
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");

	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练蝙蝠刀法。");

	if ( DIFFERSTR(me->querystr("family/family_name"), "明教"))
		return	notify_fail("蝙蝠刀法必须是明教弟子方可以练习。");

	if (me->query_skill("blade", 1) < me->query_skill("bianfu_dao", 1))
		return notify_fail("你的基本刀法火候不够，不能继续修炼蝙蝠刀法了。");

	if(me->query("mj/bianfu_dao")*50<me->query_skill("bianfu_dao", 1))
		return notify_fail("你只觉的体内真气翻腾，无法静下心来继续练习。");

	me->receive_damage("hp", 20);
	return 1;
}

static int do_xuefu(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target = NULL;
	CContainer * weapon ;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("「血海蝠影」只能对战斗中的对手使用。");

	if (! (weapon = me->query_weapon())	|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");

	if ( DIFFERSTR(me->querystr("family/family_name"), "明教"))
		return	notify_fail("「血海蝠影」必须是明教弟子方可以使用。");

	if (me->query("mp")<600)
		return notify_fail("你的内力修为不足，无法运足「血海蝠影」的内力。");

	if (me->query_skill("qingfu_shenfa", 1) <200)	
		return notify_fail("你的青蝠身法火候太浅。");

	if (me->query_skill("bianfu_dao", 1) < 149)	
		return notify_fail("你的蝙蝠刀法火候太浅。");

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	me->add("mp", -400);
	
	msg = "$HIR只见红光一闪，刀光穿梭而过，如蝠翼掠过$n的喉间,形成一片血海激起喷射的血流。\n";
	
	me->start_busy(1);
	if( random(me->query_combat_exp()) >  target->query_combat_exp()/3 ) 
	{
		msg +=   " $HIR$P的精神一振，脸上顿时有了血色。"  ;
		//target->start_busy(me->query_skill("blade") / 40 + 2 );
		int damge_hp=(me->query_skill("blade")*2/3+me->query_skill("bianfu_dao")*3/2)*(random(me->query("kill/guilt")/100+1)+1);
		if(target->query("hp")<=damge_hp)
			damge_hp=target->query("hp")*90/100;
		target->add("hp",-damge_hp);
		me->add("hp",damge_hp*85/100);
		if(me->query("hp")>me->query("max_hp"))
			me->set("hp",me->query("max_hp"));
	} 
	else 
	{
		msg += "可是$p看破了$P的企图，并没有上当。"  ;
		me->start_busy(1);
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}


SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp





