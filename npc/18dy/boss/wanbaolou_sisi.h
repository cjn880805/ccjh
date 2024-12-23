//wanbaolou_sisi 思思 
//奈何桥BOSS

//wuqing 2001-11-29

BOSS_BEGIN(CNwanbaolou_sisi);

virtual void create()
{
	set_name("思思", "si si");
	set("title", "万宝楼楼主");
	
	set("gender", "女性");
	set("age", 58);
	set("long", "她长的羞花闭月,脸上却始终挂着淡淡的忧郁,唯有不经意间眼中射出的精光让人不寒而栗。");
	set("icon", young_woman1);
    
	set("str", 55);
	set("int", 55);
	set("con", 55);
	set("dex", 55);
	set("per",40);
	set("level",140);

	set("chat_chance_combat", 30);		//设置NPC使用绝招的几率
	
	set_inquiry("万宝楼", "唉,现在奸商太多,生意一天比一天难做啊。");
	set_inquiry("浪迹天涯", "天涯在那？谁陪我一起去浪迹？");
	set_inquiry("金钱", "我本心向照明月,奈何明月照沟渠。你竟然问我这么俗的问题我不理你了。");

	set("hp", 42000);
	set("max_hp", 42000);
	set("mp", 32000);
	set("max_mp", 32000);
	set("mp_factor", 500);
	
	set("combat_exp", 60000000);
	set("score", 500000);
	
	set_skill("force", 500);
    set_skill("dodge", 500);
    set_skill("parry", 500);
	set_skill("finger", 500);
    set_skill("jiuyang_shengong", 500);
	set_skill("lingfa", 500);
	set_skill("shenghuo_lingfa", 500);
	set_skill("qiankun_danuoyi", 500);
	set_skill("shenghuo_xinfa", 500);
	set_skill("huntian_qigong", 500);
	set_skill("fengyu_wuqingzhi", 500);

	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "jiuyang_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");
	map_skill("finger", "fengyu_wuqingzhi");

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

	set("apply/armor", 550);
    set("apply/damage", 420);

	set("chat_chance", 5);
	carry_object("shenghuo_ling")->wield();

	set("family/family_name","明教");
	set("death_times",1);
	
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
		return "思思幽幽的说道：“想当年我美貌风靡江湖,如今年华老去无人问津。”";
	case 1:
		return "思思轻叹道：知我者谓我心忧,不知我者谓我何求 ";
	case 2:
		return "思思忧郁的望着远方，叹道：“万宝楼也没落了,再没有以前的风光了。”";
	case 3:
		return "思思叹了口气，道：“那里有青春永驻的药啊？”";
	}
	return 0;
	
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("shenghuo_ling", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("lingfa duo", 1);
			break;
		case 1:
			perform_action("lingfa xiyanling", 1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id")) && me->query("level")>110 )
		{
			message_vision("$HIR$N不可置信的看着$n道：“你一定会后悔的！你一定会后悔的！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level2"))
				me->set("18dy/level3",1);
			me->move(load_room("高昌鬼门关"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
