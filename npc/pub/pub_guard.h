NPC_BEGIN(CNPub_guard);

virtual void create()
{
	set_name( "金牌捕快","bu kuai");
	set("icon", 18);
	set("age", 32);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("title", "六扇门");

	set("bigboss",1);

	set("shen_type", 1);
	set("chat_chance", 100);
	set("chat_chance_combat", 90);

	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 150);
	
	set("max_hp", 900000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_force", 300);
	set("combat_exp", 20000000);
	set("score", 1200000);

	set_skill("force", 320);
	set_skill("taiji_shengong", 320);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 350);
	set_skill("taiji_quan", 350);
	set_skill("parry", 300);
	set_skill("sword", 330);
	set_skill("taiji_jian", 330);
	set_skill("blade", 300);
	set_skill("taiji_dao", 300);
	set_skill("taoism", 350);
	set_skill("literate", 300);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");

	create_family("武当派", 3, "弟子");

	carry_object("changjian")->wield();

	set("no_chan",1);
	set_temp("apply/no_连字诀",1);
	set_temp("apply/no_黯然消魂",1);

}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	}
	if(query("guard"))
		del("guard");
	return 0;
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
	if(query("guard"))
	{
		char msg[255];
		CUser * player;
		snprintf(msg,255,"%d",query("guard"));
		player=find_online(msg);
		if(!player )
			destruct(this);
		else if(!player->query_temp("fight/is_fighting"))
			destruct(this);
		else if(player->query_temp("fight/is_fighting") && EQUALSTR(((player->environment())->environment())->name(1),(environment())->name(1)))
		{
			int team;
			CFightRoom * obj=(CFightRoom *)player->environment();
			if(player->query_temp("fight/fight_team"))		//加入A队
				team = 1;
			else
				team = 0;
			move(obj);
			obj->Join_Team(this, team);
			tell_room(obj, "$HIR金牌捕快大喝道：大胆狂徒，敢在官府眼皮底下行凶犯案，还不赶快给我住手！");
		}
	}
	else
		destruct(this);
	return 0;
}

NPC_END;




