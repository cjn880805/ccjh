// shenkong-xing.c �����

FORCE_BEGIN(CSshenkong_xing);

virtual void create()
{
	set_name( "�����");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char action[][255] = {
		{"$nʹ��һ�С��Ŀա�����������Ʈȥ"},
		{"$nʹ��һ�С����Կա���˫��һ�㣬Ծ������֮��"},
		{"$nʹ��һ�С����ա�������һ�䣬����$N���"},
		{"$n���һ����ʹ��һ�С��󰲿ա�����$Nͷ��Խ��"},
		{"$nʹ��һ�С���ա���������Ʈȥ��˲��������$N��ǰ"},
		{"$nʹ��һ�С���տա�����ʱ$N��Χ����$n����Ӱ"},
	};

	return action[random(6)];
};

virtual int valid_enable(string usage) { return usage=="dodge" ||  usage=="move"; }

virtual int valid_learn(CChar * me){return 1;}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ�������ϰ����С�");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
