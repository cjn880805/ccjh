// kurong_shengong.c ������

FORCE_BEGIN(CSkurong_shengong);

virtual void create()
{
	set_name( "������");
}

int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("kurong_shengong", 1);

	if ( EQUALSTR(me->querystr("gender"), "����") && lvl > 49)
		return notify_fail("���޸����ԣ���������������������Ŀ����񹦡�");

	if ( me->query_skill("force",1)<100)
		return notify_fail("��Ļ����ڹ���򲻵����޷���ϰ�����񹦡�");

	if ( me->query_skill("tianlong_shengong",1)<40)
		return notify_fail("����������������Ϊ�����ģ�����������������񹦡�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�");
}

FORCE_END;
