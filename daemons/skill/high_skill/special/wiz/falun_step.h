// falun_step.h ���ֱ��׹�
//code by Teapot
//date : 2001-2-06

SKILL_BEGIN(CSfalun_step);

virtual void create()
{
	set_name( "���ֱ��׹�");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][100]=
	{
        "$nһ�С��������Ρ���ȫ����ǧ�ٸ���Ӱ��������$N��һ�С�\n",
        "$n���۵��һ�С������ı䡱�����μ������㿪$N������һ����\n",
        "$n������������Х������һ�С���ң���⡱���������⡣\n",
        "$n˫����̤������һ�С��������족�������ޱ�����ص������ߡ�\n",
        "$nʹ�����ⷨ�������˲��еġ��������֡������λ�ʵΪ��ض㿪��$N��һ�С�\n",
        "$n�ڿ�һԾ��˫�������̤��һ�С�����ǧ�ء����㿪���ߡ�\n",
        "$n���λζ���һ�С�����Ȼ����ȫ����������Ӱ�ӳ����⡣\n",
        "$n����һ������һ�С����ֻ����������һ���ޱȹ��������Ť���ŵ������ߡ�\n"
	};
	
	return dodge_msg[random(8)];
}

virtual int valid_enable(string usage) 
{
	return (usage == "dodge");
}

virtual int valid_learn(CChar * me) { return 1; }

virtual int practice_skill(CChar * me)
{
	if(me->query("hp") < 5 )
		return notify_fail("�������̫���ˣ����������ֱ��׹���");
	me->receive_damage("hp", 5);
	return 1;
}

SKILL_END;


