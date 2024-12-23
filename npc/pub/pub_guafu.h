NPC_BEGIN(CNpub_guafu);

virtual void create()
{

	set_name("小寡妇","guafu");

	set("icon", young_woman12);
	set("gender", "女性" );
	set("age", 25);
	set("long", "一个年轻漂亮又不甘寂寞的小寡妇。");
	set("shen_type", -1);
	set("combat_exp", 10000);
	set("str", 18);
	set("dex", 19);
	set("con", 19);
	set("int", 19);
	set("attitude", "friendly");
	set("chat_chance",20);

	carry_object("green_cloth")->wear();

	add_money(120);


};

virtual char * chat_msg(CChar * me )
{
	switch(random(2))
	{
	case 0:
		return "小寡妇哭道：我苦命的夫哇，你怎么撇下我不管了哟 :~(";
	case 1:
		return "小寡妇抹了把眼泪，暗暗瞟了你一眼。";
	}
	return "";
}


NPC_END;
