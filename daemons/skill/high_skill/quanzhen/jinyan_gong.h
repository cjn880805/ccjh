//jinyan_gong.h ���㹦

SKILL_BEGIN(CSjinyan_gong);

virtual void create()
{
	set_name( "���㹦");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[8][120]={	
		{"$n���λζ���ʹ��һ�г������ޣ�����ʵ�ң���ǰ�����������޵�����$N�Ĺ�����"},
		{"$nͻȻ����һ����һ�в����伣������������֮�⡣"},
		{"����$nһ�з���˷���Ȼ�������࣬���λζ��������$N�Ĺ��ơ�"},
		{"ֻ��$n����������������б��������һ���������죬��֪����$n�Ѿ�����$N�����"},
		{"$n��ס���ˣ���Ȼ���λζ���һ�н��жݱ�ת����$N����ࡣ"},
		{"$n�������ߣ�һ��������������$N���������ơ�"},
		{"$n����һ�㣬һ�л���ת��бб�ķɳ�ǡ�ɶ㿪��$N�Ľ�����"},
		{"$nһ�г������ղ���һ�ã�$N�������˸��ա�"},
	};

	return dodge_msg[random(8)];
}

virtual int valid_enable(string usage) { return usage == "dodge"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

virtual int practice_skill(CChar * me)
{
        if( me->query("hp") < 40 )
                return notify_fail("�������̫���ˣ����������㹦��");
        me->receive_damage("hp", 30);
        return 1;
}

SKILL_END;

