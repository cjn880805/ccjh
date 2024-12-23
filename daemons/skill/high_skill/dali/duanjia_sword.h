// duanjia_sword.c 段家剑
// last modified by sound 2001-05-29
// 加了perform "风雷四击" 。

SKILL_BEGIN(CSduanjia_sword);

virtual void create()
{
	set_name( "段家剑");

	Magic_t * magic;

	magic = add_magic("jingtian", do_jingtian);
	magic->name = "惊天一击";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("fenglei", do_fenglei);
	magic->name = "风雷四击";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;

	return notify_fail("段家剑必须与大理独门内功配合使用。");
}


virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force,dodge, damage, lvl;
		char damage_type[5];
	}action[] = {
		{"$N向前跨上一步，一招「云横秦岭」，手中$w自左向右向$n的$l缓缓划去", 
		100, 20, 25, 0, "刺伤",},
		{"$N向上跃起，左手剑诀，右手一抖，$w剑光缦妙如瀑，一式「飞流直下」直刺$n的$l", 
		120, 15, 30, 9, "刺伤",},
		{"$N一招「雪涌兰关」，$w闪起数道寒光，自下而上反挑$n的$l", 
		140, 15, 35, 19, "刺伤",},
		{"$N一招「奇兵突起」，手中$w看似横扫实则斜劈，刺向$n的$l", 
		160, 10, 45, 29, "刺伤",},
		{"$N使出「夜叉探海」，$w挽出三个剑花，绵绵不断划向$n的$l", 
		180, 10, 60, 39, "刺伤",},
		{"$N一招「泰山压顶」，左手一捏剑诀，右手$w自上而下雷霆万钧般直向$n的$l劈乐下去", 
		210, 5, 70, 49, "刺伤",},
		{"$N一招「雨打梨花」，身在半空，$w回抽，反手勾向$n的$l", 
		250, 10, 90, 69, "刺伤",},
		{"$N身影一晃, 绕到$n背后，一招「逐鹿中原」，剑尖向$n的$l疾挑", 
		300, -5, 100, 89, "刺伤",},
	};
 
	int level = 0;

	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("duanjia_sword", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
//			m_actions.set("dodge", action[level].dodge);
			if(me->query_temp("apply/加_段家剑"))
//				m_actions.set("damage", (me->query_temp("apply/加_段家剑")+100) * action[level].damage/100);
				m_actions.set("damage", (me->query("skill_pro/大理段家/段家剑/damage")+me->query_temp("apply/加_段家剑")+100) * action[level].damage/100);
			else
//				m_actions.set("damage", action[level].damage);
				m_actions.set("damage", (me->query("skill_pro/大理段家/段家剑/damage")+100) * action[level].damage/100);
			
			m_actions.set("dodge", (me->query("skill_pro/大理段家/段家剑/dodge")+100) * action[level].dodge/100);
			break;
		}
	}

	return & m_actions;
};

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("dodge")) 
		{
			me->add("skill_pro/大理段家/段家剑/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/大理段家/段家剑/dodge"));
			if(me->query("skill_pro/大理段家/段家剑/dodge_point")>=level_point)
			{
				me->add("skill_pro/大理段家/段家剑/dodge",1);
				me->set("skill_pro/大理段家/段家剑/dodge_point",1);
				tell_object(me,"\n$HIR你的段家剑使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/大理段家/段家剑/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/大理段家/段家剑/damage"));
			if(me->query("skill_pro/大理段家/段家剑/damage_point")>=level_point)
			{
				me->add("skill_pro/大理段家/段家剑/damage",1);
				me->set("skill_pro/大理段家/段家剑/damage_point",1);
				tell_object(me,"\n$HIR你的段家剑威力更大了。\n");
			}
		}
	}
	return "";
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "staff") || (usage == "parry");}

virtual int valid_learn(CChar * me)
{

	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	if (me->query_skill("kurong_changong", 1) < 20)
		return notify_fail("你的枯荣禅功火候太浅。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练段家剑。");
	me->receive_damage("hp", 20);
	return 1;
}

//perform 
//段家剑法「惊天一击」
static int do_jingtian(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("「惊天一击」只能对战斗中的对手使用。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query_skill("duanjia_sword", 1) < 70 )
		return notify_fail("你的段家剑法不够娴熟，不会使用。");
	
	if (me->query_skill("kurong_changong", 1) < 70 )
		return notify_fail("你的枯荣禅功修为不够高。");
	
	if (me->query("mp") < 300)
		return notify_fail("你现在内力太弱，不能使用「惊天一击」。");

	if(DIFFERSTR(me->querystr("family/family_name"), "大理段家") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	msg = "$N一跃而起，手腕一抖，挽出一个美丽的剑花，飞向$n。\n";

	if (random(me->query_skill("force")) > ((CChar *)target)->query_skill("force")/2 )
	{
		target->start_busy( me->query_skill("duanjia_sword") / 20 + 1);
		
		int damage = me->query_skill("kurong_changong", 1);
		damage = damage +  me->query_skill("duanjia_sword", 1);
		damage = damage +  me->query_skill("sword", 1);
		
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/4);
		me->add("mp", -damage);
		msg += "只见$N人剑合一，穿向$n,$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！";
		me->start_busy(2);
	} 
	else 
	{
		msg += "可是$p猛地向边上一跃,跳出了$P的攻击范围。";
		me->add("mp", -100);
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);

	if(! target->is_killing(me))
		target->kill_ob(me);

	return 1;

}

//段家剑法「风雷四击」

static int do_fenglei(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	int i = me->query_skill("duanjia_sword", 1);
    
	if( !target ||! me->is_fighting(target) )
		return notify_fail("「风雷四击」只能在战斗中使用。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("手中无剑,你怎么使得出「风雷四击」！");

	if ( me->query("mp") < 500 )
		return notify_fail("你的真气不够，不能使用「风雷四击」。");

	if ( me->query_skill("wuluo_zhang",1) < 100 ||
		DIFFERSTR(me->query_skill_mapped("strike"), "wuluo_zhang") )
		return notify_fail("你的五罗清烟掌还不到家，无法使用「风雷四击」绝技！");

	if ( me->query_skill("strike",1) < 100 )
		return notify_fail("你的掌法造诣不够，无法使用如此高深的「风雷四击」绝技！");

	if ( me->query_skill("duanjia_sword", 1) < 150 )
		return notify_fail("你的段家剑法还不到家，无法使用「风雷四击」绝技！");

//	if(DIFFERSTR(me->querystr("family/family_name"), "大理段家") && me->querymap_temp("biwu"))
//		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if(DIFFERSTR(me->querystr("family/family_name"), "大理段家"))
		return notify_fail("你依稀中还记「风雷四击」的要决，可惜离开大理段家太久，已经无法把握其中的精髓。");

	message_vision("$BLU$N长笑一声，剑交左手，蹂身而上，施展「风雷四击」绝技,试图快速击伤$n $COM", me, target);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	me->add("mp",-300); 
	me->add_temp("apply/attack", i);
	me->add_temp("apply/dodge", i);
	
	message_vision("$HIY$N握剑直上，对着$n就是一剑！$COM", me, target);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);

	message_vision("$HIY$N脚踩流星步，错步而前，恍惚之间已到$n面前！$COM", me, target);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);

	message_vision("$HIY$N立身而起，一鹤冲天，一招[风火雷电]闪电般劈向$n！$COM ", me, target);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);

	me->start_busy(2);
	me->add_temp("apply/dodge", -i);
	me->add_temp("apply/attack", -i);

	return 1;
}

SKILL_END;
