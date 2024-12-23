
// huagu_mianzhang.h 化骨绵掌
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CShuagu_mianzhang);

virtual void create()
{
	set_name( "化骨绵掌");
	
	Magic_t * magic;

	magic = add_magic("hua", do_hua);
	magic->name = "辣手化骨";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N身形微晃，一招「长恨深入骨」，十指如戟，插向$n的双肩锁骨", 200, 10, 0, "内伤",},		
		{"$N出手如风，十指微微抖动，一招「素手裂红裳」抓向$n的前胸",220 ,20 , 20, "内伤",},		
		{"$N双手忽隐忽现，一招「长风吹落尘」，鬼魅般地抓向$n的肩头", 250,30 , 40, "内伤",},		
		{"$N左手当胸画弧，右手疾出，一招「明月映流沙」，猛地抓向$n的额头", 290, 25, 60, "内伤",},		
		{"$N使一招「森然动四方」，激起漫天的劲风，撞向$n", 340, 40, 80, "内伤",},		
		{"$N面无表情，双臂忽左忽右地疾挥，使出「黯黯侵骨寒」，十指忽伸忽缩，迅猛无比地袭向$n全身各处大穴", 460, 30, 100, "内伤",},		
		{"$N使出「黄沙飘惊雨」，蓦然游身而上，绕着$n疾转数圈，$n正眼花缭乱间，$N已悄然停在$n身后，右手划出一道光圈，接着右手冲出光圈猛抓$n的后背", 430, 20, 120, "内伤",},		
		{"$N突然双手平举，$n一呆，正在猜测间，便见$N嗖的一下将双手收回胸前，接着一招「白骨无限寒」，五指如钩，直抓向$n的腰间", 400, 35, 140, "内伤",},		
	};
 
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		level++;
		if(action[i - 1].lvl < me->query_skill("huagu_mianzhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "strike") || (usage == "parry");
}

virtual int valid_combine(string combo) { return combo=="shenlong_bashi"; }

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail("练化骨绵掌必须空手。");
	if (2* me->query_skill("shenlong_xinfa",1) < me->query_skill("shenlong_bashi",1))
		return notify_fail("你的神龙心法火候不够，无法继续学化骨绵掌。");
    if ( me->query_skill("force", 1) < 50)
		return notify_fail("你的内功心法火候不够，练化骨绵掌会走火入魔。");
    if ( me->query("max_mp") < 300)
		return notify_fail("你的内力太弱，无法练化骨绵掌。");
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("hp") < 30)
        return notify_fail("你的体力太低了。");
    if ( me->query("mp") < 8)
        return notify_fail("你的内力不够练化骨绵掌。");
    if (me->query_skill("huagu_mianzhang", 1) < 60)
        me->receive_damage("hp", 15);
    else
		me->receive_damage("hp", 30);
    me->add("mp", -5);
    return 1;
	
}

virtual char * hit_ob(CChar * me, CChar *victim, LONG &damage)
{
    if( random(me->query_skill("huagu_mianzhang",1)) > 50) 
	{
		victim->receive_damage("hp", random(2) + 1);
    }
	return "";
}


//perform 
static int do_hua(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( (me->environment())->query("no_fight") )
		return notify_fail("这里不能攻击别人! ");
	
	if( !target || ! me->is_fighting(target) )
		return notify_fail("辣手化骨只能对对手使用。");
	
	if(  me->query_skill("shenlong_xinfa", 1) < 50 )
		return notify_fail("你的神龙心法不够娴熟，不能化骨。");
	
	if(  me->query_skill("huagu_mianzhang", 1) < 40 )
		return notify_fail("你的化骨绵掌不够娴熟，不能化骨。");

	if(DIFFERSTR(me->querystr("family/family_name"), "神龙教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if(  me->query("mp") < 300 )
		return notify_fail("你的内力不够，不能化骨。");
	
    me->add("mp", -100);
	
	msg =   "$N掌出如风轻轻落在$n肩头上。\n" ;
	
	me->start_busy(1);
	if( random(  me->query_skill("huagu_mianzhang",1))
		> random(target->query_skill("dodge"))+1 )
    {
		msg +=   "结果只听扑的一声，$p被$P一掌拍中！"  ;
		msg +=   "$p只觉得全身暖洋洋的，感到有点轻飘无力轻。"  ;
		target->add_temp("apply/attack", -3);
		target->add_temp("apply/dodge", -3);
		target->add_temp("apply/defense", -3);
	}
	else 
	{
		msg +=  "可是$p急忙闪在一旁，躲了开去。"  ;
		me->start_busy(3);
	}
	message_vision(msg.c_str(), me, target);
	//if( !target->is_fighting(me) ) target->kill_ob(me);
	return 1;
}

SKILL_END;
