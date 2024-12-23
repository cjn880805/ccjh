// huashan_ken.h ��ɽȭ��
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CShuashan_ken);

virtual void create()
{
	set("name", "��ɽȭ��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  dodge,parry,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nʹһ�С�����Ǭ������ȭ������������ʽʹ�ϣ���ȭ�Ѵ���ȭ֮�״�������׼$n��$l��������һȭ", -40, 40,0,"����",},
		{"$N��ȭͻȻ�ſ���ȭ�����ƣ�ֱ����Ϊ��ɨ��һ�С����￴��������$n��$l�к���ȥ",  -30, 30,10,"����",},
		{"$N���ֻ�����ԣ�����һȦ��һ�С������������$n��$l����", -30, 30,20,"����",},
		{"$N����һ������ȭ���һ�У���ȭʹ����÷��ŪӰ������$n$l", -30, 30,30,"����",},
	};
 	
	int level = 0;
	
	for(int i=4; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("huashan_ken", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    if( me->query_weapon() )
	   return notify_fail("����ɽȭ��������֡�");
    return 1;

}

virtual int practice_skill(CChar * me)
{
    if(  me->query("hp") < 30 )
   return notify_fail("������������ˣ���Ϣһ�������ɡ�");
    me->receive_damage("hp", 30);
    return 1;
}

SKILL_END;
