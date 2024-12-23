//yintianzheng.h
//Lanwood 2000-01-09

NPC_BEGIN(CNmingjiao_yintianzheng);

virtual void create()
{
	set_name("殷天罡", "yin tiangang");
	set("long",  "他是一位身材魁梧的秃老者，身穿一件白色长袍。他长眉胜雪，垂下眼角，鼻子钩曲，犹如鹰嘴。");
	                                                         
	set("title", "白眉鹰王");
	set("mjlevel",9);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("icon",old_man2);
	set_weight(50000000);

	CMapping par;

	par.set("level", 5);
	set("party", par);

	set("age", 72);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("hp", 3500);
	set("max_hp", 10500);
	
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 150);
	set("combat_exp", 1200000);
	set("score", 50000);

	set_skill("force", 250);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("claw", 300);

	set_skill("sougu", 250);
	set_skill("shenghuo_shengong", 200);
	set_skill("shenghuo_xinfa", 200);
	set_skill("piaoyibu", 150);
	set_skill("literate", 120);

	map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "piaoyibu");
	map_skill("claw", "sougu");
	map_skill("parry", "sougu");
	prepare_skill("claw","sougu");
	set("chat_chance", 5);
	set("chat_chance_combat", 10);
	
    create_family("明教",35, "护法");
	
//    set_inquiry("护教", ask_me);
	carry_object("baipao")->wear();
	set_inquiry("护教任务",ask_hujiao);
	set("no_huan",1);
};

static char * ask_hujiao(CNpc *who,CChar *me)
{
	char msg[255];
	CContainer * r = load_room("明教大殿");
	if(me->query_temp("mj/鹰王"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "明教") && r->query_temp("yingwang_count"))
		{
			tell_object(me, "殷天罡说道:这次大战，多亏了小兄弟你了。过来过来，到我这里来。。");
			tell_object(me, "你按照鹰王的提示坐在地上，殷天罡也盘膝坐在你的背后，缓缓将手掌贴在你的背上...");
			tell_object(me, "顿然间你只觉一股浩荡无比的真气直冲顶门...");
			me->start_busy(50);
			me->add("max_mp",random(10)+10);
			r->add_temp("yingwang_count",-1);
			tell_object(me, "$HIR你在鹰王的协助下，突破了自身的内力上限。");
			me->UpdateMe();
		}
		else
		{
			tell_object(me, "殷天罡说道:这次大战，多亏了小兄弟你救了不少教中的兄弟们，可惜我现在内力没有恢复完全...");
			int exp=(random(25)+40)*me->query("level");
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIY殷天罡传授了你%ld点的实战经验！", exp));
		}
		me->delete_temp("mj/鹰王");
	}
	else
		tell_object(me, "殷天罡：什么？？");
	return "";
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
		perform_action("claw muye", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) &&  !is_fighting())
	{
		if(me->query_temp("marks/护教2")) 
		{ 
			call_out(do_back, 1);
		}
        
		if ((DIFFERSTR(me->querystr("party/party_name"), "明教"))) 
		{
		    remove_call_out(do_killing);
            call_out(do_killing, 4, me->object_id());
		}
	}
}

static void do_killing(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(!who ) return;

	g_Channel.do_emote(me, who, "consider", 0);
    me->kill_ob(who);
	return;
}

static char * ask_me(CNpc * me, CChar * who)
{
	if ( who->query_temp("marks/护教1") ) 
	    return "如果不想护教就退出吧。";
	
	if ( who->query_combat_exp() > 50000)  
		return "你武功高强，护教这些事就留给后辈人来做吧。";
	
    if ( who->query_temp("marks/护教3") ) 
		return "现在没有任务分派给你，休息休息再来吧。";
	
	who->set_temp("marks/护教1", 1);
	who->call_out(do_hujiao, 150);
	return "现在正好缺少人手，你就到山脚下去护教吧。以防六大派偷袭光明顶。";
}

static void do_hujiao(CContainer * ob, LONG param1, LONG param2)
{ 
	tell_object((CChar *)ob, "你的护教时间到了，该回去复命了。");
	ob->set_temp("marks/护教2", 1);
}

