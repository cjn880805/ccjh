//mantian_xing.h 满天星

SKILL_BEGIN(CSmantian_xing);

virtual void create()
{
	set_name( "满天星");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, dodge, lvl;
	}action[13] = {
			{"$N轻身而退，一招『初露星芒』，手中$w化作一点寒芒射向$n",
			   30, 40, 0,},
		   {"$N右手微向前一伸，使出『乍见星辰』，手里$w径直射向$n的双眼",
		   40, 45, 9,},
		   {"$N一声轻啸，施展出『寒夜孤星』，身形微动，手中$w竟然向上飞起绕了个圈，随而迅速袭向$n的腰间",
		   50, 50, 18,},
		   {"$N使一招『星光闪烁』，突然纵身向后一个翻滚，就在快落地的一瞬间，$n陡然发现几点寒光闪烁不定地袭向自己",
		   55, 55, 27,},
		   { "$N右手一挥，一招『星芒不定』，$n明明看见$N手里的$w已射向自己的胸前大穴，到了近处却突然转攻向自己的后心",
		   60, 60, 36,},
		   {"$N不急不缓地一矮身，使出『坠落之星』，手中$w平直地射向$n的咽喉，却又加上暗劲使之中途改向，射向$n的下盘",
		   70, 70, 45,},
		   {"$N腾身一跃而起，施展出『黎明之星』，手里的$w从上往下笔直地射向$n的头部",
		   85, 80, 54,},
		   {"$N原地一个急转身，随即双手一拂，$w就飘飘忽忽地飞向$n，原来这招是『星辰游离』",
		   110, 85, 63,},
		   {"$N使出一招『星光顿灭』，前脚一跺，随即翻身而起，手中$w不带丝毫风声却又迅速无比地射向$n的前胸",
		   120, 90, 72,},
		   {"$N突然腾身向后急退，使出『星空炸雷』，双手向前一推，手里$w就隐隐带着雷声疾射向$n",
		   140, 95, 81,},
		   {"$N施展出『星划长空』，原地侧身飞起，右手微微向前一洒，手中$w幻作一点寒光呈圆弧形射向$n",
		   160, 100, 90,},
		   {"$N微微凝神，使出『星光万丈』，身影飘忽不定，$n顿觉十分刺眼，却见$N手里的$w已挟着地上的沙石以及周围的树页攻向自己",
		   190, 105, 99,},
		   {"$N忽然轻叹一声，转身而行，$n正迟疑间，却见眼前已尽是$w的影子，眼看无处可躲了！只怕这招就是『满天星雨』了，$n不由大惊失色",
		   220, 110, 110,},
		};
 
  	int level = me->query_skill("mantian_xing", 1);
	for(int i = 13; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="throwing" ||usage=="dodge"||usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("force", 1) < 20)
		return notify_fail("你的内功心法火候不够，无法学满天星。");
    if (me->query_skill("dodge", 1) < 20)
		return notify_fail("你的轻功火候不够，无法领悟满天星。");
    if (me->query_dex() < 25)
		return notify_fail("你的身法不够灵巧，无法领悟满天星。");

    return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

    if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "throwing"))
		return notify_fail("你使用的武器不对。");
    if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
    if (me->query("mp") < 30)
		return notify_fail("你的内力不够练满天星。");
    
	me->receive_damage("hp", 30);
	return 1;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( random(me->query_skill("mantian_xing",1)) > 50) 
	{
		victim->apply_condition("anqi_poison", random(2) + 1 +
			victim->query_condition("anqi_poison"));
    }
	return "";
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[8][80]={	
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


SKILL_END;

