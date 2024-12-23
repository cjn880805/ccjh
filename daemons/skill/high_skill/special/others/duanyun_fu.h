// duanyun_fu.c ���Ƹ�

SKILL_BEGIN(CSduanyun_fu);

virtual void create()
{
	set_name( "���Ƹ�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  damage, dodge, lvl;
	}action[8] = {
		{"$N����ڿ�Ծ��˫�ֽ���$w����׼$n��ͷ�������϶��µؿ�����ȥ��ֻ�ڰ��������һ�ž޴�ĺ�Ӱ",
			300, 50, 0,},
		{"$NͻȻ��һ��������ǰ����������$w���¶��Ϸ���$n����·��$n����һ������ɫ����Ӱ�����Լ�����֪�����æ�м�",
		325, 45, 10,},
		{"$N��Ȼ����һ��������б����ǰ�����һ��������΢�Σ�����$w�ڿ��л���һ����Ӱ�����ٺ�ɨ$n���Ҽ磬��������",
		350, 40, 20,},
		{"$NͻȻ�������ҹ������漴���𣬾��������һ˲�䣬�ѵ�������$w����$n�����ߣ����ּȿ��Һ�",
		390, 35, 30,},
		{"$N˫�ֺ��$w��ƽɨ$nǰ�أ���ʽδʹ�Ͼ��Ѵ�ס�Ȼ���У�����ֱײ$n��С��",
		430, 40, 42,},
		{"$N����������ת��΢�ף�$n��$N¶����������æ������ȴͻȻ����$N��������ת����������$w��Ѹ�͵�ɨ���Լ�������",
		480, 30, 55,},
		{"$N����΢��������ͬһʱ�������������ҿ����師��$n�����$w�Ӳ�ͬ�ķ�λ�����Լ���һʱ�侹��֪������м�",
		540, 25, 68,},
		{"$Nǰ���͵�������һ�٣����Ҳ΢΢һ�𣬽��ž���ͷ��ͷ����ת��Ȧ��$w����������֮��ƽֱ�����ȵ�Ϯ��$n��$n������δ����㣬�ܿ����������Լ�����һ�ߣ����ɴ�ʧɫ",
		600, 65, 80,},
	};
	
	int level = me->query_skill("duanyun_fu", 1);
	for(int i = 8; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
			
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
		
		return & m_actions;
};

virtual int valid_enable(string usage) { return usage == "axe" || usage == "parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 150)
		return notify_fail("�������������");
	
	if (me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ����̫ǳ��");
	
	return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "axe"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("������������������˶��Ƹ���");
	
	me->receive_damage("hp", 25);
	return 1;
}

SKILL_END;

