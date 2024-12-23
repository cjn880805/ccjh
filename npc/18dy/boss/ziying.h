//ziying 紫郢 
//地狱第十六层BOSS

BOSS_BEGIN(CNziying);

virtual void create()
{	
	set_name("紫郢", "zi ying");
	set("title", "头号色巫");
	set("gender", "男性");
	set("icon", young_man3);
	set("age", 399);
	set("long",  "他风流潇洒,才华横溢,令人一见倾心。");
		
	set("str", 130);
	set("int", 130);
	set("con", 130);
	set("dex", 95);
	set("per",25+random(10));
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 15);		//设置NPC使用绝招的几率
	
	set_inquiry("靠谱", "那是我的拿手绝活。");
	set_inquiry("女朋友", "明天在天,她在那里呢？");

	set("hp", 202000);
	set("max_hp",202000);
	set("max_mp", 95000);
	set("mp", 95000);
	set("mp_factor", 500);
	
	set("combat_exp", 330000000);
	set("score", 500000);
	
	set_skill("force", 950);
	set_skill("yunv_xinfa", 950);
	set_skill("seaforce", 950);
	set_skill("sword", 950);
	set_skill("yunv_jian", 950);
	set_skill("smithsword",950);
	set_skill("dodge", 950);
	set_skill("xianyun_bufa", 950);
	set_skill("parry", 950);
	set_skill("unarmed", 950);
	set_skill("meinv_quan", 950);    
	set_skill("anranxiaohun_zhang", 950);
	set_skill("tianluo_diwang", 950);
	set_skill("literate", 950);
	
	map_skill("force", "seaforce");
	map_skill("sword", "smithsword");
	map_skill("dodge", "xianyun_bufa");
	map_skill("parry", "anranxiaohun_zhang");
	map_skill("unarmed", "anranxiaohun_zhang");
	
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

	set("couple_betray",1);
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 1300);
    set("apply/damage", 1200);

	set("chat_chance", 5);
    carry_object("changjian")->wield();

	set("family/family_name","古墓派");
	
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
		return "紫郢很诧异的看着眼神迷茫的你，说道：“人不风流枉少年。”";
	case 1:
		return "紫郢很深情的看着远处的平台，说道：“江湖凝聚了好多人的心血。” ";
	case 2:
		return "紫郢仰天长啸，放声喝道：“何日拿起尘封已久的刀,再重出江湖？”";
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
			perform_action("sword flood", 1);
			break;
		case 1:
			perform_action("force recover",0);
			break;
		case 2:
			perform_action("force flood", 1);
			break;
		}
	}
	else
	{
		switch(random(6))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("unarmed xiaohun", 1);
			break;
		case 2:
			perform_action("force flood", 1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>163 )
		{
			message_vision("$HIR$N平静的看着你道：“既然如此，$n就下去吧！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level19"))
				me->set("18dy/level20",1);
			me->move(load_room("高昌烊铜地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
