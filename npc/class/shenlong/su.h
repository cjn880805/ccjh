//su.h
//code by zwb
//12-16
//inherit F_UNIQUE;
//inherit F_MASTER;

NPC_BEGIN(CNshenlong_su);

virtual void create()
{
	set_name("苏情","su quan");
	set("title",  "神龙教教主夫人" );
	set("long", "她就是神龙教教主洪安通的夫人。");
	set("gender", "女性");
	set("age", 23);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	set("icon",young_man2);	
	
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	set("combat_exp", 1000000);
	set("score", 400000);

    set_skill("force", 180);
    set_skill("dodge", 180);
    set_skill("unarmed", 180);
    set_skill("strike", 150);
    set_skill("parry", 180);
    set_skill("staff", 150);
    set_skill("sword", 150);
	set_skill("literate", 120);
	
	set_skill("shenlong_xinfa", 160);
	set_skill("yixingbu", 160);
	set_skill("shenlong_bashi", 160);
	set_skill("huagu_mianzhang", 160);
	set_skill("shedao_qigong", 160);

	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
    map_skill("sword", "shedao_qigong");
	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");

	create_family("神龙教",2,"弟子");

    set_inquiry("神龙教","一般人是入不了我神龙教的.");
	set_inquiry("退教",ask_tuijiao );
	set_inquiry("口号","万年不老!永享仙福!寿与天齐!文武仁圣!");

	carry_object("cloth")->wear();
	carry_object("duanjian")->wear();
	add_money(10000);

	set("chat_chance_combat", 10);
}

virtual char * chat_msg_combat()
{
	
	if(!query_temp("wei/renwu4_1"))
	{
		switch(random(5))
		{
		case 0:
			return "你活得不耐烦了找死啊？";
		case 1:
			perform_action("sword chang", 1);
			break;
		case 2:
			perform_action("sword chang2", 1);
			break;
		case 3:
			perform_action("sword chang3", 1);
			break;
		case 4:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		tell_room(environment(), "苏情慌慌张张的离开了战斗。");
		CFightRoom * obj=(CFightRoom *)environment();
		obj->End_Fight();
	}

	return 0;
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

	if (DIFFERSTR(player->querystr("gender"), "女性"))
	{
		say("教主不喜欢我收男弟子的。",player);
		SendMenu(player);
		return;
	}

	if (player->query_skill("shenlong_xinfa",1) < 60 ) 
	{
		say ("你的本门内功心法太低了，还是努努力先提高一下吧!",player);
		SendMenu(player);
		return;
	}

	if(player->query_skill("shedao_qigong",1) < 60 ) 
	{
		say(" 你的本门奇功太低了，还是努努力先提高一下吧!",player);
		SendMenu(player);
		return;
	}

	if (player->query("repute") > -10000  ) 
	{
		say(" 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！",player);
		SendMenu(player);
		return;
	}

	say(" 很好，很好。");
	SendMenu(player);
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
}

static char * ask_tuijiao(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("party/party_name"), "神龙教") )
	{
		return "苏情莞尔一笑，对你说道：你还没加入我神龙教呢，就想退教？";            
	}
	
	if( EQUALSTR(player->querystr("family/family_name"), "神龙教" ))
	{
		return "苏情板起俏脸对你说道：你已经是我神龙弟子，如何能退教？";            
	}
	
	npc->say(g_Channel.do_emote(npc,player, "sigh", 1), player);
	npc->say(g_Channel.do_emote(npc,player, "nod", 1), player);
	npc->say("异日你不要撞在我手上! ",player);
	npc->SendMenu(player);
	
	player->del("party");
	// player->del("rank");
	//  player->del("level");
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!query("ok"))
	{
		if(me->query_temp("wei/renwu4_8"))
		{
			say("苏情叹了口气：“江湖事，是是非非，如今我已心灰意冷！唉，还是随你回小宝身边去吧！”",me);
			SendMenu(me);
			return 1;
		}
		else if(me->query("wei/renwu1") && !me->query("wei/renwu4") && !me->query_temp("wei/renwu4_1") )
		{
			if(! strlen(ask))
			{
				AddMenuItem("向苏情咨询小桂子的问题","xiaobao",me);
			}
			else if(!strcmp(ask, "xiaobao") )
			{
				me->set_temp("wei/renwu4_1",1);//向苏情过咨询小桂子的问题
				set_temp("wei/renwu4_1",1);
				say("我虽与小宝恩爱有加，但是神龙教现在百业待兴，我怎能不顾而去！？",me);
			}
			SendMenu(me);
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

void init(CChar * me)
{
	CNpc::init(me);
	if(!query("ok"))
	{
		if(me->query_temp("wei/renwu4_7") && !me->query_temp("wei/renwu4_8") )
		{
			me->set_temp("wei/renwu4_8",1);//苏情答应回家
			tell_object(me,"\n苏情感慨万千：“我与洪安顺夫妻数载，未曾想他竟是个出尔反尔的小人！”");
			tell_object(me,"苏情叹了口气：“江湖事，是是非非，如今我已心灰意冷！唉，还是随你回小宝身边去吧！”\n");

			tell_object(me,"$HIC苏情开始跟随你行动。\n");
			
			CChar * wei = load_npc("shenlong_su");
			wei->move(environment());
			wei->set("owner",me->id(1));
			wei->set_leader(me);
			destruct(this);
		}
	}
}
NPC_END;