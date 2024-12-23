NPC_BEGIN(CNpub_gongnv);

virtual void create()
{
	
	set_name("宫女","gongnv");
	
	set("icon", young_woman1);
	set("gender", "女性" );
	set("age", 14+random(10));
	set("long", "这是一个宫女,容貌很清秀,看来挺能干.");
	set("shen_type", 1);
	set("combat_exp", 3000);
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 19);
	set("attitude", "friendly");
	
	carry_object("female5_cloth")->wear();
};


NPC_END;
