// liumai_shenjian.h 六脉神剑

SKILL_BEGIN(CSliumai_shenjian);

virtual void create()
{
	set_name( "六脉神剑");
	
	Magic_t * magic;
	
	magic = add_magic("ci", do_ci);
	magic->name = "刺字决";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("feng", do_feng);
	magic->name = "封字决";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("tan", do_tan);
	magic->name = "弹字决";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("guiyi", do_guiyi);
	magic->name = "六脉归一";
	magic->mp = 1100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;
	
	return notify_fail("六脉神剑必须与大理独门内功配合使用。");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int force, dodge, damage ,lvl;
		char damage_type[5];
	}action[11] = {
		{"$N反过手来，双手拇指同时捺出，嗤嗤两声急响，“少商剑”有如石破天惊、风雨大至之势，分指$n膻中和$l",
		350, 50, 250, 0, "刺伤",},
		{"$N食指连动，手腕园转，“商阳剑”一剑又一剑的刺出，轻灵迅速，奇巧活泼，剑气纵横，$n根本无法看清来路",
		400, 100, 200, 10, "刺伤",},
		{"$N右手中指一竖，“中冲剑”向前刺出。真气鼓荡，嗤然声响，无形剑气直指$n的$l",
		350, 40, 250, 20, "刺伤",},
		{"$N右手无名指伸出，“关冲剑”剑路拙滞古朴，一股雄浑的内力鼓荡而出，如排山倒海般向$n涌去",
		350, 60, 250, 30, "刺伤",},
		{"$N左手小指一伸，一条气流从少冲穴中激射而出，“少泽剑”出手入风，指向$n的$l",
		350, 50, 250, 40, "刺伤",},
		{"$N右手反指，小指伸出，真气自少冲穴激荡而出，“少冲剑”横生奇变，从$n意想不到的方向刺向$n的$l",
		350, 40, 250, 50, "刺伤",},
		{"$N身子微侧，忽然眼中精光大现，左手食指和右手拇指各弹出一道瞬雷一般的无形剑气刺向$n的$l", 
		510, 220, 200 , 60, "刺伤",},
		{"$N身法激变，连从数个意想不到的方位发出变幻莫测的剑气或劈或刺或削地攻向$n的$l",
		570 , 225, 250, 75, "刺伤",},
		{"$N鼓动全身真气，六脉剑气齐出，从六个方位同时交错射向$n，眼看$n已是无路可逃", 
		600, 250, 300, 100 , "刺伤",},
		{"$N身法忽然加快，直逼到$n的面前，手指已经按上$n小腹，六脉剑气才猛然射出！！", 
		750, 350, 400, 160, "刺伤",},
	};
	
	int level;

	if( ! (level = me->query_temp("pfm_lmsj")) )
	{
		for(int i=10; i>0; i--)
		{
			if(action[i - 1].lvl < me->query_skill("liumai_shenjian", 1))
			{
				level = random(i);				
				break;
			}
		}
	}
	else
		level--;
	
	if (DIFFERSTR(me->querystr("family/family_name"), "大理段家"))
	{
		m_actions.set("action", "$N歪歪扭扭的冲$n伸出手指，你听到轻轻的一声“噗”。");
		m_actions.set("force", 0l);
		m_actions.set("dodge", 0l);
		m_actions.set("damage", 0l);
	}
	else
	{
		m_actions.set("action", action[level].action);

		if(! me->query_temp("pfm_lmsj"))
			m_actions.set("force", action[level].force);
		else
			m_actions.set("force", 0l);

		m_actions.set("dodge", action[level].dodge);
		if(me->query_temp("apply/加_六脉"))
			m_actions.set("damage", (me->query_temp("apply/加_六脉")+100) * action[level].damage/100);
		else
			m_actions.set("damage", action[level].damage);
	}
	
	return & m_actions;
};

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练六脉神剑必须空手。");
	
	if(me->query_skill("liumai_shenjian",1)<=0)
		return notify_fail("你必须学会每一脉的剑法，才可以学.");
	
	if (me->query("max_mp") < 2000)
		return notify_fail("你的内力太弱，无法练六脉神剑。");
	
	if (me->query_skill("kurong_changong", 1) < 80 
		||me->query_skill("tianlong_shengong", 1) < 80)
		return notify_fail("你的本门内功火候不够，无法学一阳指。");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 100)
		return notify_fail("你的体力太低了。");
	
	if (me->query("mp") < 100)
		return notify_fail("你的内力不够练六脉神剑");
	me->receive_damage("hp", 80);
	me->add("mp", -80);
	
	return 1;
}
/*
virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if (random(me->query_skill("liumai_shenjian",1)) > 200 
		&& me->query_skill("kurong_changong",1) > 200 
		&& me->query("mp") > 1000)

		me->add("mp", -200);
		
		m_actions.set("action", "\n$N忽然觉得剑谱中的六路剑法一一涌向心头，十指纷弹，此去彼来，连绵无尽。\n\n剑气纵横，尘烟四起，六路剑法回转运使，$n顿时心神大乱，但觉全身几处刺痛，几股鲜血从身上标出。\n\n忍痛抬头一看，一柱剑气迎面又到！\n");
		m_actions.set("force", 1000);
		m_actions.set("dodge", 0l);
		m_actions.set("damage", 1000);
		m_actions.set("damage_type", "刺伤");
	}
	
	if( damage < 100 )
	{
		damage = 0;
		return 0;
	}
	if( random( damage / 2) > victim->query_str() )
	{
		victim->receive_wound("hp", (damage - 100) / 2 );
		return "$HIR你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！$COM";
	}
	return 0;
}
*/

