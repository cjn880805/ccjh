//tiannan_step.h���ϲ���

//code by Fisho
//date:2000-11-29

SKILL_BEGIN(CStiannan_step);

virtual void create()
{
	set_name( "���ϲ���");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][100]=
	{
		"ֻ��$nһ�С����ذδС����������ϱ�ֱ���������࣬�����$N��һ�С�",
		"$nһ��������鳲��������ݳ�����֮Զ���ܿ���$N���������ơ�",
		"$nʹ������������������һ��ƮȻ�ݳ��������ŵء�"
		"����$n����Ʈ����һ�С��������С�����һ�ݣ����ѱܿ���",
		"$n������ת��һ�С��˷��ȥ��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�",
		"����$n����һ�ã�һ�С��绯������$N��һ�����˸��ա�",
		"ȴ��$n�㲻��أ�һ�С�����ֱ�ϡ����Դܿ����ߣ����˿�ȥ��",
		"$n����΢�Σ�һ�С�������졹�о����յرܿ���$N��һ�С�"
	};
	
	return dodge_msg[random(8)];
}

virtual int valid_enable(string usage) { return (usage == "dodge") || (usage == "move");}

virtual int valid_learn(CChar * me) { return 1; }

virtual int practice_skill(CChar * me)
{
    if( me->query("hp") < 40 )
       return notify_fail("�������̫���ˣ���������������");
    me->receive_damage("hp", 30);
    return 1;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp