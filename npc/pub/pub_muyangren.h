//muyangren.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_muyangren);

virtual void create()
{
	set_name("牧羊人","muyangren");
	
	set("icon", cateran);
	set("gender", "男性" );
	set("age", 22);
	set("long", "他一个摆夷牧羊男子。");
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
