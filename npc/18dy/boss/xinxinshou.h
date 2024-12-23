//xinxinshou 华山新新手 
//地狱第九层BOSS

BOSS_BEGIN(CNxinxinshou);

virtual void create()
{
	set_name("华山新新手", "huashan xinxinshou");
	set("title", "剑魔");
	set("gender", "男性");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "他看上去非常和蔼,胸襟上系了一朵红花,手中的那把长剑记载了他不平凡的一生。");
   
	set("str", 115);
	set("int", 115);
	set("con", 115);
	set("dex", 95);
	set("per",27);
	set("level",216);
	set("repute",50000000);

	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
	
	set_inquiry("独孤九剑", "九剑一出破尽天下兵器。");
	set_inquiry("红花会", "那是个人才济济的帮会,可惜现在都已经隐居了。");
	set_inquiry("阎罗殿", "那是我们敌对的帮派,高手众多可惜走了邪道。");

	set("hp", 142000);
	set("max_hp",142000);
	set("max_mp", 77000);
	set("mp", 77000);
	set("mp_factor", 500);
	
	set("combat_exp", 220000000);
	set("score", 500000);
	
	set_skill("cuff", 800);
	set_skill("force", 800);
	set_skill("dodge", 800);
	set_skill("parry", 800);
	set_skill("sword", 800);
	set_skill("strike",800);
	set_skill("unarmed", 800);
	set_skill("zixia_shengong", 800);
	set_skill("poyu_quan", 800);
	set_skill("huashan_sword", 800);
	set_skill("hunyuan_zhang", 800);
	set_skill("lonely_sword", 800);
	set_skill("huashan_shenfa",800);
	set_skill("literate", 800);
	set_skill("zhengqijue", 800);

	map_skill("cuff", "poyu_quan");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("sword", "lonely_sword");
	map_skill("strike", "hunyuan_zhang");
	
	prepare_skill("strike","hunyuan_zhang");
	prepare_skill("cuff","poyu_quan");
	
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

	set("apply/armor", 1100);
    set("apply/damage", 970);

	set("chat_chance", 5);
    carry_object("changjian")->wield();

	set("family/family_name","华山派");
	
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
		return "华山新新手说道：“红花遍地。”";
	case 1:
		return "华山新新手无限遐往的望着远处，喃喃说道：“白蚁、笨熊、红袖、凯子你们还好吗？ ”";
	case 2:
		return "华山新新手恨声说道：“阎罗殿，我与你们誓不两立。”";
	case 3:
		return "华山新新手诧异的叹道：“红花会你都不知道,你太孤陋寡闻了吧？”";
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
			perform_action("sword poqi", 1);
			break;
		case 1:
			perform_action("cuff leidong", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(3))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("cuff leidong", 1);
			break;
		case 2:
			perform_action("strike wuji", 1);
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
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj;  
		if(!userp(me))	continue;
		//最后一个打倒的人将获得进入下一层的资格
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>155 )
		{
			message_vision("$HIR$N猛的喷出一口鲜血，怒吼道：“$n竟然杀了我,红花会的兄弟不会放过你的”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level12"))
				me->set("18dy/level13",1);
			me->move(load_room("高昌寒冰地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
