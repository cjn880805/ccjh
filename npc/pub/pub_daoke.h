NPC_BEGIN(CNPub_daoke);

virtual void create()
{
	set_name("刀客","daoke");

	set("icon", young_man2);
	set("gender", "男性");
	set("age", 20);
	set("long","这家伙满脸横肉，一付凶神恶煞的模样，令人望而生畏。");
	set("combat_exp", 15000);
    set("shen_type", -1);
	set("attitude", "heroism");

	set_skill("unarmed", 45);
	set_skill("blade", 45);
	set_skill("parry", 40);
	set_skill("dodge", 40);


    carry_object("gangdao")->wield();
    carry_object("cloth")->wear();

	add_money(100);

};

NPC_END;
