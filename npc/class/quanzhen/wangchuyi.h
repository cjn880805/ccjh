// quanzhen_wangchuyi.c 王处一

//code by Fisho
//date:2000-12-21

NPCQUANZHEN_BEGIN(CNquanzhen_wangchuyi);

virtual void create()
{
	set_name("王老五","wang laowu");
	set("gender", "男性");
	set("age", 35);
	set("class", "taoist");
	set("nickname","玉阳子");
	set("long","他就是全真七子之五王老五王真人。他身材修长，服饰整洁，三绺黑须飘在胸前，神态潇洒。");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 32);
	set("int", 30);
	set("foolid",55);	set("con", 32);
	set("dex", 30);
	set("icon",taoist);
	
	set("title","全真七子之五");
	set("chat_chance_combat", 60);
	set("chat_chance", 8);
	
	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 220);
	set_skill("xiantian_qigong", 220);    //先天气功
	set_skill("sword", 220);
	set_skill("quanzhen_jian",220);  //全真剑
	set_skill("dodge", 200);
	set_skill("jinyan_gong", 200);   //金雁功
	set_skill("parry", 220);
	set_skill("unarmed",220);
	set_skill("haotian_zhang", 220);    //昊天掌
	set_skill("literate",160);
	set_skill("strike",180);
	set_skill("taoism",150);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("全真教", 2, "弟子");
	
	set("book_count",1);
	
	set_inquiry("全真教","我全真教是天下道家玄门正宗。");
	set_inquiry("南帝",ask_me);
	set_inquiry("段皇爷",ask_me);
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	set("no_huan",1);
}

virtual char *chat_msg()
{
	switch (random(2))
	{
	case 0:
		return "王处一长叹一声，唉，可恨那杨寿把我的药全都藏起来了。";
	case 1:
		return "王处一道：谁能帮我找回药来，我一定重重酬谢他。";
	}
	return "";
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if ( ob->query_skill("xiantian_qigong",1) < 80 )
	{
		say("你的本门内功心法火候不足,难以领略更高深的武功。", ob);
		SendMenu(ob);
		return;
	}
	if ( ob->query("repute")<30000) 
	{
		say("行侠仗义是我辈学武人的基本品质，你若能多做些狭义之事，我一定收你为徒。", ob);
		SendMenu(ob);
		return;
	}

	say("好吧，我就收下你这个徒弟了。");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (   DIFFERSTR(ob->querystr("name"), "熊胆")
		&& DIFFERSTR(ob->querystr("name"), "田七")
		&& DIFFERSTR(ob->querystr("name"), "没药")
		&& DIFFERSTR(ob->querystr("name"), "血竭") )
		return 0;
	
	//	remove_call_out(destroying);
	//	call_out(destroying, 1, me, ob->object_id() );
	destruct(ob);
	say("难为你了，我可以教你点功夫。", who);
	SendMenu(who);
	
	who->add_temp("tmark/王", 10);
	//更新who的菜单
	DownLoad(who);
	return 1;
	
}

static char * ask_me(CNpc *who,CChar *me)
{	
	if(me->query_temp("tmark/指")==1) 
	{
		me->add_temp("tmark/指",1);
		return("去年师傅去过段皇爷那里，据说段皇爷把他最厉害的一阳指功夫传授给我师傅了。");
	}
	else 
	{
		me->set_temp("tmark/指",0l);
		return("段皇爷遇上了一件大伤心事，现在出家做了和尚了，唉！");
	}
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if ( EQUALSTR(me->querystr("family/family_name"), "全真教")) return 0;

	if (! me->querymap("family"))
	{
		say("你可还没拜过师啊，要学功夫还是先拜个师父再说吧。");
		return 1;
	}

	if ( me->query_temp("tmark/王") == 1 )
	{
		me->delete_temp("tmark/王");
		DownLoad(me);

		say("我能教你的东西到此为止，你也不要再找我学功夫了。", me);
		SendMenu(me);
		return 1;
	}

	me->add_temp("tmark/王", -1);
	
	return 0;
}

virtual int recognize_apprentice(CChar * me)
{
	if (! me->query_temp("tmark/王"))
		return 0;

	return 1;
}

NPCQUANZHEN_END;