// jinyu_quan.c ����ȭ

SKILL_BEGIN(CSjinyu_quan);

virtual void create()
{
	set_name( "����ȭ");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;

	return notify_fail("����ȭ�������������ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force,dodge, damage, lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһ�С������á���˫ȭһ��һ��, ��$n��ȥ",120 ,10 , 20,0 ,"����",},
		{"$Nһ�С������Ͻ𡹣��ó�һƬȭӰ��������磬����$n��ͷ��", 140, 20, 30, 20,"����",},
		{"$N��Ӱ����Ʈ������΢Ц��һ�С��������񡹣���������$n��$l", 150, 20, 45,40 ,"����",},
		{"$Nһ�С��������⡹��˫ȭһ�ϣ�$nֻ��������$N��ȭӰ", 160, 25, 60, 60,"����",},
		{"$N����$nһת���������ߣ�ȭ����磬��������$n������һ�С��������á�", 170, 30, 60, 80,"����",},
		{"ֻ��$Nһ�������˲���������Σ�ͻȻ�Ϳ��������ѵ�$n��ǰ����ȭ���������Ⱦ������ף�Ѹ����ף�һ�С���ʯ�ɽ𡹻���$n��ǰ��",180 ,35 , 80, 100,"����",},
		{"$Nһ�С��ڿ���𡹣�����$n���ƺ�$n��ȫ����ȭӰ����", 280, 30, 100,120 ,"����",},
	};
 
	int level = 0;

	for(int i=7; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("jinyu_quan", 1))
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
	return (usage == "cuff")  || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    if (me->query_skill("kurong_changong",1) < 20)
		return notify_fail("��Ŀ���������򲻹����޷�������ȭ��");

	if (me->query_weapon() )
		return notify_fail("������ȭ������֡�");

	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷�������ȭ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 50)
		return notify_fail("�������̫���ˡ�");

	if (me->query("mp") < 20)
		return notify_fail("�����������������ȭ��");

	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_combine(string combo) { return combo=="wuluo_zhang"; }

SKILL_END;
