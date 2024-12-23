//tangseng.h
//唐僧·任务ＮＰＣ·黄河入海口·唱歌的人·保护任务
//Teapot 2001-02-14
//写在VDay...grin

//修改：可以为人赎罪

NPC_BEGIN(CNpub_tangseng);

void create()
{
	set_name("唐僧", "tang seng");
	set("title", "［南无阿米托火］");
	set("gender", "男性");
	set("age", 27);
	set("per", 30);
	set("max_hp",7200);
	set("eff_hp",7200);
	set("hp",7200);
	set("combat_exp",0l);
//	set("env/wimpy",100);

	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_monk);

	set_inquiry("应聘", "佛祖他老人家在西天召开功德大会，缺少几个工作人员，我想去应聘，可是一路艰险……你愿意帮助我吗？");
	set_inquiry("帮助", agree_help);
	set_inquiry("修理武器", repair_weapon);	
	set("no_huan",1);
};

static char * repair_weapon(CNpc * me, CChar * who)
{
	char msg[80];

	CContainer * weapon = who->PresentName(snprintf(msg, 80, "s_weapon_%s", who->id(1)), IS_ITEM);

	if(! weapon) return "出家人不打诳语，没有断掉的武器，何谈修理呢？";

	if(weapon->querymap("apply"))
		return "呵呵，你福大命大造化大，身上的武器还没坏。";

	if(! CMoney::Player_Pay(who, 50000))
		return "先准备5万再来谈吧。贫僧也不容易……";
				
	weapon->set_name( weapon->querystr("staticname"));
	who->add("teapot/cumpower",-2);
	if(who->query("teapot/cumpower")<0)
		who->del("teapot/cumpower");
		
	weapon->set("cumpower", who->query("teapot/cumpower"));
	weapon->create();		//added by lanwood 2001-03-26	重新计算武器强度
	weapon->UpdateMe();
	weapon->Save();
	who->Save();	
	return "武器修好了，收了你50000手工费。";
}

