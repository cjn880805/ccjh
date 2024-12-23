//tudou 土豆 
//地狱第十一层BOSS

BOSS_BEGIN(CNtudou);

virtual void create()
{	
	set_name("土豆", "tu dou");
	set("title", "洪门");
	set("gender", "男性");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "他长的五大三粗,看上去一副不解风情的样子,但是他和冰凉的美好爱情是所有江湖人都羡慕的。");
	
	set("str", 117);
	set("int", 117);
	set("con", 117);
	set("dex", 95);
	set("per",25);
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
	
	set_inquiry("洪门", "唉，那个帮派早就没人了。");
	set_inquiry("MM", "冰凉不准我再想任何MM");
	set_inquiry("鬼娃娃", "不知道谁还记得这个家伙。");

	set("hp", 157000);
	set("max_hp",157000);
	set("max_mp", 80000);
	set("mp", 80000);
	set("mp_factor", 500);
	
	set("combat_exp", 250000000);
	set("score", 500000);
	
	set_skill("force", 825);
    set_skill("dodge", 825);
    set_skill("parry", 825);
	set_skill("strike", 825);
	set_skill("lingfa", 825);
	set_skill("shenghuo_lingfa", 825);
	set_skill("qiankun_danuoyi", 825);
	set_skill("shenghuo_xinfa", 825);
	set_skill("hanbing_mianzhang", 825);
	set_skill("shenghuo_shengong", 825);
	
	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");
    map_skill("strike", "hanbing_mianzhang");
	
	prepare_skill("strike","hanbing_mianzhang");
	
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
    carry_object("shenghuo_ling")->wield();

	set("family/family_name","明教");
	
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
		return "土豆不胜感慨的叹道：“想当年玉树临风,如今却......”";
	case 1:
		return "土豆说道：“洪门和万宝楼是联盟。” ";
	case 2:
		return "土豆似乎给勾起了对往事的回忆，沉默了很久，放声高吟道：“少年侠气，交结五都雄。肝胆洞，毛发耸。”";
	
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
			perform_action("strike xixue", 1);
			break;
		case 1:
			perform_action("force recover", 0);	
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>162 )
		{
			message_vision("$HIR$N吼道：“小子,你连我都敢动,$n就等着我去找开心帮我报仇吧！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level14"))
				me->set("18dy/level15",1);
			me->move(load_room("高昌畜性地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
