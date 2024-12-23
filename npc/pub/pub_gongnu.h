NPC_BEGIN(CNpub_gongnu);

virtual void create()
{
	
	set_name("大理皇宫宫女","gongnu");
	

	set("icon", young_woman2);
	set("gender", "女性" );
	set("age", 17);
	set("long", "一位大理皇宫乌夷族宫女，以酥泽发，盘成两环，一身宫装，目无表情。");
	set_temp("apply/defense", 5);
	set("combat_exp", 7000);
	set("shen_type", 1);
	set("per", 28);
	set("str", 14);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	carry_object("whitecloth1")->wear();
	
	
	
};



NPC_END;
