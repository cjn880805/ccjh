
// haotian_zhang.h 夺命金花
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CShaotian_zhang);

virtual void create()
{
	set_name( "昊天掌");

	set("diff",100);

	Magic_t * magic;

	magic = add_magic("ju", do_ju);
	magic->name = "三花聚顶";
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
		{"$N使一招「春江潮水」，双手划了个半圈，按向$n的$l", 100, 50, 5, 0,"内伤",},
		{"$N使一招「海上明月」，左手轻轻一挥，劈向$n的$l", 120, 48, 10,5 ,"内伤",},
		{"$N右手掌心向外，由右向左，使一招「滟滟随波」，向$n的$l打去", 140, 46, 15, 10,"内伤",},
		{"$N使一招「江流宛转」，分击$n的胸口和$l", 160, 44, 20,15 ,"内伤",},
		{"$N使一招「月照花林」，左右掌同时击出，在空中突然左右掌方向互变", 180, 42, 25, 20,"内伤",},
		{"$N左手不住晃动，右掌一招「空中流霜」，向$n的$l打去", 200, 40, 30, 25,"内伤",},
		{"$N左手变掌为啄，右掌立掌如刀，一招「汀上白沙」，劈向$n的$l", 220, 38, 35, 30,"内伤",},
		{"$N左脚退后半步，右掌使一招「江天一色」，横挥向$n", 240, 36, 40,35 ,"内伤",},
		{"$N一招「皎皎孤月」，左掌先发而后至，右掌后发而先至", 260, 34, 45, 40,"内伤",},
		{"$N双掌缩入袖中，双袖飞起扫向$n的$l，却是一招「长江流水」，仪态潇洒", 280, 32, 50, 45,"内伤",},
		{"$N左手虚按，右手划道弧线使一招「白云悠悠」，向$n的$l插去", 300, 30, 56, 50,"内伤",},
		{"$N双手变掌做拳，向前向后划弧，一招「青枫浦上」击向$n的$l", 320, 28, 62,55 ,"内伤",},
		{"$N左手虚划，右手变掌为钩一记「楼月蜚回」击向$n的$l", 340, 26, 68, 60,"内伤",},
		{"$N施出「玉户帘中」，右掌向外挥出，左掌同时攻向$n",360 , 24, 74, 65,"内伤",},
		{"$N由臂带手，在面前缓缓划过，使一招「鸿雁长飞」，挥向$n的$l", 380, 22, 81, 70,"内伤",},
		{"$N负身就地，右掌使一招「鱼龙潜跃」，自下而上向$n的$l击去", 400, 20, 88, 75,"内伤",},
		{"$N右手由钩变掌，双手掌心向上，右掌向前推出一招「月华流照」", 420, 18, 98, 80,"内伤",},
		{"$N右掌不住向外扫出，是一式「闲潭落花」，左掌旋转着向$n攻去", 440, 16, 110, 85,"内伤",},
		{"$N右手经腹前经左肋向前撇出，使一招「江水流春」，向$n的$l锤去", 460, 14, 120, 90,"内伤",},
		{"$N使一招「斜月沉沉」，左掌连划三个大圈，右掌从圈中穿出击向$n", 480, 12, 130, 95,"内伤",},
		{"$N左手向上划弧拦出，右手使一招「碣石潇湘」，手掌不住晃动，不离$n头顶方寸之间", 500, 10, 150, 100,"内伤",},
	};
	
	int level = 0;
	
	for(int i=21; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("haotian_zhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/
			m_actions.set("force", (me->query("skill_pro/全真派/昊天掌/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/全真派/昊天掌/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/全真派/昊天掌/damage")+100) * action[level].damage/100);
			
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
			me->add("skill_pro/全真派/昊天掌/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/全真派/昊天掌/force"));
			if(me->query("skill_pro/全真派/昊天掌/force_point")>=level_point)
			{
				me->add("skill_pro/全真派/昊天掌/force",1);
				me->set("skill_pro/全真派/昊天掌/force_point",1);
				tell_object(me,"\n$HIR你的昊天掌配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/全真派/昊天掌/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/全真派/昊天掌/dodge"));
			if(me->query("skill_pro/全真派/昊天掌/dodge_point")>=level_point)
			{
				me->add("skill_pro/全真派/昊天掌/dodge",1);
				me->set("skill_pro/全真派/昊天掌/dodge_point",1);
				tell_object(me,"\n$HIR你的昊天掌使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/全真派/昊天掌/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/全真派/昊天掌/damage"));
			if(me->query("skill_pro/全真派/昊天掌/damage_point")>=level_point)
			{
				me->add("skill_pro/全真派/昊天掌/damage",1);
				me->set("skill_pro/全真派/昊天掌/damage_point",1);
				tell_object(me,"\n$HIR你的昊天掌威力更大了。\n");
			}
		}
	}
	return "";
}

virtual int valid_combine(string combo) { return combo=="sun_finger"; }

virtual int valid_enable(string usage) 
{ 
	return (usage == "strike") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
		return notify_fail("练昊天掌必须空手。");
	if ( me->query_skill("xiantian_qigong", 1) < 10)
		return notify_fail("你的先天气功火候不够，无法学昊天掌。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ( me->query("mp") < 20)
		return notify_fail("你的内力不够练昊天掌。");
	me->receive_damage("hp", 25);
	me->add("mp", -10);
	return 1;
	
}

//perform 
static int do_ju(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("三花聚顶只能对战斗中的对手使用。");
	
    if(  me->query_skill("haotian_zhang", 1) < 50 )
		return notify_fail("你的昊天掌不够娴熟，不会使用三花聚顶。");

	if(DIFFERSTR(me->querystr("family/family_name"), "全真教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if (me->query_weapon()  )
		return notify_fail("你必须空手。");	

    if(  me->query_skill("xiantian_qigong", 1) < 50 )
		return notify_fail("你的先天功不够娴熟，不会使用三花聚顶。");
	
    if(  me->query("mp") < 150 )
		return notify_fail("你现在内力太弱，不能使用三花聚顶。");
	
    msg =   "$N大喝一声，合身向$n扑上，双掌同时击出，是一招「三花聚顶」。" ;
	
   // if( !target->is_fighting(me) ) target->kill_ob(me);
	
    if (random(me->query_skill("force")) > target->query_skill("force")/2 )
    {
		me->start_busy(1);
		
		int damage =  me->query_skill("haotian_zhang", 1) +  me->query_skill("force",1);
		//(昊天掌级别+基本内功)
		
		damage = damage/2 + random(damage/2) ;
		target->receive_damage("hp", damage);
		target->start_busy(3);
		me->add("mp", -100);
		msg +=  "结果$n被$N的气势所摄，一惊之下，竟然忘了抵挡！" ;
    }
    else
    {
		me->start_busy(3);
		msg +=  "可是$p识破了$P这一招，斜斜一跃避开。" ;
    }
    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
