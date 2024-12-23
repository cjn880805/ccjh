//songshan_sword.h ��ɽ����

SKILL_BEGIN(CSsongshan_sword);

virtual void create()
{
	set_name( "��ɽ����");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int dodge,  damage;
	}action[7] = {
		{"$N����$wһ�����ٽ���������������ʹһ�С��������ڡ����ǵ�ϵ���ڵ���ɽ����",
			50, 170,},
        { "$N����$wͻȻ�佣��һ�£�����һ���׺磬������ΰ������Ʈ�ݣ�������ɽ�����ľ�Ҫ���ڣ�һ�С�ǧ����������$n$lֱ�̹���",
        -70,  120,},
		{ "$N����$wͻȻ�佣��һ�£�һ�С����両�࡯����һ����⣬��׳�ۻ룬��$n$lֱ�̹���",
        -70,  120,},
		{ "$N����$w����һ�£�һ�С������ء��������࣬������ΰ����$n$lֱ�̹���",
        -70,  120,},
		{ "$N��������һ�֣�����$w�����ӳ���ʹ������ɽ�ɽ��������ż�ɽ��",
        -70, 120,},
		{ "$N����$w���϶��µ���$nֱ����ȥ��һ�С�������ɽ��������ʯ���쾪�����ƣ�����ɽ����֮�������ӵ����쾡��",
		-40,  90,},
		{ "$N����$wˢ��һ��������Ҽ�����ȥ������һ����ɽ�����ڽ���������������������$w�԰���к��������������ֱ����������һ������һ��",
		-40, 140,},};
 
  	int level = random(7);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
	
	return & m_actions;
};

virtual int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	CContainer * ob;

    if( me->query("max_mp") < 50 )
        return notify_fail("�������������û�а취����ɽ������\n");

    if( !(ob = me->query_weapon())
		|| DIFFERSTR(ob->querystr("skill_type"), "sword") )
        return notify_fail("���������һ�ѽ�������������");

    return 1;
}


virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 30
		||   me->query("mp") < 5 )
        return notify_fail("�����������������û�а취��ϰ��ɽ������");
    me->receive_damage("hp", 30);
    me->add("mp", -5);
    
    return 1;
}

SKILL_END;

