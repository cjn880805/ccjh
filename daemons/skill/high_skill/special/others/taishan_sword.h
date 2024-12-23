//taishan_sword.h ̩ɽ����

SKILL_BEGIN(CStaishan_sword);

virtual void create()
{
	set_name( "̩ɽ����");	
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int dodge,  damage;
	}action[5] = {
		{"$N����$wбָ���£�������ָ������ָ��������һ�����壬�ն���ȭ���ֽ�Ĵָ������ζ�ʳָ��������ָȫչ����������Ĵָ����ʳָ��������ָ��Ȼ������$w���Ⱪ������$n��$l��ȥ",
			50, 170,},
		{ "$N����$wһ�Σ����һ���������һ�С��������ơ���ת������������΢����$w��$nбб��ȥ",
		-70, 120,},
		{ "$N����$wȦת��һ�С������ա�ȥ���漲�������������$n��$l",
		-40,  90,},
		{ "$Nչ�����ƣ����潣�ߣ����һ�գ��ұ�һ�䣬ԽתԽ�����͵�$w���Ⱪ����һ�С�̩ɽʮ���̡���$n$l��ȥ",
        -40, 140,},
		{ "$N����$wٿ�ش̳���һ���彣��ÿһ���Ľ��нԲ�Ȼ�й��⡣�������ӣ��ڲ���䣬���ǡ����򽣡�",
        60, 220,},};
		
  	int level = random(5);
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
        return notify_fail("�������������û�а취��̩ɽ������");

    if( !(ob = me->query_weapon())
		|| DIFFERSTR(ob->querystr("skill_type"), "sword") )
        return notify_fail("���������һ�ѽ�������������");

	return 1;
}


virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 30
		|| me->query("mp") < 5 )
        return notify_fail("�����������������û�а취��ϰ̩ɽ������");

    me->receive_damage("hp", 30);
    me->add("mp", -5);

	return 1;
}

SKILL_END;

