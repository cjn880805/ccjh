//shanzei2.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shanzei2);

virtual void create()
{
	set_name("山贼","shanzei2");

	set("icon", cateran);
	set("gender", "男性" );
	set("age", 20);
	set("long", "这是个面目可憎的山贼。");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 21);
	set("int", 21);
	set("con", 22);
	set("dex", 21);

	set("max_hp", 600);

	set("mp", 80);
	set("max_mp", 80);
	set("combat_exp", 10000+random(5000));
	set("score", 2000);

	add_money(50);
	carry_object("dadao")->wield();




};

virtual void init(CChar * me)
{
	if(userp(me) && ! is_fighting())
		kill_ob(me);
}

NPC_END;
