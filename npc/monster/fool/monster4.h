
NPC_BEGIN(CNmonster4);

virtual void create()
{
	set_name("大清叛徒","daqing pangtu");
	set("title", "「伤害风化」　");
	set("gender", "男性");
	set("age", 47);
	set("attitude", "friendly");
	set("icon", young_man1);

	set("str", 55);

	set("repute", 500000);
	
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	
	set("hp", 35000);
	set("eff_hp", 35000);
	set("max_hp", 35000);
	
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 200);

	set("combat_exp", 3000000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("cuff", 200);
	set_skill("blade", 200);

	set_skill("taixuan_gong", 200);
	set_skill("luohan_quan", 500);

	set_skill("hunyuan_yiqi", 200);
	set_skill("xianyun_bufa", 200);

	map_skill("force", "hunyuan_yiqi");
	map_skill("cuff", "luohan_quan");
	prepare_skill("cuff","luohan_quan");
	map_skill("parry", "taixuan_gong");
	map_skill("dodge", "taixuan_gong");

	set("chat_chance_combat", 80);

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
	perform_action("cuff foxue", 1);

	return 0;
}

NPC_END;

