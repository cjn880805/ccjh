//fengyu_bu.h ����Ʈ�㲽

SKILL_BEGIN(CSfengyu_bu);

virtual void create()
{
	set_name( "����Ʈ�㲽");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={	
		{"$nһ�����ʹ������������䡹���ó�������Ӱ����$N������ʽ�������Ρ�"},
		{"$nʹ��һ�С�ڤڤ��ȥ�١�����Ȼ�������࣬���$N���˸��ա�"},
		{"$nһ����ĮĮ�����ء�������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�"},
		{"$n˫��һ�㣬бб����ʹ����������֡�������$N��ࡣ"},
		{"$n����һҡ���ó�������Ӱ��һ�С�ɽ�紵���֡������$N�Ĺ��ơ�"},
		{"$nһ�С�ǧ��ͬһɫ������Ծ��ٿ��������$N���"},
	};

	return dodge_msg[random(6)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

SKILL_END;

