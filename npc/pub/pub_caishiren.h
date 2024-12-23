NPC_BEGIN(CNPub_caishiren);

virtual void create()
{
	set_name("采石人","caishiren");

	set("icon", banditi);
	set("gender", "男性");
	set("age", 22);
	set("str", 25);
	set("dex", 16);
	set("per", 20);
	set("long", "这是一个精壮汉子。");
	set("combat_exp", 6000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	carry_object("tieqiao")->wield();
	carry_object("cloth")->wear();



};

NPC_END;
