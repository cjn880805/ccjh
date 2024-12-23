//bingliang_bohe 冰凉薄荷 
//地狱第十层BOSS

BOSS_BEGIN(CNbingliang_bohe);

virtual void create()
{
	set_name("冰凉薄荷", "bingliang buhe");
	set("title", "凤舞九天");
	set("gender", "女性");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "她眉眼如画，温和娴雅，笑起来风情万种。");
	
	set("str", 115);
	set("int", 115);
	set("con", 115);
	set("dex", 95);
	set("level",218);
	set("per",32);
	set("repute",50000000);

	set("chat_chance_combat", 15);		//设置NPC使用绝招的几率
	
	set_inquiry("思思", "她在那里啊？");
	set_inquiry("仗解", "在老庄主那里。");

	set("hp", 152000);
	set("max_hp",152000);
	set("max_mp", 78000);
	set("mp", 78000);
	set("mp_factor", 500);
	
	set("combat_exp", 240000000);
	set("score", 500000);
	
	set_skill("force", 820);
	set_skill("unarmed", 820);
	set_skill("dodge", 820);
	set_skill("parry", 820);
	set_skill("hand",820);
	set_skill("staff", 820);
	set_skill("hamagong", 820);
	set_skill("chanchu_bufa", 820);
	set_skill("shexing_diaoshou", 820);
	set_skill("lingshe_zhangfa", 820);
	set_skill("xunshou_shu",820);
	set_skill("poison", 820);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");
	
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

	set("apply/armor", 1150);
    set("apply/damage", 1000);

	set("chat_chance", 5);
    carry_object("shezhang")->wield();

	set("family/family_name","白驼山派");
	
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
		return "冰凉薄荷自言自语道：“死土豆又不知道跑那里去泡MM了。”";
	case 1:
		return "冰凉薄荷笑咪咪的念道：“睡觉睡到自然醒，数钱数到手抽筋。”";
	case 2:
		return "冰凉薄荷轻轻的叹了口气，道：“好怀念以前跟兄弟姐妹在江湖的日子。”";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * item = PresentName("shezhang", IS_ITEM);
	if(query_weapon() == item && item)
	{
		
		switch(random(4))
		{
		case 0:
			perform_action("staff pili", 1);
			break;
		case 1:
			perform_action("force powerup", 0);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		case 3:
			perform_action("unarmed wugu", 1);
			break;
		}
	}
	else
	{
		switch(random(3))
		{
		case 0:
			perform_action("force powerup", 0);
			break;
		case 1:
			perform_action("force recover", 0);
			break;
		case 2:
			perform_action("unarmed wugu", 1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>160 )
		{
			message_vision("$HIR$N道：“不跟你玩了,我回家去带宝宝了！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level13"))
				me->set("18dy/level14",1);
			me->move(load_room("高昌剥皮地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
