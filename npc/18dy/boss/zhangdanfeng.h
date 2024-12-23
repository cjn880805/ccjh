//zhangdanfeng 张丹枫 
//地狱第十五层BOSS

BOSS_BEGIN(CNzhangdanfeng);

virtual void create()
{	
	set_name("张丹枫", "zhang dan feng");
	set("title", "桥头游侠");
	set("gender", "男性");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "他长的魁梧有力，一张经历风霜的脸上带着浅浅的微笑，亲切中流露出一丝严厉，轻皱的眉头，漆黑的的眼中有那么一种顽皮。");
		
	set("str", 125);
	set("int", 125);
	set("con", 125);
	set("dex", 95);
	set("per",25+random(10));
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 15);		//设置NPC使用绝招的几率
	
	set_inquiry("桥头总舵", "那是我们桥头吧的兄弟们组建起来的帮派。");
	set_inquiry("四大恶人", "江湖四大恶人我、段小楼、天才小混混、在水伊人。");
	set_inquiry("唐山帮", "那是我们的敌人。");

	set("hp", 192000);
	set("max_hp",192000);
	set("max_mp", 95000);
	set("mp", 95000);
	set("mp_factor", 500);
	
	set("combat_exp", 310000000);
	set("score", 500000);
	
	set_skill("force", 900);
	set_skill("taiji_shengong", 900);
	set_skill("dodge", 900);
	set_skill("tiyunzong", 900);
	set_skill("unarmed", 900);
	set_skill("taiji_quan", 900);
	set_skill("parry", 900);
	set_skill("sword", 900);
	set_skill("taiji_jian", 900);
	set_skill("blade", 900);
	set_skill("taiji_dao", 900);
	set_skill("taoism", 900);
	set_skill("literate", 900);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");
	
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
	set_temp("apply/震字诀",10+random(10));
	set_temp("apply/挤字诀",random(10));
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 1250);
    set("apply/damage", 1120);

	set("chat_chance", 5);
    carry_object("changjian")->wield();

	set("family/family_name","武当派");
	
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
		return "张丹枫呵呵一笑，道：“桥头和唐山那场战役当年轰动了整个江湖。”";
	case 1:
		return "张丹枫仰天大笑道：“我就是四大恶人之首「恶贯满盈」。”";
	case 2:
		return "张丹枫负手踱步，冷冷的说道：“我不问江湖是非已经很多年了。”";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * item = PresentName("changjian", IS_ITEM);
	if(query_weapon() == item && item)
	{
		switch(random(4))
		{
		case 0:
			perform_action("sword lian", 1);
			break;
		case 1:
			perform_action("sword chan", 1);
			break;
		case 2:
			perform_action("sword sui", 1);
			break;
		case 3:
			perform_action("force recover",0);
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
			perform_action("unarmed zhen", 1);
			break;
		case 2:
			perform_action("unarmed ji", 1);
			break;
		case 3:
			perform_action("unarmed zhenup",1);
			break;
		case 4:
			perform_action("unarmed zhan",1);
			break;
		case 5:
			perform_action("unarmed jielidali",1);
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
			message_vision("$HIR$N道：“我真的老了，江湖是$n你们年轻一辈的了！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level18"))
				me->set("18dy/level19",1);
			me->move(load_room("高昌蛆虫地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
