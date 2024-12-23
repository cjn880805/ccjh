//tianyu_qijian.h 天羽奇剑

SKILL_BEGIN(CStianyu_qijian);

virtual void create()
{
	set_name( "天羽奇剑");

	set("valid_force", "bahuang_gong");
	
	Magic_t * magic;
	set("diff",150);
	
	magic = add_magic("san", do_san);
	magic->name = "天女散花";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("kuangwu", do_kuangwu);
	magic->name = "天羽狂舞";
	magic->mp = 650;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("yushijufen", do_yushijufen);
	magic->name = "玉石俱焚";
	magic->mp = 0;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force, dodge,  damage, lvl;
	}action[9] = {
		{"$N使一式「海天一线」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
			120, 0, 30, 0,},
		{"$N错步上前，使出「闪电惊虹」，手中$w划出一道剑光劈向$n的$l",
		140, 10, 40, 9,},
		{"$N手中$w一抖，一招「日在九天」，斜斜一剑反腕撩出，攻向$n的$l",
		160, 10, 50, 18,},
		{"$N手中剑锵啷啷长吟一声，一式「咫尺天涯」，一道剑光飞向$n的$l",
		180, 10, 100, 27,},
		{"$N一式「怒剑狂花」，手中$w舞出无数剑花，使$n难断虚实，无可躲避",
		220, 15, 100, 36,},
		{"$N手中$w斜指苍天，剑芒吞吐，一式「九弧震日」，对准$n的$l斜斜击出",
		260, 15, 120, 44,},
		{"$N一式「漫天风雪」，手腕急抖，挥洒出万点金光，刺向$n的$l",
		320, 15, 125, 52,},
		{"$N一式「天河倒泻」，$w飞斩盘旋，如疾电般射向$n的胸口",
		380, 15, 140, 60,},
		{"$N一式「天外飞仙」，$w突然从天而降，一片金光围掠$n全身",
		380, 20, 150, 60,},
	};
	
	int level = me->query_skill("tianyu_qijian", 1);
	for(int i = 9; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
			
			m_actions.set("action", action[level].action);
			m_actions.set("force", (me->query("skill_pro/灵鹫宫/天羽奇剑/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/灵鹫宫/天羽奇剑/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/灵鹫宫/天羽奇剑/damage")+100) * action[level].damage/100);
			break;
		}
		
		return & m_actions;
};

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/灵鹫宫/天羽奇剑/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/灵鹫宫/天羽奇剑/force"));
			if(me->query("skill_pro/灵鹫宫/天羽奇剑/force_point")>=level_point)
			{
				me->add("skill_pro/灵鹫宫/天羽奇剑/force",1);
				me->set("skill_pro/灵鹫宫/天羽奇剑/force_point",1);
				tell_object(me,"\n$HIR你的天羽奇剑配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/灵鹫宫/天羽奇剑/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/灵鹫宫/天羽奇剑/dodge"));
			if(me->query("skill_pro/灵鹫宫/天羽奇剑/dodge_point")>=level_point)
			{
				me->add("skill_pro/灵鹫宫/天羽奇剑/dodge",1);
				me->set("skill_pro/灵鹫宫/天羽奇剑/dodge_point",1);
				tell_object(me,"\n$HIR你的天羽奇剑使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/灵鹫宫/天羽奇剑/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/灵鹫宫/天羽奇剑/damage"));
			if(me->query("skill_pro/灵鹫宫/天羽奇剑/damage_point")>=level_point)
			{
				me->add("skill_pro/灵鹫宫/天羽奇剑/damage",1);
				me->set("skill_pro/灵鹫宫/天羽奇剑/damage_point",1);
				tell_object(me,"\n$HIR你的天羽奇剑威力更大了。\n");
			}
		}
	}
	return "";
}

