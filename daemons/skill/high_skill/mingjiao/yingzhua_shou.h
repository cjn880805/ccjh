
// yingzhua_shou.h ӥצ�֣���������
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSyingzhua_shou);

virtual void create()
{
	set_name( "ӥצ��");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenghuo_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;

	return notify_fail("ӥצ�ֱ���������ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N�ڿն��𣬰��һ�����һʽ��������á���Ѹ�͵�ץ��$n��$l", 100, 10,10 ,0 ,0 ,"����",},
		{"$N��������վ����˫�������չ��һʽ����ӥչ�᡹��˫צһǰһ��£��$n��$l", 120,15 , 15, 5,10 ,"����",},
		{"$Nһʽ���γ��ɡ���ȫ����б����Ծȥ������һ����˫צ����$n�ļ�ͷ", 150, 10, 10, 10, 20,"����",},
		{"$N˫צ�����Ͼ٣�ʹһʽ��ӭ����᡹��һ�����ֱ�Ϯ��$n����Ҹ����", 190, 15, 15, 15,30 ,"����",},
		{"$Nȫ�������ǰ��һʽ����ӥ��צ�����������������$n��ǰһ����ͻȻ���ֹ��Ȱ�ץ��$n���ؿ�", 250, 20, 20, 15, 40,"����",},
		{"$N���ػ��У�һʽ������հ�ա�������Ϯ�����д�Ѩ�����ַ�ץ$n���ɲ�", 310,25 , 25,20 , 50,"����",},
		{"$N��������צ���棬һʽ���������ա��������������ƿն�����Ѹ���ޱȵػ���$n", 380, 25, 25,25 ,55 ,"����",},
		{"$N�ڿո߷����ɣ�һʽ��ӥ�����������ж�ʱ�Գ�һ������צӰ����������$n",470 , 40, 40, 30, 60,"����",},
	};
 		
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("yingzhua_shou", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "hand") ;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
		return notify_fail("��ӥ�ֱ�����֡�");
	if ( me->query_skill("hand",1) < 20)
		return notify_fail("��Ļ����ַ�̫��ˣ��޷�ѧӥצ�֡�");
	if ( me->query_skill("shenghuo_shengong", 1) < 40)
		return notify_fail("���ʥ���񹦻������ң��޷�ѧӥצ�֡�");
	if ( me->query("max_mp") < 200)
		return notify_fail("�������̫�����޷���ӥצ�֡�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ( me->query("mp") < 20)
		return notify_fail("�������������ӥצ�֡�");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;

}

SKILL_END;
