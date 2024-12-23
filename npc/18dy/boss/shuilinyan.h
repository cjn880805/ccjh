//shuilinyan 水临烟 
//地狱第十四层BOSS

BOSS_BEGIN(CNshuilinyan);

virtual void create()
{	
	set_name("水临烟", "shui lin yan");
	set("title", "碧落星辰");
	set("gender", "女性");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "她一身华服，眉眼如画，温和娴雅，犹如一弯温润清华的明月，连笑容也是温温和和，淡若春风似的。。");
		
	set("str", 123);
	set("int", 123);
	set("con", 123);
	set("dex", 95);
	set("per",38);
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 15);		//设置NPC使用绝招的几率
	
	set_inquiry("好老白", "不知道他在美国过的可好。");
	set_inquiry("舞剑", "先花舞,再剑舞,你可明白？");
	set_inquiry("碧落星辰", "那是我的绰号。");

	set("hp", 182000);
	set("max_hp",182000);
	set("max_mp", 92000);
	set("mp", 92000);
	set("mp_factor", 500);
	
	set("combat_exp", 290000000);
	set("score", 500000);
	
	set_skill("force", 870);
	set_skill("unarmed", 870);
	set_skill("dodge", 870);
	set_skill("parry", 870);
	set_skill("finger",870);
	set_skill("hand",870);
	set_skill("strike", 870);
    set_skill("sword",870);

	set_skill("zhemei_shou",870);
	set_skill("liuyang_zhang",870);
    set_skill("tianyu_qijian",870);
	set_skill("yueying_wubu",870);
	set_skill("bahuang_gong", 870);
	set_skill("rouqing_zhi",870);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
    map_skill("strike","liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
    map_skill("sword","tianyu_qijian");
	map_skill("finger","rouqing_zhi");

	if(random(2))
	{
		prepare_skill("strike","liuyang_zhang");
		prepare_skill("hand","zhemei_shou");
	}
	else
		prepare_skill("finger","rouqing_zhi");
	
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
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 1220);
    set("apply/damage", 1090);

	set("chat_chance", 5);
    carry_object("changjian")->wield();

	set("family/family_name","灵鹫宫");
	
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

virtual char * chat_msg()				
{
	switch(random(4))
	{
	case 0:
		return "水临烟伸出右手，拂了拂额头垂下的几缕秀丝，轻声曼唱起来：“水临烟杏花疏影里，吹笛到天明。”";
	case 1:
		return "水临烟似乎想起了什么，摇了摇头，念道：“此情可待成追忆，只是当时已惘然。”";
	case 2:
		return "水临烟幽幽的冒出一句，“风华绝代”";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * item = PresentName("changjian", IS_ITEM);
	if(query_weapon() == item && item)
	{
		switch(random(3))
		{
		case 0:
			perform_action("sword san", 1);
			break;
		case 1:
			perform_action("sword kuangwu", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(4))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("strike zhong", 1);
			break;
		case 2:
			perform_action("finger caiyue", 1);
			break;
		case 3:
			perform_action("hand duo",1);
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
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj;  
		if(!userp(me))	continue;
		//最后一个打倒的人将获得进入下一层的资格
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>163 )
		{
			message_vision("$HIR$N道：“可惜好老白不在,要不$n怎么过的了我们的双剑。”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level17"))
				me->set("18dy/level18",1);
			me->move(load_room("高昌冰地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
