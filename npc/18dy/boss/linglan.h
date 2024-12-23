//linglan 灵蓝 

//地狱第十八层最终BOSS



BOSS_BEGIN(CNlinglan);



virtual void create()

{	

	set_name("灵蓝", "ling lan");

	set("title", "太刀根小百合");

	set("gender", "女性");

	set("icon", young_woman3);

	set("age", 68);

	set("long",  "她清秀如画，但眼中所带的迷离,让人感觉她犹如一弯天上遥不可及的明月。");

		

	set("str", 150);

	set("int", 150);

	set("con", 150);

	set("dex", 95);

	set("per",40);

	set("level",220);

	set("repute",50000000);



	set("chat_chance_combat", 15);		//设置NPC使用绝招的几率

	

	set_inquiry("江湖", "我不问江湖是非已经很多年了。");

	set_inquiry("灵袄", "你不知道那是为子陵做的衣服吗？");

	set_inquiry("BUG", "那是我最讨厌的东西。");

	set_inquiry("逍遥刀的秘密", "恩怨造就的诅咒，只有通过化解才可以解开。");



	set("hp", 352000);

	set("max_hp",352000);

	set("max_mp", 12000);

	set("mp", 12000);

	set("mp_factor", 500);

	

	set("combat_exp", 450000000);

	set("score", 500000);

	

	set_skill("force", 1000);

	set_skill("beiming_shengong", 1000);

	set_skill("dodge", 1000);

	set_skill("lingboweibu", 1000);

	set_skill("strike", 1000);

	set_skill("liuyang_zhang", 1000);

	set_skill("parry", 1000);

	set_skill("blade", 1000);

	set_skill("xiaoyao_dao", 1000);

	set_skill("zhemei_shou", 1000);

	set_skill("hand", 1000);

	set_skill("literate", 1000);

	

	map_skill("force", "beiming_shengong");

	map_skill("dodge", "lingboweibu");

	map_skill("hand", "zhemei_shou");

	map_skill("strike", "liuyang_zhang");

	map_skill("parry", "xiaoyao_dao");

	map_skill("blade", "xiaoyao_dao");

	

	prepare_skill("hand","zhemei_shou");

	prepare_skill("strike","liuyang_zhang");

	

	set("no_kill",1);

	set("no_缠字决",1);

	set_temp("apply/no_连字诀",1);

	set_temp("apply/no_千环套狗",1);

	set_temp("apply/no_相思无用",1);

	set_temp("apply/no_势合形离",1);

	set_temp("apply/no_点字决",1);

	set_temp("apply/no_天外飞龙",1);

	set_temp("apply/no_拼命",1);

	set_temp("apply/no_祭血神刀",1);

	set_temp("apply/no_封字决",1);

	set_temp("apply/刀神一笑",1);

	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 1400);
    set("apply/damage", 1200);

    carry_object("gangdao")->wield();

	set("family/family_name","逍遥派");

	call_out(do_full, 7200);

	

}



static void do_full(CContainer * ob, LONG param1, LONG param2)

{

	CChar * me = (CChar *)ob;

	if(!me->query_temp("fight/is_fighting"))

	{

		message_vision("\n$HIR$N缓缓坐下，运功调息。", me);

		me->set("mp",me->query("max_mp"));

		me->set("hp",me->query("max_hp"));

	}

	me->call_out(do_full, 7200);

}



virtual char * chat_msg_combat()

{
	char msg[255];
	CContainer * item = PresentName("gangdao", IS_ITEM);
	if(query_weapon() == item && item)
	{
		switch(random(4))
		{
		case 0:
			perform_action("force maxsuck", 1);
			break;
		case 1:
			perform_action("force recover",0);
			break;
		case 2:
			perform_action("blade daoshenxiao", 1);
			break;
		case 3:
			perform_action("force neilisuck", 1);
			break;
		case 4:
			command(snprintf(msg, 40, "unwield %ld", item->object_id()));
			break;
		}
	}
	else
	{
		switch(random(5))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("force maxsuck", 1);
			break;
		case 2:
			perform_action("force neilisuck", 1);
			break;
		case 3:
			perform_action("strike zhong", 1);
			break;
		case 4:
			if(!item)
				carry_object("gangdao")->wield();
			break;
		case 5:
			if(item && ! query_weapon())
				command(snprintf(msg, 40, "wield %ld", item->object_id()));
			break;
		}
	}
	return 0;
}



void die()

{

	CContainer * obj = environment();

	DTItemList * list = obj->Get_ItemList();  

	POSITION p = list->GetHeadPosition(); 

	CChar * me;
	char msg[255];

	while(p) 

	{ 

		CContainer * obj = list->GetNext(p);

		if(! obj->is_character()) continue; 

		me = (CChar *)obj;  

		if(!userp(me))	continue;

		//最后一个打倒的人将获得进入下一层的资格

		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>163 )

		{

			message_vision("$HIR$N轻叹道：“连我都能打败,天地之大已经没有人是$n的对手了！”", this,me);

			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);

			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看......");

			g_Channel.do_channel(&g_Channel, 0, "chat", 
				snprintf(msg, 255, "$HIC%s弟子%s(%s)$HIY历经千辛万苦，终于挑战十八地狱成功。$COM",  me->querystr("family/family_name"),me->name(1),me->id(1)));

			if(me->query("18dy/level21"))

				me->set("18dy/level22",1);

			me->move(load_room("高昌黄泉之路"));

			break;

		}

	}

	CNbossnpc::die();

}



BOSS_END;

