// xue-dao.c 血刀
SKILL_BEGIN(CSxue_dao);

virtual void create()
{
	set_name( "血刀");
	set("valid_force", "longxiang");

	Magic_t * magic;

	magic = add_magic("jixue", do_jixue);
	magic->name = "祭血神刀";
	magic->mp = 600;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, lvl, damage;
	}action[] = {
		{"$N高举手中$w,使出一招「磨牙吮血」，一刀斜劈$n的$l", 200, -5, 5, 0, 20,},
		{"$N就地一滚，使一招「刺血满地」，手中$w卷向$n的大腿", 240, 5, 5, 8, 25,},
		{"$N足尖一点，使出「血海茫茫」，刀锋自上而下直插$n的$l", 280, 10, 5, 16, 30,},
		{"$N使出一招「呕心沥血」，将$w舞得如白雾一般压向$n", 320, 5, 5, 24, 40,},
		{"$N低吼一声，使出「血口喷人」，举$w直劈$n的$l", 350, -5, 5, 48, 50,},
		
		{"$N使出「血迹斑斑」，飞身斜刺，忽然反手一刀横斩$n的腰部", 380, 10, 5, 60, 60,},
		{"$N使一式「以血还血」，挥刀直指$n的胸口", 400, 5, 10, 80, 80,},
		{"$N刀锋虚点，使出一招「血流满面」，转身举$w横劈$n的面门", 400, 10, 20, 100, 100,},
	};

	int level = me->query_skill("xue_dao", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="blade" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 50)
		return notify_fail("你的内力不够。");
	
	if (me->query_skill("longxiang", 1) < 20)	//此处原来是血刀心法，因为没NPC会，改了。lanwood 2001-03-11
		return notify_fail("你的龙象般若功火候太浅。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练血刀。");
	me->receive_damage("hp", 30);
	return 1;
}


//exert heal
static int do_jixue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || ! me->is_fighting(target))
		return notify_fail("「祭血神刀」只能对战斗中的对手使用。");
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("装备刀才能使用「祭血神刀」？");

	if(DIFFERSTR(me->querystr("family/family_name"), "雪山寺") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_skill("xue_dao", 1) < 40 )
		return notify_fail("你血刀刀法不够娴熟，使不出「祭血神刀」。");
	
	if (me->query_skill("longxiang", 1) < 60 )
		return notify_fail("你龙象般若功火候不够，使不出「祭血神刀」。");
	if (me->query("max_mp") < 600)
		return notify_fail("你内力修为不足，无法运足内力。");
	if (me->query("mp") < 600)
		return notify_fail("你现在内力不够，没能将「祭血神刀」使完！");

	msg = "$N右手持刀向左肩一勒，一阵血珠溅满刀面，紧接着右臂抡出，一片血光裹住刀影向$n当头劈落，\n";
	if(target->query_temp("apply/no_祭血神刀")&& (random(2)||target->query("bigboss")))
	{
		msg += "可是$n侧身避让，不慌不忙，躲过了$N的血刀。";
		me->start_busy(4);
	}
	else
	{
		if ( random(me->query_combat_exp()) > target->query_combat_exp()/2 )
		{
			int repute=me->query("repute");
			if(repute<-60000000)
				repute=-60000000;
			int damage = random(repute/-1000)+(repute/-4000);
			if(damage>10000)
			{
				if( random(100)<40)
					damage=random(5000)+5000;
				//else if(damage>15000)
				//	damage=15000;
			}
			me->add("mp", -600);
			me->receive_wound("hp", me->query("hp")/20);
			me->start_busy(1);
			target->start_busy(random(3));
			target->receive_damage("hp", damage);
			target->receive_wound("hp", damage/2);
			msg += "$n疾忙侧身避让，但血刀疾闪，只觉眼前一阵血红，刀刃劈面而下，鲜血飞溅，惨声大嚎！\n";
			message_vision(msg.c_str(), me, target);
			char msg1[255];
			message_vision(snprintf(msg1,255,"$HIR结果造成了%d点的伤害。$COM\n",damage), me, target);
		} 
		else
		{
			me->start_busy(2);
			me->receive_wound("hp", me->query("hp")/20);
			msg += "可是$n侧身避让，不慌不忙，躲过了$N的血刀。";
			me->add("mp", -200);
			message_vision(msg.c_str(), me, target);
		}
	}
	if(!target->is_killing(me)) target->kill_ob(me);
	return 1;
}

SKILL_END;
