//tufei2.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_tufei2);

virtual void create()
{
	set_name("土匪乙","tufei");

	set("icon", banditi);
	set("gender", "男性");
	set("age", 20);
	set("long","这家伙满脸横肉，一看就知道不好惹");
	set("combat_exp", 5000);
    set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack", 10);
	set("apply/defense", 10);

//	set("chat_chance", 30);
//	set("chat_msg", ({
//		"土匪一声大喊: 此山是我开，此树是我栽，若要从此过，留下买路财 !\n",
//	}) );

	set_skill("unarmed", 25);
	set_skill("parry", 20);
	set_skill("dodge", 20);

    carry_object("cloth")->wear();
	add_money(10);

};


NPC_END;
