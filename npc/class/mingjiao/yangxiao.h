//yangxiao.h
//Lanwood 2000-01-09

NPC_BEGIN(CNmingjiao_yangxiao);

virtual void create()
{
	set_name("杨遥", "yang yao");
	set("long",  "他是一位中年书生，身穿白布长袍。他相貌俊雅，只是双眉略向下垂，嘴边露出几条深深的皱纹，不免略带衰老凄苦之相。他不言不动，神色漠然，似乎心驰远方，正在想什么事情。");
	
	set("title", "光明左使");
	set("mjlevel",11);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("icon",young_man1);
	set_weight(50000000);

	CMapping par;

	par.set("level", 5);
	set("party", par);
	
	set("age", 42);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_hp", 10500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 150);
	set("combat_exp", 1350000);
	set("score", 50000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("sword", 250);

	set_skill("mingwang_jian", 200);
	set_skill("shenghuo_shengong", 200);
	set_skill("piaoyibu", 200);
	set_skill("shenghuo_xinfa", 200);
	set_skill("qiankun_danuoyi", 150);
	set_skill("literate", 160);

	map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("parry", "qiankun_danuoyi");
	map_skill("sword", "mingwang_jian");
	set("chat_chance", 5);
	
	create_family("明教",35, "护法");
    set_inquiry("炎龙马",  ask_me);
	set("chat_msg", 10);

	carry_object("baipao")->wear();
	carry_object("changjian")->wield();
	set_inquiry("护教任务",ask_hujiao);
	set("no_huan",1);
};

static char * ask_hujiao(CNpc *who,CChar *me)
{
	char msg[255];
	CContainer * r = load_room("明教大殿");
	CContainer * bot;
	if(me->query_temp("mj/左使"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "明教") && r->query_temp("zuoshi_count"))
		{
			tell_object(me, "杨遥说道:感谢大侠这次仗义相助，救了不少教中的兄弟们");
			tell_object(me, "我这把“明王剑”跟随了我多年，不过近来我已经很少使用兵器了，就送给你吧！");
			bot = load_item("mingwang_jian");
			bot->move(me);
			r->add_temp("zuoshi_count",-1);
		}
		else
		{
			tell_object(me, "杨遥说道:感谢大侠这次仗义相助，救了不少教中的兄弟们，可惜我再也没什么东西好送了。。");
			int exp=(random(20)+40)*me->query("level");
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIY杨遥传授了你%ld点的实战经验！", exp));
		}
		me->delete_temp("mj/左使");
	}
	else
		tell_object(me, "范逍：什么？？");
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

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) &&  !is_fighting())
	{
		if (DIFFERSTR(me->querystr("party/party_name"), "明教"))  
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
	if( me->query_skill("force") < 70)
	{
		say("你的基本内功太低了，学习武功要先打好基础。", me);
		SendMenu(me);
		return;
	}

	if(me->query("repute") <= 1000)
	{
		say("你应当多作些行侠仗义的事，以修身心。", me);
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


static char * ask_me(CNpc * me, CChar * who)
{
	if ( who->query_temp("marks/令") ) 
		return "你不是刚刚才问过吗？";
	    
	who->set_temp("marks/令", 1);
	return "我的炎龙马不知道哪里去了，不然我可以让你骑着它去波斯。";
}

virtual int accept_object(CChar * me, CContainer * obj)
{
	if (EQUALSTR(obj->querystr("id"), "tuijian xin4" )
		&& me->query_temp("have_letter") )
	{
		me->set_temp("apprentice_ok",1);
		destruct(obj);
	    say("好，你愿意加入本使者座下吗？");
		AddMenuItem("愿意加入", "$0join $1", me);
		AddMenuItem("暂时不想", "", me);
		SendMenu(me);
		return 1;
	}

    say(g_Channel.do_emote(this, 0, "?", 1), me);
    say("这东西给我可没有什麽用。", me);
	SendMenu(me);
	return CNpc::accept_object(me, obj);
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
		snprintf(new_rank, 40, "%s座下信使", title);
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




