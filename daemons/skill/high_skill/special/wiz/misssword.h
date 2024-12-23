//misssword.h 销魂剑法

SKILL_BEGIN(CSmisssword);

virtual void create()
{
	set_name( "销魂剑法");

	Magic_t * magic;

	magic = add_magic("xiangsi", do_xiangsi);
	magic->name = "何去何从";
	magic->mp = 2250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("combines", do_combines);
	magic->name = "伏流剑";
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
		{"$N使一招「欲将愁心与明月」，手中$w轻飘飘地向$n斩去！",
		30, 10, 10, 0,},
		{"$N手腕微挫，$w随著一招「问君能有几多愁」由下而上撩往$n！",
		60,15,20,20,},
		{"$N身形一转，一招「人比黄花瘦」$w剑光不定，劈向$n！",
		80,30,30,40,},
		{"$N舞动$w，一招「胡天八月即飞雪」迅捷无伦地刺向$n！",
		120,45,	40, 60,},
		{"$N手中$w一晃，一招「伤之如何」往$n斜斜挑出一剑！",
		160,60,50,80,},
		{"$N蓄劲发力，一招「莫道不销魂」直劈$n！",
		200,75,60,100,},
		{"$N移步侧身，使一招「沧海月明珠有泪」望$n点去！",
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
//			m_actions.set("action", "只见刀气纵横，卷荡四方！");

		if (me->query_temp("teapot/perform_combineb"))
			m_actions.set("action", "刀剑交织，并袭而过！");
			
		if (me->query_temp("teapot/perform_combines"))
			m_actions.set("action", "只见剑气穿梭，剑意飞扬！");
			
			break;
		}
			
	return & m_actions;
};

const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[][255] ={
		"$n使一招「欲将愁心与明月」，手中$W轻飘飘地向$N斩去！",
		"$n手腕微挫，$W随著一招「问君能有几多愁」由下而上撩往$N！",
		"$n身形一转，一招「人比黄花瘦」$W剑光不定，劈向$N！",
		"$n舞动$W，一招「胡天八月即飞雪」迅捷无伦地刺向$N！",
		"$n手中$W一晃，一招「伤之如何」往$N斜斜挑出一剑！",
		"$n蓄劲发力，一招「莫道不销魂」直劈$N！",
		"$n移步侧身，使一招「沧海月明珠有泪」望$N点去！",
	};

	return parry_msg[random(7)];
}

