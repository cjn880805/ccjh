//yan.h
//Lanwood 2001-03-11

NPC_BEGIN(CNwudang_yan);

virtual void create()
{
	set_name("俞岱岩",  "yu daiyan");
	set("nickname", "武当三侠");
	set("long", "他身穿一件干干净净的青布长衫。他不过三十出头年纪，双腿残废，张真人命他主持真武剑阵。");
	set("gender", "男性");
	set("age", 31);
	set("foolid",131);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("str", 28);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_hp", 6000);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 50);
	
	set("combat_exp", 250000);
	set("score", 60000);
	
	set_skill("force", 100);
	set_skill("taiji_shengong", 100);
	set_skill("dodge", 50);
	set_skill("tiyunzong", 50);
	set_skill("unarmed", 100);
	set_skill("taiji_quan", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	
	set("chat_chance", 1);
	
	create_family("武当派", 2, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("bluecloth")->wear();
}

virtual char * chat_msg()
{
	if(random(2))
		return "俞岱说道：真武剑阵是恩师的心血。";
            
	return "俞岱仰天叹道：哪位巫师能治好我的腿，我也请鸭庄一顿。";
}
        

virtual void init(CChar * player)
{
	CNpc::init(player);
	if(userp(player) && !is_fighting())
	{
		if(DIFFERSTR(environment()->querystr("base_name"), "武当南岩宫高台"))
			return;

		remove_call_out(do_greeting);
		call_out(do_greeting, 2, player->object_id());
	}
}

static void do_greeting(CContainer * ob , LONG param1 ,  LONG param2)
{
	CChar * me = (CChar * )ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(! target) return;

	if(! target->query_skill("taiji_shengong", 1))
    {
		message_vision("$CYN十三弟子对$N齐声喝道：你这个邪魔外道，敢来真武剑阵？\n\n", target);

		if(target->query("hp") < 500)
			target->unconcious();
		else
			target->receive_wound("hp", target->query("max_hp") / 2);
	//	if (target->query_combat_exp() < 2000)
	//	{
	//		target->set("combat_exp", target->query("sk_exp"));
	//		target->set("level", 1);
	//	}
      //  else 
	//		target->add("combat_exp", -1000);

		message_vision("$CYN真武剑阵顿时启动，高台上剑气纵横，把$N围在中央。\n十三口长剑齐出，在$N身上划出了十三道口子，鲜血淋漓。\n\n\n$n脸现怒容：“邪魔外道，也敢闯真武剑阵！”\n$COM$n居高临下，起手一掌把$N劈落高台。\n\n\n", target, me);
		target->move(load_room("武当南岩宫"));
		//g_Channel.do_channel(me, 0, "chat", snprintf(msg, 255, "%s私闯真武剑阵，念其成长不易，暂免一死！", target->name(1)));
   }
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];
	
	if (player->query_skill("taiji_shengong",1) < 30 )
	{
		say("我武当派最注重内功心法，你是否还应该在太极神功上多下点功夫？",player);
		SendMenu(player);
		return;
	}
	
	if (player->query("repute") < 1000)
	{
		say("我武当乃是堂堂名门正派，对弟子要求极严。",player);
		say("在德行方面，你是否应该加强一下？", player);
		SendMenu(player);
		return;
	}

	command(snprintf(msg,255,"recruit %ld",player->object_id()) );	
}


NPC_END;