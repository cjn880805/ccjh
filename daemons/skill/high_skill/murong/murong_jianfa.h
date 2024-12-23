// murong_jianfa.h 慕容剑法

SKILL_BEGIN(CSmurong_jianfa);

virtual void create()
{
	set_name( "慕容剑法");
	
	Magic_t * magic;
	
	magic = add_magic("qixing", do_qixing);
	magic->name = "剑转七星";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("kuangjian", do_kuangjian);
	magic->name = "快剑";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("lianhuan", do_lianhuan);
	magic->name = "七剑连环指";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenyuan_gong") || EQUALSTR(arg, "shenyuan_gong"))
		return 1;
	
	return notify_fail("慕容剑法必须与神元功配合使用。");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[6] = {
		{"$N剑尖下指，一式「洗耳恭听」，双脚后退三步，剑尖直点$n腿部",
		100, 20, 30, 0,},
		{"$N踏前数步，避虚就实，右手使一式「明察秋毫」直刺$n的右肋",
		100, 15, 60, 20,},
		{"$N一招「甜言蜜语」，剑尖抖起五朵剑花，分别刺向$n的左脸和右耳",
		140, 5, 80, 40,},
		{"$N剑身横摆，剑尖指向$n的脸部，一招「望尘莫及」，宛若万马千军一般，横扫$n的$l",
		200, 10, 100, 60,},
		{"$N双脚离地，使出草上飞，身行直奔$n，一招「骑虎难下」，剑出中宫，平削$n的$l",
		260, 5, 120, 80,},
		{"$N长笑一声，横剑斜削，一招「抛砖引玉」，剑风逼向$n的$l",
		300, -5, 140, 100,},
	};
	
	int level = me->query_skill("murong_jian", 1);
	for(int i = 6; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			
			break;
		}
		
		return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练慕容剑法。");
	
	me->receive_damage("hp", 25);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	
	if (me->query_skill("hunyuan_yihp", 1) < 20)
		return notify_fail("你的神元功火候太浅。");
	
	if (me->query_skill("parry", 1) < 20)
		return notify_fail("你的基本招架火候太浅。");
	
	return 1;
}

virtual char * hit_ob(CChar *me, CChar *victim, LONG & damage)
{	
	CContainer * weapon;
	string msg;	
	weapon = me->query_weapon();
	
	if(me->query_temp("lianhuan") && !me->query_temp("lianhuan_hit")
		&& DIFFERSTR(me->query_skill_prepared("finger"), "canhe_zhi")	//判断参和指是否准备好。
		&& DIFFERSTR(me->query_skill_mapped("finger"), "canhe_zhi"))
	{
		me->set_temp("lianhuan_hit", 1);
//		weapon->unequip();
		weapon->move(me);
//		COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),1); 
		g_Combatd.Do_Attack(me, victim, CCombatd::TYPE_QUICK);
		weapon->wield();
		me->add("mp", -30);
		me->delete_temp("lianhuan_hit");
		me->add_temp("lianhuan", -1);
	}
	return 0;
}

virtual int valid_enable(string usage) { return usage == "sword" || usage == "parry";}

