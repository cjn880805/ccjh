//shaonu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shaonu);

virtual void create()
{
	set_name("少女","shaonu");
	
	set("icon", young_woman8);
	set("gender", "女性" );
	set("age", 17);
	set("long", "一位乌夷族的少女，以酥泽发，盘成两环，上披蓝纱头巾，饰以花边。");
	set_temp("apply/defense", 5);
	set("combat_exp", 7000);
	set("shen_type", 1);
	set("per", 28);
	set("str", 14);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	carry_object("wchangqun")->wear();
	
	
};


NPC_END;
