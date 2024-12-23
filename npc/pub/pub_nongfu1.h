NPC_BEGIN(CNPub_nongfu1);

virtual void create()
{
	set_name("女农夫","nongfu");
	
	set("icon", young_woman12);
	set("gender", "女性" );
	set("age", 22);
	set("long", "一位年轻的台夷农妇，在田里辛勤地劳作着。");
	set_temp("apply/defense", 15);
	set("combat_exp", 700);
	set("shen_type", 1);
	set("per", 18);
	set("str", 24);
	set("dex", 25);
	set("con", 36);
	set("int", 15);
	set("attitude", "friendly");
	carry_object("tongqun")->wear();
	carry_object("liandao")->wield();
	
	
};


NPC_END;
