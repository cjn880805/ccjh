// yunlong_shenfa ������
FORCE_BEGIN(CSyunlong_shenfa);

virtual void create()
{
	set_name( "������");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char action[][255] = {
		{"$nһʽ�����ڻ�Ծ��������һת���͵�����һ��,�����$N�Ĺ��ơ�", },
		{"$nһʽ��ɳ���������˫��������󣬲������������״�$N��ǰ�����", },
		{"$nһʽ������ͬ�ۡ������˷�����һ�����Ƶ���$N�����", },
		{"$nһʽ���������񡹣����������һ�ˣ������ù���$N���������ơ�", },
		{"$nһʽ�����Ĳ�����������һ�����һ�Σ�������Ʈ����Զ��", },
		{"$nһʽ����ӥ���á���������һֻ��ӥ������һ����$N����ǰ�ɹ���", },
		{"$nһʽ���������졹�����İεض����ڰ����һת�����䵽����Զ�ĵط���", },
		{"$nһʽ��������졹��ȫ��Ϊһ����Ӱ������һ���շ��������Ʈ���ұߡ�", },
		{"$nһʽ���������̡������ζ��ر��Ʈ����������$N�޷����塣", },
		{"$nһʽ���������¡�������һ����ʸ������ٿ�İεض�����$N�������ӡ�", },
	};

	return action[random(10)];
};

virtual int valid_enable(string usage) { return usage=="dodge" ||  usage=="move"; }

virtual int valid_learn(CChar * me){return 1;}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ���������������");
	me->receive_damage("hp", 20);
	return 1;
}

SKILL_END;
