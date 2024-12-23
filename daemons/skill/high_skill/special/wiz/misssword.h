//misssword.h ���꽣��

SKILL_BEGIN(CSmisssword);

virtual void create()
{
	set_name( "���꽣��");

	Magic_t * magic;

	magic = add_magic("xiangsi", do_xiangsi);
	magic->name = "��ȥ�δ�";
	magic->mp = 2250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("combines", do_combines);
	magic->name = "������";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, force,  parry, lvl;
	}action[7] = {
		{"$Nʹһ�С��������������¡�������$w��ƮƮ����$nնȥ��",
		30, 10, 10, 0,},
		{"$N����΢�죬$w����һ�С��ʾ����м������¶�������$n��",
		60,15,20,20,},
		{"$N����һת��һ�С��˱Ȼƻ��ݡ�$w���ⲻ��������$n��",
		80,30,30,40,},
		{"$N�趯$w��һ�С�������¼���ѩ��Ѹ�����׵ش���$n��",
		120,45,	40, 60,},
		{"$N����$wһ�Σ�һ�С���֮��Ρ���$nбб����һ����",
		160,60,50,80,},
		{"$N�������һ�С�Ī�������꡹ֱ��$n��",
		200,75,60,100,},
		{"$N�Ʋ�����ʹһ�С��׺����������᡹��$n��ȥ��",
		240,90,70,120,},
	};
 
  	int level = me->query_skill("misssword", 1);
	for(int i = 7; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("damage", action[level].damage);
			m_actions.set("force", action[level].force);
			m_actions.set("parry", action[level].parry);

//		if (me->query_temp("teapot/perform_combineb"))
//			m_actions.set("action", "ֻ�������ݺᣬ���ķ���");

		if (me->query_temp("teapot/perform_combineb"))
			m_actions.set("action", "������֯����Ϯ������");
			
		if (me->query_temp("teapot/perform_combines"))
			m_actions.set("action", "ֻ���������󣬽�����");
			
			break;
		}
			
	return & m_actions;
};

const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[][255] ={
		"$nʹһ�С��������������¡�������$W��ƮƮ����$Nնȥ��",
		"$n����΢�죬$W����һ�С��ʾ����м������¶�������$N��",
		"$n����һת��һ�С��˱Ȼƻ��ݡ�$W���ⲻ��������$N��",
		"$n�趯$W��һ�С�������¼���ѩ��Ѹ�����׵ش���$N��",
		"$n����$Wһ�Σ�һ�С���֮��Ρ���$Nбб����һ����",
		"$n�������һ�С�Ī�������꡹ֱ��$N��",
		"$n�Ʋ�����ʹһ�С��׺����������᡹��$N��ȥ��",
	};

	return parry_msg[random(7)];
}

virtual int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
/*
	if( DIFFERSTR(me->querystr("gender"), "����") )
		return notify_fail("���꽣��ֻ�����Ӳ�������");

	if(me->query("max_mp") < 100)
		return notify_fail("�������������û�а취�����꽣����");
	
	CContainer * weapon;

	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword") )
		return notify_fail("���������һ�ѽ�������������");

	return 1;
*/
	return 0;
}

virtual int practice_skill(CChar * me)
{
/*
	CContainer * weapon;

	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword") )
		return notify_fail("���������һ�ѽ�������������");

	if( me->query("hp") < 150
		||	me->query("mp") < 100 )
		return notify_fail("�����������������û�а취��ϰ���꽣����");

	me->receive_damage("hp", 150);
	me->add("mp", -100);
	message_vision("$HIW $N������֮������һ�����꽣����", me);
	return 1;
*/
	return 0;
}

