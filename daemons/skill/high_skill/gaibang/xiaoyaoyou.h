
// xiaoyaoyou.h ��ң��
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSxiaoyaoyou);

virtual void create()
{
	set_name( "��ң��");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]=
	{
		"$nһ�������ѵ�ˮ���������$N��һ�С�",
		"$n�������һ�ݣ�ʹ��һ�С�ϸ���ɷ��ơ����ܹ���$N�Ĺ�����",
		"$nʹ�����黳���ȡ���ǡ�ö����$N�Ĺ��ơ�"
	};
	
	return dodge_msg[random(3)];
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
	if( me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ���������ң�Ρ�");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
