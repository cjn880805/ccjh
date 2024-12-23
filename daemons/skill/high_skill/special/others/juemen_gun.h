//juemen_gun.h ���Ź�
//LANWOOD 2000-01-04

SKILL_BEGIN(CSjuemen_gun);

virtual void create()
{
	set_name( "���Ź�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, dodge, lvl;
	}action[5] = {
		{"$Nб���ǰһ���������죬����$w��ɨ$n��$l",
			350, 60,},
		{"$N��Ȼֱ������գ��ܾ�Ҳ������Ӱ��$n����Ѱ�䣬$N�ѷ������£�$w����$n��$l",
		400, 55,},
		{ "$Nԭ��һ���������ȴ����ص�һɲ�ǣ�������$nƽ�ɹ�ȥ������$wָ��$n��$l",
		350, 70,},
		{"$NͻȻһ����ת��$w��ɨһȦ��Ю�����ҵľ�������$n��$l",    
		450, 85,},
		{ "$N��ǰ�˳���˳��һ�������ŷ�����������$wб���ϻ���$n��$l",
		400, 75,},
	};
 
  	int level = random(5);
	
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="staff" || usage=="parry"|| usage=="dodge"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷������Ź���");
    return 1;
}


virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
    if (me->query("mp") < 20)
		return notify_fail("����������������Ź���");
    me->receive_damage("hp", 20);
    return 1;
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[5][80]={	
		{"$n�ҽ�����һ��Ծ�������$N�Ĺ�����",},
		{"$n���Ա��˳���˳��һ��������һ�ߡ�",},
		{"$nб���ǰһ���������죬$N��һ���䵽�մ���",},
		{"$n��Ȼֱ������գ��ܾ�Ҳ������Ӱ�������������$N�ı���",},
		{"$nͻȻһ����ת��$N����һ�л�����һ�ߡ�",},
	};

	return dodge_msg[random(5)];
}

SKILL_END;

