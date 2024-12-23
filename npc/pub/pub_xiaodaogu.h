//xiaodaogu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xiaodaogu);

virtual void create()
{
	set_name("小道姑","xiaodaogu");

	set("icon", taoistess);
	set("long","玉虚观的小道姑，她是在这接待香客的。");
	set("gender", "女性");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);
    set("class", "taoist");

	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_hp", 450);
	set("mp", 150);
	set("max_mp", 150);

	set("combat_exp", 2000);
	set("score", 1000);

	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);

	carry_object("cynrobe")->wear();

};

NPC_END;
