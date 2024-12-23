//feixing_shu.h 飞星术
SKILL_BEGIN(CSfeixing_shu);

virtual void create()
{
	set_name("飞星术");
	
	Magic_t * magic;
        set("valid_force", "huagong_dafa");
	magic = add_magic("huayu", do_huayu);
	magic->name = "星殒西天";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	static struct {
		char action[255];
		int damage, dodge;
		int lvl;
	}action[13] = {
		{ "$N轻身而退，一招『初露星芒』，手中$w化作一点寒芒射向$n",
			230, -20, 0,},
		{ "$N右手微向前一伸，使出『乍见星辰』，手里$w径直射向$n的双眼",
		240, -95, 9,},
		{ "$N一声轻啸，施展出『寒夜孤星』，身形微动，手中$w竟然向上飞起绕了个圈，随而迅速袭向$n的腰间",
		250, -90, 18,},
		{ "$N使一招『星光闪烁』，突然纵身向后一个翻滚，就在快落地的一瞬间，$n陡然发现几点寒光闪烁不定地袭向自己",
		255, -85, 27,},
		{ "$N右手一挥，一招『星芒不定』，$n明明看见$N手里的$w已射向自己的胸前大穴，到了近处却突然转攻向自己的后心",
		260, -80, 36,},
		{ "$N不急不缓地一矮身，使出『坠落之星』，手中$w平直地射向$n的咽喉，却又加上暗劲使之中途改向，射向$n的下盘",
		270, -70, 45,},
		{ "$N腾身一跃而起，施展出『黎明之星』，手里的$w从上往下笔直地射向$n的头部",
		285, -60, 54, },
		{"$N原地一个急转身，随即双手一拂，$w就飘飘忽忽地飞向$n，原来这招是『星辰游离』",
		290, -55, 63, },
		{"$N使出一招『星光顿灭』，前脚一跺，随即翻身而起，手中$w不带丝毫风声却又迅速无比地射向$n的前胸",
		320, -45,72, },
		{"$N突然腾身向后急退，使出『星空炸雷』，双手向前一推，手里$w就隐隐带着雷声疾射向$n",
		340, -40, 81,},
		{"$N施展出『星划长空』，原地侧身飞起，右手微微向前一洒，手中$w幻作一点寒光呈圆弧形射向$n",
		360, 30, 90},
		{"$N微微凝神，使出『星光万丈』，身影飘忽不定，$n顿觉十分刺眼，却见$N手里的$w已挟着地上的沙石以及周围的树页攻向自己",
		390, -25, 99},
		{"$N忽然轻叹一声，转身而行，$n正迟疑间，却见眼前已尽是$w的影子，眼看无处可躲了！只怕这招就是『满天星雨』了，$n不由大惊失色",
		420, -20, 110,}};
		
		int level = me->query_skill("feixing_shu", 1);
		
		for(int i = 13; i > 0; i--)
			if(level > action[i-1].lvl)
			{
				level = random(i);
				m_actions.set("action", action[level].action);
				m_actions.set("damage", action[level].damage);
				m_actions.set("dodge", action[level].dodge);
				
				break;		
			}
			
			return & m_actions;
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[8][80] = {
		{"$n左一点右一晃，随即回到原地，轻巧地躲过了$N这一招。",},
		{"$n腾身跃起一个空翻，并顺势闪到一边。",},
		{"$n轻轻往旁边一纵，就已离$N有了相当的距离，$N这一招自然失效。",},
		{"$n揉身而上，轻灵地跃过$N，闪到了$N的背后。",},
		{"$n身形急闪，斜向前一步，竟然已经躲开了$N的这一招。",},
		{"$N眼前一花，却见$n竟然已离自己有数丈之远，却没见$n如何躲过自己的攻击的",},
		{"$N一个不留神，$n已没了踪影。$N急转身，却见$n在那儿向自己招手。",},
		{"$N一招攻出，$n已然不见，$N茫然四顾，却不见$n的影子！",},
	};
	
	return dodge_msg[random(8)];
}

virtual int practice_skill(CChar * me)
{
	CContainer *  weapon;
    if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "throwing"))
		return notify_fail("你使用的武器不对。");
	
    if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
    if (me->query("mp") < 30)
		return notify_fail("你的内力不够练飞星术。");
    me->receive_damage("hp", 30);
	
    return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("force", 1) < 20)
		return notify_fail("你的内功心法火候不够，无法学飞星术。");
	if (me->query_skill("dodge", 1) < 20)
		return notify_fail("你的轻功火候不够，无法领悟飞星术。");
    if (me->query_dex() < 25)
		return notify_fail("你的身法不够灵巧，无法领悟飞星术。");
    return 1;
}

virtual int valid_enable(string usage) { return usage=="throwing" ||usage=="dodge"||usage=="parry";}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( random(me->query_skill("poison",1)) > 100)
    {
		victim->apply_condition("xx_poison", random(50) + 1 +
			victim->query("condition/xx_poison"));
    }
	
	return "";
}

static int do_huayu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
    CContainer * weapon;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
    if( !target || ! me->is_fighting(target) )
        return notify_fail("星殒西天只能在战斗中对对手使用。");
	
    if (! (weapon = me->query_weapon()) )
		return notify_fail("你没有装备武器。");
	
    if( me->query_skill("feixing_shu", 1) < 150 )
        return notify_fail("你的飞星术不够娴熟，不会使用星殒西天。");
    if( me->query_skill("huagong_dafa", 1) < 100 )
        return notify_fail("你的化功大法不够娴熟，不能使用星殒西天。");

	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if( me->query("mp") < 200 )
        return notify_fail("你内力不够，不能使出星殒西天。");
	
	if(weapon->query("no_duo"))
		return notify_fail("如此宝贝，%s怎么舍得呢？",me->name());
	
    int skill = me->query_skill("feixing_shu", 1);
	
    me->add("mp", -100);
    target->receive_damage("hp", skill/ 3);
	
    msg = "只见一道刺目的绿光从$N的右侧发出，$N手中的";
	msg += weapon->name();
	msg += "如流星般向$n飞射过去！";
	
    me->start_busy(1);
	if( random( me->query_skill("dodge", 1))
		> random(target->query_skill("dodge") - 1) ) 
	{
		msg += "$HIR结果$p被$P的绝招打中了要害部位，痛得倒在地上大声惨呼。";
		target->receive_wound("hp", random(skill) * 3);
		target->start_busy( me->query_skill("feixing_shu", 1) / 20 + 2);
        target->apply_condition("xx_poison", random(me->query_skill("poison",1)/3) + 1 +
			target->query("condition/xx_poison"));
	} 
	else 
	{
		msg += "可是$p躲过了$P的最后一击。";
	}
		
	message_vision(msg.c_str(), me, target);
		
	//use out all throwing
	weapon->move(me->environment());
	return 1;
}

SKILL_END;



