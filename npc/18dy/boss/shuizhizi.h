//shuizhizi 水栀子 
//地狱第六层BOSS

BOSS_BEGIN(CNshuizhizi);

virtual void create()
{
	set_name("水栀子", "shui zhi zi");
	set("title", "夜来香");
	set("gender", "女性");
	set("icon", young_woman3);
	set("age", 38);
	set("long",  "她是一位身材高挑的少妇，长长的发高高梳成马尾式，用玉环扣制，发长垂至腰部，刘海也长长地掩住眉眼，看不清面容。长发雪衣，飘逸得仿若名家笔下的泼墨水彩，遗世独立，虚幻若仙。");

	set("per",39);
	set("str", 100);
	set("int", 100);
	set("con", 100);
	set("dex", 95);
	set("level",205);
	set("repute",50000000);

	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
	
	set_inquiry("碧落", "那是某个著名网站的一帮朋友组建成的帮派。");
	set_inquiry("轻寒子", "他在那里啊，你见过他吗？");
	set_inquiry("灵鹫武功", "灵鹫武功在于轻盈。");

	set("hp", 112000);
	set("max_hp", 112000);
	set("mp", 62000);
	set("max_mp", 62000);
	set("mp_factor", 500);
	
	set("combat_exp", 190000000);
	set("score", 500000);
	
	set_skill("force", 740);
	set_skill("unarmed", 740);
	set_skill("dodge", 740);
	set_skill("parry", 740);
	set_skill("finger",740);
	set_skill("hand",740);
	set_skill("strike", 740);
    set_skill("sword",740);

	set_skill("zhemei_shou",740);
	set_skill("liuyang_zhang",740);
    set_skill("tianyu_qijian",740);
	set_skill("yueying_wubu",740);
	set_skill("bahuang_gong", 740);
	set_skill("rouqing_zhi",740);
	set_skill("beiming_shengong", 740);

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

	set("apply/armor", 950);
    set("apply/damage", 820);

	set("chat_chance", 5);

    carry_object("changjian")->wield();
 	carry_object("qingyi")->wear();
    carry_object("doupeng")->wear();

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
		return "水栀子转过身去，轻声叹道：“轻寒子，你现在在那里呢？”";
	case 1:
		return "水栀子幽幽的叹了一口气，曼声轻吟：“玲珑骰子安红豆,入骨相思知不知。”";
	case 2:
		return "水栀子眉头一挑，笑嘻嘻的说道：“灵蓝MM还欠我一顿饭呢。”";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("changjian", IS_ITEM);
	if(query_weapon() == ling && ling)
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>145 )
		{
			message_vision("$HIR$N轻叹道：“往日已经如同风花雪月,$n就下去吧！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level9"))
				me->set("18dy/level10",1);
			me->move(load_room("高昌镬汤地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
