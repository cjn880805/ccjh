NPC_BEGIN(CNPub_nongfu);

virtual void create()
{
	set_name("男农夫","nongfu");
	
	set("icon", banditi);
	set("gender", "男性" );
	set("age", 22);
	set("long", "一位乌夷族的农夫，束发总于脑后，用布纱包着，上半身裸露，下著兽皮。");
	set_temp("apply/defense", 15);
	set("combat_exp", 1700);
	set("shen_type", 1);
	set("per", 18);
	set("str", 24);
	set("dex", 25);
	set("con", 36);
	set("int", 15);
	set("attitude", "friendly");
	
	carry_object("wdahui")->wear();
	carry_object("liandao")->wield();
	
};


NPC_END;
