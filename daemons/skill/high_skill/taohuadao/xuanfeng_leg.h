
// xuanfeng_leg.h 旋风扫叶腿
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSxuanfeng_leg);

virtual void create()
{
	set_name( "旋风扫叶腿");
	set("valid_force", "bibo_shengong");

	set("diff",110);

	Magic_t * magic;

	magic = add_magic("kuangfeng", do_kuangfeng);
	magic->name = "狂风绝技";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  damage,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N双手虚晃，左脚猛地飞起，一式「风起云涌」，脚尖晃动，踢向$n的屁股", 100, 15,10 ,"瘀伤",},
		{"$N左脚顿地，别转身来抽身欲走，只一刹那间一回身，右脚一式「空谷足音」，猛踹$n的$l", 120, 10, 0,"瘀伤",},
		{"$N左手一挣，反手扭搭住$n的右手，右脚同时踹出，既猛且准，一式「碧渊腾蛟」，踢中的$n的胸口", 140, 15, 10,"瘀伤",},
		{"$N突然跃起，双足连环圈转，一式「秋风落叶」，足带风尘，攻向$n的全身", 160, 15, 10,"瘀伤",},
		{"$N两手护胸，双脚交叉踢起，一式「风扫残云」，脚脚不离$n的面门左右", 180, 20, 20,"瘀伤",},
		{"$N突然侧身，却步后退，一个前空翻，右脚自上而下一式「流星坠地」，照$n的面门直劈下来", 200, 35, 30,"瘀伤",},
		{"$N使一式「朔风吹雪」，全身突然飞速旋转，双足忽前忽后，迅猛无极踹向$n的胸口", 220, 30, 40,"瘀伤",},
		{"$N抽身跃起，开声吐气，大喝一声：嗨！一式「雷动九天」，双脚如旋风般踢向$n的$l", 250, 35, 30,"瘀伤",},
	};

	int level = me->query_skill("xuanfeng_leg", 1);
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level )
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/
			m_actions.set("dodge", (me->query("skill_pro/桃花岛/旋风扫叶腿/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/桃花岛/旋风扫叶腿/damage")+100) * action[level].damage/100);
	
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return usage == "unarmed" || usage == "parry" || usage == "leg";	//装备到基本腿法
}

virtual int valid_combine(string combo) { return combo=="luoying_shenzhang"; }

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("dodge")) 
		{
			me->add("skill_pro/桃花岛/旋风扫叶腿/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/桃花岛/旋风扫叶腿/dodge"));
			if(me->query("skill_pro/桃花岛/旋风扫叶腿/dodge_point")>=level_point)
			{
				me->add("skill_pro/桃花岛/旋风扫叶腿/dodge",1);
				me->set("skill_pro/桃花岛/旋风扫叶腿/dodge_point",1);
				tell_object(me,"\n$HIR你的旋风扫叶腿使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/桃花岛/旋风扫叶腿/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/桃花岛/旋风扫叶腿/damage"));
			if(me->query("skill_pro/桃花岛/旋风扫叶腿/damage_point")>=level_point)
			{
				me->add("skill_pro/桃花岛/旋风扫叶腿/damage",1);
				me->set("skill_pro/桃花岛/旋风扫叶腿/damage_point",1);
				tell_object(me,"\n$HIR你的旋风扫叶腿威力更大了。\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
        return notify_fail("旋风扫叶腿必须空手。");
    if ( me->query_skill("bibo_shengong", 1) < 15)
        return notify_fail("你的碧波神功火候不够，无法学旋风扫叶腿。");
    if ( me->query("max_mp") < 100)
        return notify_fail("你的内力太弱，无法练旋风扫叶腿。");
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
    if ( me->query("mp") < 20)
		return notify_fail("你的内力不够练旋风扫叶腿。");
    me->receive_damage("hp", 20);
    me->add("mp", -1);
    return 1;
	
}


//perform 
static int do_kuangfeng(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(!target || !me->is_fighting(target) )
		return notify_fail("「狂风绝技」只能在战斗中使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if (me->query_weapon()  )
		return notify_fail("「狂风绝技」开始时不能拿着兵器！");
	
	if(  me->query("mp") < 200 )
		return notify_fail("你的真气不够！");
	
	if(  me->query_skill("bibo_shengong",1) < 50 )
		return notify_fail("你的碧波神功不够！");
	
	if(  me->query_skill("luoying_shenzhang",1) < 100 ||
		me->query_skill("xuanfeng_leg",1) < 100)
		return notify_fail("你的腿掌功夫还不到家，无法使用狂风绝技！");
/*
	if (EQUALSTR(me->query_skill_mapped("leg"), "xuanfeng_leg") && 
		EQUALSTR(me->query_skill_mapped("unarmed"), "anranxiaohun_zhang"))
		return notify_fail("「狂风绝技」怎么可能用拳头打出？");
*/	
	message_vision("$N使出桃花岛绝技「狂风绝技」，身法陡然加快！", me);
	
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	
	me->add("mp", -200);
	me->start_busy(2);
	
//	if(!((CChar *)ob)->is_fighting(me)) ((CChar *)ob)->kill_ob(me);
	return 1;
}

SKILL_END;
