NPC_BEGIN(CNPub_enu);

virtual void create()
{
	set_name("恶奴","enu");

	set("icon", banditi);
	set("age", 32);
	set("gender", "男性");
	set("long", "他看上去膀大腰粗，横眉怒目，满面横肉。看来手下倒也有点功夫 。");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 20);
	set("dex", 16);
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
	carry_object("tiehuyao")->wear();
	carry_object("tiehuwan")->wear();


};

NPC_END;
