//lingshe_zhangfa.h 灵蛇杖法

//coded by Fisho
//data: 2000-11-29

SKILL_BEGIN(CSlingshe_zhangfa);

virtual void create()
{
	set_name( "灵蛇杖法");
	set("valid_force", "hamagong");

	Magic_t * magic;

	magic = add_magic("pili", do_pili);
	magic->name = "雷霆霹雳";
	magic->mp = 150;
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
		{"$N使出一招「灵蛇出洞」，手中$w大开大阖扫向$n的$l", 220, -3, 56, 10,"挫伤",},
		{"$N手中$w阵阵风响，一招「摇头摆尾」向$n的$l攻去", 240, -5, 68, 20,"挫伤",},
		{"$N举起$w，居高临下使一招「灵蛇下涧」砸向$n的$l", 280, -10, 80, 30,"挫伤",},
		{"$N一招「灵蛇挺身」，手中$w猛烈扫向$n的$l", 320, -5, 66, 80,"挫伤",},
		{"$N使出一招「蛇游蟒走」，$w左右迂回向$n的$l扫去", 360, -3, 120, 50,"挫伤",},
		{"$N手中$w一挥，使出一招「蛇缠左右」，忽左忽右扫向$n的$l", 400, -5, 136, 60,"挫伤",},
		{"$N使出一招「巨蟒下山」，高举手中$w，劈头砸向$n的$l", 440, -10, 168,80 ,"挫伤",},
		{"$N使出一招「灵蛇出洞」，手中$w猛一探，直扫$n的$l", 480, -3, 180, 100,"挫伤",},
	};
	for(int i = 8; i > 0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("lingshe_zhangfa", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/			m_actions.set("force", (me->query("skill_pro/白驼山派/灵蛇杖法/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/白驼山派/灵蛇杖法/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/白驼山派/灵蛇杖法/damage")+100) * action[level].damage/100);
			break;
		}
	}
		
	if (me->query_temp("teapot/thunder"))
			m_actions.set("action", "$N大喝一声，突然雷霆霹雳的一招攻向$n！");
	
	
	return & m_actions;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/白驼山派/灵蛇杖法/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/白驼山派/灵蛇杖法/force"));
			if(me->query("skill_pro/白驼山派/灵蛇杖法/force_point")>=level_point)
			{
				me->add("skill_pro/白驼山派/灵蛇杖法/force",1);
				me->set("skill_pro/白驼山派/灵蛇杖法/force_point",1);
				tell_object(me,"\n$HIR你的灵蛇杖法配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/白驼山派/灵蛇杖法/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/白驼山派/灵蛇杖法/dodge"));
			if(me->query("skill_pro/白驼山派/灵蛇杖法/dodge_point")>=level_point)
			{
				me->add("skill_pro/白驼山派/灵蛇杖法/dodge",1);
				me->set("skill_pro/白驼山派/灵蛇杖法/dodge_point",1);
				tell_object(me,"\n$HIR你的灵蛇杖法使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/白驼山派/灵蛇杖法/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/白驼山派/灵蛇杖法/damage"));
			if(me->query("skill_pro/白驼山派/灵蛇杖法/damage_point")>=level_point)
			{
				me->add("skill_pro/白驼山派/灵蛇杖法/damage",1);
				me->set("skill_pro/白驼山派/灵蛇杖法/damage_point",1);
				tell_object(me,"\n$HIR你的灵蛇杖法威力更大了。\n");
			}
		}
	}
	if( random(me->query_skill("hamagong") + 1) > 10 ) 
	{
		victim->apply_condition("snake_poison", random(me->query_skill("hamagong")/10) + 1 +
			victim->query("condition/snake_poison"));
        tell_object(victim,  "你觉得被击中的地方一阵麻木！"  );
        tell_object(victim,  "原来是被杖头窜出的毒蛇咬了一口！"  );
	}
	return "";
}

virtual int valid_enable(string usage)
{ 
	return (usage == "staff") || (usage == "parry"); 
}

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");
	
	if (me->query("max_mp") < 70)
		return notify_fail("你的内力不够。");

 	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon ;
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("你使用的武器不对。");

	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练灵蛇杖法。");

	me->receive_damage("hp", 20);
	return 1;
}

static int do_pili(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("雷霆霹雳只能对战斗中的对手使用。");
		
	if(DIFFERSTR(me->querystr("family/family_name"), "白驼山派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	me->set_temp("teapot/thunder",1);
	g_Combatd.Do_Attack(me,target,CCombatd::TYPE_REGULAR);
	me->delete_temp("teapot/thunder");
	me->start_busy(2);
	

    return 1;
}


SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp





