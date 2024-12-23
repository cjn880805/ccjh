//yingying.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yingying);

virtual void create()
{
	set_name("崔莺莺","yingying");

	set("icon", young_woman1);
	set("long", "她长得极美，尤其是那对眼睛，媚得直可以勾人魂魄。");
	set("title", "财主女儿");
	set("gender", "女性");
	set("age", 17);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 20000);
	set("shen_type", 1);

	carry_object("necklace")->wear();
	carry_object("pink_cloth")->wear();

};



NPC_END;
