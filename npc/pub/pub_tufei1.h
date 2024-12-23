//tufei1.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_tufei1);

virtual void create()
{
	set_name("土匪甲","tufei");

	set("icon", banditi);
	set("gender", "男性");
	set("age", 30);
	set("long","这家伙满脸横肉一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 10000);
    set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack", 20);
	set("apply/defense", 20);

//	set("chat_chance", 30);
//	set("chat_msg", ({
//		"土匪一声大喊: 此山是我开，此树是我栽，若要从此过，留下买路财 !\n",
//	}) );

	set_skill("unarmed", 40);
	set_skill("sword", 20);
	set_skill("parry", 40);
	set_skill("dodge", 40);

    carry_object("duanjian")->wield();
    carry_object("cloth")->wear();
	add_money(1);

};


NPC_END;
