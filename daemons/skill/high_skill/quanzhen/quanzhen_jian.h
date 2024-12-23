
// quanzhen_jian.h 全真剑法
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSquanzhen_jian);

virtual void create()
{
	set_name( "全真剑");
	
	set("diff",120);
	Magic_t * magic;

	magic = add_magic("ding", do_ding);
	magic->name = "定阳针";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("flood", do_flood);
	magic->name = "沧澜一剑";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xiantian_gong") || EQUALSTR(arg, "xiantian_qigong"))
		return 1;

	return notify_fail("全真剑必须与先天功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N使一式「探海屠龙」，手中$w由左至右横扫向向$n的$l",120 , 0, 30, 0,"割伤",},
		{"$N踏上一步，「罡风扫叶」，手中$w盘旋飞舞出一道剑光劈向$n的$l", 140, 10, 40, 9,"割伤",},
		{"$N手中$w一抖，一招「顺水推舟」，斜斜一剑反腕撩出，攻向$n的$l", 160, 5, 50, 18,"割伤",},
		{"$N手中$w连绕数个大圈，一式「星弛电闪」，一道剑光飞向$n的$l", 180, 10, 65,27 ,"刺伤",},
		{"$N一式「白鹤亮翅」，左手伸展，右手$w挥向$n的$l", 220, 15, 80, 36,"割伤",},
		{"$N手中$w斜指苍天，一式「横行漠北」，对准$n的$l斜斜击出", 260, 5, 100, 44,"刺伤",},
		{"$N一式「马蹴落花」，手腕急抖，挥洒出万点金光，刺向$n的$l", 320, 5, 105, 52,"刺伤",},
		{"$N一式「九品莲台」，$w飞斩盘旋，如疾电般射向$n的胸口", 380, 5, 125, 60,"刺伤",},
		{"$N使一式「荆轲刺秦」，手中$w合身疾刺$n的胸口，威不可当", 380, 5, 125, 70,"刺伤",},
		{"$N手中$w划出一道长长的弧线，刺向$n的$l，却是一招「箫史乘龙」", 380, 5, 140, 80,"刺伤",},
		{"$N回剑自守，使一式「深藏若虚」，蓦地手中$w向$n击出", 380, 5, 140, 90,"刺伤",},
		{"$N左足踢起，一式「魁星踢斗」，$w从不可思议的角度刺向$n", 380, 5, 140, 114,"刺伤",},
		{"$N一式「紫电穿云」，$w突然从天而降，一片金光围掠$n全身", 380, 5, 155, 129,"刺伤",},
	};
	
	int level = 0;
	
	for(int i=13; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("quanzhen_jian", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/			m_actions.set("force", (me->query("skill_pro/全真派/全真剑/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/全真派/全真剑/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/全真派/全真剑/damage")+100) * action[level].damage/100);

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
		if(victim->query("force")) 
		{
			me->add("skill_pro/全真派/全真剑/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/全真派/全真剑/force"));
			if(me->query("skill_pro/全真派/全真剑/force_point")>=level_point)
			{
				me->add("skill_pro/全真派/全真剑/force",1);
				me->set("skill_pro/全真派/全真剑/force_point",1);
				tell_object(me,"\n$HIR你的全真剑配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/全真派/全真剑/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/全真派/全真剑/dodge"));
			if(me->query("skill_pro/全真派/全真剑/dodge_point")>=level_point)
			{
				me->add("skill_pro/全真派/全真剑/dodge",1);
				me->set("skill_pro/全真派/全真剑/dodge_point",1);
				tell_object(me,"\n$HIR你的全真剑使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/全真派/全真剑/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/全真派/全真剑/damage"));
			if(me->query("skill_pro/全真派/全真剑/damage_point")>=level_point)
			{
				me->add("skill_pro/全真派/全真剑/damage",1);
				me->set("skill_pro/全真派/全真剑/damage_point",1);
				tell_object(me,"\n$HIR你的全真剑威力更大了。\n");
			}
		}
	}
	return "";
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if ( me->query_skill("yunv_xinfa", 1) < 15 &&
		me->query_skill("xiantian_qigong", 1) < 15)
		return notify_fail("你的内功心法火候不到，无法学习全真剑法。");
	
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
        ||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	if ( me->query("hp") < 50)
		return notify_fail("你的体力不够练全真剑法。");
	me->receive_damage("hp", 25);
	return 1;
	
}

