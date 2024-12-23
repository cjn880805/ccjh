// yunlong-jian.c 云龙剑
SKILL_BEGIN(CSyunlong_jian);

virtual void create()
{
	set_name( "云龙剑");

	Magic_t * magic;

	magic = add_magic("xian", do_xian);
	magic->name = "云龙三现";
	magic->mp = 300;
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
		{"$N使一式「悠悠顺自然」，手中$w嗡嗡微振，幻成一条白光刺向$n的$l", 120, -10, 15, 0,},
		{"$N错步上前，使出「来去若梦行」，剑意若有若无，$w淡淡地向$n的$l挥去", 140, -10, 20, 0,},
		{"$N一式「志当存高远」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l", 160, 5, 30, 15,},
		{"$N纵身轻轻跃起，一式「表里俱澄澈」，剑光如水，一泻千里，洒向$n全身", 180, 10, 35, 20,},
		{"$N手中$w中宫直进，一式「随风潜入夜」，无声无息地对准$n的$l刺出一剑", 220, 15, 40, 30,},

		{"$N手中$w一沉，一式「润物细无声」，无声无息地滑向$n的$l", 250, 15, 40, 40,},
		{"$N手中$w斜指苍天，剑芒吞吐，一式「云龙听梵音」，对准$n的$l斜斜击出", 280, 25, 45, 50,},
		{"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「万里一点红」刺向$n的咽喉", 320, 15, 55, 60,},
		{"$N合掌跌坐，一式「我心化云龙」，$w自怀中跃出，如疾电般射向$n的胸口", 380, 15, 60, 70,},
		{"$N呼的一声拔地而起，一式「日月与同辉」，$w幻出万道光影，将$n团团围住", 420, 15, 70, 80,},
		
		{"$N随风轻轻飘落，一式「清风知我意」，手中$w平指，缓缓拍向$n脸颊", 450, 15, 80, 90,},
		{"$N剑尖微颤作龙吟，一招「高处不胜寒」，切骨剑气如飓风般裹向$n全身", 500, 15, 90, 100,},
		{"$N募的使一招「红叶舞秋山」，顿时剑光中几朵血花洒向$n全身", 500, 25, 100, 110,},
	};

	int level = me->query_skill("yunlong_jian", 1);
	for(int i=13; i>0; i--)
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

virtual int valid_enable(string usage) { return usage=="sword" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 200)
		return notify_fail("你的内力不够。");
	if (me->query_skill("yunlong_xinfa", 1) < 20)
		return notify_fail("你的云龙心法火候太浅。");
	if (me->query_skill("force", 1) < 40)
		return notify_fail("你的基本内功火候太浅。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练云龙剑法。");
	me->receive_damage("hp", 30);
	return 1;
}

//perform 
static int do_xian(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("云龙三现只能对战斗中的对手使用。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");

	if( me->query_skill("yunlong_jian", 1) < 50 )
		return notify_fail("你的云龙剑法不够娴熟，不会使用「云龙三现」。");

	if( me->query_skill("yunlong_shengong", 1) < 50 )
		return notify_fail("你的云龙神功不够高，不能用来反震伤敌。");

	if( me->query("mp") < 300 )
		return notify_fail("你现在内力太弱，不能使用「云龙三现」。");

	msg = "$N微微一笑，猛吸一口气,欲使出以气驭剑绝技攻击$n。\n";
	
	if( random(me->query_skill("force")) > target->query_skill("force")/5 )
	{
		target->start_busy( random(me->query_skill("yunlong_jian", 1) / 30+1) );
		int damage = me->query_skill("yunlong_xinfa", 1);
		damage = damage +  me->query_skill("yunlong_shengong", 1);
		damage = damage +  me->query_skill("yunlong_jian", 1);
		if(me->Query(CChar::IS_NPC))
			damage=damage*(2+random(15));

		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/2);
		me->add("mp", -damage);

		msg += "只见$N手中剑光幻作一条金龙,腾空而起,倏的罩向$n,\n$n只觉一股大力铺天盖地般压来,登时眼前一花，两耳轰鸣,哇的喷出一口鲜血！！";
		me->add("mp", -100);
		me->start_busy(2);
	}
	else
	{
		msg += "可是$p猛地向前一跃,跳出了$P的攻击范围。";
		me->add("mp", -100);
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;
