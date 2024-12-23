//shitailong.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_shitailong);

virtual void create()
{

	set_name("史泰龙","shi tai long");

	set("gender", "男性");
	set("title", "黑龙鞭");
	set("age", 35);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一个精壮军官，腰间围一条长鞭。");
	set("combat_exp", 45000);
	set("shen_type", -1);
	set("attitude", "peaceful");
 	set("icon",young_man5);

    set("startroom","北京皇城");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("whip", 80);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set_skill("yunlong_bian", 70);

	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 20);

	map_skill("whip", "yunlong_bian");
	map_skill("parry", "yunlong_bian");

	set("mp", 200); 
	set("max_mp", 200);
	set("mp_factor", 5);
	set("chat_chance", 15);

	carry_object("junfu")->wear();
	carry_object("heilongbian")->wield();
	add_money(30);
}

virtual char * chat_msg(CChar * player)
{
	switch(random(4))
	{
	case 0:
		return "史泰龙一拍腰间的软鞭，说道:在下黑龙鞭史泰龙，奉鳌少保将令，擒拿天地会反贼。" ;
	case 1:
		return "史泰龙大叫: 反了，反了！通通给我拿下！";
	case 2:
		return "史泰龙说道: 鳌少保天生神勇，武功盖世，曾在北京街上一拳打死一头疯牛，就凭你也配和鳌少保动手？" ;
	case 3:
		//random_move();
		return "";
	}
	return "";
}


virtual void init(CChar * player)
{
	if (userp(player) && !(player->environment())->query("no_fight") && (player->query("combat_exp") > 10000) && ( player->querystr("party/party_name") == "天地会" ))
	{
		say(" 你这个天地会反贼，纳命来吧！！！");
		kill_ob(player);
	}       
}



NPC_END;