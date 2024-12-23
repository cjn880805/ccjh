//muyangnu.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_muyangnu);

virtual void create()
{
	set_name("牧羊女","muyangnu");
	
	set("icon", young_woman1);
	set("gender", "女性" );
	set("age", 22);
	set("long", "她是一个摆夷牧羊女子。");
	set_temp("apply/defense", 15);
	set("combat_exp", 170);
	set("shen_type", 1);
	set("per", 18);
	set("str", 24);
	set("dex", 25);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	
	carry_object("wchangqun")->wear();
	carry_object("yangbian")->wear();
};


NPC_END;
