NPC_BEGIN(CNPub_caiyaoren);

virtual void create()
{
	set_name("采药人","caiyaoren");

	set("icon", banditi);
	set("gender", "男性");
	set("age", 30 + random(10));
	
	set("long", "一个辛苦工作的采药人。");
	set("attitude", "friendly");
	
	set("combat_exp", 1000);
	set("shen_type", 1);
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("hammer", 20);
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	
	add_money(50);
	carry_object("yaochu")->wield();
	carry_object("moyao")->wear();
	carry_object("fuling")->wear();
	
};

NPC_END;
