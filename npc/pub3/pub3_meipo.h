//meipo.h
//code by zwb
//12-25

NPC_BEGIN(CNpub3_meipo);


virtual void create()
{
	
	set_name("空白妖女","kongbai yaonv");

	set("icon", young_woman1);
	set("title", "情人庄");
	set("gender", "男性" );
	set("age", 43);
	set("per", 3);
	set("long","一个没有［面目］的人");
	
	set("max_hp", 2400);
	set("combat_exp", 10000);
	set("attitude", "friendly");

	set_inquiry("昭示天下","刚结婚？花个２０万就能让整个江湖知道……" );
	
	set_skill("literate", 70);
	set_skill("dodge", 200);
	set_skill("unarmed", 100);
	set("no_huan",1);
//	carry_object("cloth")->wear();
}

virtual int accept_object(CChar * who, CContainer * ob)
{

	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")>=200000 && who->query_temp("teapot/m_m"))
	{
		destruct(ob);
		message_vision("空白妖女咧嘴一笑，撮指在唇边吹出一阵哨音，只听一大阵响亮的鸽哨声破空而去。",who);

		who->delete_temp("teapot/m_m");

		g_player(who, who->querystr("couple/id"));
		g_lost();

		return 1;
	}

return 0;
}

int g_player(CChar * me, string id)
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
	
		char msg[255];
		
//			g_Channel.do_channel(&g_Channel, 0, "wiz", 
//				snprintf(msg, 255, "%s Founded！", obj->name(1) ));


//		if (obj->querystr("id")==id || obj->querystr("id")==me->querystr("id"))
//			continue;

		CContainer * gift;

		snprintf(msg, 255, "天上飘扬着落下一个袋子，不偏不倚落在你的怀中……\n你打开一看，看到了一张喜帖，一瓶酒和一块蛋糕。");
		
		//一只鸽子落了下来，告诉你：%s和%s结婚了……",me->name(1),me->querystr("teapot/marryname").c_str());
		
        tell_object(obj,msg);

		gift=load_item("cake");
		gift->move(obj);

		if (EQUALSTR(obj->querystr("gender"), "男性"))	//竹叶青
		{
			gift=load_item("jiuping2");
			gift->move(obj);
		}
		
		if (EQUALSTR(obj->querystr("gender"), "女性"))	//女儿红
		{
			gift=load_item("nverhong");
			gift->move(obj);
		}
		
		if (EQUALSTR(obj->querystr("gender"), "无性"))	//壮阳酒
		{
			gift=load_item("jiuping");
			gift->move(obj);
		}
		
		snprintf(msg, 255, "%s和%s的结婚喜帖",me->name(1),me->querystr("couple/name"));

		gift=load_item("anmenkey");
		gift->set_name(msg, "xi tie");
		gift->set("value",0l);
		gift->set("long",msg);
		gift->set("unit","张");
		gift->move(obj);
    }
    
	return 1;
}

int g_lost()
{
	return 1;
}

NPC_END;