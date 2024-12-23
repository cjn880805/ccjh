//mantian_xing.h ������

SKILL_BEGIN(CSmantian_xing);

virtual void create()
{
	set_name( "������");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, dodge, lvl;
	}action[13] = {
			{"$N������ˣ�һ�С���¶��â��������$w����һ�㺮â����$n",
			   30, 40, 0,},
		   {"$N����΢��ǰһ�죬ʹ����է���ǳ���������$w��ֱ����$n��˫��",
		   40, 45, 9,},
		   {"$Nһ����Х��ʩչ������ҹ���ǡ�������΢��������$w��Ȼ���Ϸ������˸�Ȧ�����Ѹ��Ϯ��$n������",
		   50, 50, 18,},
		   {"$Nʹһ�С��ǹ���˸����ͻȻ�������һ�����������ڿ���ص�һ˲�䣬$n��Ȼ���ּ��㺮����˸������Ϯ���Լ�",
		   55, 55, 27,},
		   { "$N����һ�ӣ�һ�С���â��������$n��������$N�����$w�������Լ�����ǰ��Ѩ�����˽���ȴͻȻת�����Լ��ĺ���",
		   60, 60, 36,},
		   {"$N����������һ����ʹ����׹��֮�ǡ�������$wƽֱ������$n���ʺ�ȴ�ּ��ϰ���ʹ֮��;��������$n������",
		   70, 70, 45,},
		   {"$N����һԾ����ʩչ��������֮�ǡ��������$w�������±�ֱ������$n��ͷ��",
		   85, 80, 54,},
		   {"$Nԭ��һ����ת���漴˫��һ����$w��ƮƮ�����ط���$n��ԭ�������ǡ��ǳ����롻",
		   110, 85, 63,},
		   {"$Nʹ��һ�С��ǹ���𡻣�ǰ��һ�壬�漴�����������$w����˿������ȴ��Ѹ���ޱȵ�����$n��ǰ��",
		   120, 90, 72,},
		   {"$NͻȻ��������ˣ�ʹ�����ǿ�ը�ס���˫����ǰһ�ƣ�����$w��������������������$n",
		   140, 95, 81,},
		   {"$Nʩչ�����ǻ����ա���ԭ�ز����������΢΢��ǰһ��������$w����һ�㺮���Բ��������$n",
		   160, 100, 90,},
		   {"$N΢΢����ʹ�����ǹ����ɡ�����ӰƮ��������$n�پ�ʮ�ִ��ۣ�ȴ��$N�����$w��Ю�ŵ��ϵ�ɳʯ�Լ���Χ����ҳ�����Լ�",
		   190, 105, 99,},
		   {"$N��Ȼ��̾һ����ת����У�$n�����ɼ䣬ȴ����ǰ�Ѿ���$w��Ӱ�ӣ��ۿ��޴��ɶ��ˣ�ֻ�����о��ǡ��������꡻�ˣ�$n���ɴ�ʧɫ",
		   220, 110, 110,},
		};
 
  	int level = me->query_skill("mantian_xing", 1);
	for(int i = 13; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="throwing" ||usage=="dodge"||usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("force", 1) < 20)
		return notify_fail("����ڹ��ķ���򲻹����޷�ѧ�����ǡ�");
    if (me->query_skill("dodge", 1) < 20)
		return notify_fail("����Ṧ��򲻹����޷����������ǡ�");
    if (me->query_dex() < 25)
		return notify_fail("������������ɣ��޷����������ǡ�");

    return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

    if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "throwing"))
		return notify_fail("��ʹ�õ��������ԡ�");
    if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
    if (me->query("mp") < 30)
		return notify_fail("������������������ǡ�");
    
	me->receive_damage("hp", 30);
	return 1;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( random(me->query_skill("mantian_xing",1)) > 50) 
	{
		victim->apply_condition("anqi_poison", random(2) + 1 +
			victim->query_condition("anqi_poison"));
    }
	return "";
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[8][80]={	
		{"$n��һ����һ�Σ��漴�ص�ԭ�أ����ɵض����$N��һ�С�",},
		{"$n����Ծ��һ���շ�����˳������һ�ߡ�",},
		{"$n�������Ա�һ�ݣ�������$N�����൱�ľ��룬$N��һ����ȻʧЧ��",},
		{"$n������ϣ������Ծ��$N��������$N�ı���",},
		{"$n���μ�����б��ǰһ������Ȼ�Ѿ��㿪��$N����һ�С�",},
		{"$N��ǰһ����ȴ��$n��Ȼ�����Լ�������֮Զ��ȴû��$n��ζ���Լ��Ĺ�����",},
		{"$Nһ��������$n��û����Ӱ��$N��ת��ȴ��$n���Ƕ����Լ����֡�",},
		{"$Nһ�й�����$n��Ȼ������$NãȻ�Ĺˣ�ȴ����$n��Ӱ�ӣ�",},
	};

	return dodge_msg[random(8)];
}


SKILL_END;