static int do_ci(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	int lvl;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("「刺」字决攻击只能对战斗中的对手使用。");
	
	if ( me->query_weapon())
		return notify_fail("你不能使用武器！");
	
	if( (lvl = me->query_skill("liumai_shenjian", 1)) < 100 )
		return notify_fail("你的六脉神剑太生疏，不会使用「刺」字决。");
	
	if ( me->query("mp") < 200)
		return notify_fail("你的内力不够，现在无法使用「刺」字决。");
	
	if (DIFFERSTR(me->querystr("family/family_name"), "大理段家"))
		return notify_fail("你苦思冥想，就是想不出怎么做。");
	
	me->add("mp", -40);
	
	msg =  "$N使出六脉神剑「刺」式，指尖飞扬，霎时间剑气纵横，将$n包围在内。\n";
	
	me->start_busy(2);
	if( random( me->query("mp") + me->query_skill("liumai_shenjian",1) * 10 ) > random( target->query_skill("dodge",1) * 10 + 1)
		&& random(me->query("combat_exp")) > target->query("combat_exp")/4) 
	{
		msg +=  "结果$p一声闷哼，连被数创。" ;
		target->receive_damage("hp", random(lvl*10) + lvl);
		target->receive_wound("hp", random(lvl*5));
	} 
	else 
	{
		msg += "可是$p连连招架，堪堪挡住了$P攻势。" ;
	}
	message_vision(msg.c_str(), me, target);
	
	return 1;
}

static int do_feng(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("「封」字决指法只能对战斗中的对手使用。");
	
	if ( me->query_weapon())
		return notify_fail("你不能使用武器！");
	
	if (DIFFERSTR(me->querystr("family/family_name"), "大理段家"))
		return notify_fail("你苦思冥想，就是想不出怎么做。");
	
	if( me->query_skill("liumai_shenjian", 1) < 90 )
		return notify_fail("你的六脉神剑太生疏，不会使用「封」字决。");
	
	if ( me->query("mp") < 150)
		return notify_fail("你的内力不够，现在无法使用「封」字决。");
	me->add("mp", -30);
	
	if( target->is_busy() )
		return notify_fail( "%s目前正自顾不暇，放胆攻击吧！",target->name() );
	
	msg =  "$HIR$N长出一口气，使出六脉神剑「封」式，指指点点，剑气如潮而至。\n";
	
	me->start_busy(1);
	if( (random( me->query("mp")) + me->query_skill("dodge",1) * 10 + 1) >random( target->query_skill("dodge",1) * 10) + 1
		&& random(me->query("combat_exp")) > target->query("combat_exp")/5
		&& !(target->query_temp("apply/no_封字决") && target->query("bigboss"))) 
	{
		msg +=  "$HIR$p强做精神，左遮右挡，无法还手！" ;
		target->start_busy( me->query_skill("liumai_shenjian", 1) / 40 );
	} 
	else 
	{
		msg += "可是$p身形一错，已飘然脱离$P的攻击。" ;
	}
	message_vision(msg.c_str(), me, target);
	
	return 1;
}

