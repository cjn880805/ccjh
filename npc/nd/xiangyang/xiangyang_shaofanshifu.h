// shaofanshifu.c
//sound 2001-07-11

NPC_BEGIN(CNxiangyang_shaofanshifu);

virtual void create()
{
	set_name("烧饭师傅", "shaofan shifu");
	set("str", 50);
	set("gender", "男性");
	set("age", 18);
	set("attitude", "pub_boss");
	set("long", "他是聚义馆厨房的烧饭师傅。");
	set("combat_exp", 2000);
	set("attitude", "friendly");

	carry_object("cloth")->wear();
}

NPC_END;