static int do_qixing(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	int damage;
	weapon = me->query_weapon();
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("剑转七星只能对战斗中的对手使用。");
	
	if( me->query_skill("murong_jianfa", 1) < 100 )
		return notify_fail("你的剑转七星还未练成，不能使用！");
	
	if( me->query_skill("shenyuan_gong", 1)<70)
		return notify_fail("你的本门内功火候未到，！");
	
	if( me->query("mp") < 300 )
		return notify_fail("你现在内力不足，不能使用剑转七星！");
	
	if( me->query_skill("sword", 1) < 100 )
		return notify_fail("你的基本剑法不够娴熟，不能使用剑转七星。");

	msg = "\n$HIY$N忽然剑锋一转，将内力传至剑锋，只见七朵剑花绽开，分别袭向$n的";
	msg += "七大要穴！$COM\n";
	
	if ( random(me->query("dex")) > target->query("dex")*2/3 )
	{
		msg += "\n$HIR$p只觉得全身受到内力震荡，钻心般巨痛，一口鲜血喷出，身上多\n";
		msg += "出七个血肉模糊的血窟窿。$COM\n";
		message_vision(msg.c_str(), me, target);
		me->add("mp", -100);
	}
	
	else
	{
		msg += "\n$HIG$p情急之中双脚跋地而起，空中身行一闪，狼狈地躲过这一照，脸色变的苍白。$COM\n";
		message_vision(msg.c_str(), me, target);
		me->start_busy(2);
	}
	if (random(me->query_skill("parry")) > target->query_skill("parry")/2 )
	{
		me->start_busy(2);
		
		damage = me->query_skill("shenyuan_gong", 1);
		
		damage = damage*5/2 + random(damage);
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage);
		target->add("mp", -random(damage));
		me->add("mp", -100);
		if( damage < 300 ) msg += "\n$HIC结果$n脸色变得惨白，踉踉跄跄退了好几步！$COM\n";
		else if( damage < 400 ) msg += "\n$HIM结果重重地击中，$n「哇」地一声吐出一口鲜血！$COM\n";
		else if( damage < 500 ) msg += "\n$RED结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！$COM\n";
		else msg += "\n$HIR结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！$COM\n";
		
	}
	else
	{
		me->start_busy(2);
		msg += "\n$HIG$p情急之中双脚跋地而起，空中身行一闪，狼狈地躲过这一照，脸色变的苍白。$COM\n" ;
	}
	if(!me->query_temp("lianhuan"))
	{
		if( me->query_skill("murong_jianfa", 1) > 249 )
		{
			message_vision("\n$HIG$N忽然剑锋再转，只见七朵剑花再次绽开，分别袭向$n的七大要穴！$COM\n",me,target);
			msg = "$HIW星转一斗：$WHT〖$HIY天枢星$WHT〗\n\n$HIG只见$N手中之剑势一抖，笔直刺入$n的身体，$n只觉身上一痛，随即$HIC『天门穴』$HIG传来无法形容的剧烈疼痛！$COM\n";
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			msg += "$HIM星斗又见：$WHT〖$HIY天眩星$WHT〗\n\n$HIG只见$N剑势再抖，笔直刺入$n的肩头，$n只觉身上一痛，随即$HIC『肩井穴』$HIG传来一阵剧烈刺痛！$COM\n" ;
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			msg += "$MAG转星见斗：$WHT〖$HIY天机星$WHT〗\n\n$HIG只见$N剑随势上，三剑又出，竟然绝不可能的刺入$n的足底！$n只觉轻微一痛，随即$HIC『涌泉穴』$HIG传来一阵剧烈疼痛！$COM\n";
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			msg += "$YEL星转四斗：$WHT〖$HIY天权星$WHT〗\n\n$HIG只见$N剑抖四星，笔直刺入$n的身体，$n只觉身上被一阵乱刺，随即感到$HIC『任脉四穴』$HIG传来一阵剧烈疼痛！$COM\n";
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			msg += "$HIB五星在中：$WHT〖$HIY玉衡星$WHT〗\n\n$HIG只见$N剑走偏锋，笔直刺入$n的腰侧，$n只觉腰上一痒，随即$HIC『齐门穴』$HIG竟然喷出血花！$COM\n";
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			msg += "$RED星聚遇斗：$WHT〖$HIY开阳星$WHT〗\n\n$HIG只见$N抖剑而上，由上而下刺入$n的头顶，$n突然觉得全身真力不续，随即重穴$HIC『百汇穴』$HIG竟然疼痛无比！$COM\n";
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			msg += "$HIR斗转星移：$WHT〖$HIY谣光星$WHT〗\n\n$HIG只见$N剑花连抖，如众星捧剑，任$n奋力闪躲，亦将$n的第一重穴$HIC『太阳穴』$HIG刺了两道血迹！$COM\n";
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			message_vision("$WHT\n$N祭完七星，收剑挺立场中，一代王者风范凛然而出！仿佛毫不在意$n的存在。$COM\n",me,target);        
			me->add("mp", -300);
			me->start_busy(5);
			return 1;
		}
	}
	message_vision(msg.c_str(), me, target);
	
	return 1;
}

