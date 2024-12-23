
NPC_BEGIN(CNmonster6);

virtual void create()
{
	set_name("¶ñÄ§Íö»ê", "emo cangsheng");
	set("title", "¡¸²Ðº¦²ÔÉú¡¹¡¡");
	set("gender", "ÄÐÐÔ");
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

	set_skill("falun_zhanfa", 200);

	set("falun/know",100);

	set_skill("falun_gong", 200);
	set_skill("xianyun_bufa", 200);

	map_skill("force", "falun_gong");
	map_skill("unarmed", "falun_zhanfa");
	map_skill("parry", "falun_zhanfa");
	map_skill("dodge", "xianyun_bufa");

	set("chat_chance_combat", 70);

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

	message_vision("$N²Ò½ÐÒ»Éù£¬»¯Îª»Ò½ý¡£", this);

	destruct(this);
	return;
}




virtual char * chat_msg_combat()
{
	int i;
	i=random(3);
	if(i == 0)
	{
		perform_action("unarmed zhen", 1);
		return 0;
	}
	if(i == 1)
	{
		perform_action("unarmed shan", 1);
		return 0;
	}
	if(i == 2)
	{
		perform_action("unarmed ren", 1);
		return 0;
	}


	return 0;
}

NPC_END;

