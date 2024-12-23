//jinwu_daofa.h ���ڵ�

SKILL_BEGIN(CSjinwu_daofa);

virtual void create()
{
	set_name( "���ڵ�");

}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force, dodge,  parry, damage, lvl;
	}action[10] = {
		{"$N�ص����գ�һ�С�����鮵������������¶��ϻ��˸��뻡����$n��$l��ȥ",
			120, -10, 5,15,0,},
		{"$N�����������⣬һ�С�÷ѩ���ġ�������$w��ֱ����$n��$l",
        130, -10, 10, 20, 12,},
		{"$Nһ�С�ǧ��ѹ�ա���$w�ƾ�������ˢ��һ�����϶�����$n����",
        140, -5, 5, 25, 18,},
		{"$N���ַ�ִ������һ�С����ս�ġ�����һ����$wֱ��$n�ľ���նȥ",
        160, 5, 5, 30, 24,},
		{"$Nһ�С��������ء����������⻯����㷱�ǣ���$n��$l��ȥ",
        180, 10, 5, 35,30,},
		{ "$N˫�ֺ�ִ$w��һ�С�����֮������š��ת������ֱ����$n��˫��",
        210, 15, 15, 40, 36,},
		{"$Nһ�С����ò����������$w����һ����ƽʮ�֣���$n�ݺ���ȥ",
        240, 15, 15, 50, 42,},
		{"$N��ת�����׼�Լ���һ�С�������֦����ȫ��һ��������$w��$n����նȥ",
        280, 20, 10, 60, 48,},
		{"$Nһ�С��������ס���$w�ĵ���·𻯳�һ�ش����棬��$n����Χ��",
			320, 10, 20, 75, 54,},
		{"$N����ƽָ��һ�С��󺣳�ɳ����һƬƬ�йǵ�����쫷�����$n��ȫ��",
        370, 5, 25, 90, 60,},
	};
 
  	int level = me->query_skill("jinwu_daofa", 1);
	for(int i = 10; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
        return notify_fail("�������������");
	return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

    if (!(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "blade"))
               return notify_fail("��ʹ�õ��������ԡ�");
    if (me->query("hp") < 50)
               return notify_fail("����������������ڵ�����");
    me->receive_damage("hp", 30);
    return 1;
}

SKILL_END;

