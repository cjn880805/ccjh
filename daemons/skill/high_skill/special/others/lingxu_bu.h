//lingxu_bu.h ���鲽

SKILL_BEGIN(CSlingxu_bu);

virtual void create()
{
	set_name( "���鲽");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={	
		{"$nһʽ��ѩ�������������ӳ���һת��$Nֻ������ǰһ����ʧȥ��Ŀ�ꡣ",},
		{ "$nһʽ��һ�����졹��˫�ŵ�أ�����ͻȻ�θ�����������Ʈ����$N���",},
		{"$nһʽ�����л�Ӱ��������һ�Σ���ʱ��������Ӱһ���ӳ�����$N����ǰ��",},
		{"$nһʽ���������ߡ���ƮȻ���һ�ˣ��㿪$N���������ơ�",},
		{"$nһʽ������Ʈ�졹�����弱ת����Ϊһ���׹⣬��ò����ĳ�����$N����Χ��",},
		};

	return dodge_msg[random(5)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

SKILL_END;

