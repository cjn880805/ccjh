//huanhua_bu.h 佻�����

SKILL_BEGIN(CShuanhua_bu);

virtual void create()
{
	set_name( "佻�����");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={	
		{"$nһ�С���ˮ�صޡ��������ɵر��˿�ȥ��"},
		{"ֻ��$n��Ӱһ�Σ�һʽ��������̡����ѱ����߳�֮�⡣"},
		{"$nʹ������ת��С����������ɵ�������"},
		{"$n����һ�㣬һ�С���Ӱ�������ڿն��𣬱��˿�ȥ��"},
		{"����$nʹһ�С��綯�񶯡�����������Ʈ�˿�ȥ��"},
		{"$n��Ӱ΢�����Ѿ���һ�С�������������������"},
		{"����$nһ�С���ҡ�ɵء�ʹ���������Ƶ�$N���ᣡ"},
	};

	return dodge_msg[random(7)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

SKILL_END;

