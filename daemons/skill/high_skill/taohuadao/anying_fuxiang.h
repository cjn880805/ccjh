//anying_fuxiang.h ��Ӱ����

SKILL_BEGIN(CSanying_fuxiang);

virtual void create()
{
	set_name( "��Ӱ����");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[6][80]={	
		{"$nһ������������ͷ��������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�"},
		{"$nʹ��һ�С���Į����ֱ������Ȼ�������࣬���$N���˸��ա�"},
		{"$n����һҡ���ó�������Ӱ��һ�С���Ӱ��б���������$N�Ĺ��ơ�"},
		{"$nһ�С���������ˮ������Ծ��ٿ��������$N���"},
		{"$n��һҡ����һ�Σ�һ�С����֪����������������"},
		{"$n˫��һ�㣬бб����ʹ����б���ӻ��ɡ�������$N��ࡣ"},
	};

	return dodge_msg[random(6)];
}

virtual int valid_enable(string usage) { return (usage == "dodge") ; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

virtual int practice_skill(CChar * me)
{
        if( me->query("hp") < 30 )
            return notify_fail("�������̫���ˣ���������Ӱ���㡣");
        if (me->query_skill("yan_shuangfei", 1) < 30)
	        me->receive_damage("hp", 10);
		me->receive_damage("hp", 20);
        return 1;
}

SKILL_END;