static int do_tan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg,msg1;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target ||	!me->is_fighting(target) )
		return notify_fail("「弹」字决指法只能对战斗中的对手使用。");
	
	if ( me->query_weapon())
		return notify_fail("你不能使用武器！");
	
	if (DIFFERSTR(me->querystr("family/family_name"), "大理段家"))
		return notify_fail("你苦思冥想，就是想不出怎么做。");
	
	if (! (weapon = target->query_weapon()) )
		return notify_fail("对方并没有武器，你不用担心！");
	
	if( me->query_skill("liumai_shenjian", 1) < 190 )
		return notify_fail("你的六脉神剑太生疏，不会使用「弹」字决。");
	
	if ( me->query("mp") < 250)
		return notify_fail("你的内力不够，现在无法使用「弹」字决。");
	
	me->add("mp", -50);
	
	msg =  "$N长出一口气，使出六脉神剑「弹」式，一道犀利无比的剑气直奔$n而去。\n";
	
	me->start_busy(2);
	if( random( me->query_skill("force") ) > random( target->query_skill("force") + 1) )
	{
		if(weapon->query("no_duo") && !random(3))
			msg += "可是$n看破了$N的企图，并没有上当。\n";
		else if (ob->querystr("owner")[0])
		{
			msg +=  " $p忙用";
			msg += weapon->name();
			msg += "招架，只觉得虎口剧震，所幸兵器完好无损。" ;
			target->start_busy(2);
		} 
		else
		{
			msg +=  " $p连忙招架，只听见「啪」地一声，$p手中的";
			msg += weapon->name();
			if(weapon->query("no_duo") )
			{
				msg += "竟然不易而飞！\n";
				char msg1[40];
				target->command(snprintf(msg1, 40, "unwield %ld", weapon->object_id()));
			}
			else
			{
				msg += "已经断为数截，激飞上天！" ;
				
				//ob->unequip();
				weapon->move(target->environment());
				
				msg1 = "断掉的";
				msg1 += weapon->querystr("name");
				weapon->set_name(msg1.c_str());
				weapon->set("value", 0l);
				weapon->del("apply");
				target->start_busy(2);
			}
		}
	} 
	else
	{
		msg += "$p真气贯注";
		msg += weapon->name();
		msg += "，和$P剑气相交，冒出点点火光。" ;
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_guiyi(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	int extra = me->query_skill("liumai_shenjian", 1) / 3;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("「六脉归一」只能在战斗中使用。");
	
	if ( me->query_weapon())
		return notify_fail("「六脉归一」只能空手使用。");		
	
	if (DIFFERSTR(me->querystr("family/family_name"), "大理段家"))
		return notify_fail("你苦思冥想，就是想不出怎么做。");

	if ( me->query("mp") < 1100)
		return notify_fail("你的真气不够！");
	
	if( me->query_skill("liumai_shenjian", 1) < 199 )
		return notify_fail("你的六脉神剑火候不够，无法使用「六脉归一」！");
	
	if( me->query_skill("force", 1) < 110 )
		return notify_fail("你的内功修为不够，无法使用「六脉归一」！");

	if (me->query_skill("finger", 1)
		&& !EQUALSTR(me->query_skill_prepared("finger"), "liumai_shenjian"))
		return notify_fail("「六脉归一」只能组合到基本指法上才能使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "大理段家") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if(!me->query_temp("apply/六脉归一"))
		return notify_fail("你心思涣乱，隔空遥指了几下，结果却没有任何反映。");

	me->add("mp", -1100);

	me->add_temp("apply/attack", +extra);
	me->add_temp("apply/damage", +extra);
	
	message_vision("$CYN$N心思涣乱，朝$n隔空遥指了几下，不料却使出了六脉剑法的精髓$HIY[六脉归一]$CYN！$COM\n", me, target);

	message_vision("\n$HIR-------------------------------少商剑！$COM", me, target);
	me->set_temp("pfm_lmsj", 1);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 

	message_vision("\n$HIG-------------------------------商阳剑！$COM", me, target);
	me->set_temp("pfm_lmsj", 2);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 

	message_vision("\n$HIM-------------------------------中冲剑！$COM", me, target);
	me->set_temp("pfm_lmsj", 3);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 

	message_vision("\n$HIY-------------------------------关冲剑！$COM", me, target);
	me->set_temp("pfm_lmsj", 4);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 

	message_vision("\n$HIW-------------------------------少泽剑！$COM", me, target);
	me->set_temp("pfm_lmsj", 5);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 

	message_vision("\n$HIB-------------------------------少冲剑！$COM", me, target);
	me->set_temp("pfm_lmsj", 6);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 

	me->delete_temp("pfm_lmsj");
	
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	
	me->start_busy(6);
		
	return 1;
}

SKILL_END;





