// zhutian_bu.h ���컯��
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSzhutian_bu);

virtual void create()
{
	set_name( "���컯��");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][100]=
	{
		"ֻ��$nһ�С���ع����������ڿգ�˫�����ϣ���ֱ���������࣬�����$N��һ�С�",
		"$n������ת��һʽ�����ͷ��ͷ��ǰͦ�������ո���ٿ����һ��Ų�������ߣ��ܹ�����һ�С�",
		"$n˫��ץ�أ�����΢�Σ�һ�С�ӥצ�ɡ��о����յرܿ���$N��һ�С�",
		"����$n����Ʈ����һʽ���������������һ�ݣ����ѱܿ���",
		"$nһ������������������ݳ�����֮Զ���ܿ���$N���������ƣ��������۽�$N���ԡ�",
		"$nʹ�������¿ۡ���˫���繳��һ��ƮȻ�ݳ��������ŵء�",
	};
	
	return dodge_msg[random(6)];
}

virtual int valid_enable(string usage) 
{
	return (usage == "dodge") || (usage == "move");
}

virtual int valid_learn(CChar * me) 
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");
	return 1;
 }

virtual int practice_skill(CChar * me)
{
	if(me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ����������컯����");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;




