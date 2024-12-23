// ����֮��������֮��������������˪������
// ice_sword.h ����֮��
// Coded by Teapot
// Create @ 2001-02-20
// Last Modify @ 2001-02-20


SKILL_BEGIN(CSice_sword);

virtual void create()
{
	set_name( "���콣��");

	Magic_t * magic;

	magic = add_magic("freeze", do_freeze);
	magic->name = "˪������";
	magic->mp = 1300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[] = {
		{"$Nһ������$w��ֻ��һ����ɫ�ı�˪֮������$n��", 120,1,30,125,0,},
		{"$N������$w��$nбб��ȥ���̹Ǻ�����Ϯ������", 320,-15,30,230,50,},
		{"$N����б��$w��ֻ��������Ȧ���ű������$n��", 420,-35,30,340,100,},
		{"$N���һ�������ὣ�⣬��$n��ֱ�̳�����һ����", 720,25,30,450,150,},
		{"$N΢΢һЦ��$w���ƺ����ᡢ��ů�͵������ݳ���ֻ��$n�Ÿо�������һ���ĺ��⣡", 420,-70,-70,160,200,},
	};
	int level = me->query_skill("ice_sword");

	CContainer * weapon;
	weapon = me->query_weapon();
	char msg[255];

	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			if (weapon->query("is_icesword") && me->query("mp")>50)
			{
				m_actions.set("force", action[level].force*2);
				me->add("mp",-50);
				snprintf(msg,255,"$HIW %s $COM",action[level].action);
				m_actions.set("action", msg);
			}
			else
			{
				m_actions.set("force", action[level].force);
			}

			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}


	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="sword" ; }

virtual int valid_learn(CChar * me)
{
//	if (me->query("max_mp") < 100)
//		return notify_fail("�������������");
//	if (me->query_skill("taiji_shengong", 1) < 20)
//		return notify_fail("���̫���񹦻��̫ǳ��");
//	if (me->query_skill("taiji_quan", 1) < 20)
//		return notify_fail("���̫��ȭ���̫ǳ��");
//	return 1;
	return 0;
}

virtual int practice_skill(CChar * me)
{
//	CContainer * weapon;
//
//	if (! (weapon = me->query_weapon())
//		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
//		return notify_fail("��ʹ�õ��������ԡ�");
//	
//	if (me->query("hp") < 50)
//		return notify_fail("����������������ǽ�����");
//	me->receive_damage("hp", 30);
//	return 1;
	return 0;
}


static int do_freeze(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("˪������ֻ�ܶ�ս���еĶ���ʹ�á�");

	if( target->query_temp("teapot/frozen") || !target->Query(IS_LIVING))
		return notify_fail("����û�б�Ҫʹ��˪�����֡�");

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("��������æ���ء�");

	if (! (weapon = me->query_weapon())
		|| !weapon->query("is_icesword") )
		return notify_fail("��ʹ�õ��������ԡ�");	// frost blade cast only.

	int skilla;
	skilla=me->query_skill("ice_sword",1);

	if( skilla < 240 )
		return notify_fail("��ı��콣����������죬ʹ�������¾��׵�˪�����֡�");

	if( me->query("mp") < 1300)	
		return notify_fail("������������Դ߶����к��⣬����ܡ�˪�����֡���");

	string mvsname;
	string mvsid;
	mvsname=me->querystr("couple/name");
	mvsid=me->querystr("couple/id");

	if (!mvsname.length() || !mvsid.length())
	{
		return notify_fail("û�к���֮������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷���˪�����֡���");
	}

	CContainer * env;
	env=me->environment();
	CChar * mvs;
	mvs=(CChar * ) env->present(mvsid.c_str());

	if (!mvs || !mvs->is_fighting(target))
	{
		return notify_fail("û�к���֮������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷���˪�����֡���");
	}
	if (me->query_team() != mvs->query_team())
	{
		return notify_fail("û�к���֮������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷���˪�����֡���");
	}


	 if (mvs->is_busy() || mvs->query_temp("pending/exercising"))
		return notify_fail("û�к���֮������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷���˪�����֡���");

	
	CContainer * weapon2;

	if (! (weapon2 = mvs->query_weapon())
		|| !weapon2->query("is_frostblade") )
		return notify_fail("û�к���֮������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷���˪�����֡���");


	int skillb;
	skillb=mvs->query_skill("frost_blade",1);

	if( skillb < 240 )
		return notify_fail("û�к�˪��������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷���˪�����֡���");

	if( mvs->query("mp") < 1300)	
		return notify_fail("û�к���֮������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷���˪�����֡���");


	message_vision("ֻ��$N���б���֮����$n���к���֮�����ڶ������������ϯ����أ�",me,mvs);
	message_vision("ɲ�Ǽ���ɫ���������ж�ë��ѩ������£���������͸�Ƕ�����ֱ��Ҫ���˶�����",me,mvs);
	message_vision("������������˪�����֣���",me,mvs);


	long ap;
	long dp;
	ap=(me->query_skill("sword")+mvs->query_skill("blade"))/20;
	ap = ( ap * ap  * ap ) * (me->query("max_mp")/30+mvs->query("max_mp")/30+1) ;
	if (ap<0)
		me->set_temp("aho",1);
//	me->set_temp("ap2",ap);
	dp = target->query_combat_exp();
//	me->set_temp("ap3",dp);
//
	if( random(ap + dp) > dp || me->query_temp("aho")) 
	{
		me->delete_temp("aho");
		message_vision("ֻ��$Nȫ��һ������ʱ��������һ�㣡",target);
		target->disable_player("������");
		//	target->set_temp("block_msg/all", 1);
		//	Announce(target, "unconcious");
		target->SendState();
		
		ap=skilla+skillb;
		ap=ap/18;
		ap=random(ap)+ap;
		ap=ap/2+1;
		target->set_temp("teapot/frozen",1);
		
		target->call_out( remove_frozen, ap, skilla, skillb);
	}
	else
		message_vision("��$NĬ���ڹ������溮֮���ֿ���",target);

//	m_nRevive = random(100 - query("con")) + 30;	//30������������
	me->add("mp",-1300);
	mvs->add("mp",-1300);

	me->start_busy(6);
	mvs->start_busy(6);

	return 1;
}


static void remove_frozen(CContainer *ob, LONG amount, LONG amount1)
{
	CChar *target=(CChar *)ob;
	CContainer * obj;
	obj=target->environment();

	while( obj->Query(IS_CHAR))
	{
		target->move(obj->environment());
		obj=target->environment();
	}

	target->enable_player();
//	Announce(target, "revive");
//	target->delete_temp("block_msg/all");

	target->delete_temp("teapot/frozen");

	message_vision("$N���ϵı�ѩ������ȥ�����ѹ�����",target);

	target->SendState();
	return;
}


SKILL_END;