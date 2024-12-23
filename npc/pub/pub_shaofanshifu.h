NPC_BEGIN(CNPub_shaofanshifu);

virtual void create()
{
	set_name( "烧饭师傅");

	set("icon", pub_boss);
	set("str", 50);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是聚义馆厨房的烧饭师傅。");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	carry_object("cloth")->Do_Action(DO_WIELD);
};

NPC_END;
