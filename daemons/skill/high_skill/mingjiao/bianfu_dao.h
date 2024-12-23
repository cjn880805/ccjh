//bianfu_dao.h �����ȷ�

//coded by Fisho
//data: 2000-11-29

SKILL_BEGIN(CSbianfu_dao);

virtual void create()
{
	set_name( "���𵶷�");
	set("valid_force", "shenghuo_shengong");

	Magic_t * magic;

	magic = add_magic("xuefu", do_xuefu);
	magic->name = "Ѫ����Ӱ";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar *me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int  force,dodge, damage,lvl;
	}action[]={
		{"$Nһ�п���ƽ������ġ���ɽ���꡹��$w�����һ����˿��$n��ȥ��",  10,-40,  140, 10,},
		{"$N���˺�һ�����⽻�ڣ�����$w����������$n��$l��", 20,-45,  200, 45,},
		{"$N���е�$w�ó�һƬ�������ִ�$n�����е�����������", 30,-35,  220, 85,},
		{"$N����������е�$w�ó�һƬ���⣬����Ȼ����һ����ն$n��$l��",  40,-15, 300, 95,},
		{"$N���е�$w��â������ʹ����˭��Ӣ�ۡ����������������$n��$l��",  50,-15, 480, 145,},
	};
	for(int i = 5; i > 0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("bianfu_dao", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
}

virtual int valid_enable(string usage)
{ 
	return (usage == "blade") || (usage == "parry"); 
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");

	if ( DIFFERSTR(me->querystr("family/family_name"), "����"))
		return	notify_fail("���𵶷����������̵��ӷ�����ѧϰ��");

	if(!me->query("mj/bianfu_dao"))
		return notify_fail("û�еõ���ʦָ�㣬����ѧ���������������أ�");

	if (me->query_skill("blade", 1) < 30)
		return notify_fail("��Ļ�������̫�������������𵶷���");

	if(me->query("mj/bianfu_dao")*50<me->query_skill("bianfu_dao", 1))
		return notify_fail("��ֻ���������������ڣ��޷�������������ѧϰ��");

 	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon ;
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if (me->query("hp") < 50)
		return notify_fail("����������������𵶷���");

	if ( DIFFERSTR(me->querystr("family/family_name"), "����"))
		return	notify_fail("���𵶷����������̵��ӷ�������ϰ��");

	if (me->query_skill("blade", 1) < me->query_skill("bianfu_dao", 1))
		return notify_fail("��Ļ���������򲻹������ܼ����������𵶷��ˡ�");

	if(me->query("mj/bianfu_dao")*50<me->query_skill("bianfu_dao", 1))
		return notify_fail("��ֻ���������������ڣ��޷���������������ϰ��");

	me->receive_damage("hp", 20);
	return 1;
}

static int do_xuefu(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target = NULL;
	CContainer * weapon ;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("��Ѫ����Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (! (weapon = me->query_weapon())	|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if ( DIFFERSTR(me->querystr("family/family_name"), "����"))
		return	notify_fail("��Ѫ����Ӱ�����������̵��ӷ�����ʹ�á�");

	if (me->query("mp")<600)
		return notify_fail("���������Ϊ���㣬�޷����㡸Ѫ����Ӱ����������");

	if (me->query_skill("qingfu_shenfa", 1) <200)	
		return notify_fail("������������̫ǳ��");

	if (me->query_skill("bianfu_dao", 1) < 149)	
		return notify_fail("������𵶷����̫ǳ��");

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	me->add("mp", -400);
	
	msg = "$HIRֻ�����һ�������⴩��������������ӹ�$n�ĺ��,�γ�һƬѪ�����������Ѫ����\n";
	
	me->start_busy(1);
	if( random(me->query_combat_exp()) >  target->query_combat_exp()/3 ) 
	{
		msg +=   " $HIR$P�ľ���һ�����϶�ʱ����Ѫɫ��"  ;
		//target->start_busy(me->query_skill("blade") / 40 + 2 );
		int damge_hp=(me->query_skill("blade")*2/3+me->query_skill("bianfu_dao")*3/2)*(random(me->query("kill/guilt")/100+1)+1);
		if(target->query("hp")<=damge_hp)
			damge_hp=target->query("hp")*90/100;
		target->add("hp",-damge_hp);
		me->add("hp",damge_hp*85/100);
		if(me->query("hp")>me->query("max_hp"))
			me->set("hp",me->query("max_hp"));
	} 
	else 
	{
		msg += "����$p������$P����ͼ����û���ϵ���"  ;
		me->start_busy(1);
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}


SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp





