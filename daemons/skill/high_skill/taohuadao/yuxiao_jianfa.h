
// yuxiao_jianfa.h 玉萧剑法
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSyuxiao_jianfa);

virtual void create()
{
	set_name( "玉萧剑法");
	set("valid_force", "bibo_shengong");

	set("diff",130);

	Magic_t * magic;

	magic = add_magic("hua", do_hua);
	magic->name = "势合形离";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N身形一转，手中的$w划了个半圈，一式「朝朝暮暮」刺向$n的$l", 60, 10,5 , 30, 0,"刺伤",},
		{"$N左掌横推，一式「羞花碧月」，$w向前疾出，指向$n的面门", 120, 15, 10, 60, 4,"刺伤",},
		{"$N手中的$w划了个半圈，一式「风花雪夜」，向$n的$l划过", 180, 20, 15, 90, 9,"刺伤",},
		{"$N双目微睁，一式「怒涛惊魂」，$w泛出几个圆弧，一起刺向$n的$l", 250, 25, 20, 120,14 ,"刺伤",},
		{"$N身形跃起，手臂微抬，一式「曾经沧海」，蓄势捺向$n的$l", 320, 30, 25, 150, 19,"刺伤",},
		{"$N回身拧腰，右手虚抱，一招「推波助澜」，$w中宫直进，刺向$n的$l", 400, 35,30 , 180, 149,"刺伤",},
	};
 		
	int level = me->query_skill("yuxiao_jianfa", 1);
	
	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/
			m_actions.set("dodge", (me->query("skill_pro/桃花岛/玉萧剑法/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/桃花岛/玉萧剑法/damage")+100) * action[level].damage/100);
			
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("dodge")) 
		{
			me->add("skill_pro/桃花岛/玉萧剑法/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/桃花岛/玉萧剑法/dodge"));
			if(me->query("skill_pro/桃花岛/玉萧剑法/dodge_point")>=level_point)
			{
				me->add("skill_pro/桃花岛/玉萧剑法/dodge",1);
				me->set("skill_pro/桃花岛/玉萧剑法/dodge_point",1);
				tell_object(me,"\n$HIR你的玉萧剑法使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/桃花岛/玉萧剑法/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/桃花岛/玉萧剑法/damage"));
			if(me->query("skill_pro/桃花岛/玉萧剑法/damage_point")>=level_point)
			{
				me->add("skill_pro/桃花岛/玉萧剑法/damage",1);
				me->set("skill_pro/桃花岛/玉萧剑法/damage_point",1);
				tell_object(me,"\n$HIR你的玉萧剑法威力更大了。\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{
	if ( me->query("max_mp") < 500)
		return notify_fail("你的内力不够。");
	if ( me->query_skill("bibo_shengong", 1) < 150)
		return notify_fail("你的碧波神功火候太浅。");
	if ( me->query_skill("luoying_shenjian", 1) < 100)
		return notify_fail("你的落英神剑火候太浅。");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	if ( me->query("hp") < 50)
		return notify_fail("你的体力不够练玉萧剑法。");
	me->receive_damage("hp", 30);
	return 1;
	
}

//perform 
static int do_hua(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target	||	!me->is_fighting(target) )
		return notify_fail("「势合形离」只能对战斗中的对手使用。");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "yuxiao_jianfa"))
		return notify_fail("必须配合玉萧剑法使用。");
	
	if(  me->query_skill("yuxiao_jianfa", 1) < 60 )
		return notify_fail("你的玉萧剑法极不够娴熟，不会使用「漫天花雨」。");
	
	if(  me->query_skill("bibo_shengong", 1) < 100 )
		return notify_fail("你的碧波神功不够娴熟，不会使用「漫天花雨」。");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if( me->query("mp") < 100)		//add by Lanwood 2000-12-26
		return notify_fail("你的内力不足。");
	
	msg =  "$N手腕一抖，一式「势合形离」，泛出数朵剑花连续递出。\n";
		
	if( random(me->query_combat_exp()) >  target->query_combat_exp()/3 )
	{
		if(target->query_temp("apply/no_势合形离")&& (!random(2)||target->query("bigboss")))
		{
			msg += "可是$p看破了$P的企图，并没有上当。";
		}
		else
		{
			msg +=   " 结果$p被$P攻了个措手不及！"  ;
			int attack_time = random( me->query_skill("yuxiao_jianfa", 1) / 30);
			if(attack_time < 1)
				attack_time = 1;
		
			for(int	i = 0; i < attack_time; i++)
				g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
		
			me->start_busy(random(2));
			me->add("mp", -100);
		}
	}
	else
	{
		msg += "可是$p看破了$P的企图，并没有上当。"  ;
		me->start_busy(random(3));
		me->add("mp", -50);				//add by lanwood 2000-12-26
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;




