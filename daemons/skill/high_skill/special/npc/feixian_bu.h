//feixian_bu.h ���ɲ���

SKILL_BEGIN(CSfeixian_bu);

virtual void create()
{
	set_name( "���ɲ���");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={	
		{"$nһ�С��������ࡹ�������ɵر��˿�ȥ��"},
		{"ֻ��$n��Ӱһ�Σ�һʽ������Ҳ������ѱ����߳�֮�⡣"},
		{"$nʹ������ת��Ȩ�����������ɵ�������"},
		{"$n����һ�㣬һ�С���Ӱ���ࡹ�ڿն��𣬱��˿�ȥ��"},
		{"����$nʹһ�С��綯��⡹����������Ʈ�˿�ȥ��"},
		{"$n��Ӱ΢�����Ѿ���һ�С�������������������"},
		{"����$nһ�С��������١�ʹ���������Ƶ�$N���ᣡ"},
	};

	return dodge_msg[random(7)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

SKILL_END;