static int do_xiangsi(CChar * me, CContainer * ob)
{
	CContainer * weapon = me->query_weapon();
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	string msg;

	if( DIFFERSTR(me->querystr("gender"), "����") )
		return notify_fail("����ȥ�δӡ�ֻ�����Ӳ���ʹ�á�");

	if( !target || !me->is_fighting(target) )
		return notify_fail("����ȥ�δӡ�ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (me->query_skill("sword",1) < 200)		
		return notify_fail("��Ļ����������������죡");

	if (me->query_skill("misssword",1) < 200)		
		return notify_fail("������꽣�����������죡");

	if (! weapon || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if (me->query("mp") < 2250)
		return notify_fail("�����������!");
	
	string mvsname;
	string mvsid;
	mvsname=me->querystr("couple/name");
	mvsid=me->querystr("couple/id");
	
	if (!mvsname.length() || !mvsid.length())
		return notify_fail("������̫ǳ���޷���ᵽ��˼���⡣");

	me->add("mp",-2250);

	if (target->query("hp") < 600)
		return notify_fail("ֵ��ʹ�á���ȥ�δӡ���");

//	(me->environment())->set("rem_room_locked", (me->environment())->query("room_locked"));
	//(me->environment())->set("room_locked", FIGHT_LOCKED);

	me->start_busy(99);
/*
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());



	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
		CChar * targett;
		
		if(! obj->is_character()) continue;
		targett = (CChar *)obj;

		targett->disable_player("");
		targett->SendState();
	}
*/	
	me->call_out(yearn2, 1, target->object_id(),0);
	return 1;	
}			

static void yearn2(CContainer * ob, LONG param1, LONG step)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) return;

	char msg[441];

	snprintf(msg, 441, "$HIW�����ʣ�ɲ�Ǽ��Ԫ������һ������������\n������������$n��\nû������������һ����\n�����ԡ���ͼ���������֣���û�а취������һ�̣���Ϊ�ǲ��ǿ죬Ҳ�����棬\n�����Ǿ����಻ֻ��������������һ�еĽ�ϣ��ټ����־��ޣ���������������\n��ꡢһ�ֲ���һ����\nһ�о��޵ġ������ġ����ġ����һ�����һ���Ľ�����\n��ʲô�����ˣ����ܴ��������һ��ֻӦ�����С���Ӧ�����޵Ľ�����\n�⾿���ǽ����������ɷ���\n���˼�Ľ��������ɽ���\n����ɱ��\nһ�����Σ�\n��ȥ��\n�δӣ�");
	
	message_vision(msg, me, target);
	

		if (random(target->query_skill("parry"))<me->query_skill("sword")/**2*/)
			me->call_out(yearn3, 1, param1, 1);
		else
			me->call_out(yearn4, 1, param1, 1);

		return;

}


static void yearn3(CContainer * ob, LONG param1, LONG step)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) return;
	
	message_vision("$HIR���ӹ������޺ۣ�һ��Ѫ����$Nü�ĵ��䡣\n", target);
	int i;
	i=random(me->query("mp_factor")*20)+me->query_skill("sword")*6+me->query("level")*15+me->query_skill("misssword")*6;
	i=i/2+random(i);
	target->receive_damage("hp", i,me);
	char msg[255];
//	message_vision(snprintf(msg,255,"$N�ܵ���%d����˺���",i),target);

	tell_object(target,snprintf(msg,255,"���ܵ���%d����˺���",i));
	me->start_busy(6);

	return;
}


static void yearn4(CContainer * ob, LONG param1, LONG step)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) return;

	message_vision("���ӹ������޺ۣ�$Nü���ֳ�һ���ӡ��\n", target);
	int i;
	i=random(me->query("mp_factor")*5)+1;
	target->receive_wound("hp", i,me);
	char msg[255];
	tell_object(target,snprintf(msg,255,"���ܵ���%d����˺���",i));
	me->start_busy(6);

	return;
}


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	CChar * target = NULL;
	string msg;
