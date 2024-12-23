// zhaixinggong.h ժ�ǹ�
SKILL_BEGIN(CSzhaixinggong);

virtual void create()
{
	set_name( "ժ�ǹ�");
}

virtual int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

virtual int valid_learn(CChar * me)
{
	return 1;
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80] = {
		{"$nһ��������ժ�ǡ���Ծ�����ߣ������$N��һ�С�",},
		{"$n�������һ�ݣ�ʹ��һ�С�ƮȻ���������ܹ���$N�Ĺ�����",},
		{"$nʹ����������ˮ����ǡ�ö����$N�Ĺ��ơ�",},
		{"$n������ת��һ�С���ת���ơ���ٿ����һ��Ų�������ߣ��ܹ�����һ�С�",},
		{"$n�㲻��أ�ʹ�������Ǹ��¡������Դܿ����ߣ����˿�ȥ��",},
		{"$nһ�С�֯Ů���󡹣���̬����ض��˿�ȥ��"},
	};

	return dodge_msg[random(6)];
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
         return notify_fail("�������̫���ˣ�������ժ�ǹ���");
	if (me->query_skill("zhaixinggong", 1) < 30)
	     me->receive_damage("hp", 10);
	else if (me->query_skill("zhaixinggong", 1) < 60)
		me->receive_damage("hp", 20);
	else 
		me->receive_damage("hp", 30);
   
	return 1;
}

SKILL_END;