//youlong_staff.h �����ȷ�

//coded by Fisho
//data: 2000-11-29

SKILL_BEGIN(CSyoulong_staff);

virtual void create()
{
	set_name( "�����ȷ�");
	set("valid_force", "shenghuo_shengong");

	Magic_t * magic;

	magic = add_magic("chuanyun", do_chuanyun);
	magic->name = "��������";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar *me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int  force,dodge, damage,lvl;
			char damage_type[5];
	}action[]={
		{"$N��߳һ����˫�ֲ��٣����ⶸ�ɣ���ʱ���Ⱥ�һ�����ֱ��$n��ȥ��",  10,-45,  220, 10,"����",},
		{"$N������Ӱէ�ţ��������ص�⣬������ͻ�֡���Ȼ��ɨ��", 20,-45,  250, 25,"����",},
		{"$Nʹ��һ�С��������֡�������$w�������ѩ�����������֣����Ȳ���$n��$l��", 30,-40,  270, 40,"����",},
		{"$N����$wһ�Σ�����ȻΪ˫��һ�С�˫��Ϸˮ�����ֱ�Ϯ��$n������Ҫ����",  40,-50,  340, 60,"����",},
		{"$N����$w�ն���������������Х����һ�С���Х��������ֱ��$n��$l��ȥ��",  50,-60,  380, 85,"����",},
		{"$N������ת������$wһ�С�����������������$n��$lɨȥ��",  60,-50,  450, 120,"����",},
		{"$N��ʽһ�䣬ɱ���Ĳ���չ������������ȥ�޻ص�ɱ�С���Х���졹��", 70,-80,  650, 250,"����",},
	};
	for(int i = 7; i > 0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("youlong_staff", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	if (me->query_temp("teapot/youlong"))
	{
			m_actions.set("action", "$HIY$NԾ�����ɣ����ڰ�գ���ʽ���䣬���������ơ��羪�κ��ˣ���ת������䡣$COM");
			m_actions.set("force", 100);
			m_actions.set("dodge", -60);
			m_actions.set("damage", 700);
	}

	return & m_actions;
}

virtual int valid_enable(string usage)
{ 
	return (usage == "staff") || (usage == "parry"); 
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");

	if ( DIFFERSTR(me->querystr("family/family_name"), "����"))
		return	notify_fail("�����ȷ����������̵��ӷ�����ѧϰ��");

	if(!me->query("mj/youlong_staff"))
		return notify_fail("û�еõ���ʦָ�㣬����ѧ���������������أ�");

	if (me->query_skill("staff", 1) < 30)
		return notify_fail("��Ļ����ȷ�̫���������������ȷ���");

	if(me->query("mj/youlong_staff")*50<me->query_skill("youlong_staff", 1))
		return notify_fail("��ֻ���������������ڣ��޷�������������ѧϰ��");

 	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon ;
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if (me->query("hp") < 50)
		return notify_fail("������������������ȷ���");

	if ( DIFFERSTR(me->querystr("family/family_name"), "����"))
		return	notify_fail("�����ȷ����������̵��ӷ�������ϰ��");

	if (me->query_skill("staff", 1) < me->query_skill("youlong_staff", 1))
		return notify_fail("��Ļ����ȷ���򲻹������ܼ������������ȷ��ˡ�");

	if(me->query("mj/youlong_staff")*50<me->query_skill("youlong_staff", 1))
		return notify_fail("��ֻ���������������ڣ��޷���������������ϰ��");

	me->receive_damage("hp", 20);
	return 1;
}

static int do_chuanyun(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon ;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("���������ơ�ֻ�ܶ�ս���еĶ���ʹ�á�");

	if ( DIFFERSTR(me->querystr("family/family_name"), "����"))
		return	notify_fail("���������ơ����������̵��ӷ�����ʹ�á�");

	if (! (weapon = me->query_weapon())	|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if (me->query("mp")<400)
		return notify_fail("���������Ϊ���㣬�޷����㡸�������ơ���������");

	if (me->query_skill("shenghuo_shengong", 1) <200)	
		return notify_fail("���ʥ���ķ����̫ǳ��");

	if (me->query_skill("youlong_staff", 1) < 199)	
		return notify_fail("��������ȷ����̫ǳ��");

	if(EQUALSTR(target->query_skill_mapped("sword"), "lonely_sword") && EQUALSTR(target->querystr("family/family_name"), "��ɽ��") )
	{
		string msg;
		msg = "\n$HIY$NԾ�����ɣ����ڰ�գ���ʽ���䣬���������ơ��羪�κ��ˣ���ת������䡣$COM";
		msg+= "$HIY$n����ͻ��Ц�ݣ��ƺ��ѿ���$N���书��ʽ�����г����һ������$N��$l����ʱ$N������ҡ�\n" ;
		me->start_busy(2);
		me->add("mp",-250);
		message_vision(msg.c_str(), me, target);
	}
	else if(random(me->query("combat_exp")) > target->query("combat_exp")/3)
	{
		me->set_temp("teapot/youlong",1);
		g_Combatd.Do_Attack(me,target,CCombatd::TYPE_REGULAR);
		me->delete_temp("teapot/youlong");
		target->start_busy(random(2));
		me->start_busy(random(2));
		me->add("mp",-250);
	}
	else
	{
		me->set_temp("teapot/youlong",1);
		g_Combatd.Do_Attack(me,target,CCombatd::TYPE_REGULAR);
		me->delete_temp("teapot/youlong");
		me->start_busy(random(2));
		me->add("mp",-250);
	}
    return 1;
}


SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp





