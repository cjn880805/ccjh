//qingdie_shenfa.h �����

SKILL_BEGIN(CSqingdie_shenfa);

virtual void create()
{
	set_name( "�����");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[4][80]={	
		"ֻ��$nһ�С�����Ȫ�ߡ�������Ʈ�������������$N��һ�С�",
		"$nһʽ��ƾ���ٷ硹�����λζ�����һ��Ʈ�����ܿ���$N��һ�С���",
		"$nʹ���������ɡ���һ�����Ľ��󷭳����ܿ���$N���������ơ�",
		"$nһ�С�˫��������������ת��$Nֻ����ǰһ����$n������$N�����",
	};

	return dodge_msg[random(4)];
}

virtual int valid_enable(string usage) { return (usage == "dodge") ; }

virtual int valid_learn(CChar * me)
{
	if(me->query_skill("dodge",1) < 20)
		return notify_fail("��Ļ����Ṧ��򲻹���");

    return 1;
}

virtual int practice_skill(CChar * me)
{
        if( me->query("hp") < 40 )
            return notify_fail("�������̫���ˣ��������������");
        
		me->receive_damage("hp", 30);
        return 1;
}

SKILL_END;

