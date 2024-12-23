// wudu_shenzhang.h 五毒神掌
SKILL_BEGIN(CSwudu_shenzhang);

virtual void create()
{
	set_name( "五毒神掌");

	Magic_t * magic;

	magic = add_magic("jiedu", do_jiedu);
	magic->name = "解毒术";
	magic->mp = 300;
	magic->target = CAST_TO_RANDOM;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int dodge, force;
	}action[] = {
			{"$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l",
			30, 210,},
			{"$N突然身形旋扑向$n，双掌飞舞拍向$n的$l",
			10, 210,},
			{"$N将毒质运至右手，阴毒无比地抓向$n的$l",
			-20, 210,},
			{"$N双掌如风,连环拍向$n的$l",
			10, 210,}
	};

	int level = random(4);
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", me->query_skill("wudu_shenzhang",1)/2 );

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }


virtual int valid_learn(CChar * me)
{
	if( DIFFERSTR(me->querystr("family/family_name"), "古墓派"))
		return notify_fail("只有古墓派弟子方可学习。");
	if ( me->query_weapon() )
		return notify_fail("练五毒神掌必须空手。");
	if (me->query_skill("wudu_xinfa", 1) < 10)
		return notify_fail("你的五毒心法火候不够，无法练五毒毒掌。");
	if (me->query("max_mp") < 60)
		return notify_fail("你的内力太弱，无法练五毒神掌");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if( DIFFERSTR(me->querystr("family/family_name"), "古墓派"))
		return notify_fail("只有古墓派弟子方可练习。");
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 8)
		return notify_fail("你的内力不够练五毒神掌。");
	if (me->query_skill("wudu_shenzhang", 1) < 50)
		me->receive_damage("hp", 20);
	else
		me->receive_damage("hp", 30);
	me->add("mp", -5);
	return 1;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( damage < 100 )
	{
		damage = 0;
		return 0;
	}

     if( random(me->query_skill("wudu_xinfa")) > 150 &&  !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "古墓派")) )
	{
        victim->apply_condition("wuduz_poison", (me->query_skill("wudu_shenzhang")/10) + 1 +
            victim->query("condition/wuduz_poison"));
	}

	if( random(me->query_str()) > victim->query_str())  
	{
	//	victim->receive_wound("hp", (damage - 100) / 2 );
		victim->receive_wound("hp", (me->query_skill("wudu_xinfa", 1)/3+me->query_skill("wudu_shenzhang", 1)/3)*(random(10)+1)); //秦波 2002、1、15
		return "你听到「砰」一声巨响，$n像泄气的皮球缓缓的瘫倒！";
	}

	return 0;
}

static int do_jiedu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

    if( !ob || !ob->Query(CChar::IS_CHAR) )
		return notify_fail("你要给谁解毒。");

	target = (CChar *)ob;

    if( me->query_skill("wudu_xinfa", 1) < 40 )
        return notify_fail("你的五毒心法不够娴熟，不能解五毒神掌。");

    if( me->query_skill("wudu_shenzhang", 1) < 40 )
        return notify_fail("你的五毒神掌不够娴熟，不能解五毒神掌。");

	if(DIFFERSTR(me->querystr("family/family_name"), "古墓派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

    if( me->query("mp") < 300 )
        return notify_fail("你现在内力太弱，不能解毒。");
                
    if( target->query("condition/wuduz_poison") < 1)
		return notify_fail("没有中毒。");

    me->add("mp", -300);
    target->apply_condition("wuduz_poison", 0);
	if(me == target)
	{
		message_vision("$N使出五毒神掌之解毒术，给自己驱毒！", me);
	}
	else
	{
		target->SendState();
		message_vision("$N使出五毒神掌解毒的手法为$n推拿。接着给$n服下一粒解药.", me, target);
	}

    return 1;
}

SKILL_END;




