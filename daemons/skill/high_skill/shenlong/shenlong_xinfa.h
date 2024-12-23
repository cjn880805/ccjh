
// shenlong_xinfa.h �����ķ�
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSshenlong_xinfa);

virtual void create()
{
	set_name( "�����ķ�");
}

virtual int valid_enable(string usage) { return usage == "force"; }

virtual int practice_skill(CChar * me)
{
	return notify_fail("�����ķ�ֻ�ܿ��������ߡ�");
}

virtual int valid_learn(CChar * me)
{
	int i = me->query_skill("shenlong_xinfa", 1);
	int t = 1, j;

	if( i <= 100)
		for (j = 1; j < i / 10; j++)
			t*= 2;

	if ( EQUALSTR(me->querystr("gender"), "����") && i > 49)
		return notify_fail("���޸����ԣ���������������������������ķ���");
	if (me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ�����ķ���");

	if(i<=100)
	{
		if (i > 10 && -me->query("repute") < t * 100) 
			return notify_fail("ѧ�����ķ���Ҫ�ĺ���������������������ò���ѽ��");
	}
	else
	{
		if (-me->query("repute") < (51200 + (i - 100) * 1000)) 
			return notify_fail("ѧ�����ķ���Ҫ�ĺ���������������������ò���ѽ��");
	}

	if ( me->query_skill("bibo_shengong",1)
	|| me->query_skill("beiming_shengong",1)
	|| me->query_skill("bahuang_gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
	|| me->query_skill("hunyuan_yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang_shengong",1)
	|| me->query_skill("taiji_shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("zixia_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����ķ�����");

	return 1;
}

SKILL_END;
