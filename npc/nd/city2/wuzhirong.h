// wuzhirong.h   吴之荣
//zhangdongni  2001-07-18

NPC_BEGIN(CNcity2_wuzhirong);

virtual void create()
{
	set_name("吴荣之", "wuzhirong");
	set("gender", "男性");
	set("age", 40);
	set("long", "原归安县知县,因贪赃枉法,终被告发革职。他长得尖嘴猴腮,一看就知不是好人。\n");
	set("attitude", "peaceful");
	set("icon", young_man3);
	set("shen_type", -1);
	set("str", 15);
	set("int", 20);
	set("con", 20);
	set("dex", 150);
	set("hp", 1000);
	set("max_hp", 1000);
	set("mp", 500);
	set("max_mp", 500);
	set("combat_exp", 5000);
	set("score", 5000);
    set_skill("literate", 100);
	
	carry_object("cloth")->wear();
//	carry_object("goldleaf");
}

NPC_END;