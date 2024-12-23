// kill_hammer.c 
//oho出品，质量不保证
SKILL_BEGIN(CSkill_hammer);

virtual void create()
{
	set_name( "打色狼锤");
}


virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, lvl, damage;
	}action[] = {
		{"$N大喝一声“死色狼！”，$w忽然好像变大了一倍，向$n的头部砸去", 120, -10, 100, 0, 50,},
		{"$N大喝一声“臭色狼！”，$w忽然好像变大了几倍，向$n的头部砸去", 160, -20, 200, 30, 105,},
		{"$N大喝一声“坏色狼！”，$w忽然好像变大了十几倍，向$n的头部砸去", 200, -20, 100, 100, 160,},
		{"$N大喝一声“打死你这色狼！，$w忽然好像变大了几百倍，向$n的头部砸去", 340, 5, 150, 250, 265,},
	};

	
	int level = me->query_skill("kill_hammer", 1);
	for(int i=4; i>0; i--)
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

virtual int valid_enable(string usage) { return usage=="hammer" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	if (DIFFERSTR(me->querystr("gender"), "女性") )
		return notify_fail("这种霸道的功夫只有凶悍的雌性动物才能学。");;	
	if(me->query("str") < 30 || me->query_str() < 45)
		return notify_fail("你的力量不够，还是乖乖的被色狼欺负把。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "hammer"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练不了打色狼锤。。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
