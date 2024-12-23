
NPC_BEGIN(CNmonster3);

virtual void create()
{
	set_name("明教弟子","mingjiao dizi");
	set("title", "「蛊惑人心」　");
	set("gender", "男性");
	set("age", 47);
	set("attitude", "friendly");
	set("icon", young_man1);

	set("str", 35);

	set("repute", -1);
	
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	
	set("hp", 15000);
	set("eff_hp", 15000);
	set("max_hp", 15000);
	
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 200);

	set("combat_exp", 3000000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("unarmed", 200);
	set_skill("blade", 200);

	set_skill("wuyue_blade", 200);

	set_skill("seaforce", 200);
	set_skill("xianyun_bufa", 200);

	map_skill("force", "seaforce");
	map_skill("blade", "missblade");
	map_skill("parry", "missblade");
	map_skill("dodge", "xianyun_bufa");

	set("chat_chance_combat", 60);
	carry_object("monsterblade")->wield();

};

virtual void die()
{
	CChar * me;
	me=(CChar *)find_object(query_temp("last_damage_from"), 1);

	if(! me) 
	{
		CNpc::die();
		return;
	}

	if (me->query_temp("teapot/fool_seed")!=this->query_temp("teapot/fool_seed"))
	{
		CNpc::die();
		return;
	}

	me->del("teapot/fool_doing");
	me->set("teapot/fool_finish",1);

	message_vision("$N惨叫一声，化为灰烬。", this);

	destruct(this);
	return;
}




virtual char * chat_msg_combat()
{
	perform_action("blade xiangsi", 1);

	return 0;
}

NPC_END;

