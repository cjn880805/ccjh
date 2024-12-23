
// yixingbu.h ���β���
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSyixingbu);

virtual void create()
{
	set_name( "���β���");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80] = {
		{"$n�������ĵ���������һ�����պñܹ�$N���������ơ�"},
		{"����$n����������������һ���������$N��һ�С�"},
		{"����$n����Ʈ��������һ�ݣ����ѱܿ���"},
		{"$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�"},
		{"����$n����һ�ã�$N��һ�����˸��ա�"},
		{"ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��"},
		{"$n����΢�Σ��о����յرܿ���$N��һ�С�"},
		{"$n�������ĵ�����һ������ͷ΢��,�����ܹ���$N��һ�С�"},
	};
	return dodge_msg[random(8)];
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move");
}

virtual int valid_learn(CChar * me)
{
	return 1; 
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 50 )
		return notify_fail("�������̫���ˣ����������β�����");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
