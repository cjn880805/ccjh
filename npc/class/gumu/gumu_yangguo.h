//longnv.h
//code by zwb
//12-23

NPC_BEGIN(CNGuMu_yangguo);

virtual void create()
{
	set_name("过儿","guo er");
	
	set("gender", "男性");
	set("age", 38);
	set("long","他是一位高大的男子，相貌俊秀。一只长袖空空如也，显是断了一臂，尽管如此，仍然掩不住他迷人的风采。");
	set("title","独醉红尘");
	set("attitude", "friendly");
	set("icon",young_man1);
	
	set("per", 40);
	set("str", 40);
	set("int", 37);
	set("con", 36);
	set("dex", 58);	
	set("foolid",61);
	set("chat_chance", 10);
	set("chat_chance_combat", 40);
	
	set("hp", 22000);
	set("max_hp", 22000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_factor", 200);
	
	set("combat_exp", 54000000);
	
	set_skill("force", 220);
	set_skill("yunv_xinfa", 220);	//玉女心法
	set_skill("seaforce", 300);		//狂潮心法
	
	set_skill("sword", 300);
	set_skill("yunv_jian", 260);
	set_skill("smithsword",300);	//玄铁重剑式
	
	set_skill("dodge", 260);
	set_skill("xianyun_bufa", 260);	//纤云步法
	
	set_skill("parry", 300);
	set_skill("unarmed", 300);
	set_skill("meinv_quan", 220);    
	set_skill("anranxiaohun_zhang", 300);
	set_skill("tianluo_diwang", 220);
	
	set_skill("literate", 260);
	
	map_skill("force", "seaforce");
	map_skill("sword", "smithsword");
	map_skill("dodge", "xianyun_bufa");
	map_skill("parry", "anranxiaohun_zhang");
	map_skill("unarmed", "anranxiaohun_zhang");
	
	create_family("古墓派", 3, "弟子");
	
	set_inquiry("玄铁重剑式","玄铁重剑式得于落瀑，归于大潮。");
	set_inquiry("古墓派","我和龙儿本来是一对璧人，可是...");
	set_inquiry("绝情丹",do_jueqingdan);
	set_inquiry("绝情谷","具体位置我也不知道在那，你去问问百晓生吧");
	set_inquiry("百晓生","江湖第一消息灵通的人，他在成都。");
	set_inquiry("出去","这是什么话，要能出去我早出去了！");
	
	carry_object("xuantiesword")->wield();	

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("no_huan",1);
}

static char * do_jueqingdan(CNpc *who,CChar *me)
{
//	if(DIFFERSTR(me->querystr("family/family_name"), "古墓派"))
//		return "过儿眉头一皱道：你不是我们古墓弟子，我怎么敢麻烦你呢？";
			
	if ( me->query("repute") < 100000)
		return "过儿叹了一口气说：你的声望这么低，怎么可以进的了绝情谷呀！";

	if ( me->query_temp("gumu/jq_dan_ok") )
		return "过儿惊喜着说道：你真的拿到了绝情丹？？";

	if ( me->query("gumu/jq")==me->query("age") )
		return "过儿呵呵一笑：我记得你已经帮我找到了绝情丹了呀！";
	
	if(!me->query_temp("gumu/jq_dan"))
	{
		who->say("龙儿中了情花之毒，需要绝情丹解毒，你能帮我找到吗？", me);
		who->SendMenu(me);
		me->del("gumu/完成");
		me->set_temp("gumu/jq_dan",1);
	}
	else
	{
		if(random(1))
			who->say("绝情丹应该只有绝情谷谷主才有，不知道你能不能从他那里拿到。", me);
		else
			who->say("绝情谷具体位置我也不知道在那，只有“江湖百事通”百晓生知道在那里。", me);
		who->SendMenu(me);
	}
	return 0;
}

virtual char * chat_msg_combat(CChar * player)
{
//	char msg[255];	
	switch(random(3))
	{
	case 1:
		perform_action("unarmed anranxiaohun", 1);
		return 0;
	case 2:
		perform_action("force recover", 0);
	}
	return 0;
}

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "过儿道：该死的武道我理，告诉我龙儿在这里，害我跳下来被困……";
	case 1:
		return "过儿道：黯然销魂着，惟别而已。";
	case 2:
		return "过儿道：爱欲生忧，忧而生怖，若离于爱，何忧何怖？";
	}
	return "";
}

virtual void attempt_apprentice(CChar  * player)
{
	if (!player->query_temp("hjcss"))
	{
		say("你见到过龙儿吗？",player);
		SendMenu(player);
		return;
	}
	if(player->query("per") < 28)
	{
		say(" 尊容实在不敢恭维，收了你会给龙儿笑话我的。",player);
		SendMenu(player);
		return;
	}
	if(player->query_int() < 35)
	{
		say(" 收你这么笨的徒弟，不让龙儿笑话我才怪。",player);
		SendMenu(player);
		return;
	}
	if(player->query("repute") < 50000)
	{
		say(" 龙儿最不喜欢大奸大恶之人，你我无缘。",player);
		SendMenu(player);
		return;
	}
	if(DIFFERSTR(player->querystr("family/family_name"), "古墓派"))
	{
		say(" 龙儿不会让我收外人为徒的，你先到古墓去问问她吧。",player);
		SendMenu(player);
		return;
	}
	if(EQUALSTR(player->querystr("class"), "taoist"))
	{
		say(" 龙儿不喜欢她师姐的弟子，我怎么敢收你啊？",player);
		SendMenu(player);
		return;
	}
	else
	{
		say(" 好吧，我就收下你这个徒弟了。");
		recruit_apprentice(player);
	}
	return;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if( EQUALSTR(ob->querystr("base_name"), "junzijian")
		&& who->query_temp("marks/ask_long"))
	{
		command("ah");
		command("faint");
		command("say");
		command("thank");
		who->set_temp("hjcss",1);
		destruct(ob);
		say("是龙儿让你来找我的吧，很好。想入我派的话就说吧，没问题。");
		SendMenu(who);
		return 1;	
	}
	else if(EQUALSTR(ob->querystr("id"), "jue qing dan")&& who->query_temp("gumu/jq_dan_ok"))
	{
		destruct(ob);
		say("谢谢你，麻烦你把这个直接交给龙儿吧！她在古墓。");
		CContainer * bot = load_item("mixian");
		bot->set_name("绝情丹", "jue qing dan");
		bot->set("long","四四方方骰子般的丹药，色作深黑，腥臭刺鼻，正使天竺奇花『情花』的独门解药。");
		bot->set("value", 0l);      
		bot->set("unit", "颗");
		bot->move(who);
		who->delete_temp("gumu/jq_dan_ok");
		who->set_temp("gumu/jq_dan_nv",1);
		SendMenu(who);
		return 1;
	}
	else
		return 0;
}

NPC_END;




