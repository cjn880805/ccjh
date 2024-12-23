SKILL_BEGIN(CSsanhua_zhang);

virtual void create()
{
	set_name( "ɢ����");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[4] = {
		{ "$N���Ʊ���һʽ������ݾ�����˫�Ʊ�����£���������$n��$l",
			180, 5, 20, 10, 0,},
		{ "$N��ָ������һʽ�����ж���ܰ���������ƴ��巭�ɣ�����$n��$l��ȥ",
		260, 10, 15, 20, 20,},
		{ "$Nʹһʽ���ﺨ��˪�塹���������У�����է��է�ϣ��͵ز���$n��$l",
		340, 15, 20, 30, 40,},
		{ "$N˫��Ѫ�죬һʽ��������÷�������ó�����÷����䣬������$n��ȥ",
		420, 20, 30, 40, 60,},
	};

	int level = me->query_skill("sanhua_zhang", 1);
	for(int i = 4; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);

			break;
		}
	
	return & m_actions;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("ɢ���Ʊ��������ֶ����ڹ����ʹ�á�");
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 20)
		return notify_fail("�������������ɢ���ơ�");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("��ɢ���Ʊ�����֡�");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧɢ���ơ�");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷���ɢ���ơ�");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
virtual int valid_combine(string combo) {return combo=="nianhua_zhi"; }

SKILL_END;