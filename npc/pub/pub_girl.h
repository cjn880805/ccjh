NPC_BEGIN(CNPub_girl);

virtual void create()
{
	set_name( "女孩", "gril");

	set("icon", girl1);
	set("gender", "女性");
	set("age", 12);

    set("long", "这是个平民少女，只有十二、三岁，身材已经很成形了。");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
	set("str", 14);
	set("dex", 10);
	set("con", 10);
	set("int", 15);
	set("attitude", "friendly");

	set("nkgain", 30);
	
	add_money(5);
};

NPC_END;
