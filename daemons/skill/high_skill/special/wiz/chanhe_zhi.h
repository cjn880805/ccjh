
// chanhe_zhi.h �κ�ָ
//code by oho
//date : 2001-6-02

SKILL_BEGIN(CSchanhe_zhi);

virtual void create()
{
	set_name( "�κ�ָ");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "douzhuan_xingyi") )
		return 1;

	return notify_fail("�κ�ָ�����Ľ�ݼҵ��ڹ�����ϡ�");
}


virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl,damage;
		char damage_type[5];
	}action[] = {
		{"$Nһָ������������Ϣ��Ϯ��$n��ȫ��������Ѩ�����ǲκ�ָ�ľ��С����ͻ��", 100, 5, 0,10 ,"����",},
		{"$N��ָ������ʹ����Ѫ���ǽ塯����$n����ǰ",150 , 5, 15, 25,"����",},
		{"$N���һ��������ʳָȫ��������һ�С�ǧţնȱ������$n���ʺ�", 200, 8, 25, 45,"����",},
		{"$N�����죬һʽ����ɽѪ�䡯��ָ���ɵ���$n��ն�¡�", 280,5 , 65,65 ,"����",},
		{"$Nһʽ�������ݽ桯�����������֣�����ָ���ĳ��ݺ���ɨ��", 300, 15, 80,80 ,"����",},
		{"$Nʮָ�ҵ㣬����Ĵ������������һ�С��򻧹�ޡ�", 330, 20, 100, 90,"����",},
	};
	
	int level = 0;
	
	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("chuanhe_zhi", 1))
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
		return notify_fail("���κ�ָ������֡�");
	if ( me->query_skill("finger", 1) < 30)
		return notify_fail("��Ļ���ָ����������ʵ���޷����κ�ָ��");
	if ( me->query("max_mp") < 350)
		return notify_fail("�������̫�����޷����κ�ָ��");
	if ( me->query_skill("douzhuan_xingyi", 1) < 30)
		return notify_fail("��Ķ�ת���ƻ���㣬�޷����κ�ָ��");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("��ľ�̫���ˡ�");
	if ( me->query("mp") < 20)
		return notify_fail("��������������κ�ָ��");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

SKILL_END;
