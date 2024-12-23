//chongtian 冲天 
//地狱第八层BOSS

BOSS_BEGIN(CNchongtian);

virtual void create()
{	
	set_name("冲天", "chong tian");
	set("title", "追魂剑");
	set("gender", "男性");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "他棱角分明的脸,让人一看就知道是个性显然的人。");

	set("per",random(20)+10);
	set("str", 110);
	set("int", 110);
	set("con", 110);
	set("dex", 95);
	set("level",210);
	set("repute",50000000);

	set("chat_chance_combat", 20);		//设置NPC使用绝招的几率
	
	set_inquiry("龙门客栈", "那是一帮志同道合的兄弟姐妹组建的帮派。");
	set_inquiry("第一", "江湖第一只是个虚名而已,徒增烦恼而已");
	set_inquiry("修罗", "那家伙又不知道跑那里去泡MM了。");

	set("hp", 132000);
	set("max_hp", 132000);
	set("mp", 72000);
	set("max_mp", 72000);
	set("mp_factor", 500);
	
	set("combat_exp", 210000000);
	set("score", 500000);
	
	set_skill("buddhism", 780);
	set_skill("literate", 780);

	set_skill("blade", 780);
	set_skill("claw", 780);
	set_skill("club", 780);
	set_skill("cuff", 780);
	set_skill("dodge", 780);
	set_skill("finger", 780);
	set_skill("force", 780);
	set_skill("hand", 780);
	set_skill("parry", 780);
	set_skill("staff", 780);
	set_skill("strike", 780);
	set_skill("sword", 780);
	set_skill("whip", 780);

	set_skill("banruo_zhang", 780);
	set_skill("cibei_dao", 780);
	set_skill("damo_jian", 780);
	set_skill("fengyun_shou", 780);
	set_skill("wuying_jian", 780);
	set_skill("hunyuan_yiqi", 780);
	set_skill("jingang_quan", 780);
	set_skill("longzhua_gong", 780);
	set_skill("luohan_quan", 780);
	set_skill("nianhua_zhi", 780);
	set_skill("pudu_zhang", 780);
	set_skill("qianye_shou", 780);
	set_skill("sanhua_zhang", 780);
	set_skill("riyue_bian", 780);
	set_skill("shaolin_shenfa", 780);
	set_skill("weituo_gun", 780);
	set_skill("wuchang_zhang", 780);
	set_skill("xiuluo_dao", 780);
	set_skill("yingzhua_gong", 780);
	set_skill("yijinjing", 780);
	set_skill("yizhi_chan", 780);
	set_skill("zui_gun", 780);

	map_skill("blade", "cibei_dao");
	map_skill("claw", "longzhua_gong");
	map_skill("club", "wuchang_zhang");
	map_skill("cuff", "luohan_quan");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun_shou");
	map_skill("parry", "yizhi_chan");
	map_skill("staff", "weituo_gun");
	map_skill("strike", "sanhua_zhang");
	map_skill("sword", "wuying_jian");
	map_skill("whip", "riyue_bian");

	prepare_skill("finger", "nianhua_zhi");
	prepare_skill("strike", "sanhua_zhang");
	
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

	set("apply/armor", 1050);
    set("apply/damage", 920);

	set("chat_chance", 5);

    carry_object("changjian")->wield();
	carry_object("xuan_cloth")->wear();

	set("family/family_name","少林派");
	
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
		return "冲天双手合起，口中佛号响起：“罪过罪过，风魔、玉面去喝花酒去。”";
	case 1:
		return "冲天伸出中指，演示出佛门伏魔无上绝技指法，同时念道：“立谈中，生死同，一诺千金重。”";
	case 2:
		return "冲天无奈的说道：“保镖虽然好辛苦,可是总算有事情做了。”";
	case 3:
		return "冲天无可奈何的摇了摇头，合掌说道：“心中无佛的和尚又怎么可以成佛呢？难怪今日少林不如往昔，希望当年我留在那里的东西可以帮的上他们。罪过，罪过。。”";
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
			perform_action("sword wuying", 1);
			break;
		case 1:
			perform_action("force roar", 1);
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
			perform_action("finger foxue", 1);
			break;
		case 2:
			perform_action("parry dian", 1);
			break;
		case 3:
			perform_action("parry jingmo", 1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>152 )
		{
			message_vision("$HIR$N吼道：“$n你竟然能打败昔日的江湖第一,那你可以去下一层了！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level11"))
				me->set("18dy/level12",1);
			me->move(load_room("高昌嵯山地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
