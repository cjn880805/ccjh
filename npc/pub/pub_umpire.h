NPC_BEGIN(CNpub_umpire);

virtual void create()
{
	set_name( "裁判","cai pan");
	set("icon", 18);
	set("age", 32);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("shen_type", 1);
	set("chat_chance", 100);
//	set("chat_chance_combat", 100);

	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	
	set("max_hp", 30000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_force", 300);
	set("combat_exp", 7000000);
	set("score", 1200000);

	set_weight(50000000);
	set("no_kill",1);

}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0 )
	{
		me->start_busy(2);
		return 1;
	}
	return CNpc::handle_action(comm, me, arg);
}

virtual char * chat_msg()
{
	char msg[255];
	CUser * player1;
	CUser * player2;
	player1=find_online(snprintf(msg,255,"%d",query("biwu/a")));
	player2=find_online(snprintf(msg,255,"%d",query("biwu/b")));
	if(player1)
	{
		CFightRoom * obj=(CFightRoom *)player1->environment();
		obj->set("room_locked", FIGHT_LOCKED);
	}
	else
	{
		destruct(this);
		return 0;
	}
	if(!player1 || !player2 ||!player2->query_temp("fight/is_fighting")||!player1->query_temp("fight/is_fighting"))
	{
		destruct(this);
		return 0;
	}
	else if((player1->query("hp")<0 || player2->query("hp")<0) && player1->query_temp("fight/is_fighting") 
		&& player2->query_temp("fight/is_fighting"))
	{
		CFightRoom * obj=(CFightRoom *)player1->environment();
		if(player1->query("hp")<0)
		{
			player1->set("eff_hp", player1->query("max_hp"));
			player1->set("hp", 1);
			player1->delete_temp("block_msg/all");
			player1->enable_player();
			message_vision("\n$N向空中深吸一口气，大叫道：裁判快暂停！我认输了！！\n", player1);
		}
		else if(player2->query("hp")<0)
		{
			player2->set("eff_hp", player2->query("max_hp"));
			player2->set("hp", 1);
			player2->delete_temp("block_msg/all");
			player2->enable_player();
			message_vision("\n$N向空中深吸一口气，大叫道：裁判快暂停！我认输了！！\n", player2);
		}
		obj->End_Fight();
		player1->del("condition");
		player2->del("condition");
		player1->delete_temp("biwu");
		player2->delete_temp("biwu");
		player1->delete_temp("no_fei");
		player2->delete_temp("no_fei");
		player1->set_weight(50000);
		player2->set_weight(50000);
		destruct(this);
	}
	else
	{
		CFightRoom * obj1=(CFightRoom *)player1->environment();
		obj1->set("room_locked", FIGHT_LOCKED);
		player1->set_temp("no_fei",1);
		player2->set_temp("no_fei",1);
		player1->set_temp("biwu/ok",1);
		player2->set_temp("biwu/ok",1);
	}
	return 0;
}

void die()
{
	revive(1);
	message_vision("$N望空中深深的吸了口气。", this);
	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);

}

NPC_END;




