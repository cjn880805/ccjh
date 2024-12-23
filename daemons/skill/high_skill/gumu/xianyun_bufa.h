
// xianyun_bufa.h ���Ʋ���
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSxianyun_bufa);

virtual void create()
{
	set_name( "���Ʋ���");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][120]=
	{
		{"$nʹ�� ���Ʋ��� ���㣬�Ų��ƣ�������������ˮ��ֱ�������ࡣ" },
		{"$nʹ�� ���Ʋ��� ��Ȼһ������ȫ�����ض��У���ʱ������$N���������ơ�"},
		{"$nʹ�� ���Ʋ��� �㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����" },
		{"$nʹ�� ���Ʋ��� һת��䣬����˷�Ʈ����������$n����Ӱ����$N�����޴롣"},
		{"$nʹ�� ���Ʋ��� ��̤�㣬��תǬ������һ�Σ��㵽����Զ�ĵط���" },
		{"$nʹ�� ���Ʋ��� ���ڿ��У������������һ�㣬��$Nͷ���ڿն�����" },
		{"$nʹ�� ���Ʋ��� ����һ����ȫ��Ϊһ����Ӱ�����ĵش�$Nͷ��Ʈ�䡣"  },
		{"$nʹ�� ���Ʋ��� ���������ݰ㼱ת����ʱһ������ӿ������$N���Զ�����"  },
		{"$nʹ�� ���Ʋ��� ����ٿ�Ĵ�$N����ǰֱ�Ƶ����$N�ɴ������ۣ��������ԡ�" },
		{"$nʹ�� ���Ʋ��� ����ٿ�Ĵ�$N����ǰƮ��������һ˦������֮����"  },
	};
 	
	return dodge_msg[random(10)];
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "dodge")  ;
}

virtual int valid_learn(CChar * me)
{
	if( me->query_skill("tianluo_diwang",1)<30)
	 	return notify_fail("������޵����ƻ���������,����ѧϰ���Ʋ�����");
	if( me->query_skill("seaforce",1)<30)
	 	return notify_fail("��Ŀ��ķ���Ϊ����,���������Ʋ�����");
	 if(me->query_skill("seaforce",1)<me->query_skill("xianyun_bufa",1))
	 	return notify_fail("��Ŀ��ķ���Ϊ�����ˣ����ܼ���ѧϰ���Ʋ�����");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	
	if( me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ����������Ʋ�����");
	me->receive_damage("hp", 20);
	return 1;
}

SKILL_END;
