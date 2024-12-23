// murong_daofa.h 慕容刀法
SKILL_BEGIN(CSmurong_daofa);

virtual void create()
{
	set_name( "慕容刀法");
/*
	Magic_t * magic;

	magic = add_magic("yingzhang", do_yingzhang);
	magic->name = "刀影掌";
	magic->mp = 600;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenyuan_gong") || EQUALSTR(arg, "shenyuan_gong"))
		return 1;

	return notify_fail("慕容刀法必须与神元功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, damage, lvl;
		char damage_type[5];
	}action[] = {
		{"$N大喝一声「看招」，一招「劈天盖地满壮志」，刀锋自上而下向$n的$l挥去", 
		160, 10, 30, 0, "割伤",},
		{"$N一招「弯刀逆转倒乾坤」，手中$w在空中急速转动数圈，划向$n的$l腿", 
		200, 10, 60, 30, "割伤",},
		{"$N猛一挫身，一招「遥看万疆千里雪」,$w直向$n的颈中斩去", 
		260, 5, 90, 70, "割伤",},
		{"$N一招「壮志豪气满江湖」，无数刀尖化作点点繁星，向$n的$l挑去", 
		300, 5, 120, 100, "割伤",},
	};

	int level = me->query_skill("murong_daofa", 1);
	for(int i=4; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			m_actions.set("damage_type", action[level].damage_type);
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
	
	if (me->query_skill("shenyuan_gong", 1) < 20)
		return notify_fail("你的神元功火候太浅。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 40)
		return notify_fail("你的体力不够练慕容刀法。");

	if (me->query("mp") < 15)
		return notify_fail("你的体力不够练慕容刀法。");

	me->receive_damage("hp", 25);
	me->receive_damage("mp", 8);
	return 1;
}
/*
static int do_yingzhang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	int d=me->query_skill("yanling_shenfa",1)/5;
	int j=me->query_skill("murong_daofa", 1)/5;
	int i=me->query_skill("xingyi_zhang", 1)/5;

//	weapon = me->query_temp("weapon");
	weapon = me->query_weapon();

	if( !target || ! me->is_fighting(target))
		return notify_fail("刀影掌只能对战斗中的对手使用。");

	if( me->query_skill("murong_daofa", 1) < 100 )
		return notify_fail("你的刀法还未练成，不能使用刀影掌！");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你手里没有刀，无法使用刀影掌！");

	if( me->query_skill("xingyi_zhang", 1) < 100 )
		return notify_fail("你的掌法还未练成，不能使用刀影掌！");

	if( me->query("mp") < 600 )
		return notify_fail("你现在内力不足，不能使用刀影掌！");

	if( me->query_skill("blade", 1) < 100 )
		return notify_fail("你的基本刀法不够娴熟，不能在刀招中夹杂使用刀影掌。");

	if( me->query_skill("strike", 1) < 100 )
		return notify_fail("你的基本掌法不够娴熟，不能在刀招中夹杂使用刀影掌。");

	msg += "\n$YEL$N大吼一声使出刀影掌，掌随刀走，刀光中夹杂着阵阵掌风一起奔向$n！$COM";
	me->add("mp", -250); 
	me->add_temp("apply/dodge", d); 
	me->add_temp("apply/attack", (i+j)/2); 
//	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	weapon->unequip(); 
	msg += "$YEL$N弃刀换掌，身形飞转！$COM\n";
	me->add_temp("apply/strike", i/2); 
//	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	msg += "$YEL$N弃掌换刀，身形飞转！$COM\n";
	me->add_temp("apply/strike", -i/2); 
	weapon->wield(); 
//	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	me->add_temp("apply/attack", -((i+j)/2)); 
	me->add_temp("apply/dodge", -d); 
        me->start_busy(5);

        return 1;
}
*/
SKILL_END;
