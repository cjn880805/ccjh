// yunlong_bian.c 云龙鞭法

SKILL_BEGIN(CSyunlong_bian);

virtual void create()
{
	set_name( "云龙鞭法");

	
	Magic_t * magic;

	magic = add_magic("chan", do_chan);
	magic->name = "缠字诀";
	magic->mp = 50;
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
		{"$N单手一扬，一招「开天辟地」，手中$w抖得笔直，对准$n当头罩下", 100, 10, 10, 0,},
		{"$N身形一转，一招「龙腾四海」，手中$w如矫龙般腾空一卷，猛地击向$n太阳穴", 150, 10, 20, 10,},
		{"$N唰的一抖长鞭，一招「矫龙出水」，手中$w抖得笔直，刺向$n双眼", 200, 30, 30, 20,},
		{"$N力贯鞭梢，一招「破云见日」，手中$w舞出满天鞭影，排山倒海般扫向$n全身", 200, 40, 40, 30,},
		{"$N运气于腕，一招「开山裂石」，手中$w向一根铜棍般直击向$n", 250, 50, 50, 40,},
		{"$N单臂一挥，一招「玉带围腰」，手中$w直击向$n腰肋", 300, -20, 60, 50,},
		{"$N高高跃起，一招「大漠孤烟」，手中$w笔直向$n当头罩下", 350, -50, 70, 60,},
	};

	int level = me->query_skill("yunlong_bian", 1);

	for(int i=7; i>0; i--)
	{
		if(action[i - 1].lvl < level)
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

	if( me->query("max_mp") < 200 )
		return notify_fail("你的内力不足，没有办法练云龙鞭法, 多练些内力再来吧。");

	if (me->query_skill("force", 1) < 40)
		return notify_fail("你的基本内功火候太浅。");
	
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
		return notify_fail("你的体力不够练云龙鞭法。");
	me->receive_damage("hp", 5);
	return 1;
}

//perform 
static int do_chan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( ! target ||	! me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。");

	if( me->query_skill("yunlong_bian",1) < 50)
		return notify_fail("你的「云龙鞭法」功力太浅，使不了「缠」字诀！");

	if( me->query("mp") < 50)	//add by Lanwood 2000-12-25
		return notify_fail("你的内力不足。");

	msg = "$N使出云龙鞭法「缠」字诀，连挥长鞭企图把$n的全身缠住。\n";
	
	if( random(me->query_combat_exp()) > target->query_combat_exp()/4 )
	{
		msg += "结果$p被$P攻了个措手不及。";
		target->start_busy( me->query_skill("yunlong_bian") / 30 + 1);
		me->start_busy(1+ random(2));
	} 
	else 
	{
		msg += "可是$p看破了$P的企图，并没有上当。" ;
		me->start_busy(4);
	}

	me->add("mp", -50);
	message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
