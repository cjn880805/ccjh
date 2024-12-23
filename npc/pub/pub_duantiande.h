NPC_BEGIN(CNPub_duantiande);

virtual void create()
{
	set_name("段天良","duantiande");

	set("icon", general);
	set("gender", "男性");
	set("title", "大宋兵马指挥使");
	set("age", 45);
	set("per", 15);
	set("long", "他是大宋临安兵马指挥使。");
	set("combat_exp", 4000);
    set_skill("dodge", 20);
    set_skill("unarmed", 20);
    set_temp("apply/attack",  20);
    set_temp("apply/defense", 20);
	set("shen_type", -1);

	add_money(30);
	carry_object("junfu")->wear();




};

NPC_END;
