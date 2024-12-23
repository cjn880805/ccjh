//shanzei1.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shanzei1);

virtual void create()
{
	set_name("小山贼","shanzei1");

	set("icon", cateran);
	set("gender", "男性" );
	set("age", 12);
	set("long", "这是个尚未成年的小山贼。");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 15);
	set("int", 16);
	set("con", 15);
	set("dex", 16);

	set("max_hp", 600);
	set("mp", 80);
	set("max_mp", 80);
	set("combat_exp", 1000+random(500));
	set("score", 1000);

	add_money(1);



};


NPC_END;
