//lady2.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_lady2);

virtual void create()
{
	set_name("苏州少女","lady");
	
	set("icon", young_woman3);
	set("gender", "女性" );
	set("age", 21);
	set("long","她一脸聪明乖巧，满口伶牙俐齿。见有人稍微示意，便过去加茶倒水。");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	carry_object("cloth")->wear();
	
};


NPC_END;
