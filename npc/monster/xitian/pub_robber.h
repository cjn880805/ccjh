
NPC_BEGIN(CNpub_robber);

virtual void create()
{
	set_name("强盗", "qiang dao");
	
	set("gender", "男性");
	set("age", 20);
	set("shen_type", -1);
	set("attitude", "friendly");
	set("icon", old_man2);

	set("str", 21);
	set("int", 21);
	set("con", 21);
	set("dex", 21);

	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 20);

	set("combat_exp", random(100000)+1);
	set("score", 200);

	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("blade", 30);
	set_skill("fanliangyi_dao", 50);
	set_skill("unarmed", 200);
	set_skill("taiji_quan", 200);

	map_skill("blade", "fanliangyi_dao");
	map_skill("parry", "fanliangyi_dao");
	map_skill("unarmed", "taiji_quan");

	set("chat_chance_combat", 20);
	carry_object("gangdao")->wield();
};



virtual char * chat_msg_combat()
{
	if(! random(3))
		perform_action("blade sanshen", 1);

	return 0;
}


virtual void die()
{
	message_vision("强盗尖叫一声，逃的踪影不见了。", this);
	destruct(this);
}


NPC_END;

