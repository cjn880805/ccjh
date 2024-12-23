//wang.c 王重阳
//Lanwood
//2001-01-15

ZUSHI_BEGIN(CNquanzhen_wang);

virtual void create()
{
	set_name("王重阳", "wang chongyang");
	set("gender", "男性");
	set("age", 66);
	set("class", "taoist");
	set("nickname", "活死人");
	set("long","他就是全真教的开山祖师、首代掌教王重阳王真人。他白须飘飘，宽袍缓袖，眉目清癯，颇有些仙风道骨的味道。");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);
	set("foolid",33);
	set("chat_chance_combat", 60);
	
	set("hp", 29500);
	set("max_hp", 29500);
	
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_factor", 300);
	
	set("combat_exp", 70000000);
	set("score", 500000);
	
	set_skill("force", 280);
	set_skill("sword", 300);
	set_skill("dodge", 290);
	set_skill("parry", 280);
	set_skill("unarmed",290);
	set_skill("strike",280);
	set_skill("finger",400);
	set_skill("literate",180);
	set_skill("taoism",220);

	set_skill("xiantian_qigong", 260);
	set_skill("xiantian_gong", 280);
	set_skill("quanzhen_jianfa",300);  //全真剑
	set_skill("quanzhen_jian",300);  //全真剑
	set_skill("jinyan_gong", 240);   //金雁功
	set_skill("haotian_zhang", 240);    //昊天掌
	set_skill("sun_finger",200);  //一阳指

	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jianfa");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jianfa");
	map_skill("strike", "haotian_zhang");
	map_skill("finger","sun_finger");

	prepare_skill("finger","sun_finger");
	prepare_skill("strike","haotian_zhang");
	
	create_family("全真教", 1, "掌教");
	
	set("book_count",1);
	set_inquiry("全真教", "我全真教是天下道家玄门正宗。");
	set_inquiry("九阴真经", ask_jiuyin);
	set_inquiry("一阳指", ask_zhipu);
	set_inquiry("段皇爷", ask_duan);
	
	carry_object("changjian")->wield();
	carry_object("greenrobe")->wear();

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("shen_type", 1);
	set("no_huan",1);
}

virtual char * chat_msg_combat()
{
	char msg[40];
	CContainer * changjian = present("changjian");

	switch(random(19))
	{
	case 0:
	case 1:
		perform_action("force recover", 0);
		break;
	case 2:
	case 3:
	case 4:
		perform_action("strike ju", 1);
		break;
	case 5:
	case 6:
	case 7:
		perform_action("sword ding", 1);
		break;
	case 8:
	case 9:
	case 10:
	case 11:
		if(query_weapon() == changjian && changjian)
			command(snprintf(msg, 40, "unwield %ld", changjian->object_id()));
		break;
	case 12:
	case 13:
	case 14:
	case 15:
		if(! query_weapon() && changjian)
			command(snprintf(msg, 40, "wield %ld", changjian->object_id()));
		break;
	case 16:
	case 17:
	case 18:
		perform_action("finger qiankun", 1);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[40];
	
	if (me->query_int() < 30) 
	{
		say("你的资质不够，还是先找我那几个徒弟学习吧。", me);
		SendMenu(me);
		return;
	}
	if ( me->query_skill("xiantian_qigong",1) < 150 ) 
	{
		say("你的本门内功心法火候不足,难以领略更高深的武功。", me);
		SendMenu(me);
		return;
	}
	
	if (me->query("repute")<80000) 
	{
		say("行侠仗义是我辈学武人的基本品质，你若能多做些狭义之事，我一定收你为徒。");
		SendMenu(me);
		return;
	}
	
	say("好吧，依你资质，定可传我衣钵，我就收下你这个徒弟了。");
	command(snprintf(msg, 40, "recruit %ld", me->object_id()));
}

static char * ask_jiuyin(CNpc * npc, CChar * who)
{
	if (DIFFERSTR(who->querystr("family/family_name"), "全真教"))
		return "你与本教毫无瓜葛，这话从何说起？";
	
	if(who->query_skill("force",1) < 50 )
		return "你的基本内功火候如此之浅，强练真经上的上乘武功有害无益。";
	
	return "九阴真经是天下武学正宗，我已交给我师弟周伯通保管，。";
}

static char * ask_duan(CNpc * npc, CChar * who)
{
	if(who->query_temp("tmark/指")==4) 
	{
		who->add_temp("tmark/指",1);
		return "段皇爷号称‘南帝’，家传的一阳指是天下最厉害的指法。";
	}
	
	who->set_temp("tmark/指",0l);
	return "你问段皇爷做甚么，莫非想与他为难？";
}

static char * ask_zhipu(CNpc * npc, CChar * who)
{
	if(who->query_temp("tmark/指")==5) 
	{
		who->set_temp("tmark/指",0l);
		if(npc->query("book_count") > 0) 
		{
			load_item("zhifapu")->move(who);
			npc->add("book_count",-1);
			return "好吧，你历经艰苦，意志甚坚，这本指法谱就交给你了。";
		}
		
		else
			return "你来晚了，指法谱已经被人取走了。";
	}
	
	
	who->set_temp("tmark/指",0l);
	return  "你不是想跟我较量较量吧？";      
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "重阳宫后山" ))
		return notify_fail("我这是在哪里？");
	char msg[255];
	if( EQUALSTR(ob->querystr("base_name"), "cyjian")&& who->query_temp("gumu/cyjian"))
	{
		destruct(ob);
		command("sigh");
		CContainer * bot = load_item("xiangsijianpu");
		bot->set("owner1",who->id(1));
		bot->move(who);
		say("你这是从那里得来的这个.....",who);
		say("当年我金戈铁马实是无力报答朝英的一片深情。。。。。",who);
		say("谢谢你了，小兄弟。",who);
		say("这是她当年寄到军中予我的青梅素笺，你拿去吧！",who);
		say("你既是朝英弟子，应能体会其中深意。",who);
		who->delete_temp("gumu/cyjian");
		who->set_temp("gumu/read",1);
		SendMenu(who);
		return 1;
	}
	else if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s点了点头，收下了你送过来的包裹。",name(1)));
		tell_object(who, "\n$YEL你完成了替福威镖局押运暗镖的任务。");
		tell_object(who, snprintf(msg, 255, "$YEL获得了%d的经验奖励，江湖声望上升了%d点",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)压运暗镖成功，获得了%d的经验奖励，江湖声望上升了%d点！", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}
	return 0;
}

ZUSHI_END;




