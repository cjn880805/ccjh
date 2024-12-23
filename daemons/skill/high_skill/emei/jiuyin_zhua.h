// jiuyin_zhua.h 九阴白骨爪
//code by Fisho
//date : 2000-12-02

/*
	技能配置有BUG。修改。
	lanwood 2001-04-29
*/

SKILL_BEGIN(CSjiuyin_zhua);

virtual void create()
{
	set_name("九阴白骨爪");

	Magic_t * magic;

	magic = add_magic("zhua", do_zhua);
	magic->name = "亡魂一击";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge, damage;
		char damage_type[5];
		int  lvl;
	}action[] = {
		{"$N身形微晃，一招「相思深入骨」，十指如戟，插向$n的双肩锁骨", 
		200,10 , 0, "内伤", 0,},
		{"$N出手如风，十指微微抖动，一招「素手裂红裳」抓向$n的前胸",
		220, 20, 0, "内伤", 10,},
		{"$N双手忽隐忽现，一招「铁指破残阳」，鬼魅般地抓向$n的肩头",
		250, 30, 0, "内伤", 20,},
		{"$N左手当胸画弧，右手疾出，一招「明月当空照」，猛地抓向$n的额头", 
		290, 25, 0, "内伤", 31,},
		{"$N使一招「阴气动四方」，激起漫天的劲风，撞向$n", 
		340,40, 0, "内伤", 43,},
		{"$N突然双手平举，$n一呆，正在猜测间，便见$N嗖的一下将双手收回胸前，接着一招「森然见白骨」，五指如钩，直抓向$n的腰间", 
		400, 35, 0, "内伤", 56,},
		{"$N使出「阴魂仍不散」，蓦然游身而上，绕着$n疾转数圈，$n正眼花缭乱间，$N已悄然停在$n身后，右手划出一道光圈，接着右手冲出光圈猛抓$n的后背",
		430, 20,20,"内伤",71 ,},
		{"$N面无表情，双臂忽左忽右地疾挥，使出「九阴搜魂手」，十指忽伸忽缩，迅猛无比地袭向$n全身各处大穴", 
		460, 5, 30,"内伤", 87,},
		{"$N左手轻挥，荡起阵阵阴风，一道青光闪过，$N的右手已变成青白色，接着集中精神施展出「爪现鬼神亡」祭出九道爪影击向$n的头顶", 
		520, 10, 20,"内伤", 110,},
	};
	
	int level = 0;
	
	for(int i=9; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("jiuyin_zhua", 1))
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

virtual int valid_enable(string usage) 
{ 
   return usage == "claw" || usage == "unarmed" || usage == "parry";
}

virtual int valid_combine(string combo) { return combo=="xianglong_zhang"; }
virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");

	if ( me->query_weapon())
		return notify_fail("练九阴白骨爪必须空手。");
	
    if (me->query_skill("force", 1) < 50)
		return notify_fail("你的内功心法火候不够，练九阴白骨爪会走火入魔。");
		if (me->query("max_mp") < 300)
			return notify_fail("你的内力太弱，无法练九阴白骨爪。");
		return 1;
}

virtual int practice_skill(CChar * me)
{
    if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
    if (me->query("mp") < 8)
		return notify_fail("你的内力不够练九阴白骨爪。");
    if (me->query_skill("jiuyin_zhua", 1) < 60)
		me->receive_damage("hp", 15);
    else
		me->receive_damage("hp", 30);
    me->add("mp", -5);
    return 1;
}
virtual char * hit_ob(CChar *me, CChar *victim, LONG &damage)
{
    if( random(me->query_skill("jiuyin_zhua",1)) > 50) 
	{
		victim->apply_condition("jy_poison", random(2)+1+victim->query("condition/jy_poison"));
    }

	return 0;
}

//perform 
static int do_zhua(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("「亡魂一击」只能对战斗中的对手使用。");
	
    if( me->query("repute") > 0)
        return notify_fail("你是侠义道人士，怎麽能「亡魂一击」这种阴毒武功。");
	
    if( me->query_skill("jiuyin_zhua", 1) < 85 )
        return notify_fail("你的九阴白骨爪不够娴熟，还使不出「亡魂一击」。");
	
    if( me->query_skill("force", 1) < 85 )
        return notify_fail("你的内功心法火候不够，使用「亡魂一击」会震伤自己的经脉。");

	if(me->query("mp") < 300)
		return notify_fail("你的内力不足。");
	
    msg = "$N突然将双掌变爪合于胸前，然后象风车般急转数圈，而后施展出「亡魂一击」，双爪向外一翻，随后绕着$n疾转数圈，又回到原地。\n";

	if(target->query_temp("apply/no_亡魂一击") && !random(3))
	{
		msg += "可是$p看破了$P的企图，闪身护头躲在了一边。";
	}

    else if (random(me->query_skill("force") + 1) > target->query_skill("force")/2||
        random(me->query_combat_exp() + 1) > target->query_combat_exp()/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
		
        int damage = me->query_skill("jiuyin_zhua", 1);
		
		damage = damage + random(damage);
		
        target->receive_damage("hp", damage/2);
        target->receive_wound("hp", damage/4);
        me->add("mp", -damage/3);
		
		msg += "原来$N已在$n头顶留下了五个整整齐齐的指洞！$n只觉得头顶一阵麻痒，就软软地歪在一边了。厉害！！！";
    } 
	else
    {
        me->start_busy(4);
        msg += "可是$p看破了$P的企图，闪身护头躲在了一边。";
    }
    message_vision(msg.c_str(), me, target);
	
    //if(userp(target)) target->kill_ob(me);
    //else
	
	if( !target->is_killing(me) ) target->kill_ob(me);

    return 1;
	
}

SKILL_END;




