//shinu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shinu);

virtual void create()
{
	set_name("慌张的侍女","shinu");

	set("icon", young_woman10);
	set("gender", "女性" );
	set("age", 20);
	set("long", "神情慌张,似乎做了什么事情,总是向堂厅看去。");
	set("shen_type", -1);
	set("combat_exp", 10000);
	set("str", 20);
	set("per", 21);
	set("dex", 22);
	set("con", 20);
	set("int", 21);
	set("attitude", "friendly");

	carry_object("cloth")->wear();
	carry_object("card3")->wear();
	add_money(10);



};

NPC_END;
