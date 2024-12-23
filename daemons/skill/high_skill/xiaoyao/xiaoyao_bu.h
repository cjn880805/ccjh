// xiaoyao-bu.c ��ң��

FORCE_BEGIN(CSxiaoyao_bu);

virtual void create()
{
	set_name( "��ң��");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char action[][255] = {
			{"ֻ��$nһ�С������졹�����ζ�Ȼ���𣬶����$N��һ�С�"},
			{"$nһʽ��ӣ���䡹�����λζ�����һ��Ʈ�����ܿ���$N��һ�С�"},
			{"$nһ�С�����������������ת��$Nֻ����ǰһ����$n������$N�����"},
			{"$nʹ��������硹��һ�����Ľ��󷭳����ܿ���$N���������ơ�"},
	};
	return action[random(4)];
};

virtual int valid_enable(string usage) { return usage=="dodge" ||  usage=="move"; }

virtual int valid_learn(CChar * me) {return 1;}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ���������ң����");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
