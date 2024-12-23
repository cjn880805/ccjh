// jianghuyiren.c
//sound 2001-07-16

NPC_BEGIN(CNdali_jianghuyiren);

virtual void create()
{
	set_name("江湖艺人", "jianghu yiren");
	set("long", "他是一个外地来的江湖艺人，手里牵着一只金丝猴儿，满脸风尘之色。");
	set("gender", "男性");
	set("age", 53);
	set("attitude", "friendly");
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);
	set("icon",young_man5);	

	set_skill("unarmed", 75);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_skill("force", 60);

	set("mp", 400);
	set("max_mp", 400);
	set("mp_factor", 20);
	set("combat_exp", 30000);
	set("score", 10000);

	carry_object("cloth")->wear();
}

NPC_END;
