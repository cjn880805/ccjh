//hengshan_jian.h ��ɽ����

SKILL_BEGIN(CShengshan_jian);

virtual void create()
{
	set_name( "��ɽ����");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge,  damage;
	}action[] = {
		{"$N����$w�����˸���Ȧ��бб��$n$l��ȥ",
			120, -40, 30,},
		{"$NͻȻ�佫$w�����֣����ִ̳�",
		140, -35, 35,},};
 
  	int level = 0;
	level = random(2);
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
	
	return & m_actions;
};

virtual int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	 if (me->query("max_mp") < 100)
		return notify_fail("�������������");

    if (DIFFERSTR(me->querystr("gender"), "Ů��") )
		return notify_fail("��������Ľ���ֻ��Ů�Ӳ��ʺ�ѧ��");
    return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

    if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");

    if (me->query("hp") < 50)
		return notify_fail("���������������ɽ������");

    me->receive_damage("hp", 30);
    return 1;
}

SKILL_END;

