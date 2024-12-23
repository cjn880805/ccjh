//tiancai_hunhun 天才小混混 
//地狱第四层BOSS

BOSS_BEGIN(CNtiancai_hunhun);

virtual void create()
{
	set_name("天才小混混", "tiancai hunhun");
	set("title", "忆月如");
	set("gender", "男性");
	set("age", 98);
	set("class", "bonze");
	set("icon",young_monk);
	set("long",  "年仅十五、六岁的模样，生着一张天真犹存、童稚未泯的脸蛋儿，长的甚是清秀瘦削，圆亮如星的双眸，挺直俊俏的鼻梁，红润优美的菱角嘴似笑非笑地微翘着，看来就像个绝对无害的乖宝宝。");
   
	set("str", 90);
	set("int", 90);
	set("con", 90);
	set("dex", 90);
	set("per",25);
	set("level",190);
	set("repute",-60000000);

	set("chat_chance_combat", 15);		//设置NPC使用绝招的几率
	
	set_inquiry("月如", "那是我的那个..那个..。");
	set_inquiry("无恶不做", "我是四大恶人里的老三");
	set_inquiry("幼儿园", "江湖里的宝宝都来我的帮派上幼儿园哦。");

	set("hp", 92000);
	set("max_hp", 92000);
	set("mp", 52000);
	set("max_mp", 52000);
	set("mp_factor", 500);
	
	set("combat_exp", 160000000);
	set("score", 500000);
	
	set_skill("mizong_xinfa", 700);
	set_skill("literate", 700);
	set_skill("force", 700);
	set_skill("parry", 700);
	set_skill("blade", 700);
	set_skill("sword", 700);
	set_skill("dodge", 700);
	set_skill("longxiang", 700);
	set_skill("shenkong_xing", 700);
	set_skill("hand", 700);
	set_skill("dashou_yin", 700);
	set_skill("mingwang_jian", 700);
	set_skill("xue_dao", 700);
	set_skill("poison", 700);
	   
	map_skill("force", "longxiang");
	map_skill("dodge", "shenkong_xing");
	map_skill("hand", "dashou_yin");
	map_skill("parry", "xue_dao");
	map_skill("blade", "xue_dao");
	map_skill("sword", "mingwang_jian");
	   
	prepare_skill("hand","dashou_yin");
	
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

	set("apply/armor", 850);
    set("apply/damage", 720);

	set("chat_chance", 5);
	carry_object("xblade")->wield();
	carry_object("p_jiasha")->wear();
	carry_object("sengmao")->wear();

	set("family/family_name","雪山寺");
	
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
		return "天才小混混眉头一抬，喝道：“你丫的不认识我？我就是传说中的雪山派开山掌门天才小混混。”";
	case 1:
		return "天才小混混傲然说道：“我就是杀手阁的老大，血刀金轮一出，从不失手哦。 ”";
	case 2:
		return "天才小混混黯然叹道：“想当年,我和月如是令江湖人人羡慕的一对,如今却......”";
	
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("xblade", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("blade jixue", 1);
			break;
		case 1:
			perform_action("force fanchang", 1);
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
			perform_action("hand tianyin", 1);
			break;
		case 2:
			perform_action("force fanchang", 1);
			break;
		case 3:
			carry_object("xblade")->wield();
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>135 )
		{
			message_vision("$HIR$N无限遗憾的叹道：“一代新人换旧人，如今的江湖我已经混不下去了吗？”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level7"))
				me->set("18dy/level8",1);
			me->move(load_room("高昌黑身地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
