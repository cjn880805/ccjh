//kao.h ��
SKILL_BEGIN(CSkao);

virtual void create()
{
	set_name( "��");
	
}

virtual int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry";}


virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
        return notify_fail("����������֡�");
    if (me->query("max_mp") < 200)
        return notify_fail("�������̫�����޷�������");

	return 1;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[255];
		int force, dodge, damage;
		int lvl;
	}action[4] = {
		{"$N��$n����֮�ʣ�һ����ţ�ʹ�����С���ɽ����ײ���$l",
			120, 10, 30, 0,},
		{"$Nץס�Է����֣�һ�С���˿����ײ��$n��$l",
			150, 20, 45, 0,},
		{"$N����Χ$nת�˰�Ȧ��һ�С����Ŷ�����ײ��$n����������֮��",
			180, 30, 55, 0,},
		{"$N����һ������Ȼһ�С��ϲ��忿��ֱײ��$n�Ŀյ�",
		240, 50, 100, 100,},
	};

	int level = me->query_skill("kao",1);

	for(int i = 4; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].damage);
			m_actions.set("dodge", action[level].dodge);
	
			break;		
		}

	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	
	if (me->query("mp") < 20)
		return notify_fail("�����������������");
	
	me->receive_damage("hp", 30);
    me->add("mp", -20);

	return 1;
}

SKILL_END;