virtual int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练天羽奇剑。");
	
	me->receive_damage("hp", 25);
	
    return 1;
}
/*
static int do_san(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	CContainer * weapon;
	string msg;
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("「天女散花」只能对战斗中的对手使用。");
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if( me->query_skill("tianyu_qijian", 1) < 50 )
		return notify_fail("你的天羽奇剑不够娴熟，不会使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_skill("bahuang_gong", 1) < 50 )
		return notify_fail("你的八荒六合唯我独尊功不够高。");
	
	if( me->query("mp") < 300 )
		return notify_fail("你现在内力太弱，不能使用「天女散花」。");
	
	msg = "$CYN$N凝神息气，手腕疾抖，挽出千万个剑花，铺天盖地飞向$n。$COM\n";
	
	if( !target->is_killing(me) ) target->kill_ob(me);
	
	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		target->start_busy( me->query_skill("tianyu_qijian") / 20 + 1);
		
		int damage = me->query_skill("bahuang_gong", 1);
		damage = damage +  me->query_skill("tianyu_qijian", 1);
		damage = damage +  me->query_skill("sword", 1);
		
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/3);
		me->add("mp", -damage);
		msg += "$HIR只见$N剑花聚为一线，穿向$n,\n$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！$COM";
		me->start_busy(2);
	} 
	else 
	{
		msg += "$CYN可是$p猛地向前一跃,跳出了$P的攻击范围。$COM";
		me->add("mp", -100);
		me->start_busy(4);
	}
	
	message_vision(msg.c_str(), me, target);
	
	return 1;
}
*/
// san.c  天女散花
static int do_san(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	CContainer * weapon;
	string msg;
	
	int extra = me->query_skill("tianyu_qijian",1);
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("「天女散花」只能对战斗中的对手使用。");
	
	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if( me->query_skill("tianyu_qijian", 1) < 50 )
		return notify_fail("你的天羽奇剑不够娴熟，不会使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_skill("bahuang_gong", 1) < 50 )
//	if((me->query_skill("bahuang_gong", 1) < 50 ) 
//		&& (me->query_skill("beiming_shengong", 1) < 50 ))
		return notify_fail("你的本门内功实在太差，没法用「天女散花」。");
	
	if( me->query("mp") < 300 )
		return notify_fail("你现在内力太弱，不能使用「天女散花」。");
	
//	msg = "$CYN$N凝神息气，手腕疾抖，挽出千万个剑花，铺天盖地飞向$n。$COM";
	message_vision("$CYN$N凝神息气，手腕疾抖，挽出千万个剑花，铺天盖地飞向$n。$COM\n" ,me,target); 

	extra = me->query_skill("tianyu_qijian",1) / 20;
	extra += me->query_skill("tianyu_qijian",1) /20;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	
	message_vision("\n$HIR上一朵剑花！$COM" ,me,target);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	message_vision("\n$HIG下一朵剑花！！$COM" ,me,target);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	message_vision("\n$HIY最后一朵剑花！！！$COM" ,me,target);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	
	me->add("mp",-150);
	me->start_busy(2);
	return 1;
}

// kuangwu  天羽狂舞
static int do_kuangwu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	CContainer * weapon;
	string msg;

	int extra;
	extra = me->query_skill("tianyu_qijian",1);

	if ( !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫")))
		return	notify_fail("［天羽狂舞］必须是本门弟子方可以使用");

	if( !target || !me->is_fighting(target) )
		return notify_fail("［天羽狂舞］只能对战斗中的对手使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	//if( ! DIFFERSTR(me->query_skill_mapped("sword"), "tianyu_qijian" ))
	//	return notify_fail("［天羽狂舞］只能装备在基本剑法上才可以使用。");

	if (!(weapon = me->query_weapon())|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");

	if( extra < 200) return notify_fail("你的天羽奇剑还不够纯熟！");

	if( me->query("mp")<650)
		return notify_fail("你的内力不够。"); 

	if( me->query("hp")<1500)
		return notify_fail("你的气血不够。"); 

	if( me->query_skill("bahuang_gong", 1) < 160 )
//	if( (me->query_skill("bahuang_gong", 1) < 160 ) 
//		&& (me->query_skill("beiming_shengong", 1) < 160 ))
		return notify_fail("你的本门内功不够娴熟。");
	
	me->add("mp",-650);
	me->add("hp",-1000);
	weapon = me->query_weapon();
//	weapon = me->query_temp("weapon");
//	message_vision("$HIM$N使出天羽奇剑中的绝招［天羽狂舞］，一招连环六剑，手中的"+weapon->name()+"闪电般向$n攻出第一剑！$COM\n\n" ,me,target); 
	message_vision("$HIM$N使出天羽奇剑中的绝招［天羽狂舞］，一招连环七剑，闪电般向$n攻出第一剑！$COM\n\n" ,me,target); 
	extra = me->query_skill("tianyu_qijian",1) /20;
//	extra += me->query_skill("tianyu_qijian",1) /20;
	if (me->query("combat_exp")> target->query("combat_exp")/3 )
	{
		me->add_temp("apply/attack", extra);	
		me->add_temp("apply/damage", extra);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		message_vision("$HIR第二剑！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

		message_vision("$HIC第三剑！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

		message_vision("$HIY第四剑！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

		message_vision("$HIG第五剑！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

		message_vision("$HIM第六剑！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

		message_vision("$HIW最后一剑！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
			msg = "$HIC一道生死符$HIM打中$n的身上,$n只觉得伤口一冷！$COM\n";   
			message_vision(msg.c_str(), me, target);
			target->apply_condition("ss_poison", 5);
			target->start_busy(2);
        }
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
			msg = "$HIY一道生死符$HIM打中$n的身上,$n只觉得伤口一冷！$COM\n";   
			message_vision(msg.c_str(), me, target);
			target->apply_condition("ss_poison", 5);
			target->start_busy(2);
        }
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
			msg = "$HIR一道生死符$HIM打中$n的身上,$n只觉得伤口一冷！$COM\n";   
			message_vision(msg.c_str(), me, target);
			target->apply_condition("ss_poison", 5);
			target->start_busy(2);
        }
		
        message_vision("$WHT$N连出七剑，结果$n被攻了个手忙脚乱！$COM\n" ,me,target);
        me->start_busy(5);
		me->add_temp("apply/attack", -extra);
		me->add_temp("apply/damage", -extra);
	} 
	else 
	{ 
		message_vision("$HIC可是$n看破了$N的招式,趁机发动进攻！$COM\n" ,me,target);
		me->start_busy(2);
	}        
	return 1;
}

// yushijufen  玉石俱焚	
static int do_yushijufen(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	CContainer * weapon;
	string msg;

	if ( !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫")))
		return	notify_fail("［玉石俱焚］必须是本门弟子方可以使用");

	if( !target || !me->is_fighting(target) )
		return notify_fail("「玉石俱焚」只能对战斗中的对手使用。");
	
	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if( me->query_skill("tianyu_qijian", 1) < 180 )
		return notify_fail("你的天羽奇剑不够娴熟，不会使用。");
	
	if( (me->query_skill("bahuang_gong", 1) < 40 ) 
		&& ( me->query_skill("beiming_shengong", 1) < 40 ))
		return notify_fail("你的本门内功不够娴熟。");
	
	if( !( me->query("eff_hp")<100||(me->query("max_hp")/me->query("eff_hp"))>=2.5))
		return notify_fail("你还没受重伤，不要使用玉石俱焚。");

	if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if( me->query_skill("bahuang_gong", 1) < 100 )
//	if( (me->query_skill("bahuang_gong", 1) < 100 ) 
//		&& ( me->query_skill("beiming_shengong", 1) < 100 ))
		return notify_fail("你的本门内功实在太差，没法用「玉石俱焚」。");
	
	if( me->query("max_mp") < 1500 )
		return notify_fail("你现在内力太弱，不能使用「玉石俱焚」。");
	
	msg = "$RED$N跃出数丈，神色凝重，一招[玉石俱焚]想跟$n同归于尽！$COM\n";
	
	if( random(me->query("combat_exp")) > target->query("combat_exp")/2 ) 
	{
		if(random(2)==1)
		{
			msg += "结果$p被$P攻了个措手不及，昏死过去！$COM\n" ;
			target->unconcious();
		}
		msg += "$P自己由于用力过度，昏死过去！$COM\n" ;
		me->unconcious();
	} 
	else 
	{
		msg += "可是$p还是躲过了$P的最后一击！但自己由于用力过度，昏死过去！$COM\n" ;
		me->unconcious();
	}
	message_vision(msg.c_str(), me, target);
//	me->unconcious();
	return 1;
}


SKILL_END;





