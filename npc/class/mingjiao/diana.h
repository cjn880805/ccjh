//diana.h
//Cat
//2001-02-27
//紫衫龙王

NPC_BEGIN(CNmingjiao_diana);

virtual void create()
{
	set_name("黛安娜", "diana");
	set("long", "明教四大法王之一，据说年轻的时侯相当漂亮。一手夺命银花更是旷古绝今。\n");
 
	set("title","紫衫龙王");
	set("mjlevel",9);
	set("gender", "女性");
    set("age", 45);
    set("attitude", "friendly");
	set("icon",old_woman);
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

	set("hp", 10500);
	set("max_hp", 10500);
	
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 150);
	set("combat_exp", 1350000);
	set("score", 50000);
    
    set_skill("force", 200);
    set_skill("dodge", 200);
    set_skill("parry", 200);
	set_skill("unarmed", 200);
    set_skill("throwing", 280);
	set_skill("finger", 150);

    set_skill("shenghuo_shengong", 200);
	set_skill("xuantian_shengong", 200);
	set_skill("xuantian_zhi", 300);
	set_skill("shenghuo_xinfa", 200);
	set_skill("duoming_jinhua", 280);
	set_skill("piaoyibu", 200);
	set_skill("literate", 120);

	map_skill("parry", "duoming_jinhua");
	map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "piaoyibu");
	map_skill("throwing", "duoming_jinhua");
	map_skill("finger", "xuantian_zhi");
	prepare_skill("finger", "xuantian_zhi");

	set("chat_chance", 5);
	set("chat_chance_combat", 10);

    create_family("明教",35, "护法");
	
	carry_object("baipao")->wear();
	carry_object("jinhua", 300)->wield();

	set_temp("have_hua", 20);
	set_inquiry("夺命银花", ask_hua);
	set_inquiry("护教任务",ask_hujiao);
	set("no_huan",1);
};

static char * ask_hujiao(CNpc *who,CChar *me)
{
	char msg[255];
	CContainer * r = load_room("明教大殿");
	if(me->query_temp("mj/龙王"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "明教") && r->query_temp("longwang_count"))
		{
			tell_object(me, "黛安娜说道:感谢大侠这次仗义相助，救了我教不少兄弟！");
			tell_object(me, "我看你资质不错，这里有一套我自己钻研出来的“游龙杖法”，就传给你吧！");
			me->set_skill("youlong_staff",me->query_skill("youlong_staff", 1)+1);
			me->add("mj/youlong_staff",1);
			me->add("mj/skill_count",1);
			me->FlushMySkill(me);
			if(!me->query("mj/youlong_staff"))
				me->set(snprintf(msg, 255, "mj/skill%d",me->query("skill_count")),"youlong_staff");
			r->add_temp("longwang_count",-1);
		}
		else
		{
			tell_object(me, "黛安娜说道:感谢大侠这次仗义相助，救了我教不少兄弟！");
			tell_object(me, "如果大侠不嫌弃的话，我就传授你一些实战经验吧！");
			int exp=(random(20)+40)*me->query("level");
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIY黛安娜传授了你%ld点的实战经验！", exp));
		}
		me->delete_temp("mj/龙王");
	}
	else
		tell_object(me, "黛安娜：什么？？");
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
			perform_action("throwing huayu", 1);
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

	if( EQUALSTR(obj->querystr("id"), "tieyan ling")
		&& EQUALSTR(me->querystr("party/party_name"), "明教")
		&& me->query("party/level") == 4
		&& !me->query_temp("have_letter") ) 
	{
		me->set_temp("fight_ok",1);
		destruct(obj);
		say("好，既然已得到教主许可，我们就来验证一下武功。", me);
		AddMenuItem("开始比试", "$0bishi $1", me);
		AddMenuItem("转身离开", "", me);
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

	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "法王比试会");
		carry_object("jinhua", 100)->wield();
		return 1;
	}
	if(strcmp(comm, "join") == 0 && me->query_temp("apprentice_ok"))
		return do_join(me);

	return CNpc::handle_action(comm, me, arg);
}

virtual void is_defeated(CChar * winner, CChar * failer)
{
	if(failer == this)
	{
		if(! winner->query_temp("fight_ok"))	return;

		winner->delete_temp("fight_ok");
        say("青出於蓝胜於蓝，不愧是我明教的佳弟子 ! 恭喜你了 !");
        say("你现在已经是我教护教法王之一了 !");

		char new_rank[40];
		snprintf(new_rank, 40, "护教法王");
		winner->set("party/rank", new_rank);
		winner->set("party/level", 5);
		return;
	}
	
	say("看来你还得多加练习，方能在明教诸多弟子中出人头地 !");
	return;	
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

static char * ask_hua(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "明教") && DIFFERSTR(player->querystr("family/master_id"), "diana"))	//原为古墓派,改为明教 lanwood 2001-05-25
		return "你不是我门下传人，不给不给。";
	if(player->query_temp("mark/get_hua"))
		return "你不是刚拿过吗？不要那么贪心好不好？";
	if(npc->query("have_hua") < 0)
		return "你来迟了，银针已给了你其他同门了。";

	load_item("jinhua")->move(player);
	load_item("jinhua")->move(player);
	load_item("jinhua")->move(player);

	player->set_temp("mark/get_hua",1);
	npc->add_temp("have_hua", -1);

	message_vision("黛安娜给了$N一把夺命银花。", player);
	return "";
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




