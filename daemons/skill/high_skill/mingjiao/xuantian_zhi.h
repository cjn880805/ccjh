
// xuantian_zhi.h ��������ָ
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSxuantian_zhi);

virtual void create()
{
	set_name( "��������ָ");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "wuzheng_xinfa") || EQUALSTR(arg, "xuantian_shengong"))
		return 1;

	return notify_fail("��������ָ�����������񹦻������ķ����ʹ�á�");
}


virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl,damage;
		char damage_type[5];
	}action[] = {
		{"$N��ָ�ӳ���һʽ����Ȼ���꡹������$n����Ե", 100, 5, 0,100 ,"����",},
		{"$Nȫ��֮������һָ��һʽ���������项��ָ��$n����ǰ",150 , 5, 15, 125,"����",},
		{"$N�����������Ѩ������һʽ��������֡�����$n��$l����", 200, 8, 25, 145,"����",},
		{"$N˫Ŀŭ�ӣ�һʽ���������ġ���˫ָ����$n�Ķ�����硢�ۡ��ء���", 280,5 , 65,165 ,"����",},
		{"$Nһʽ���������ˡ��������������⣬��ָ���Ƶ���$n��$l", 350, 15, 80,180 ,"����",},
		{"$N���������ʮָ�濪��һʽ�����߱��项��Сָ����$n��̫ԨѨ", 430, 20, 100, 190,"����",},
		{"$N˫�ų�������������һʽ���������ࡹ����$n��ȫ��", 550, 25,120 , 300,"����",},
	};
	
	int level = 0;
	
	for(int i=7; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("xuantian_zhi", 1))
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
	return (usage == "finger") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
		return notify_fail("����������ָ������֡�");
	if ( me->query_skill("finger", 1) < 30)
		return notify_fail("��Ļ���ָ����������ʵ���޷�����������ָ��");
	if ( me->query("max_mp") < 500)
		return notify_fail("�������̫�����޷�����������ָ��");
	if ( me->query_skill("xuantian_shengong", 1) < 70)
		return notify_fail("��������񹦻���㣬�޷�����������ָ��");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("��ľ�̫���ˡ�");
	if ( me->query("mp") < 20)
		return notify_fail("���������������������ָ��");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

SKILL_END;




