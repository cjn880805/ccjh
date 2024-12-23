NPC_BEGIN(CNpub_guniang);

virtual void create()
{
	set_name("台夷姑娘","guniang");
	
	set("icon", young_woman9);
	set("gender", "女性" );
	set("age", 17);
	set("long", "一位年轻的台夷姑娘，上着无领衬花对襟，下穿五色筒裙。");
	set_temp("apply/defense", 5);
	set("combat_exp", 7000);
	set("shen_type", 1);
	set("per", 28);
	set("str", 14);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	carry_object("tongqun")->wear();
};

NPC_END;
