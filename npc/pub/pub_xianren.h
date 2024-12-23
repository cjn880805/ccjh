NPC_BEGIN(CNpub_xianren);

virtual void create()
{
	set_name("小混混","xianren");

	set("icon", cateran);
	set("long", "他是扬州里的小混混，整天闲着没事干。\n");
	set("gender", "男性");
	set("age", 15);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 15);
	set("str", 15);
	set("int", 14);
	set("con", 15);
	set("dex", 16);
	set("hp", 100);
	set("max_hp", 300);
	set("mp", 10);
	set("max_mp", 10);
	set("combat_exp", 200);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set("chat_chance", 10);
	add_money(100);

	carry_object("cloth")->wear();

};


virtual char * chat_msg(CChar * me )
{
	switch(random(2))
	{
	case 0:
		return "小混混道：一二三四五，上山打老虎，老虎没吃饭，专吃大坏蛋！";
	case 1:
		return "小混混道：大事不好，房子要倒，母猪母猪，我看你往哪跑？！";
	}
	return "";
}

NPC_END;
