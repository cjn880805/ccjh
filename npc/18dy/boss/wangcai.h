//wangcai 旺财 
//地狱第十七层BOSS

BOSS_BEGIN(CNwangcai);

virtual void create()
{	
	set_name("旺财", "wang cai");
	set("title", "铁血巫师");
	set("gender", "男性");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "这是一只巨犬，肌肉强壮，骨凌出峰，十分恐怖。");
		
	set("str", 140);
	set("int", 140);
	set("con", 140);
	set("dex", 95);
	set("per",25+random(10));
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 15);		//设置NPC使用绝招的几率
	
	set_inquiry("小蜜蜂", "唉,情难自禁啊,有了她我再也不可以泡MM了。");
	set_inquiry("靠谱", "传说中的江湖十大天书之一");
	set_inquiry("铁血", "情非得已,现实是很残酷的。");

	set("hp", 252000);
	set("max_hp",252000);
	set("max_mp", 10000);
	set("mp", 10000);
	set("mp_factor", 500);
	
	set("combat_exp", 380000000);
	set("score", 500000);
	
	set_skill("force", 970);
    set_skill("dodge", 970);
    set_skill("parry", 970);
    set_skill("sword", 970);
    set_skill("finger", 970);
	set_skill("kurong_changong", 970);
    set_skill("tiannan_step", 970);
    set_skill("duanjia_sword", 970);
    set_skill("liumai_shenjian", 970);
	set_skill("literate", 970);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("finger", "liumai_shenjian");
	map_skill("parry", "liumai_shenjian");
	map_skill("sword", "duanjia_sword");

	prepare_skill("finger", "liumai_shenjian");
	
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
	set_temp("apply/六脉归一",1);

	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 1400);
    set("apply/damage", 1200);

	set("chat_chance", 5);
    carry_object("changjian")->wield();

	set("family/family_name","大理段家");
	
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
		return "旺财左看看，右看看，猛的回头过来问道：“你见过像我这么帅的狗吗？”";
	case 1:
		return "旺财轻叹道：“当时年少春衫薄，引马倚斜桥，满楼红袖招。壮年听雨客舟中，江阔云低，断雁叫西风。” ";
	case 2:
		return "旺财长嘘一口气，叹道：“长沟流月去无声，世路如今已惯，此心到处悠然，风鬟霜鬓，一任阶前点滴到天明。”";
	case 3:
		return "旺财神神秘秘的凑到你耳边，说道：“有些不世的神功是需要在战斗中不断的亲身体验才可以领悟。”";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	char msg[40];
	CContainer * item = PresentName("changjian", IS_ITEM);
	if(query_weapon() == item && item)
	{
		switch(random(4))
		{
		case 0:
			perform_action("sword jingtian", 1);
			break;
		case 1:
			perform_action("force recover",0);
			break;
		case 2:
			perform_action("sword fenglei", 1);
			break;
		case 3:
			command(snprintf(msg, 40, "unwield %ld", item->object_id()));
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
			perform_action("finger ci", 1);
			break;
		case 2:
			perform_action("finger feng", 1);
			break;
		case 3:
			perform_action("finger tan", 1);
			break;
		case 4:
			perform_action("finger guiyi", 1);
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
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj;  
		if(!userp(me))	continue;
		//最后一个打倒的人将获得进入下一层的资格
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>163 )
		{
			message_vision("$HIR$N不可思议的道：“连我这么帅气的狗你都下的了手，$n那你就下去接受真正的恐怖吧！哈哈哈哈哈哈哈哈哈哈哈！！！！！！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level20"))
				me->set("18dy/level21",1);
			me->move(load_room("高昌阿鼻地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
