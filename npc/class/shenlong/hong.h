//hong.h
//code by zwb
//12-16
//inherit F_UNIQUE;
//inherit F_MASTER;

ZUSHI_BEGIN(CNshenlong_hong);

virtual void create()
{
	set_name("洪安顺","hong anshun");
	set("title",  "神龙教教主" );
	set("nickname", "永享仙福" );
	set("long", "他就是武功盖世、令江湖人等谈之色变的神龙教教主洪安顺。");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	set("icon",young_man4);	
	
	set("max_hp", 16000);
	set("hp", 10000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_farce",100);
	set("combat_exp", 1600000);
	set("score", 400000);

    set_skill("force", 240);
    set_skill("dodge", 220);
    set_skill("unarmed", 240);
    set_skill("strike",400);
    set_skill("parry", 220);
    set_skill("staff", 200);
    set_skill("sword", 200);
	set_skill("literate", 150);
	
	set_skill("shenlong_xinfa", 220);
	set_skill("yixingbu", 220);
	set_skill("shenlong_bashi", 240);
	set_skill("huagu_mianzhang", 240);
	set_skill("shedao_qigong", 240);
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
    map_skill("sword", "shedao_qigong");
	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");

	create_family("神龙教",1,"教主");

	carry_object("cloth")->wear();
	add_money(5000);
	set("no_talk",1);
	set("no_huan",1);

}

virtual char * chat_msg_combat(CChar * player)
{
	static char msg[255];
	
	switch(random(6))
	{
	case 0:
		g_Channel.do_emote(this,player, "smile", 0);
		break;
	case 1:
		g_Channel.do_emote(this,player, "haha", 0);
		break;
	case 2:
		return snprintf(msg,255,"凭你这%s也敢在太岁爷头上动土?",query_respect(player));
	case 3:
		return "你活得不耐烦了找死啊？";
	case 4:
		perform_action("strick hua", 1);
		break;
	case 5:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		say("你有什么意思，有意思可以提嘛，你不提我怎么知道你想怎么样啊？", me);
		AddMenuItem("提意见", "$2flatter $1 $2", me);
		AddMenuItem("算了","", me);
		if(me->query_temp("wei/renwu4_1"))
			AddMenuItem("关于苏情离开的事情","likai", me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "likai") && !me->query("wei/renwu4") )
	{
		if(me->query_temp("wei/renwu4_6"))
		{
			tell_object(me,"我洪安顺纵横江湖，你一个黄口小儿竟然敢与我谈条件！！！");
			set("owner",me->id(1));

			CFightRoom * obj;
			CContainer * env = me->environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set_name( "洪安顺的战斗", "fight_room");	
			obj->set("room_locked", FIGHT_LOCKED);
			obj->move(env);
			
			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);

			move(obj);
			obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);
			//检查苏情是否在场，如没有这个NPC则变一个
			env = load_room("神龙教空地");
			CContainer * wei=env->present("su quan");
			if(!wei)
			{
				CChar * robber;
				robber = load_npc("shenlong_su");
				robber->set("owner",me->id(1));
				robber->move(obj);
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_B);
			}
			else
			{
				wei->set("owner",me->id(1));
				wei->move(obj);
				obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_B);
			}
			obj->Begin_Fight(0);
			return 1;
		}
		else if(me->query_temp("wei/renwu4_2") && me->query_temp("wei/renwu4_3"))
		{
			say("洪教主神色大悦：“我其实早已经无意争雄，但因被神龙教的二使用十香软筋散废除了内力，现在必须要神龙教一种蕲蛇的胆方可化解，否则半年后皮消肉散而死。不知道这位英雄是否能帮老夫这个忙？”",me);
			SendMenu(me);
			me->set_temp("wei/renwu4_4",1);
			return 1;
		}
		else if(me->query_temp("wei/renwu4_1"))
		{
			tell_object(me, "$HIR\n洪安顺大怒道：“尔竟然敢与我提出无理要求，拿下。”");
			tell_object(me, "$HIR罗得贵与天雨道长向你扑来。\n");
			
			CFightRoom * obj;
			CContainer * env = me->environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set_name( "神龙教大厅的战斗", "fight_room");		
			obj->move(env);
			
			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
			
			//检查罗得贵是否场，如没有这个NPC则变一个
			CContainer * wei=env->present("luo degui");
			CChar * robber;
			if(!wei)
			{
				robber = load_npc("shenlong_yin");
				robber->set("owner",me->id(1));
				robber->move(obj);
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);
			}
			else
			{
				wei->set("owner",me->id(1));
				wei->move(obj);
				obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_A);
			}
			
			//检查天雨道长是否场，如没有这个NPC则变一个
			wei=env->present("tianyu daozhang");
			if(!wei)
			{
				robber = load_npc("shenlong_wugeng");
				robber->set("owner",me->id(1));
				robber->move(obj);
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);
			}
			else
			{
				wei->set("owner",me->id(1));
				wei->move(obj);
				obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_A);
			}
			
			obj->Begin_Fight(0);
		}
		return 1;
	}
	return CNpc::do_talk(me, ask);
}  

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp(comm,"flatter") == 0)
		return do_flatter(me,arg);

	return 0;
}

