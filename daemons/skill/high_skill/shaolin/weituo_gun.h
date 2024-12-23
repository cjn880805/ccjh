SKILL_BEGIN(CSweituo_gun);

virtual void create()
{
	set_name( "Τ�ӹ�");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("Τ�ӹ����������ֶ����ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[8] = {
		{"$Nһ�С���ʯ���ġ�������$w�����ѵ�ˮ�㣬������$n������Ҫ����ȥ",
			160, 5, 5, 10, 0,},
		{"$N��$wƽ���ؿڣ�һš��һ�С�����ͣ�桹��$w�͵�����$n�ľ���",
		180, 5, 10, 15, 8,},
		{"$Nһ�С�ƽ�����ɡ���ȫ���������ڵ��ϴ����ת���ٹ���$n���ظ����ȥ",
		210, 5, 15, 20, 16,},
		{"$N����һ��������һ�С��������硹��$wЮ��������Ѹ��ɨ��$n������",
		250, 15, 5, 25, 25,},
		{"$Nһ�С����Ǹ��¡��������һ�����˱Ƴ�һ��ֱ�ߣ����ǰ�����$n��$l",
		300, 20, 15, 30, 35,},
		{"$N˫�ֳֹ����˸���ش�Ȧ��һ�С���ϼ���ա���һ����Բ�����л�����ײ��$n���ؿ�",
		350, 20, 15, 35, 44,},
		{"$Nһ�С�Ͷ�޶�������$w�߾٣����������֮�ƶ�׼$n�����鵱ͷ����",
		410, 25, 20, 40, 52,},
		{"$NǱ��������һ�С������麣����$w��ʱ�������ɣ�������ֱ��$n���ؿ�",
		470, 30, 25, 50, 60,},
	};

	int level = me->query_skill("weituo_gun", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
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
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "club"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("�������������Τ�ӹ���");
	me->receive_damage("hp", 25);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��");
	return 1;
}

virtual int valid_enable(string usage) {return  (usage == "club") || (usage == "parry"); }

SKILL_END;