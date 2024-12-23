// wan.c
//sound 2001-07-18

NPC_BEGIN(CNguanwai_wan);

virtual void create()
{
	set_name("万震河", "wanzhenshan");
	set("title", "江西大侠");
	set("gender", "男性");
	set("long", "他是一个武师。自从得了连城剑法几页残篇后，武功大进。");
	set("age", 45);

	set("int", 20);
	set("con", 20);
	set("str", 20);
	set("dex", 20);
	set("per", 10);
	set("icon",young_man3);
	
	set("hp", 3000);
	set("max_hp", 3000);
	set("mp", 3500);
	set("max_mp", 3500);
	set("shen_type", -1);

	set("combat_exp", 500000);
	set("attitude", "heroism");

	set_skill("unarmed", 230);
	set_skill("dodge", 230);
	set_skill("parry", 260);
	set_skill("sword", 260);
	set_skill("doomsword", 260);
	map_skill("sword", "doomsword");
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 320);
/*
	set("chat_chance", 40);
	set("chat_msg", ({
		(: random_move :),
	}));
*/	
        set("chat_chance_combat", 90);

//	add_money("gold", 1);
	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();
}

virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(2))
	{
	case 0:
		perform_action("sword zhuang", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}	
	return 0;
}
NPC_END;