int do_flatter(CChar *me,char * arg)
{
	char msg[255];
	if( !strlen(arg)) 
		return notify_fail("你说我什么？ ");

	message_vision(snprintf(msg,255,"$N大声说道：%s", arg), me);

	if( strstr(arg, "万年不老")
		&&( strstr(arg, "永享仙福") 
		|| strstr(arg, "寿与天齐") 
		|| strstr(arg, "文武仁圣") ))
	{
		command("smile");
		me->add_temp("tmark/洪", 10);
		AddMenuItem("想学些什么，尽管说吧","", me);
		SendMenu(me);
		DownLoad(me);
	} 
	else
	{
		say(" 你如此不把我放在眼里，我又怎能容你？!");
		kill_ob(me); 
	}
	return 1;
}

virtual int prevent_learn(CChar * me, const char * arg)
{

	if (! me->querymap("family"))
	{
		say("你可还没拜过师啊，要学功夫还是先拜个师父再说吧。");
		return 1;
	}

	if ( me->query_temp("tmark/洪") == 1 )
	{
		me->delete_temp("tmark/洪");
		DownLoad(me);

		say("我能教你的东西到此为止，你也不要再找我学功夫了。", me);
		SendMenu(me);
		return 1;
	}
	if(EQUALSTR(arg, "strike"))
	{
		if(me->query_skill("strike",1)>200 && DIFFERSTR(me->querystr("family/family_name"), "神龙教"))
		{
			say("这门武功我能教你的只能到此为止，你换别的功夫再学吧！。", me);
			return 1;
		}
	}
	me->add_temp("tmark/洪", -1);
	
	return 0;
}

virtual int recognize_apprentice(CChar * me)
{
	if (! me->query_temp("tmark/洪"))
		return 0;
	return 1;
}

virtual void die()
{
	message_vision("$N奇道：“咦,居然有人能杀了我,....”说完睁着两眼倒地死了。", this);
	if(querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr("owner"));
		CContainer * suqing =env->present("su quan");
		if(me && suqing)
			me->set_temp("wei/renwu4_7",1);//杀死洪安顺
	}
	CNpc::die();
}


virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (DIFFERSTR(player->querystr("party/party_name"), "神龙教") ) 
	{
		say("你不是本教教众, 想来找死啊!",player);
		SendMenu(player);
		return;
	}

	if (player->query_skill("shenlong_xinfa",1) < 100 ) 
	{
		say("你的本门内功心法太低了，还是努努力先提高一下吧!",player);
		SendMenu(player);
		return;
	}

	if(player->query_skill("shedao_qigong",1) < 100 ) 
	{
		say("你的本门杖法太低了，还是努努力先提高一下吧!",player);
		SendMenu(player);
		return;
	}

	if (player->query("repute") > -50000  ) 
	{
		say("我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！",player);
		SendMenu(player);
		return;
	}

	say("很好，很好。");
	command(snprintf(msg,255,"recruit %ld", player->object_id()) );
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(!me->querymap("wei")) return 0;

	if(EQUALSTR(ob->querystr("name"), "蕲蛇胆") && EQUALSTR(ob->querystr("id"), "qishe dan") 
		&& me->query_temp("wei/renwu4_5"))
	{
		tell_object(me,"\n$YEL洪安顺吃下数量1的蕲蛇胆，刹时间，一股黑气从头顶涌出，只听得洪安顺的骨骼一阵爆响，内力已经完全恢复!");
		me->set_temp("wei/renwu4_6",1);//治疗好洪安顺
		destruct(ob);
	}

	return 1;
}
ZUSHI_END;