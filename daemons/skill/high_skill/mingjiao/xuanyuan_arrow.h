//xuanyuan_arrow.h ��ԯ��
SKILL_BEGIN(CSxuanyuan_arrow);

virtual void create()
{
	set_name( "��ԯ��");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenghuo_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;

	return notify_fail("��ԯ������������ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, dodge, parry;
	}action[7] = {
		{"$N��Ȼ������Х����Ծ�ڿգ�ȡ�����ҡ�\nֻ�������촦��$w�ѵ�$n��磬�ۿ���Ҫ�Դ�������\n���С������ʯ����Ȼ�д�ʯ֮��",
		25, -20, 10,},
		{"$N�������󣬸���һ�С����ĸ�������$w�Ѵ���Х����$nǰ�ط�ȥ",
		35,  20, 20,},
		{"ͻȻ�䣬$N�����������ȥ������$n����֮�⡣\n$n����׷����$N��Ȼת����һ�����ٲ������\n$w�Ѵ����ƿ�֮����ֱ��$n����",
		20, -10, -10,},
		{"$N������������׼$n��������һ����\n$n�������ܣ�ͻȻ���ֲ�����������������޴���ȥʱ��\n$N�乭�����ֻ��һ֧$w��$n��$l���ɶ���",
		25, -20, 10,},
		{"$N��ָ΢����$nֻ������ಡ���һ����$w�ѵ�$lǰ���硣\n$nû�ŵ����С��������ա��������֮�죬���������޴�",
		35, 10, -10,},
		{"$N��վ�ȣ�����͸�������Ĺ������£�$w��һ�����$n��$l",
		40, 20, 20,},
		{"$n��������������һ����$N������Ҫ���ܣ�ͻȻŤ������\nһ�С�Ϭţ���¡�������$w��ͬ����һ�㣬ֱ����$n��$l",
		30, -10, -10,},
	};
 
	int max = me->query_skill("throwing", 1) / 15;
	if ( max > 7) max = 7;

	int level = random(max);

  	m_actions.set("action", action[level].action);
	m_actions.set("damage", action[level].damage);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="throwing" || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;
  
	if(me->query_skill("throwing",1) < 20)
		return notify_fail("����������죬�����ڼ�ս���ϼ�������У�");
	if( me->query("max_mp") < 50 )
		return notify_fail("�����������������������");
	if( !( weapon = me->query_weapon()) || DIFFERSTR(weapon->querystr("skill_type"), "throwing") )
		return notify_fail("�����޹�����������ʦ�����̣�");

	return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if( ! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "throwing") )
		return notify_fail("û�й��������׼ͷ��");

	if( me->query("hp") < 40 || me->query("mp") < 10)
		return notify_fail("����������㣬����������");
	me->receive_damage("hp", 30);
	me->add("mp", -5);
	
	message_vision("$N�乭�����һ�����к��ģ�", me);
	g_Combatd.throw_weapon(me, NULL, weapon, 0);

	return 1;
}


SKILL_END;

