//shiwushi.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shiwushi);

virtual void create()
{
	set_name("石人武士","shi wus hi");

	set("icon", triggerman2);
	set("gender", "男性");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "这是守护西夏王陵的石人武士。\n");
	set("combat_exp", 30000);
	set("shen_type", 1);
	set("attitude", "aggressive");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("club", 80);
	set_skill("zhongpingqiang", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	map_skill("club", "zhongpingqiang");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 50);

	set("mp", 1000); 
	set("max_mp", 1000);
	set("mp_factor", 10);

	carry_object("tiejia")->wear();
	carry_object("changqiang")->wield();

	set("no_kill",1);

};

NPC_END;
