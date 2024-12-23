// yanxing_dao.h ���е���
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSyanxing_dao);

virtual void create()
{
	set_name( "���е���");
	set("valid_force", "linji_zhuang");

	Magic_t * magic;

	magic = add_magic("huanying", do_huanying);
	magic->name = "���λ�Ӱ";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge;
		char damage_type[5];
		int  lvl;
	}action[] = {
		{"$Nʹ�������־����������������е�бб������һ���׹�����$n��$l", 170, 30, "����", 0,},
		{"$Nʹ�������־��������ֻ��������һ�������ֵ���ͷֱ��������һ����âֱ��$n��$l����", 240, 15, "����", 10,},
		{"$Nʹ�������־��������ֺ󳷣���б���мܣ�˳���¶磬������Ҹ�´�������ס�Է����󣬵��ⲻָͣ��$n��$l", 300, 5, "����", 20,},
		{"$Nʹ�������־�����������ϣ�����ͻ�������ִ����Է�$n���У����ֵ��͵ص�������$n���ڵ�����",350 , -5, "����", 30,},
		{"$Nʹ�������־������������էȻһ�������ּ��ٲ�ס$n���֣����е�һ�������磬������ס$n��$l", 400, 20, "����", 40,},
		{"$Nʹ�������־����������䣬����Ʈ����׽����͸����$n�ۻ�����֮�ʣ����ֵ��ⷴ����$n��$l", 425, 15, "����", 50,},
		{"$Nʹ����̽�־�������ӯ��һ����ת�����ų��������ֵ�������ǰ��ֱ��$n��$l",450 ,20 , "����", 60,},
		{"$N����ʹ�������־�����������ת�������Ķ�������$n��ת�����е���������$n��ȫ���������Լ����µĵ����У��޴�����", 500, 25, "����", 70,},
		{"$N����ʹ�������־���������ص�������$nǰ����һ�������ⶸ�֣�����ǧ���������ڶ���", 500, 25, "����", 80,},
		{"$N����ʹ�������־�����˫�ֽ��棬������߫��$nʵ�ڿ����嵶�������˺����ܣ�ֻ��һ����ֱ�ƹ���", 500, 25, "����", 90,},
	};
	
	int level = 0;
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("yanxing_dao", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "blade") || (usage == "parry");}

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");

	if (me->query("max_mp") < 50)
		return notify_fail("�������������");
    if (me->query_skill("linji_zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ���̫ǳ��");
    if (me->query_skill("blade", 1) < me->query_skill("yanxing_dao", 1) )
		return notify_fail("��Ļ����������̫ǳ��");
    return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("����������������е���");
	me->receive_damage("hp", 10);
	return 1;
}

//perform 
static int do_huanying(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target || ! me->is_fighting(target) )
		return notify_fail("�����λ�Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʲô��Ц��ûװ������ôʹ�����λ�Ӱ����");
	
	if( DIFFERSTR(me->query_skill_mapped("blade"), "yanxing_dao"))
		return notify_fail("����������е���ʹ�á�");
	
    if (me->query_skill("yanxing_dao", 1) < 60 )
        return notify_fail("�����е���������죬ʹ���������λ�Ӱ����");
    
	if (me->query_skill("linji_zhuang", 1) < 90 )
        return notify_fail("���ټ�ׯ��򲻹��������λ�Ӱ��������ʽ��");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
    
	if (me->query("max_mp")<300)
        return notify_fail("���������Ϊ���㣬�޷����㡸���λ�Ӱ����������");
    
	if (me->query("mp")<200)
    {
        return notify_fail("����������������û�ܽ������λ�Ӱ��ʹ�꣡");
    }
    
	msg = "$N���һ����ȫ���Ĵ��ζ���$nֻ����$N����������Ӱ�����쵶��ϯ�������$n����һ�ܣ���$N������·��$nֻ��סһ����";
    message_vision(msg.c_str(), me, target);
	
	//���������嵶�ķ���
    g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
    
    me->add("mp", -200);
    me->start_busy(random(5));
    //if(!target->is_fighting(me)) 
	//	target->kill_ob(me);
    return 1;
	
}

SKILL_END;




