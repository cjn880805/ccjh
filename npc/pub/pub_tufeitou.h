//tufeitou.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_tufeitou);

virtual void create()
{
	set_name("土匪头","tufeitou");

	set("icon", banditi);
	set("gender", "男性");
	set("age", 45);
	set("long","这家伙满脸杀气，一付凶神恶煞的模样，令人望而生畏。");
	set("combat_exp", 20000);
    set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set("chat_chance", 5);

	set_skill("sword", 30);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

    carry_object("changjian")->wield();
    carry_object("cloth")->wear();
	add_money(1000);

};
virtual char * chat_msg(CChar *me)
{
	return "土匪头喝道：今天你就别想从这里活着出去了!";
}


NPC_END;
