//yanling_shenfa.h ������
//code by sound
//date : 2001-06-12

SKILL_BEGIN(CSyanling_shenfa);

virtual void create()
{
	set_name( "������");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[8][255]={	
		"$nһʽ�������Ϸɡ�����Žż�����ҽ���շ�����������������ˮ�㻬�����ࡣ",
		"$nһʽ��һҶ��Ŀ����������ת��˫�Űϵض��𣬶�ʱ������$N���������ơ�",
		"$nһʽ��˫��ַɡ�������˫������߳����ţ���ʱ�䵽$N���Ͽա�",
		"$nһʽ�����ӳ�������ͻȻ������ǰ�ˣ���������ĳ���$N����$N������롣",
		"$nһʽ����������������������ȫ��Χ��$N������ת����$N��æ���ң�$n���䵽����Զ�ĵط���",
		"$nһʽ������������˫����յ�أ������ݷ����У���$Nͷ����Ծ������",
		"$nһʽ�����ӻ�ͷ����˫�����������ƣ�����������Ʈ����ʱ����$N���������ơ�",
		"$nһʽ�����Ϲ鳲�������������ݰ㼱ת�������γ�һ�������У���$N������䡣",
	};

	return dodge_msg[random(8)];
}

virtual int valid_enable(string usage) { return (usage == "dodge") ; }

virtual int valid_learn(CChar * me) { return 1; }

virtual int practice_skill(CChar * me)
{
        if( me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ���������������");
		me->receive_damage("hp", 30);
        return 1;
}

SKILL_END;

