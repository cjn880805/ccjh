// shouling.c
//sound 2001-07-19

NPC_BEGIN(CNdali_shouling);

virtual void create()
{
	set("icon",young_man5);
	set_name("傣族首领", "daizu shouling");
	set("age", 42);
	set("title", "洪源洞洞主");
	set("gender", "男性");
	set("long", "这是一个身裹虎皮的高大男性。");
	set("attitude", "peaceful");

	set("str", 34);
	set("per", 16);
	set("dex", 16);
	set("combat_exp", 50000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 50);
	set_skill("parry", 40);
	set_skill("blade", 80);
	set_skill("force", 40);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	carry_object("mandao")->wield();
	carry_object("hupi")->wear();
}

NPC_END;