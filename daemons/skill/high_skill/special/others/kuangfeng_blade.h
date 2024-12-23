//kuangfeng_blade ��絶��
//by sound
//2001-07-21

SKILL_BEGIN(CSkuangfeng_blade);

virtual void create()
{
	set_name( "��絶��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force, dodge,  parry, damage, lvl;
	}action[10] = {
		{"$N����$w��ӣ�һ�С���ƽ�˾���������ƽ��ʵ��Ѹ�ٵ���$n��$l��ȥ",
			150, 10, 5, 10, 0,},
		{"$Nһ�С�������ӿ�����ҽ�һ�㣬$w��������������ӿ$n��$l",
		170, 35, 10, 20, 10,},
		{"$Nһ�С������ơ����ֱ�һ�գ�����һ�����϶���ն��$n",
		190, 25, 5, 25, 20,},
		{"$Nһ�С�������ɢ����������ˣ�$wȴ����ǰ����һ��Բ��������$n��$l",
		210, 15, 5, 35, 32,},
		{"$N���������ϣ�һ�С�������ড�������$n��ǰ��$w�Ϳ�$n��$l",
		230, 20, 5, 50, 45,},
		{"$N���ٻ���$w��ʹ��һ�С����в��򡹣�����һƬ��������$n��$l",
		260, 15, 15, 65, 58,},
		{"$Nһ�С��絶˪������ֻ�����쵶����˸�����ص�Ӱ��$n��ȫ��ӿȥ",
		290, 20, 15, 85, 71,},
		{"$Nʹһ�С���۵糸����$w��������Ӱ��$n��$lӿȥ",
		320, 40, 10, 105, 86,},
		{"$Nһ�С�����Ʈҡ����$w������˸�������ƻ�����ر�$n��$l",
		350, 10, 20, 125, 101,},
		{"$NŲ��С�ˣ�һ�С��绨ѩ�¡�������$w���赭д�ػӳ�һ�����漴�֡��ৡ�������������������������$n��$l",
		400, 20, 25, 150, 120,},
	};
	
	int level = me->query_skill("kuangfeng_blade", 1);
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
	if (me->query("max_mp") < 300)
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
		return notify_fail("���������������絶����");
    me->receive_damage("hp", 30);
    return 1;
}

SKILL_END;

