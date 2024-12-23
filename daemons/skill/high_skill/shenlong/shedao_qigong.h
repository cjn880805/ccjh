
// shedao_qigong.h �ߵ�����
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSshedao_qigong);

virtual void create()
{
	set_name( "�ߵ��湦");

	Magic_t * magic;

	magic = add_magic("chang", do_chang);
	magic->name = "���������һ��";
	magic->mp = 300;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("chang2", do_chang2);
	magic->name = "��������ڶ���";
	magic->mp = 0;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("chang3", do_chang3);
	magic->name = "�������������";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  damage,dodge,parry,force;
		char damage_type[5];
	}action[] = {
		{"$Nʹһ�С��ɺ����᡹����$wһ�ᣬ����$n��$l", 40,0 , 40, 150,"����",},		
		{"$Nʹ�������߳�����������΢��,����$wٿ����$n��$l��ȥ", 50, 80, 10, 250,"����",},		
		{"$N����΢��,���㷴��,����ת��,ʹһ�С�����������������$w�Ѵ���$n$l", 60, 80, 20, 250,"����",},		
		{"$Nʹһʽ��������衹��������$n,����һ��,˳����$w��һ��,$w��Ȼ���Լ��ʺ���.����$N��������һ��,$w�ӹ����ʺ�,����$n�������", 70,50 , 40, 350,"����",},		
		{"$N�����ڵ���һ���,ʹһ�С�С����¡�,��$n�������,����$wֱ��$n", 80, 70, 30, 350,"����",},		
		{"$N���һ����ʹһ�С�����ٶ�������������$n��ȪҪѨ,����$nˤ���ڵ�", -25, -10, 70, 400,"����",},		
		{"$N˫��һ��,�������,һ�С�³�ﲦ��������ץ��$n�ҽ�����,����$wֱ��$nС��", 80, 80, -10, 400,"����",},		
		{"$NͻȻһ�������,һ�С����ཱུ����,˫��һ��,���ڼ�ͷ,˫��ֱ��$n", 90,90 , 30, 400,"����",},		
	};

	int level = 0;

	level = random(8);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
	m_actions.set("parry", action[level].parry);
	m_actions.set("force", action[level].force);
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="sword"|| usage=="staff"|| usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())) 
		return 0;
	
	if ( DIFFERSTR(weapon->querystr("skill_type"), "staff")
		&& DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if ( me->query_skill("shenlong_xinfa", 1) < 50)
		return notify_fail("��������ķ���򲻹����޷�ѧ�ߵ��湦.");
	
	if ( me->query_skill("force", 1) < 50)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ�ߵ��湦��");
	
	if ( me->query_skill("shenlong_bashi", 1) < 50)
		return notify_fail("���������ʽ��򲻹����޷�ѧ�ߵ��湦��");
	
	if ( me->query_skill("shenlong_xinfa",1) < me->query_skill("shedao_qigong",1))
		return notify_fail("��������ķ���򲻹����޷�����ѧ�ߵ��湦��");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 50)
		return notify_fail("�������̫���ˡ�");
	if ( me->query("mp") < 30)
		return notify_fail("��������������ߵ��湦��");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
	
}

//perform 
static int do_chang(CChar * me, CContainer * ob)
{
	if(	! me->is_fighting() )
		return notify_fail("���ɷ�ֻ����ս����ʹ�á�");
	
	if( DIFFERSTR(me->query_skill_mapped("force"), "shenlong_xinfa") )
		return notify_fail("������������ķ�ʹ�á�");	

	if(  me->query_skill("shedao_qigong", 1) < 60 )
		return notify_fail("����ߵ��湦������죬����ʹ�ó��ɷ���");
	
	if(  me->query("mp") < 300 )
		return notify_fail("���Ѿ����þ�ƣ����,���������ˡ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if(  me->query_temp("chang") == 50 )
		return notify_fail("���Ѿ�����̫����,�����ٳ��ˡ�");
	
	//int skill = me->query_skill("force");
	me->add("mp", -200);
	message_vision( "ֻ��$N���������дʣ����֮���书�����"  , me);
	me->add_temp("apply/attack", 1);
	me->add_temp("apply/dodge", 1);
	me->add_temp("apply/defense", 1);
	me->add_temp("chang", 1);
	return 1;
}

static int do_chang2(CChar * me ,CContainer * ob)
{
	if( !me->is_fighting() )
		return notify_fail("���ɷ�ֻ����ս����ʹ�á�");
	
	if( DIFFERSTR(me->query_skill_mapped("force"), "shenlong_xinfa") )
		return notify_fail("������������ķ�ʹ�á�");

	if(  me->query_skill("shedao_qigong", 1) < 80 )
		return notify_fail("����ߵ��湦������죬����ʹ�ó��ɷ���");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_temp("apply/attack")<=0|| me->query_temp("apply/dodge") <=0|| me->query_temp("apply/defense") <=0 )
		return notify_fail("��Ŀǰս����̫��,�����ٻָ������ˡ�");
	
	if(  me->query_temp("chang") <=-30  )
		return notify_fail("���Ѿ�����̫����,�����ٳ��ˡ�");
	
	message_vision(  "ֻ��$N���������дʣ����֮���������ǣ�"  , me);
	me->add_temp("apply/attack", -1);
	me->add_temp("apply/dodge", -1);
	me->add_temp("apply/defense", -1);
	me->add_temp("chang", -1);
	me->add("mp", 100);
	return 1;
}

static int do_chang3(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target	||	!me->is_fighting(target) )
		return notify_fail("���ɷ�ֻ����ս����ʹ�á�");

	if( DIFFERSTR(me->query_skill_mapped("force"), "shenlong_xinfa") )
		return notify_fail("������������ķ�ʹ�á�");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if(  me->query_skill("shedao_qigong", 1) < 100 )
		return notify_fail("����ߵ��湦������죬����ʹ�ó��ɷ����־���");
	
	if( (me->environment())->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�");
	
	if(  me->query("mp") < 500 )
		return notify_fail("���Ѿ����þ�ƣ����,���������ˡ�");
	
	
	int neili = me->query("mp");
	
	me->add("mp", -(300+random(200)));
	me->receive_damage("hp", 10);
	
	me->start_busy(random(5));
	
	message_vision( "$N�������һ��������Ȼ���쳤Х��������У�����������Ǹ���ţ�����"  , me);
	
	if( neili/2 + random(neili/2) <  target->query("mp")/10) 
		return notify_fail("���˵���������߳�̫��,�˲��ˣ�");
	
	int damage = (neili -  target->query("max_mp")) / 10;
	if( damage > 0 )
	{
		target->receive_damage("hp", damage);
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage);
		target->receive_wound("hp", damage);
		message_vision( "$Nֻ������һ���ʹ��������ð��������������������ǰ�趯��"  , target);
	}
	else
	{
		message_vision( "$Nֻ������΢ʹ���ƺ�����һ�����ˡ�"  , target);
		target->receive_damage("hp", 10 );
		target->receive_damage("hp", 10 );
		target->receive_wound("hp", 10);
	}
	//if( !target->is_killing(me) ) target->kill_ob(me);
	//if( !me->is_killing(target) ) me->kill_ob(target);
	return 1;
}

SKILL_END;
