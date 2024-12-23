// 寒星之刀　冰峰之剑　寒刀冰剑　霜天再现
// ice_sword.h 冰天之剑
// Coded by Teapot
// Create @ 2001-02-20
// Last Modify @ 2001-02-20


SKILL_BEGIN(CSice_sword);

virtual void create()
{
	set_name( "冰天剑法");

	Magic_t * magic;

	magic = add_magic("freeze", do_freeze);
	magic->name = "霜天再现";
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
		{"$N一抖手中$w，只见一道白色的冰霜之气刺向$n！", 120,1,30,125,0,},
		{"$N将手中$w对$n斜斜划去，刺骨寒意侵袭而到！", 320,-15,30,230,50,},
		{"$N连连斜划$w，只见无数剑圈带着冰珠打向$n！", 420,-35,30,340,100,},
		{"$N大喝一声，气贯剑尖，望$n笔直刺出冰天一剑！", 720,25,30,450,150,},
		{"$N微微一笑，$w看似很温柔、很暖和的慢慢递出，只有$n才感觉到了这一剑的寒意！", 420,-70,-70,160,200,},
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
//		return notify_fail("你的内力不够。");
//	if (me->query_skill("taiji_shengong", 1) < 20)
//		return notify_fail("你的太极神功火候太浅。");
//	if (me->query_skill("taiji_quan", 1) < 20)
//		return notify_fail("你的太极拳火候太浅。");
//	return 1;
	return 0;
}

virtual int practice_skill(CChar * me)
{
//	CContainer * weapon;
//
//	if (! (weapon = me->query_weapon())
//		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
//		return notify_fail("你使用的武器不对。");
//	
//	if (me->query("hp") < 50)
//		return notify_fail("你的体力不够练两仪剑法。");
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
		return notify_fail("霜天再现只能对战斗中的对手使用。");

	if( target->query_temp("teapot/frozen") || !target->Query(IS_LIVING))
		return notify_fail("现在没有必要使用霜天再现。");

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("你现在正忙着呢。");

	if (! (weapon = me->query_weapon())
		|| !weapon->query("is_icesword") )
		return notify_fail("你使用的武器不对。");	// frost blade cast only.

	int skilla;
	skilla=me->query_skill("ice_sword",1);

	if( skilla < 240 )
		return notify_fail("你的冰天剑法极不够娴熟，使不出天下绝伦的霜天再现。");

	if( me->query("mp") < 1300)	
		return notify_fail("你的内力不足以催动剑中寒意，如何能“霜天再现”？");

	string mvsname;
	string mvsid;
	mvsname=me->querystr("couple/name");
	mvsid=me->querystr("couple/id");

	if (!mvsname.length() || !mvsid.length())
	{
		return notify_fail("没有寒星之刀的配合，纵然你功力再高，也无法“霜天再现”。");
	}

	CContainer * env;
	env=me->environment();
	CChar * mvs;
	mvs=(CChar * ) env->present(mvsid.c_str());

	if (!mvs || !mvs->is_fighting(target))
	{
		return notify_fail("没有寒星之刀的配合，纵然你功力再高，也无法“霜天再现”。");
	}
	if (me->query_team() != mvs->query_team())
	{
		return notify_fail("没有寒星之刀的配合，纵然你功力再高，也无法“霜天再现”。");
	}


	 if (mvs->is_busy() || mvs->query_temp("pending/exercising"))
		return notify_fail("没有寒星之刀的配合，纵然你功力再高，也无法“霜天再现”。");

	
	CContainer * weapon2;

	if (! (weapon2 = mvs->query_weapon())
		|| !weapon2->query("is_frostblade") )
		return notify_fail("没有寒星之刀的配合，纵然你功力再高，也无法“霜天再现”。");


	int skillb;
	skillb=mvs->query_skill("frost_blade",1);

	if( skillb < 240 )
		return notify_fail("没有寒霜刀法的配合，纵然你功力再高，也无法“霜天再现”。");

	if( mvs->query("mp") < 1300)	
		return notify_fail("没有寒星之刀的配合，纵然你功力再高，也无法“霜天再现”。");


	message_vision("只见$N手中冰峰之剑与$n手中寒星之刀交融而出，寒风顿起，席卷天地：",me,mvs);
	message_vision("刹那间天色阴沉，竟有鹅毛大雪纷扬而下，凛冽冰气透骨而来，直似要把人冻僵！",me,mvs);
	message_vision("「寒刀冰剑，霜天再现！」",me,mvs);


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
		message_vision("只见$N全身一抖，登时变得如冰雕一般！",target);
		target->disable_player("冻结中");
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
		message_vision("但$N默运内功，将奇寒之气抵开！",target);

//	m_nRevive = random(100 - query("con")) + 30;	//30多心跳后苏醒
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

	message_vision("$N身上的冰雪渐渐化去，苏醒过来。",target);

	target->SendState();
	return;
}


SKILL_END;
