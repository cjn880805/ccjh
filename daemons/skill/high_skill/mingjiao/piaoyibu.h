//piaoyibu.h Ʈ�ݲ�

SKILL_BEGIN(CSpiaoyibu);

virtual void create()
{
	set_name( "Ʈ�ݲ���");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={	
		{"$nһ�������ضɺ�����Ծ�����ߣ������$N��һ�С�"},
        {"$n�������һ�ݣ�ʹ��һ�С������䳾�����ܹ���$N�Ĺ�����"},
        {"$nʹ��������ɳ����ǡ�ö����$N�Ĺ��ơ�"},
        {"$nһ�С�����öݡ�����̬����ض��˿�ȥ��"},
	};

	return dodge_msg[random(4)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

virtual int practice_skill(CChar * me)
{
        if( me->query("hp") < 40 )
                return notify_fail("�������̫���ˣ�������Ʈ�ݲ�����");
        if (me->query_skill("piaoyibu", 1) < 30)
                me->receive_damage("hp", 10);
        else if (me->query_skill("piaoyibu", 1) < 60)
                me->receive_damage("hp", 20);
        else
                me->receive_damage("hp", 30);
        return 1;
}

SKILL_END;

