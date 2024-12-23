//yijianfeixian 冷 
//地狱第一层BOSS

BOSS_BEGIN(CNbiluo_leng);

virtual void create()
{
	set_name("冷", "leng");
	set("title", "碧落黄泉");
	set("gender", "女性");
	set("icon", young_woman3);
	set("age", 88);
	set("long",  "一个秀美的女子，凝脂肌肤如水眼波，长得美貌之极，又如冰雪一般好似不食人间烟火的模样。");
    
	set("str", 75);
	set("int", 75);
	set("con", 75);
	set("dex", 75);
	set("per",30);
	set("level",160);

	set("chat_chance_combat", 25);		//设置NPC使用绝招的几率
	
	set_inquiry("碧落盟", "碧落盟的兄弟现在都在那里啊。");
	set_inquiry("鱼", "鱼是我家那口死没良心的,也是八剑的老三");
	set_inquiry("斩将决", "这个..这个..我最后传给了关门弟子开星笑雨了。");

	set("hp", 62000);
	set("max_hp", 62000);
	set("mp", 37000);
	set("max_mp", 37000);
	set("mp_factor", 500);
	
	set("combat_exp", 100000000);
	set("score", 500000);
	
	set_skill("zhanjiang_jue", 600);
	set_skill("blade", 600);
	set_skill("guimei_shenfa", 600);
	set_skill("dodge", 600);
	set_skill("hunyuan_yiqi", 600);
	set_skill("force", 600);
	set_skill("finger", 600);
	set_skill("fengyu_wuqingzhi", 600);
	set_skill("zhongpingqiang", 600);
	set_skill("wuhuduanmendao", 600);

	map_skill("blade", "zhanjiang_jue");
	map_skill("finger", "fengyu_wuqingzhi");
	map_skill("dodge", "guimei_shenfa");
	map_skill("force", "hunyuan_yiqi");
	map_skill("parry", "zhanjiang_jue");

	prepare_skill("finger","fengyu_wuqingzhi");
	
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
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 650);
    set("apply/damage", 520);

	set("chat_chance", 5);
    carry_object("dadao")->wield();

	set("family/family_name","桃花岛");
	
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
	switch(random(3))
	{
	case 0:
		return "冷轻皱眉头，叹道：“斩将决的要决在于力,可惜现在的人都单薄的很,我的独门武功就要失传了。”";
	case 1:
		return "“上穷碧落下黄泉”，一身叹息自你身后幽幽响起。 ";
	case 2:
		return "冷凝视着远处，回头说道：“碧落盟是一个惩恶除奸的帮派。”";
	
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("dadao", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(2))
		{
		case 0:
			perform_action("club killyou", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(2))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("finger rain", 1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>120 )
		{
			message_vision("$HIR$N看着断了的斩马刀，惊异的望着$n道：“没想到武功也是会退步的啊？”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level4"))
				me->set("18dy/level5",1);
			me->move(load_room("高昌刀山地狱"));
			break;
		}
	}

	CNbossnpc::die();
}

BOSS_END;
