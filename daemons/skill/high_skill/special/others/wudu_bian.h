// wudu-bian.c 五毒鞭法
SKILL_BEGIN(CSwudu_bian);

virtual void create()
{
	set_name( "五毒鞭法");

	Magic_t * magic;

	magic = add_magic("judu", do_judu);
	magic->name = "聚毒术";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[] = {
		{"$N轻抖手腕，一招「青蛇吐芯」，手中$w抖得笔直，直向$n卷去", 60, 30, 30, 0,},
		{"$N身形一转，一招「毒蝎反尾」，$w在空中转了个圈，以怪异的角度劈向$n", 150, -20, 50, 10,},
		{"$N一抖长鞭，一招「黑蛛吐丝」，手中$w化做无数幻影，罩向$n", 200, 30, 60, 20,},
		{"$N力贯鞭梢，一招「蟾蜍出洞」，手中$w忽左忽右，直劈向$n胸口", 300, 10, 80, 30,},
		{"$N运气于腕，一招「蜈蚣翻身」，手中$w转起无数个圈圈，带着一股阴风，直向$n扑去", 500, -20, 150, 40,},
	};


	int level = me->query_skill("wudu_bian", 1);

	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < level )
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="whip" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;

	if( me->query_skill("wudu_xinfa") < 30 )
		return notify_fail("你的五毒心法太低，不能练五毒鞭。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip"))
		return notify_fail("你必须先找一条鞭子才能练鞭法。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练五毒鞭法。");
	me->receive_damage("hp", 25);
	return 1;
}

static int do_judu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( me->query_skill("wudu_bian",1) < 60 
		||me->query_skill("wudu_xinfa",1) < 50 )
		return notify_fail("你的五毒心法功力太浅，无法聚毒！");

	if( !target ||! me->is_fighting(target) )
		return notify_fail("你只能对站斗中的对手聚毒。");

	if( target->is_busy() )
		return notify_fail("%s已经手忙脚乱了，不需要在用毒了。", target->name());

	if( me->query("mp") < 20)		//add by Lanwood 2000-12-25
		return notify_fail("你的内力不足。");

	me->start_busy(1);
	
	msg = "$N默运内力，将毒气运于鞭上，只见一股蓝色的雾气罩住了长鞭。";

	if  ( random(me->query_combat_exp() + 1) > target->query_combat_exp()/2 
	    && random(me->query_skill("wudu_xinfa",1)) >20) 
	{
		msg += "$n措不及防，不由身染毒气。";
		target->receive_damage("hp", me->query_skill("wudu_xinfa",1));
        target->receive_wound("hp",15 + random(10));
		target->apply_condition("wudu_poison", random(me->query_skill("wudu_xinfa",1)/10) + 1 +
						target->query("condition/wudu_poison"));
		target->start_busy(1 + random(2)); 
		
	}
	else
	{
		msg += "可是$n看出了$N的毒计，立刻屏住呼吸，没有中毒。";
	}

	me->add("mp", -20);

	message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;

