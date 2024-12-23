// wei_ake.h 阿可
// 秦波	2002、12、25

NPC_BEGIN(CNwei_ake);

virtual void create()
{
	set_name("阿可","a ke");
	set("icon", young_woman3);
	set("long",  "她长的极美，其容色晶莹如玉，娇媚不可方物。");
	set("age", 17);
	set("per",40);
	
	set("gender","女性");
	set("help",1);
	
	set("str", 25);
	set("dex", 16);
	set("combat_exp", 80000);
	
	set("hp",30000);
	set("eff_hp",30000);
	set("max_hp",30000);
	
	set("max_mp",300);
	set("mp",300);
	
	set("chat_chance", 30);
	carry_object("qinqin_sword")->wield();
	call_out(do_die, 900);
	set("no_kill",1);
	set("no_huan",1);
}

void init(CChar * me)
{
	CNpc::init(me);
	if(!query("ok") && me->query_temp("wei/renwu3_7") && !me->query_temp("wei/renwu3_8")
		&& EQUALSTR(environment()->querystr("base_name"),"万劫谷澜沧江畔" ))
	{
		tell_object(me,"\n$YEL阿可站在茅屋前犹豫了一会儿，终于鼓起勇气，推开房门走了进去。");
		call_out(do_fumu, 120);
		move(load_room("temp_ake"));
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!query("ok"))
	{
		//if(querystr("owner")[0] && EQUALSTR(querystr("owner"), me->id(1)))
		//{
			if(me->query_temp("wei/renwu3_9"))
			{
				say("阿可说道：“这一路多亏英雄相助，使小女子与爹娘见了最后一面。既然小桂子叫你来找我，我这就随你回去吧！”",me);
				SendMenu(me);
				return 1;
			}
			else if(me->query_temp("wei/renwu3_8"))
			{
				if(! strlen(ask))
				{
					AddMenuItem("询问关于小宝","xiaobao",me);
					SendMenu(me);
				}
				else if(!strcmp(ask, "xiaobao") )
				{
					me->set_temp("wei/renwu3_9",1);//阿可答应回家
					tell_object(me,"$HIC阿可叹了口气。");
					tell_object(me,"\n阿可说道：“这一路多亏英雄相助，使小女子与爹娘见了最后一面。既然小桂子叫你来找我，我这就随你回去吧！”");
					tell_object(me,"$HIC阿可决定跟随你行动。\n");
					
					CChar * wei = load_npc("wei_ake");
					wei->move(environment());
					wei->set("owner",me->id(1));
					wei->set_leader(me);
					destruct(this);
				}
				return 1;
			}
		//}
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(!query("ok") && !query("cry"))
	{
		if(EQUALSTR(ob->querystr("name"), "带血的素笺") && EQUALSTR(ob->querystr("id"), "xue shu jian") 
			&& me->query_temp("wei/renwu3_4"))
		{
			tell_object(me,"\n$HIC阿可哭了起来。");
			tell_object(me,"\n$HIC阿可说道：“原来爹娘隐居在万劫谷澜沧江畔！但这可恶的吴三桂阴魂不散，到现在还不放过他们。”");
			tell_object(me,"$HIC阿可“刷”的一声拨出一把碧血剑。\n");
			
			me->set_temp("wei/renwu3_5",1);//开始保护阿可
			destruct(ob);
			
			CChar * wei = load_npc("wei_ake");
			wei->set("owner",me->id(1));
			wei->set("cry",1);
			wei->move(load_room("大理城武定镇"));
			tell_object(me,"阿可向大理城武定镇离开。");
			move(load_room("temp_ake"));
			//destruct(this);
			return 1;
		}
	}
	return 0;
}

virtual char * chat_msg()
{
	if(query("cry"))
	{
		switch(random(2))
		{
		case 0:
			bl_move();
			break;
		case 1:
			CFightRoom * obj;
			CContainer * env = environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set_name("阿可的战斗", "fight_room");		
			obj->move(env);
			
			move(obj);
			obj->Join_Team(this, CFightRoom::FIGHT_TEAM_B);
			
			for(int i=0;i<random(2)+1;i++)
			{
				CChar * robber = load_npc("wei_canbing");
				robber->move(obj);
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);
			}
			obj->Begin_Fight(0);
			break;
		}
	}
	return 0;
}

void bl_move()
{
	int i;
	i=query("teapot/bl");
	if (i==20)
	{
		set("chat_chance",0l);
		return ;	// 到达目的地！
	}
	else
	{
		static char bnline[20][20]={"大理城竹林小路","大理城喜州城","大理城天威径","大理城大路4","大理城双鹤桥","大理城南门","大理城西","大理城北门","大理城太和城","大理城南诏德化碑","大理城官道3","大理城官道2","大理城官道1","峨嵋青石阶","万劫谷江边小路1","万劫谷江边小路2","万劫谷江边小路3","万劫谷善人渡","万劫谷铁索桥","万劫谷澜沧江畔"};
		CRoom * troom=load_room(bnline[i]);
		char msg[255];
		tell_room(environment(), snprintf(msg, 255, "阿可向%s离开。",bnline[i]));
		move(troom);
		set("teapot/bl",i+1);
		return ;
	}
}

static void do_fumu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->querystr("owner")[0])
	{
		npc->move(load_room("万劫谷澜沧江畔"));
		CContainer * me;
		CContainer * env=npc->environment();
		me=env->present(npc->querystr("owner"));
		if(me)
		{
			tell_object(me,"\n$YEL阿可红着双眼走了出来。");
			me->set_temp("wei/renwu3_8",1);//阿可和父母相见后
		}
		else
		{
			destruct(npc);
		}
	}
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("ok"))
		destruct(npc);
	else
		npc->call_out(do_die, 900);
}

NPC_END;