static void do_back(CContainer * ob, LONG param1, LONG param2)
{  
	char msg[255];
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

	if ( who->query_temp("marks/护教ok") ) 
	{
		me->say(snprintf(msg, 255, "%s干得好，老夫没有什么奖励你的，就教你一些实战经验吧。", who->name()));
 		who->add("combat_exp", 140 + random(80));
		who->delete_temp("marks/护教2");
		who->delete_temp("marks/护教ok");
		who->delete_temp("marks/护教1");
		who->set_temp("marks/护教3", 1);
		who->call_out(do_waiting, 50);
		return;
	}
	else     	
	{
		me->say("你根本就没有参加护教，回来复什么命啊？");
		who->delete_temp("marks/护教2");
		who->delete_temp("marks/护教1");
		who->call_out(do_waiting, 50);
		return;
	}
}

static void do_waiting(CContainer * ob, LONG param1, LONG param2)
{
	ob->delete_temp("marks/护教3");
	ob->delete_temp("marks/护教1");
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if(me->querymap("family") && DIFFERSTR(me->querystr("family/family_name"),"明教"))
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
	if(me->query_skill("force", 1) < 100)
	{
		say("你的基本内功太低了，学习武功要先打好基础。", me);
		SendMenu(me);
		return;
	}

	if(me->query("repute") <= 10000)
	{
		say("应当多作些行侠仗义的事，以修身心。", me);
		SendMenu(me);
		return;
	}
	if(me->query("party/level") > 4)
	{
		say("以你在教中的地位，在下哪里敢当!", me);
		SendMenu(me);
		return;
	}
	if(me->query("party/level") <= 3)
	{
		say("你尚未通过堂主比试，没有堂主的推荐信，本座不能越级收徒。", me);
		SendMenu(me);
		return;
	}
	else if(me->query("family/generation") == query("family/generation") + 1)//师傅与该NPC同级
		say(snprintf(msg, 80, "%s的徒弟怎麽跑到我这儿来了，哈哈哈 !", me->querystr("family/master_name")));
	else
	{
		say("好，我就收下你这位好兄弟", me);
		SendMenu(me);
	}
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("title", snprintf(msg, 80, "%s亲传弟子", querystr("title")));
	me->UpdateMe();
	return;
}

virtual int accept_object(CChar * me, CContainer * obj)
{
	if (EQUALSTR(obj->querystr("id"), "tuijian xin4" )
		&& me->query_temp("have_letter") )
	{
		me->set_temp("apprentice_ok",1);
		destruct(obj);
	    say("好，你愿意加入本法王座下吗？");
		AddMenuItem("愿意加入", "$0join $1", me);
		AddMenuItem("暂时不想", "", me);
		SendMenu(me);
		return 1;
	}

    say(g_Channel.do_emote(this, 0, "?", 1), me);
    say("这东西给我可没有什麽用。", me);
	SendMenu(me);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "join") == 0 && me->query_temp("apprentice_ok"))
		return do_join(me);

	CContainer * env = load_room("pk");
	if((strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0 )&& env->query("mj/start") && userp(me))
	{
		message_vision("$n横眉怒视$N，恨道：“在这大敌当前之际，你到底想做什么！！”", me, this);
		me->delete_temp("mf/exp");
		me->add("hp",-me->query("hp")/2);
		me->UpdateMe();
		me->start_busy(3);
		return 1;
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_join(CChar * me)
{
	char msg[255];

	if ( me->query("party/level") >= query("party/level") )
	{
        say("在下哪里敢当 !", me);
		SendMenu(me);
		return 1;
	}

	if ( me->query("party/level") == 3 )
	{
		me->delete_temp("have_letter");
		me->delete_temp("apprentice_ok");
	
		char title[10], new_rank[40];
		strncpy(title, querystr("title"), 8)[8] = 0;
		snprintf(new_rank, 40, "%s座下护法", title);
		me->set("party/rank", new_rank);
		me->set("party/level", 4);
		
		say("哈哈哈 !", me);
        say("本教又得一可塑之才，真是可喜可贺 !", me);
	    say(snprintf(msg, 255, "恭喜你荣升为明教%s！", new_rank), me);
		SendMenu(me);	
	}
	
	return 1;
}

void die()
{
	char msg[255];
	CContainer * env = load_room("pk");
	if(env->query("mj/start"))
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me && !env->query(snprintf(msg, 255,"mj/kill_%s",this->name(1))))
		{
			env->add(snprintf(msg, 255,"mj/kill_%s",this->name(1)),1);
			env->add("mj/count",1);
			g_Channel.do_channel(&g_Channel, 0, "chat", 
				snprintf(msg, 255, "$HIY%s$HIC新立奇功，斩获明教魔头$HIY%s%s$HIC！",me->name(1),this->querystr("title"),this->name(1)));
		}
	}
	CNpc::die();
}
NPC_END;