static char * agree_help(CNpc * npc , CChar * player)
{
	CContainer * obj;
	CChar * player2;
	char msg[255];

	if(npc->query("teapot/bl") == 31)
	{
		if(EQUALSTR(npc->querystr("keeper1"), player->querystr("id")))
		{

			player->add("combat_exp", npc->query("keeper1_exp"));
		    message_vision(snprintf(msg, 255, "$N获得了%d经验！", npc->query("keeper1_exp")), player, npc);

			g_Channel.do_channel(&g_Channel, 0, "sys", 
				snprintf(msg, 255, "%s护送唐僧到东天，获得%ld经验！", player->name(1), npc->query("keeper1_exp")));

			npc->del("keeper1");
			npc->del("keeper1_exp");
		}

		if(EQUALSTR(npc->querystr("keeper2"), player->querystr("id")))
		{

			player->add("combat_exp", npc->query("keeper2_exp"));
		    message_vision(snprintf(msg, 255, "$N获得了%d经验！", npc->query("keeper2_exp")), player, npc);

			g_Channel.do_channel(&g_Channel, 0, "sys", 
				snprintf(msg, 255, "%s护送唐僧到东天，获得%ld经验！", player->name(1), npc->query("keeper2_exp")));

			npc->del("keeper2");
			npc->del("keeper2_exp");
		}

		if(! npc->querystr("keeper1")[0] && !npc->querystr("keeper2")[0])
			npc->call_out(selfdest, 3);

		return "恩……";
	}


	if(npc->querystr("keeper2")[0])
		return "啦啦啦……西天应聘啦……";

	if(npc->querystr("keeper1")[0] && DIFFERSTR(npc->querystr("keeper1"), player->querystr("id")))
	{
		npc->say("唐僧道：施主一心向佛，其心可嘉。", player);
	
		if( (player->query_combat_exp() > 100000 ) || player->query("teapot/xitian") )
		{
			npc->say("只是这个这个……怕不方便吧。", player);
			npc->SendMenu(player);
			return 0;
		}
	
		if(!random(100))
			player->set("teapot/xitian",1);

		npc->set("keeper2", player->querystr("id"));
		int exp = player->query_combat_exp()/100 + 1;
		npc->set("keeper2_exp", exp + random(exp));

//		player->set_temp("no_move",1);


		obj = npc->environment();
		player2=(CChar * ) obj->present(npc->querystr("keeper1"));

		if(npc->querystr("keeper1")[0] && !player2)
		{
			npc->del("keeper1");
			npc->del("keeper1_exp");
			npc->del("keeper2");
			npc->del("keeper2_exp");
//			player->delete_temp("no_move");
			npc->say("哎呀呀！不知道先来那位哪里去啦！先找他吧！", player);
			npc->SendMenu(player);
			return 0;
		}
		
		player2->delete_temp("teapot/xitian");

		message_vision("唐僧吸了口气，道：阿弥陀佛，阿弥陀佛。你们打点打点，准备跟我走吧。跟紧了，别丢了袄。",npc);


		npc->set("chat_chance", 70);
		npc->set_heart_beat(1);

	}
	else
	{
		npc->say("唐僧道：施主一心向佛，其心可嘉。", player);
	
		if( player->query_combat_exp() > 100000 || player->query("teapot/xitian") )
		{
			npc->say("只是这个这个……怕不方便吧。", player);
			npc->SendMenu(player);
			return 0;
		}

		if (player->query_temp("teapot/xitian"))
		{
			npc->say("别着急，别着急，再等等吧。", player);
			npc->SendMenu(player);
			return 0;
		}
	
		if(!random(100))
			player->set("teapot/xitian", 1);

		npc->set("keeper1", player->querystr("id"));
		int exp = player->query_combat_exp() / 100 + 1;
		npc->set("keeper1_exp", exp + random(exp));
		npc->say("唐僧道：只是如果只你一人，怕是不够吧……我们再等一人，如何？", player);

		player->set_temp("teapot/xitian",1);

//		player->set_temp("no_move",1);
		
		npc->say("别着急，等等，再等等吧。", player);
		npc->SendMenu(player);
	}
	
	return 0;
}

void bl_move()
{
	char msg[255];

	CContainer * obj;
	obj=environment();

	CChar * player1;
	CChar * player2;
	player1=(CChar * ) obj->present(querystr("keeper1"));
	player2=(CChar * ) obj->present(querystr("keeper2"));

	int i;
	i=query("teapot/bl");

	if (i==31)
	{
	    message_vision("唐僧看了看，道：啊～～～这里好漂亮啊。我决定就住在这里了……多谢两位！",this);
		set("chat_chance",0l);
		return ;	// 到达目的地！
	}

	if(!player1 || !player2)
	{
	    message_vision("唐僧左右看看，道：人呢？糟了糟了！！！心不诚，怎么去应聘？",this);
		remove_call_out(selfdest);
		call_out(selfdest,3);
		return ;
	}

    message_vision("唐僧道：阿米托火，山楂，山楂。",this);
    message_vision("唐僧看了看周围，迅快的往西方奔去。",this);
	
	static char bnline[31][20]={"黄河岸边7","黄河岸边6","黄河岸边5","黄河岸边4","黄河岸边3","黄河岸边2","黄河岸边1","黄河渭汾流域","黄河1","黄河河套","黄河黄土高原","黑木崖龙门渡口","黄河2","黄河3","黄河永登","黄河沙土路","黄河古浪","黄河打柴沟","黄河乌鞘岭","黄河武威","黄河土门子","黄河石峡子","黄河冰草湾","黄河营盘水","黄河古长城","黄河石门","黄河红山峡","黄河靖远","黄河沙漠1","黄河沙漠2","黄河石洞"};
			
	

	

	CRoom * troom;
	troom=load_room(bnline[i]);

	move(troom);
	player1->move(troom);
	player2->move(troom);

	if (random(3000))
	{
	    message_vision("唐僧道：西天应聘，工资无量。",this);
	}
	else
	{
	    message_vision("唐僧突然诗兴大发。",this);
	    message_vision("唐僧吟道：东临碣石，以观沧海。水何澹澹，山岛竦峙。树木丛生，百草丰茂。秋风萧瑟，",this);
	    message_vision("唐僧吟道：洪波涌起。日月之行，若出其中。星汉灿烂，若出其里。幸甚至哉，歌以咏志。",this);
		message_vision("你觉得若有所悟！", this);
		player1->set("teapot/canglang",1);
		player2->set("teapot/canglang",1);
	}

	set("teapot/bl",i+1);

	
	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "唐僧西天应聘，走到%s了。", bnline[i]));


	return ;
}


