
// shenghuo_ling.h ʥ���
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSshenghuo_ling);

virtual void create()
{
	set_name( "ʥ���");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,damage;
		char damage_type[5];
	}action[] = {
		{"$N̤��һ���������ڵ���һ�����ѱ�ס��$nС�ȡ�ʮָ��ס��$nС���ϵġ��ж�������������Ѩ��$nֻ���°��������Ѷ������һ��", -10, 30,"����",},
		{"ͻȻ֮�䣬$N���λζ���ͬʱ�۽�������$w��$n���ϻ�ȥ�����²�֪����ƶ���������䡣����ͬʱץס$n���죬һ��֮�£���$n����ԶԶ���˳�ȥ", -20, 50,"����",},
		{"$N����ֱ�������ֳ�$w��$n����������䡣������һ˲֮�䣬$n����������Ȼһȭ����$n���ϡ�$nһ�����ģ�$N���$w����$n����", -30, 70,"����",},
		{"$N���ط��֣������Ǳ�$wβ�����ϵ����ĵ�һ�죬���ô���$n����", -20, 90,"����",},
		{"$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�һʹ���ѱ�$N����ײ��", -20, 110,"����",},
		{"$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�$N����$w���Ӻ�ɨ��ͻȻ�����������Ľ��$n��֪�Է��Ǻ����⣬���뻹�Ǳ�֮Ϊ�������̤��һ������ǰ�׹⼱����$N��$w�ѵ��Ҽ�", -20, 130,"����",},
		{"$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�һʹ���ѱ�$N����ײ��", -20, 150,"����",},
	};
 		
	int level = 0;
	
	for(int i=7; i>0; i--)
	{
		if( (i - 1) * 10 < me->query_skill("shenghuo_ling", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	int lvl =  me->query_skill("qiankun_danuoyi", 1);
	
	if ( EQUALSTR(me->querystr("gender"), "����") && lvl > 49)
		return notify_fail("�����첻�㣬��ѧ��ȥ�����߻���ħ��");
	
	if ( me->query("max_mp") < 50)
		return notify_fail("����ô����������ѧʥ�����");
	
	if ( me->query_skill("jiuyang_shengong", 1) < 20)
		return notify_fail("��ľ����񹦻�򻹲�����ѧ����ʥ�����");
	
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if ( me->query("hp") < 50)
		return notify_fail("�������������ʥ�����");
	me->receive_damage("hp", 40);
	return 1;
}

SKILL_END;