virtual int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
/*
	if( DIFFERSTR(me->querystr("gender"), "男性") )
		return notify_fail("销魂剑法只有男子才能练。");

	if(me->query("max_mp") < 100)
		return notify_fail("你的内力不够，没有办法练销魂剑法。");
	
	CContainer * weapon;

	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword") )
		return notify_fail("你必须先找一把剑才能练剑法。");

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
		return notify_fail("你必须先找一把剑才能练剑法。");

	if( me->query("hp") < 150
		||	me->query("mp") < 100 )
		return notify_fail("你的内力或气不够，没有办法练习销魂剑法。");

	me->receive_damage("hp", 150);
	me->add("mp", -100);
	message_vision("$HIW $N依销魂之意舞了一遍销魂剑法。", me);
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

	if( DIFFERSTR(me->querystr("gender"), "男性") )
		return notify_fail("「何去何从」只有男子才能使用。");

	if( !target || !me->is_fighting(target) )
		return notify_fail("「何去何从」只能对战斗中的对手使用。");

	if (me->query_skill("sword",1) < 200)		
		return notify_fail("你的基本剑法还不够纯熟！");

	if (me->query_skill("misssword",1) < 200)		
		return notify_fail("你的销魂剑法还不够纯熟！");

	if (! weapon || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");

	if (me->query("mp") < 2250)
		return notify_fail("你的内力不够!");
	
	string mvsname;
	string mvsid;
	mvsname=me->querystr("couple/name");
	mvsid=me->querystr("couple/id");
	
	if (!mvsname.length() || !mvsid.length())
		return notify_fail("你阅历太浅，无法体会到相思情意。");

	me->add("mp",-2250);

	if (target->query("hp") < 600)
		return notify_fail("值得使用「何去何从」吗？");

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

	snprintf(msg, 441, "$HIW剑出鞘，刹那间混元初开，一道惊雷闪过！\n－－－　剑刺$n。\n没有人能形容这一剑。\n用语言、用图画、用文字，都没有办法形容那一刺，因为那不是快，也不是奇，\n更不是绝，亦不只是优美，而是这一切的结合，再加叁分惊艳，叁分潇洒、叁分\n惆怅、一分不可一世。\n一招惊艳的、潇洒的、惆怅的、而且还不可一世的剑法。\n是什么样的人，才能创造出这样一招只应天上有、不应世间无的剑法？\n这究竟是剑法，还是仙法？\n是人间的剑，还是仙剑？\n风萧杀，\n一剑如梦，\n何去，\n何从？");
	
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
	
	message_vision("$HIR风掠过，剑无痕，一粒血珠自$N眉心滴落。\n", target);
	int i;
	i=random(me->query("mp_factor")*20)+me->query_skill("sword")*6+me->query("level")*15+me->query_skill("misssword")*6;
	i=i/2+random(i);
	target->receive_damage("hp", i,me);
	char msg[255];
//	message_vision(snprintf(msg,255,"$N受到了%d点的伤害。",i),target);

	tell_object(target,snprintf(msg,255,"你受到了%d点的伤害！",i));
	me->start_busy(6);

	return;
}


static void yearn4(CContainer * ob, LONG param1, LONG step)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) return;

	message_vision("风掠过，剑无痕，$N眉心现出一点红印。\n", target);
	int i;
	i=random(me->query("mp_factor")*5)+1;
	target->receive_wound("hp", i,me);
	char msg[255];
	tell_object(target,snprintf(msg,255,"你受到了%d点的伤害！",i));
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
	message_vision("\n$HIR$N刀势未弱，$n剑势又起！\n",mvs,me);
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
	   return notify_fail("你现在正忙着呢。");

	if (! (weapon = me->query_weapon()) )
		return notify_fail("你使用的武器不对。");

	if (weapon->query("apply/damage")<50)
		return notify_fail("此剑的杀气不够，无法被人力所激发。");

	if (me->query_skill("sword",1) < 200)		
		return notify_fail("你的基本剑法还不够纯熟！");

	int skilla;
	skilla=me->query_skill("misssword",1);

	if( skilla < 250 )
		return notify_fail("你的销魂剑法极不够娴熟，无法反震剑气，四海伏流。");

	if( me->query("mp") < 1000)	
		return notify_fail("你的内力不足以反震剑气，四海伏流。");

	me->add("mp",-1000);

	string mvsname;
	string mvsid;
	mvsname=me->querystr("couple/name");
	mvsid=me->querystr("couple/id");

	if (!mvsname.length() || !mvsid.length())
	{
		return notify_fail("没有相思刀的配合，纵然你功力再高，也无法使出伏流剑。");
	}

	CContainer * env;
	env=me->environment();
	CChar * mvs;
	mvs=(CChar * ) env->present(mvsid.c_str());

	if (!mvs || !mvs->is_fighting(target))
	{
		return notify_fail("没有相思刀的配合，纵然你功力再高，也无法使出伏流剑。");
	}
	if (me->query_team() != mvs->query_team())
	{
		return notify_fail("没有相思刀的配合，纵然你功力再高，也无法使出伏流剑。");
	}


	 if (mvs->is_busy() || mvs->query_temp("pending/exercising"))
		return notify_fail("没有相思刀的配合，纵然你功力再高，也无法使出伏流剑。");

	
	CContainer * weapon2;

	if (! (weapon2 = mvs->query_weapon()) )
//		|| !weapon2->query("is_icesword") )
		return notify_fail("没有相思刀的配合，纵然你功力再高，也无法使出伏流剑。");

	if (weapon2->query("apply/damage")<50)
		return notify_fail("没有相思刀的配合，纵然你功力再高，也无法使出伏流剑。");


	int skillb;
	skillb=mvs->query_skill("missblade",1);

	if( skillb < 200 )
		return notify_fail("没有相思刀的配合，纵然你功力再高，也无法使出伏流剑。");

	if( mvs->query("mp") < 1000)	
		return notify_fail("没有相思刀的配合，纵然你功力再高，也无法使出伏流剑。");

	mvs->add("mp",-1000);

	message_vision("$N大喝一声，将全部内力望剑催去，剑气反震而起！",me);
	message_vision("$HIR\n$N和$n的身行突然交织在一起，越转越快！$GRN\n" ,mvs,me);

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




