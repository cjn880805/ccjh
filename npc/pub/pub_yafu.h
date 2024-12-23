//yafu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yafu);

virtual void create()
{
	set_name("哑妇","yafu");
	
	set("icon", young_woman9);
	set("gender", "女性" );
	set("age", 37);
	set("long", "这是个终年不开口的哑妇");
	set("combat_exp", 50000);
	
	set("str", 21);
	set("per", 20);
	set("dex", 30);
	set("con", 21);
	set("int", 21);
	set("attitude", "friendly");
	set_skill("guimei_shenfa", 220);
	set_skill("dodge", 220);
	map_skill("dodge", "guimei_shenfa");
	carry_object("cloth")->wear();
	
	
};

NPC_END;
