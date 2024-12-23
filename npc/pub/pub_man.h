//man.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_man);

virtual void create()
{
	set_name("农民","man");

	set("icon", banditi);
	set("gender", "男性" );
	set("age", 29);
	set("long", "一个很健壮的壮年农民。");
	set("shen_type", 1);
	set("combat_exp", 2000);
	set("str", 20);
	set("dex", 18);
	set("con", 18);
	set("int", 18);
	set("attitude", "friendly");

	carry_object("cloth")->wear();
	add_money(10);
};

NPC_END;
