// kill_hammer.c 
//oho��Ʒ����������֤
SKILL_BEGIN(CSkill_hammer);

virtual void create()
{
	set_name( "��ɫ�Ǵ�");
}


virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, lvl, damage;
	}action[] = {
		{"$N���һ������ɫ�ǣ�����$w��Ȼ��������һ������$n��ͷ����ȥ", 120, -10, 100, 0, 50,},
		{"$N���һ������ɫ�ǣ�����$w��Ȼ�������˼�������$n��ͷ����ȥ", 160, -20, 200, 30, 105,},
		{"$N���һ������ɫ�ǣ�����$w��Ȼ��������ʮ��������$n��ͷ����ȥ", 200, -20, 100, 100, 160,},
		{"$N���һ������������ɫ�ǣ���$w��Ȼ�������˼��ٱ�����$n��ͷ����ȥ", 340, 5, 150, 250, 265,},
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
		return notify_fail("�������������");
	if (DIFFERSTR(me->querystr("gender"), "Ů��") )
		return notify_fail("���ְԵ��Ĺ���ֻ���׺��Ĵ��Զ������ѧ��");;	
	if(me->query("str") < 30 || me->query_str() < 45)
		return notify_fail("����������������ǹԹԵı�ɫ���۸��ѡ�");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "hammer"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("����������������˴�ɫ�Ǵ�����");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
