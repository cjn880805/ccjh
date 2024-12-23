//sanyin_wugongzhao.h �������ץ
SKILL_BEGIN(CSsanyin_wugongzhao);

virtual void create()
{
	set_name( "�������ץ");
	set("valid_force", "huagong_dafa");
}

virtual int valid_enable(string usage) { return usage=="claw" ||  usage=="parry";}
virtual int valid_combine(string combo) { return combo=="xingxiu_duzhang"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
        return notify_fail("���������צ������֡�");
    if (me->query("max_mp") < 200)
        return notify_fail("�������̫�����޷����������צ��");

	return 1;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( random(me->query_skill("poison",1)) > 150) 
	{
		victim->apply_condition("xx_poison", random(60) + 1 +
			victim->query("condition/xx_poison"));
    }
	return "";
}
virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[255];
		int force, dodge, damage;
		int lvl;
	}action[4] = {
		{"$Nצ����ף��ǽ�¡�����϶���˺��$n��$l",
			120, 10, 70, 10,},
		{"$N˫�ֺ������֣�צצ���Ȱ�ץ��$n��$l",
			150, 10, 85, 10,},
		{"$N����Χ$nһת��צӰ�ݺ�����������$n��$lץ��",
			180, 10, 85, 10,},
		{"$Nһ���ֽУ�һצ���ֱ��$n�������",
		280, 10, 100, 100,},
	};

	int level = me->query_skill("sanyin_wugongzhao",1);

	for(int i = 4; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].damage);
			m_actions.set("dodge", action[level].dodge);
	
			break;		
		}

	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	
	if (me->query("mp") < 20)
		return notify_fail("��������������������צ��");
	
	me->receive_damage("hp", 30);
    me->add("mp", -10);

	return 1;
}

SKILL_END;