static int do_kuangjian(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( me->query_skill("murong_jianfa",1) < 200) 
		return notify_fail("你的慕容剑法还不够纯熟！");
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("［快剑］只能对战斗中的对手使用。");
	
	if ( me->query("mp")<150)
		return notify_fail("你的内力不够。"); 
	
	me->add("mp",-150);
	weapon = me->query_weapon();
//	message_vision("$HIM$N使出慕容剑法中的绝招［快剑］，一招连环六剑，手中的"+weapon->name()+"闪电般向$n攻出第一剑！$COM\n\n" ,me,target);
	message_vision("$HIM$N使出慕容剑法中的绝招［快剑］，一招连环六剑，闪电般向$n攻出第一剑！$COM\n\n" ,me, target);
	
	if (random( me->query_skill("dodge", 1)/2)>random( target->query_skill("dodge")/5 ) )
	{
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 
		message_vision("$HIW华山----------------剑法！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		message_vision("$HIC泰山----------------剑法！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		message_vision("$HIR衡山----------------五神剑！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		message_vision("$HIY恒山----------------剑法！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		message_vision("$HIB嵩山----------------剑法！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		
		message_vision("$WHT$N连出六剑，结果$n被攻了个手忙脚乱！$COM\n" ,me,target);
		me->start_busy(5);
	} 
	else 
	{ 
		message_vision("$HIC可是$n看破了$N的招式,趁机发动进攻！$COM\n" ,me,target);
		me->start_busy(2);
	}        
	return 1;
}

static int do_lianhuan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
    
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	int i=me->query_skill("murong_jianfa",1)/5;
	int j=me->query_skill("canhe_zhi",1)/5;
	int d=me->query_skill("shenyuan_gong",1)/5;
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("七剑连环指只能对战斗中的对手使用。");                
	
	if( me->query_skill("murong_jianfa", 1) < 100 )
		return notify_fail("你的剑法还未练成，不能使用七剑连环指！");
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你手里没有剑，无法使用七剑连环指！");
	
	if( me->query_skill("canhe_zhi", 1) < 100 )
		return notify_fail("你的指法还未练成，不能使用七剑连环指！");
	
	if(DIFFERSTR(me->query_skill_mapped("finger"), "canhe_zhi") )
		return notify_fail("你没有用指，无法使用七剑连环指！");
	
	if( me->query("mp") < 500 )
		return notify_fail("你现在内力不足，不能使用七剑连环指！");
	
	if( me->query_temp("lianhuan"))
		return notify_fail("你正在使用七剑连环指！"); 
	
	if( me->query_skill("sword", 1) < 100 )
		return notify_fail("你的基本剑法不够娴熟，不能在剑招中使用七剑连环指。");
	
	if( me->query_skill("finger", 1) < 100 )
		return notify_fail("你的基本指法不够娴熟，不能在剑招中使用七剑连环指。");
	
	message_vision("\n$MAG$N使出七剑连环指，剑锋一转，右手食指跟着弹出，只见剑花指风相辉相映，直袭$n！$COM\n", me,target);
	me->add("mp", -50); 
	me->set_temp("lianhuan", 2+me->query_skill("murong_jianfa", 1)/40);
	me->add_temp("apply/attack", (i+j)/3*2);
	me->add_temp("apply/damage", d);
	me->call_out(check_fight, 1);
	
	return 1;
}

static void remove_effect(CChar * me)
{
	int i=me->query_skill("murong_jianfa",1)/5;
	int j=me->query_skill("canhe_zhi",1)/5;
	int d=me->query_skill("shenyuan_gong",1)/5;   
	me->add_temp("apply/attack", -(i+j)/3*2);
	me->add_temp("apply/damage", -d);
	me->delete_temp("lianhuan");
}

static void check_fight(CContainer * me, LONG param1, LONG param2)
{
	CChar * ob = (CChar * )me;
	
	if (!ob) return;
	
	if (!ob->is_fighting()||!ob->query_temp("lianhuan"))
	{
		tell_object(ob, "$HIY你的「七剑连环指」绝技运行完毕，气回丹田,缓缓收功$COM");
		remove_effect(ob);
		return;
	}
	
	if (DIFFERSTR(ob->query_skill_mapped("finger"), "canhe_zhi")
		||DIFFERSTR(ob->query_skill_prepared("finger"), "canhe_zhi") )
		
	{
		tell_object(ob, "$COM你临时改换武功,决定不再使用「七剑连环指」绝技$COM");
		remove_effect(ob);
		return;
	}
	
	if(DIFFERSTR(ob->query_skill_mapped("parry"), "canhe_zhi") )		
		if(DIFFERSTR(ob->query_skill_mapped("parry"), "murong_jianfa"))
		{
			tell_object(ob, "$HIR你临时改换武功,决定不再使用「七剑连环指」绝技$COM");
			remove_effect(ob);
			return;
		}		
		ob->call_out(check_fight, 1);
}

SKILL_END;