
// luoying_shenjian.h ��Ӣ��
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSluoying_shenjian);

virtual void create()
{
	set_name( "��Ӣ��");
	set("valid_force", "bibo_shengong");

	set("diff",100);
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,parry,damage;
		char damage_type[5];
	}action[] = {
		{"$Nʹһ�С���Ӣ�ͷס�����������Ʈ������$w����ʵʵ�ó���㽣���׷���������$n$l", 100, 5, 40, "����",},
		{"$N�趯$w��һʽ�������һ�����������$n����һ�Σ�����$w�������佣��Ю�Ż�����������$n��$l", 140, -20, 50, "����",},
		{"$N������$nһת������$w����һָ��һʽ���������꡹�ó����콣Ӱ����$n$l�����ӳ�����", 180, 10, 70, "����",},
		{"$N����ƮȻ�����ڰ��������һ������Ȼһʽ�����Ƿɻ�������$w�������޵�������$n��$l", 210,-10 , 120, "����",},
		{"$N�������࣬һʽ��ϸ���ɷ��ء�ͷ�½��ϣ�һ�С������䡹����$w���һ����������$n��$l", 240, 10, 120, "����",},
		{"$Nһ�����ʹ�������컨�꡹������$w�ó����컨�꣬Ѹ����������$n��$l", 280, 15, 140, "����",},
		{"$N��̾һ��������$w����һ����һʱ���仨���⡹��$w��ȻԾ��ٿ�Ļ��������¶���һ���ƮȻ����$n��$l", 320, 0,140 , "����",},
	};

	int level = 0;
	
	level = random(7);
	m_actions.set("action", action[level].action);
/*	m_actions.set("force", action[level].force);
	m_actions.set("parry", action[level].parry);
	m_actions.set("damage", action[level].damage);
*/
	m_actions.set("force", (me->query("skill_pro/�һ���/��Ӣ��/force")+100) * action[level].force/100);
	m_actions.set("parry", (me->query("skill_pro/�һ���/��Ӣ��/parry")+100) *action[level].parry);
	m_actions.set("damage", (me->query("skill_pro/�һ���/��Ӣ��/damage")+100) * action[level].damage/100);

	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/�һ���/��Ӣ��/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/�һ���/��Ӣ��/force"));
			if(me->query("skill_pro/�һ���/��Ӣ��/force_point")>=level_point)
			{
				me->add("skill_pro/�һ���/��Ӣ��/force",1);
				me->set("skill_pro/�һ���/��Ӣ��/force_point",1);
				tell_object(me,"\n$HIR�����Ӣ������ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("parry")) 
		{
			me->add("skill_pro/�һ���/��Ӣ��/parry_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/�һ���/��Ӣ��/parry"));
			if(me->query("skill_pro/�һ���/��Ӣ��/parry_point")>=level_point)
			{
				me->add("skill_pro/�һ���/��Ӣ��/parry",1);
				me->set("skill_pro/�һ���/��Ӣ��/parry_point",1);
				tell_object(me,"\n$HIR��������ʹ����Ӣ�񽣣�����������һ����ǿ�ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/�һ���/��Ӣ��/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/�һ���/��Ӣ��/damage"));
			if(me->query("skill_pro/�һ���/��Ӣ��/damage_point")>=level_point)
			{
				me->add("skill_pro/�һ���/��Ӣ��/damage",1);
				me->set("skill_pro/�һ���/��Ӣ��/damage_point",1);
				tell_object(me,"\n$HIR�����Ӣ�����������ˡ�\n");
			}
		}
	}
	return "";
}


virtual int valid_learn(CChar * me)
{
	CContainer * ob;

    if(  me->query_skill("bibo_shengong",1) < 30)
        return notify_fail("��ı̲��񹦻�򻹲�����");

    if(  me->query("max_mp") < 100 )
        return notify_fail("���������������������Ӣ�񽣡�");

	if (!(ob = me->query_weapon())
	||  DIFFERSTR(ob->querystr("skill_type"), "sword"))
		return notify_fail("���������һ�ѽ�����ѧϰ������");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * ob;

    if(  me->query("hp") < 30
    ||   me->query("mp") < 5 )
        return notify_fail("�����������������û�а취��ϰ��Ӣ�񽣡�");

	if (!(ob = me->query_weapon())
	||  DIFFERSTR(ob->querystr("skill_type"), "sword"))
		return notify_fail("���������һ�ѽ�����ϰ��������");

    me->receive_damage("hp", 30);
	me->add("force", -5);
    tell_object(me,"�㰴����ѧ����һ����Ӣ�񽣡�", "practice");
	return 1;

}

SKILL_END;
