//yangdingtian.阳顶天
//Lanwood 2001-3-21

NPC_BEGIN(CNmingjiao_yangdingtian);

virtual void create()
{
	set_name("阳立地",  "yang lidi");
	set("long", "只见阳立地坐在一间小室之中，手里执着一张羊皮，满脸殷红如血。忽然间满脸铁青，但脸上这铁青之色一显即隐，立即又变成血红之色，忽青忽红。");
    set("title","明教第三十三代教主");
	set("gender", "男性");
    set("age", 40);
	set("shen_type",1);
    set("attitude", "friendly");
	set("icon",young_man2);

    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("hp", 10000);
    set("max_hp", 18000);
    
    set("mp", 6000);
    set("max_mp", 6000);
    set("mp_factor", 120);

	set("no_kill",1);//不在北京、万劫任务中出现

    set("combat_exp", 8000000);
    set("score", 455000);
    
    set_skill("force", 280);
    set_skill("dodge", 28);
    set_skill("parry", 280);
	set_skill("unarmed", 280);
    set_skill("finger", 280);
	set_skill("xuantian_shengong", 280);
	set_skill("qiankun_danuoyi", 300);
	set_skill("xuantian_zhi", 300);

	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "xuantian_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("finger", "xuantian_zhi");
	prepare_skill("finger", "xuantian_zhi");

    create_family("明教",33, "教主");
	set("chat_chance", 5);
	set("chat_chance_combat", 10);
	set_inquiry("离开密室", ask_leave);
	set_inquiry("乾坤大挪移", ask_qiankun);

    carry_object("baipao")->wear();
};

static char * ask_leave(CNpc *who,CChar *me)
{
	who->say("去“无妄”位把巨石推开，那是这里的唯一出口。", me);
	who->AddMenuItem("过去推巨石", "$0leave $1",me);
	who->AddMenuItem("算了", "", me);
	who->SendMenu(me);
	return 0;
}


static char * ask_qiankun(CNpc * npc , CChar * player)
{
	CContainer * ob;
	CContainer * r = load_room("明教广场");
	static char msg[255];
	
	if(DIFFERSTR(player->querystr("family/family_name"), "明教"))
		return snprintf(msg,255,"%s与本派毫无瓜葛，何以问起本派的秘密？",player->name());

	if (r->query_temp("no_book"))
		return "你来晚了，羊皮我已经送人了。";

	r->add_temp("no_book",1);
	ob = load_item("qiankun_xinfa");
	ob->move(player);
	return "好吧，这张羊皮你拿回去好好参悟参悟吧。";
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "leave") == 0)
	{
		return do_leave(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_leave(CChar * me)
{
	if(me->query_skill("qiankun_danuoyi", 1) < 80)
	{
		message_vision ("$N使尽吃奶的力气推来推去，可惜$N的乾坤大挪移功力不足，眼前的巨石纹丝不动。", me);
		return 0;
	}
	else
	{
		message_vision ("$N运起乾坤大挪移心法脸上由红变青又由青变红，轻轻巧巧地就把巨石推开，走了出去。", me);

		CRoom * r = load_room("明教广场");
		me->move(r);	
		return 0;
	}
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		perform_action("force recover", 0);
		break;
	case 1:
		perform_action("force heal", 0);
		break;
	}

	return 0;
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
			perform_action("force roar", 1);
			break;
	case 1:
			perform_action("force recover", 0);
			break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if(me->querymap("family") && DIFFERSTR(me->querystr("family/family_name"), "明教"))
	{
		say("你已经加入其他门派，请回吧。", me);
		SendMenu(me);
		return;
	}

	if(DIFFERSTR(me->querystr("party/party_name"), "明教"))//别帮的不收
	{
		say("阁下与本教素无来往，请回吧。", me);
		SendMenu(me);
		return;
	}

	if(me->query_int() < 40)
	{
		say("你的悟性太低了，不适合学习我的功夫。", me);
		SendMenu(me);
		return;
	}

	if(me->query_skill("force", 1) < 150)
	{
		say("你的基本内功太低了，学习我的功夫会伤及自身。", me);
		SendMenu(me);
		return;
	}

	if(me->query("repute") <= 50000)
	{
		say("你应当多作些行侠仗义的事，以修身心。", me);
		SendMenu(me);
		return;
	}

	if(me->query("party/level") < 5)
	{
		say("你入教时间尚短，无甚建树，如果有紫衫龙王的同意，我会考虑收下你的。", me);
		SendMenu(me);
		return;
	}

	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
        
	me->set("party/level", 5);
	me->set("title", "教主亲传弟子");
	say("好，我就收下你这位好兄弟", me);
	say("再接再砺！", me);
	SendMenu(me);
	return;
}

NPC_END;




