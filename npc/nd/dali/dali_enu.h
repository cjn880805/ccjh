// enu.c
//sound 2001-07-16

NPC_BEGIN(CNdali_enu);

virtual void create()
{
	set_name("恶奴", "e nu");
	set("age", 32);
	set("gender", "男性");
	set("long", "他看上去膀大腰粗，横眉怒目，满面横肉。看来手下倒也有点功夫 。\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 20);
	set("dex", 16);
	set("icon",waiter);	
	set("combat_exp", 10000);
	set("shen_type", -1);

	set_skill("unarmed", 40);
	set_skill("dodge", 100);
	set_skill("parry", 40);
	set_skill("blade", 100);
	set_skill("force", 40);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}

NPC_END;