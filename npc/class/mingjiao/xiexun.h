//xiexun.h
//Lanwood 2000-01-09

NPC_BEGIN(CNmingjiao_xiexun);

virtual void create()
{
	set_name("谢谦", "xie qian");
	set("long", "他是一位身材魁伟异常的的老者，身穿一件白布长袍。他满头黄发，威风凛凛，真如天神一般，只是两只眼睛并不睁开。");
	
	set("title", "金毛狮王");
	set("mjlevel",9);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("icon",old_man1);
	set_weight(50000000);

	set("age", 63);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_hp", 10500);
	
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 150);

	set("combat_exp", 1200000);
	set("score", 50000);

	set_skill("force", 260);
	set_skill("dodge", 240);
	set_skill("parry", 240);
	set_skill("cuff", 250);
//    	set_skill("staff", 180);
	set_skill("jiuyang_shengong", 260);
	set_skill("piaoyibu", 240);
    set_skill("qishang_quan", 280);
    set_skill("literate", 100);

	map_skill("force", "jiuyang_shengong");
	map_skill("dodge", "piaoyibu");
	map_skill("cuff", "qishang_quan");
    map_skill("parry", "qishang_quan");

	prepare_skill("cuff","qishang_quan");
	set("mj",1);

	set("chat_chance_combat", 20);
	carry_object("baipao")->wear();
	set_inquiry("护教任务",ask_hujiao);
};

static char * ask_hujiao(CNpc *who,CChar *me)
{
	char msg[255];
	CContainer * r = load_room("明教大殿");
	CContainer * bot;
	if(me->query_temp("mj/狮王"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "明教") && r->query_temp("shiwang_count"))
		{
			tell_object(me, "谢谦说道:这次六大门派来犯，多亏了你了。我这里有一把“屠龙宝刀”，就送给你了吧！希望你可以参悟出宝刀中的秘密。");
			bot = load_item("tulong_dao");
			bot->move(me);
			r->add_temp("shiwang_count",-1);
		}
		else
		{
			tell_object(me, "谢谦说道:感谢大侠这次仗义相助，救了不少教中的兄弟们，可惜我再也没什么东西好送了。。");
			int exp=(random(20)+40)*me->query("level");
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIY谢谦传授了你%ld点的实战经验！", exp));
		}
		me->delete_temp("mj/狮王");
	}
	else
		tell_object(me, "范逍：什么？？");
	return "";
}


virtual char * chat_msg_combat()
{
	switch(random(7))
	{
	case 0:
			perform_action("cuff cangli", 1);
			break;
	case 1:
			perform_action("cuff sunxin", 1);
			break;
	case 2:
			perform_action("cuff shangfei", 1);
			break;
	case 3:
			perform_action("cuff sanjiao", 1);
			break;
	case 4:
			perform_action("cuff jingshi", 1);
			break;
	case 5:
			perform_action("cuff cuiganchang", 1);
			break;
	case 6:
			perform_action("cuff hunpo", 1);
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

	return CNpc::handle_action(comm, me, arg);
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




