// huashan_linghu.c 令狐冲
//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNhuashan_linghu);

virtual void create()
{
	set_name("冲郎","ling huchong");
	set("nickname", "大师兄");
	set("long", "冲郎身材较瘦，长的浓眉阔眼，气宇暄昂，他在同门中排行老大，是华山派年轻一代中的顶尖好手。");
	set("gender", "男性");
	set("age", 28);
	set("class", "swordsman");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man2);
	
	set("hp", 2800);
	set("max_hp", 5400);
	set("mp", 2400);
	set("max_mp", 2400);
	set("mp_factor", 60);
	
	set("combat_exp", 800000);
	set("score", 100000);
	
	set_skill("unarmed",125);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 140);
	set_skill("sword", 190);
	set_skill("huashan_sword", 190);

	set_skill("huashan_shenfa", 150);
	set_skill("feiyan_huixiang",150);
	set_skill("lonely_sword",160);
	set_skill("literate", 120);
	set_skill("zhengqijue",120);
	
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("sword", "lonely_sword");
	set("card2_count",1);
	
	create_family("华山派", 14, "弟子");
	
	set_inquiry("风前辈","唉，已经很久没有见到他老人家了。你问这干嘛？");
	set_inquiry("任大小姐","你真有她的消息吗？ ");
	carry_object("ls_book", 1);	 	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"何日才能见到盈盈啊!%s，你可有她的消息?",query_respect(ob) );
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(who->query_temp("ry/renwu2_2") && !who->query_temp("ry/renwu2_3"))
	{
		if (ob->query("ry/shoujuan") &&  EQUALSTR(ob->querystr("owner1"), who->id(1)))
		{
			say( "令狐冲看到手娟后，脸上一丝露出思念之情“这么久了盈盈还在挂念我，有机会我一定去看望她。最近华山上事务繁多，你先帮我把这封信给她吧。”", who);
			destruct(ob);
			CContainer * obj = load_item("baozi");
			obj->set_name("信", "xin");
			obj->set_weight(500);
			obj->set("long", "这是一封冲郎写给盈盈的信。");
			obj->set("owner1",who->id(1));
			obj->set("ry/xin",1);
			obj->move(who);
			who->set_temp("ry/renwu2_3",1);//接受送信给盈盈的任务
			tell_object(who,"\n$HIC你得到数量1的信。\n");
		}
		else
			return notify_fail("令狐冲不需要这件东西。");
	}
	else
	{
		if (query("card2_count") == 0)
		{ 
			say( "我已经托人找盈盈去了，多谢你了!", who);
			SendMenu(who);
			return 1;
		}
		
		if ( DIFFERSTR(ob->querystr("base_name"), "huashan_letter"))
			return notify_fail("令狐冲不需要这件东西。");
		
		say( "盈盈……", who);
		say("这块白虎堂令牌你拿去还给盈盈,告诉她我就去找她!", who);
		ob = load_item("card2");//白虎堂令牌 tested by lanwood 2000-12-28
		ob->move(who);
		set("card2_count",0l);
	}
	SendMenu(who);
	return 1;
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];

	if ( ob->query("repute") < 0)
	{
		say("我华山派乃是堂堂名门正派，对弟子要求极严。", ob);
		say(snprintf(msg,255,"在德行方面，%s是否还做得不够？",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}

	if ( ob->query_int() < 25) 
	{
		say(snprintf(msg,255,"依我看%s的资质似乎不适合学我华山派武功？",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}

	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
	return;
}

NPC_END;