//	CContainer * weapon;

		target = victim;

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return "";	// Busy : Maybe Casting / Performming

	int skilla;
	skilla=me->query_skill("misssword",1);

	if( skilla < 40 )
		return "";	// Don't pef this if lv < 40.

	string mvsname;
	string mvsid;
	mvsname=me->querystr("couple/name");
	mvsid=me->querystr("couple/id");

	if (!mvsname.length() || !mvsid.length())
	{
		return "";	// Return;
	}

	CContainer * env;
	env=me->environment();
	CChar * mvs;
	mvs=(CChar * ) env->present(mvsid.c_str());

	if (!mvs || !mvs->is_fighting(target))
	{
		return "";
	}
	if (me->query_team() != mvs->query_team())
	{
		return "";
	}


	 if (mvs->is_busy() || mvs->query_temp("pending/exercising"))
		return "";

	if (me->query_temp("teapot/love_combine_strike"))
		return "";
	
	CContainer * weapon2;
	weapon2 = mvs->query_weapon();
	if (!weapon2)
		return "";
	if ( DIFFERSTR(mvs->query_skill_mapped(weapon2->querystr("skill_type")), "missblade" ))
		return "";

	int skillb;
	skillb=mvs->query_skill("missblade",1);

	if( skillb < 40 )
		return "";

	mvs->set_temp("teapot/love_combine_strike",1);
	g_Combatd.Do_Attack(mvs,victim,CCombatd::TYPE_REGULAR);
	message_vision("\n$HIR$N����δ����$n��������\n",mvs,me);
	int i;
	i=mvs->query_skill("missblade",1)+me->query_skill("misssword",1);
	i=i+random(mvs->query_skill("missblade",1)+me->query_skill("misssword",1));
	victim->receive_damage("hp",i );
	
	me->start_busy(0);
	mvs->start_busy(0);
	mvs->delete_temp("teapot/love_combine_strike");

	victim->SendState(victim);

	return "";

}

static int do_combines(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	CContainer * weapon;

	if(ob ==me )
		msg="123";

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("��������æ���ء�");

	if (! (weapon = me->query_weapon()) )
		return notify_fail("��ʹ�õ��������ԡ�");

	if (weapon->query("apply/damage")<50)
		return notify_fail("�˽���ɱ���������޷���������������");

	if (me->query_skill("sword",1) < 200)		
		return notify_fail("��Ļ����������������죡");

	int skilla;
	skilla=me->query_skill("misssword",1);

	if( skilla < 250 )
		return notify_fail("������꽣����������죬�޷����������ĺ�������");

	if( me->query("mp") < 1000)	
		return notify_fail("������������Է��������ĺ�������");

	me->add("mp",-1000);

	string mvsname;
	string mvsid;
	mvsname=me->querystr("couple/name");
	mvsid=me->querystr("couple/id");

	if (!mvsname.length() || !mvsid.length())
	{
		return notify_fail("û����˼������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷�ʹ����������");
	}

	CContainer * env;
	env=me->environment();
	CChar * mvs;
	mvs=(CChar * ) env->present(mvsid.c_str());

	if (!mvs || !mvs->is_fighting(target))
	{
		return notify_fail("û����˼������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷�ʹ����������");
	}
	if (me->query_team() != mvs->query_team())
	{
		return notify_fail("û����˼������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷�ʹ����������");
	}


	 if (mvs->is_busy() || mvs->query_temp("pending/exercising"))
		return notify_fail("û����˼������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷�ʹ����������");

	
	CContainer * weapon2;

	if (! (weapon2 = mvs->query_weapon()) )
//		|| !weapon2->query("is_icesword") )
		return notify_fail("û����˼������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷�ʹ����������");

	if (weapon2->query("apply/damage")<50)
		return notify_fail("û����˼������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷�ʹ����������");


	int skillb;
	skillb=mvs->query_skill("missblade",1);

	if( skillb < 200 )
		return notify_fail("û����˼������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷�ʹ����������");

	if( mvs->query("mp") < 1000)	
		return notify_fail("û����˼������ϣ���Ȼ�㹦���ٸߣ�Ҳ�޷�ʹ����������");

	mvs->add("mp",-1000);

	message_vision("$N���һ������ȫ������������ȥ�������������",me);
	message_vision("$HIR\n$N��$n������ͻȻ��֯��һ��ԽתԽ�죡$GRN\n" ,mvs,me);

	me->set_temp("teapot/perform_combines",1);
	mvs->set_temp("teapot/perform_combines",1);

	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
//		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

		if(! target->is_fighting(me)) continue;

		g_Combatd.Do_Attack(me,target,CCombatd::TYPE_QUICK);
	}

	me->delete_temp("teapot/perform_combines");
	mvs->delete_temp("teapot/perform_combines");

	me->start_busy(4);
	mvs->start_busy(4);

	return 1;
}


SKILL_END;




