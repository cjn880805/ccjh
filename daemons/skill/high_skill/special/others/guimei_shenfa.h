// guimei-shenfa ���������嶾�̣�

SKILL_BEGIN(CSguimei_shenfa);

virtual void create()
{
	set_name( "������");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char action[][255] = {
			{"ֻ��$n��ӰƮ������˸������ʹ$N�Ĺ���ȫ����ա�"},
			{"ȴ��$n����΢�Σ�����Ʈ�����ߣ������$N�Ĺ�����"},
			{"$n���������������м�ת����ƮƮ���ÿ���$N����һ�С�"},
			{"$n������ͬ����һ�㣬��ò������ۻ����ң���$N�޷����֡�"},
	};

	return action[random(4)];
};

virtual int valid_enable(string usage) { return usage=="dodge" ||  usage=="move"; }

virtual int valid_learn(CChar * me){return 1;}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ���������������");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
