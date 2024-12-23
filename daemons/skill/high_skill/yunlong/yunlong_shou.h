// yunlong-shou.c -云龙手
SKILL_BEGIN(CSyunlong_shou);

virtual void create()
{
	set_name( "云龙手");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int force, dodge, damage ,lvl;
	}action[] = {
		{"$N一式「草木皆兵」，十指伸缩，虚虚实实地袭向$n的全身要穴", 200, 30, 15, 10,},
		{"在呼呼风声中，$N使一招「捕风捉影」，双手如钩如戢，插向$n的$l", 250, 35, 20, 20,},
		{"$N双拳挥舞，一式「浮云去来」，两手环扣，拢成圈状，猛击$n的下颌", 250, 30, 25, 30,},
		{"$N双手平伸，十指微微上下抖动，一招「十指乾坤」打向$n的$l", 300, 35, 30, 40,},

		{"$N左手护胸，腋下含空，右手五指如钩，一招「抱残守缺」插向$n的顶门", 260, 40, 30, 50,},
		{"$N右腿斜插$n二腿之间，一招「掏虚抢珠」，上手取目，下手反勾$n的裆部", 300, 35, 40, 60,},
		{"$N一手虚指$n的剑诀，一招「空手入刃」，劈空抓向$n手中的兵刃", 350, 35, 50, 70,},
		{"$N左手指向$n胸前的五道大穴，右手斜指太阳穴，一招「降龙伏虎」使$n进退两难", 400, 40, 60, 80,},

		{"$N一手顶天成爪，一手指地，一招「拨云见日」,劲气笼罩$n的全身", 420, 50, 70, 90,},
		{"$N一式「如烟往事」，拳招若隐若现，若有若无，缓缓地拍向$n的丹田", 460, 60, 100, 100,},
		{"$N随意挥洒，使一式「我心依旧」，掌心微红,徐徐拍向$n的$l", 490, 60, 100, 80,},
	};

	int level = me->query_skill("yunlong_shou", 1);
	for(int i=11; i>0; i--)
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
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练云龙手。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_enable(string usage) { return usage == "unarmed" || usage == "hand"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练云龙手必须空手。");
	if (me->query_skill("yunlong_shengong", 1) < 50)
		return notify_fail("你的云龙神功火候不够，无法学云龙手。");
	if (me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候不够，无法学云龙手。");
	if (me->query("max_mp") < 250)
		return notify_fail("你的内力太弱，无法练云龙手。");
	if (me->query_skill("hand",1) <40)
		return notify_fail("你的基本手法火候不够，无法学云龙手。");
	if ( (2*me->query_skill("yunlong_xinfa",1)) <me->query_skill("yunlong_zhua",1))
		return notify_fail("你的云龙心法火候不够，无法继续学云龙手。");
	return 1;
}

virtual int valid_combine(string combo) { return combo=="yunlong_zhua"; }

SKILL_END;

/*
int valid_combine(string combo) { return combo=="yunlong-zhua"; }
*/