char * chat_msg()
{

	if (!random(2))
	{
		if(!random(2))
			bl_move();
		else
		{
			if(random(2))
			    message_vision("唐僧道：Only you~~~ you~~~ you~~~。",this);
			else
				call_robber();
		}
	}	
	else
	    message_vision("唐僧高兴的看看周围，道：这里的地图画的不错……",this);

	return "";
}

void call_robber()
{
	CChar * robber;
	CContainer * env = environment();

	CChar * player1;
	CChar * player2;
	player1=(CChar * ) env->present(querystr("keeper1"));
	player2=(CChar * ) env->present(querystr("keeper2"));

	
	CFightRoom * obj;

	tell_room(env, "突然串出了几条黑影！");

	//while( (obj = (CFightRoom *)env->present("fight_room")) )
	//	obj->End_Fight();		

	obj = (CFightRoom *)env->present("fight_room_tangseng");
	if(! obj)
	{
		obj = (CFightRoom *)load_item("fight_room");		
		
		obj->set("room_locked", FIGHT_LOCKED);
		obj->set_name( "唐僧应聘又一难", "fight_room_tangseng");		
		obj->move(env);

		move(obj);
		obj->Join_Team(this, CFightRoom::FIGHT_TEAM_B);

		if(player1) 
		{
			player1->move(obj);
			obj->Join_Team(player1, CFightRoom::FIGHT_TEAM_B);
		}

		if(player2) 
		{
			player2->move(obj);
			obj->Join_Team(player2, CFightRoom::FIGHT_TEAM_B);
		}
	}
	

	for(int i=0;i<random(4)+1;i++)
	{
		robber = load_npc("pub_robber");
		robber->move(obj);
		obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);	
	}

	obj->Begin_Fight(0);	
}



void init(CChar * me)
{
	CNpc::init(me);
	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}


static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

	if(random(2)==0)
	    message_vision("$n问道：$N这位施主，你可有兴趣干点零活？", who, me);
	else
	    message_vision("唐僧看着自己的马褂道：没有情人的情人节……", me);

	return;
}


static void selfdest(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * me = ob->environment();

	if(userp(me))
		tell_object((CChar *)me, "唐僧化作一道清烟消失了。");
	else
		tell_room(me, "唐僧化作一道清烟消失了。");

	destruct(ob);
	return;
}


void die()
{
	selfdest(this, 0, 0);
}

int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	LONG value1;

	if(EQUALSTR(who->querystr("family/family_name"), "丐帮") && who->query("kill/guilt")<250 )
		value1 = ob->query("value") / 2000;
	else 
		value1 = ob->query("value") / 10000;

	if(value1 < 1) return 0;

	int guilt = who->query("kill/guilt");
	
	guilt -= value1;
	if(guilt < 0) guilt = 0;

	int desc = who->query("kill/guilt") - guilt;
	
	tell_object(who, snprintf(msg, 255, "$HIY你罪行减轻了%ld点。\n唐僧向你表示感谢。", desc));
	who->set("kill/guilt", guilt);	

	destruct(ob);
	return 1;
}

NPC_END;




