//feiyan_huixiang.h �������

SKILL_BEGIN(CSfeiyan_huixiang);

virtual void create()
{
	set_name( "�������");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={	
		{  "����$n����Ʈ��������һ�ݣ�һ�С�����Ͷ�֡�����������ıܿ���һ����"},
		{"$n������ת��һʽ��ѩ�����衹��ٿ����һ��Ʈ�����ߣ��ܹ�����һ�С�"},
		{"����$n����һ�ã�ʹ����������Ʈ����$N��һ�����˸��ա�"},
		{"ȴ��$n�㲻��أ�һ�С����Ƽ��������ε�����һת�������������ߣ����˿�ȥ��"},
		{"$n���һ���ҽű�����������һ�Σ�һ�С�һ�׳��졹���������ɵرܿ�����һ�С�"},
		};

	return dodge_msg[random(5)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

virtual int practice_skill(CChar * me)
{
    if( me->query("hp") < 30 )
		return notify_fail("�������̫���ˣ��������������......");

	me->receive_damage("hp", 30);
    return 1;
}

SKILL_END;