//perform 
static int do_ding(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("定阳针只能对战斗中的对手使用。");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
    if(  me->query_skill("quanzhen_jian", 1) < 40 )
		return notify_fail("你的全真剑法不够娴熟，不能使用定阳针。");
	
    if(  me->query_skill("xiantian_qigong", 1) < 40 &&
		me->query_skill("yunv_xinfa", 1) < 40 )
		return notify_fail("你的本门内功不够娴熟，不能使用定阳针。");

	if(DIFFERSTR(me->querystr("family/family_name"), "全真教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if(  me->query("mp" ) < 150 )
		return notify_fail("你现在内力太弱，不能使用定阳针。");
	
    msg =   "$N脚下左弓右箭，神气完足如雷霆五岳，一式「定阳针」斜斜刺出。\n" ;
	
    if (random(me->query_skill("force")) > target->query_skill("force")/2 )
    {
		me->start_busy(2);
		
		int damage =  me->query_skill("quanzhen_jian", 1) +  me->query_skill("force",1);
		//(全真剑法级别+基本内功)
		
		damage = damage/2 + random(damage/2);
		
		target->receive_damage("hp", damage);
		if(EQUALSTR(me->querystr("family/family_name"), "全真教") && !target->query_temp("ding"))
		{
			target->set_temp("ding", 1);
			target->add_temp("apply/attack", -damage/3);
			target->add_temp("apply/dodge", -damage/3);
			target->call_out( remove_effect, damage/3, damage/3);
			target->SendState(target);
		}
		target->start_busy(4+me->query_skill("quanzhen_jian", 1)/100);
		me->add("mp", -100);
		
		msg +=  "$n看到$N这气拔千钧的一击，竟不知如何招架！" ;
    }
    else
    {
		me->start_busy(3);
		msg +=  "可是$p看破了$P的企图，斜跃避开。" ;
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

static void remove_effect(CContainer *ob,LONG amount,LONG param)
{
	CChar * target=(CChar *)ob;
	target->add_temp("apply/attack", amount);
	target->add_temp("apply/dodge", amount);
	target->delete_temp("ding");
	target->SendState(target);
	message_vision("$HIR$N从猛烈的攻击中摆脱了出来，连退数步,稳住了脚步", target);

}

static int do_flood(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !me->query("teapot/canglang") )
		return notify_fail("你尚未领悟全真剑法至上绝学，如何能化气归元，使出沧澜一剑？");

    if( !target || !me->is_fighting(target) )
		return notify_fail("沧澜一剑只能对战斗中的对手使用。");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
    if(  me->query_skill("quanzhen_jian", 1) < 200 )
		return notify_fail("你的全真剑法不够娴熟，不能使用沧澜一剑。");

	if(DIFFERSTR(me->querystr("family/family_name"), "全真教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if(  me->query_skill("xiantian_qigong", 1) < 200 )
		return notify_fail("你的本门内功不够娴熟，不能使用沧澜一剑。");
	
    if(  me->query("mp" ) < 3500 )
		return notify_fail("你现在内力太弱，不能使用沧澜一剑。");

	if(  me->query("repute" ) < 1000000 )
		return notify_fail("你现在正气太弱，不能使用沧澜一剑。");
	
	me->add("mp", -3500);
	
    if (random(me->query("repute")) > target->query("repute"))
    {
		int damage =  me->query_skill("sword") +  me->query_skill("force");
		damage=damage*4;
		damage = damage + random(damage);
		damage=damage*2/3;
		target->receive_damage("hp", damage);
		snprintf(msg, 255, "$N化气入心，意收丹田，形定如山，神光内敛，突的开声破气，一剑带至罡无上的先天正气浑然而出！\n剑气一如沧澜飞升，狂涛倾泻，全数击在$n身上！ \n 结果造成%d点伤害！",damage);
    }
    else
    {
		snprintf(msg, 255, "$N化气入心，意收丹田，形定如山，神光内敛，突的开声破气，一剑带至罡无上的先天正气浑然而出！\n 结果$n奋然大喝，以无双正气化为虚墙，封住沧澜一剑！");
    }
	me->start_busy(6);
    message_vision(msg, me, target);
    return 1;
}


SKILL_END;
//山水之气莫人可抵挡
//观沧海 
//曹操
//东临碣石，以观沧海。水何澹澹，山岛竦峙。树木丛生，百草丰茂。秋风萧瑟，洪波涌起。
//日月之行，若出其中。星汉灿烂，若出其里。幸甚至哉，歌以咏志