// wudang_xuxuetin.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_xuxuetin);

virtual void create()
{
	set_name("许风阁",  "xu xueting" );
	set("title", "神龙教青龙使");
	set("nickname",  "热血神龙" );
	set("gender", "男性" );
	set("age", 55);
        set("icon",old_man2);

	set("long","这是个五十来岁的高瘦汉子，着一袭青衣，昂然挺立。 ");
	
	set("int", 30);
	set("str", 25);
	set("con", 23);
	set("dex", 22);
	
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	set("hp",3000);
	set("max_hp", 9000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 150);
	set("combat_exp", 500000);
	set("score", 250000);
	
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 90);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taoism", 150);
	set_skill("literate", 60);
	set_skill("tiyunzong", 80);
	set_skill("taiji_quan", 80);
	set_skill("taiji_shengong", 80);
	set_skill("taiji_jian", 90);
	set_skill("shedao_qigong", 100);
	set_skill("shenlong_xinfa", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	
	set_inquiry("百花腹蛇膏", "这可是本教禁物啊。它一遇鲜血，便生浓香， 我们住在这灵蛇岛上，人人都服惯了雄黄酒，以避毒蛇，这股香气 一碰到雄黄酒，便使人筋骨酥软，不能动弹。对了，你怎么也知道？ ");
	set_inquiry("教主", "教主脾气不好,要讨他欢心才好。 ");
	set_inquiry("入教", ask_join);
	set_inquiry("口号","万年不老!永享仙福!寿与天齐!文武仁圣! ");
	
	set("chat_chance", 3);
	
	carry_object("duanjian")->wield();
	set("no_huan",1);
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "许雪亭忽然一怕脑袋，说：对了，可以用百花腹蛇膏！ ";
	case 1:
		return "许雪亭怒道：唉，偌大一个神龙教，都毁在一个娘么手里了！ ";
	case 2:
		return "许雪亭叹口气，说道：唉，不杀了洪安通，谁也活不了。 ";
	}
	return "";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * obn;

	if ( DIFFERSTR(ob->querystr("name"), "腹蛇胆")
		&& DIFFERSTR(ob->querystr("name"), "百香花" ) )
		return notify_fail("许雪亭摇头道：如果杀不了洪安通，给我什么也没用啊。。。 ");

	if ( EQUALSTR(ob->querystr("name"), "腹蛇胆" ))
	{
		if(query_temp("baixianghua"))
		{
			say("许雪亭见是腹蛇胆，大喜道：腹蛇胆百香花都有了,百花腹蛇膏练成了! ",who);
			SendMenu(who);
			obn=load_item("baihua");//百花腹蛇膏
			obn->move(who);
			delete_temp("fushedan");
			delete_temp("baixianghua");
			return 1;		 
		} 		
		else	
		{	
			if(query_temp("fushedan"))
			{
				say("许雪亭见是腹蛇胆，对你摇头道：腹蛇胆我有了，就差百香花了。 ",who);
				SendMenu(who);
				return 0;
			}
			else	  
			{
				say("许雪亭看见百香花，大喜道：有了百香花，只差腹蛇胆了。 ", who);
				SendMenu(who);
				set_temp("fushedan",1);	
				return 1;
			}
		}
	}

	if ( EQUALSTR(ob->querystr("name"), "百香花" ))
	{
		if(query_temp("fushedan"))
		{
			say("许雪亭见是百香花，大喜道：腹蛇胆百香花都有了,百花腹蛇膏练成了! ",who);
			SendMenu(who);
			obn=load_item("baihua");//百花腹蛇膏
			obn->move(who);
			delete_temp("fushedan");
			delete_temp("baixianghua");
			return 1;		 
		} 		
		else	
		{	
			if(query_temp("baixianghua"))
			{
				say(" 许雪亭见是百香花，对$N摇头道：百香花我有了，就差腹蛇胆了。 ",who);
				SendMenu(who);
				return 0;
			}
			else	  
			{
				say("许雪亭看见百香花，大喜道：有了百香花，只差腹蛇胆了。 ", who);
				SendMenu(who);
				set_temp("baixianghua",1);	
				return 1;
			}
		}	
	}

	return 0;
}

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp (comm,"join") == 0)
		return do_join(me,arg);

	return 0;
}

static char * ask_join(CNpc * me, CChar * who)
{
	me->say("一般人是入不了我神龙教的。你想入教么？", who);
	me->AddMenuItem("我决定入教。", "$0join $1", who);
	me->AddMenuItem("再容我考虑考虑……", "", who);
	me->SendMenu(who);
	return "";
}

int do_join(CChar *ob,char * arg)
{
	if(ob->query("shenlongjiao")) 
	{
		say("你已经是神龙教弟子了。 " , ob);
		SendMenu(ob);
		return 1;
	}

	if (ob->query("repute")>-1000)
	{
		message_vision( "许雪亭对$N大怒道：还想入教?一看你就不是好人! ", ob);
		kill_ob(ob); 
		return 1;
	}

	if (ob->query_combat_exp() < 20000)
	{
		say( "许雪亭对你摇头道：你的实战经验太低。 " , ob);
		SendMenu(ob);
		return 1;
	}

	if ( ob->query_skill("bibo_shengong",1)
		|| ob->query_skill("hamagong",1)
		|| ob->query_skill("huagong_dafa",1))
	{
		ob->set("shenlongjiao",1);
		say("你现在就是神龙教弟子了. ", ob);
		SendMenu(ob);
		return 1;	
	}
	else 
	{
		message_vision( "许雪亭对$N大怒道：还想入教?一看你就不是好人! " ,ob);
 		kill_ob(ob); 
		return 1;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if (ob->query_skill("shenlong_xinfa",1) < 40 ) 
	{
		say("你的本门内功心法太低了,还是努努力先提高一下吧!", ob);
	}else if (ob->query_skill("shedao_qigong",1) < 40 )
	{
		say("你的本门杖法太低了,还是努努力先提高一下吧!", ob);
	}
	else if (ob->query("repute") > -5000  ) 
	{
		say("我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！", ob);
	}
	else
	{
		say("很好，很好。");
		command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
		return;
	}

	SendMenu(ob);
}

NPC_END;