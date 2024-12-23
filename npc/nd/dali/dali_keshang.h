// keshang.c
//sound 2001-07-19

NPC_BEGIN(CNdali_keshang);

virtual void create()
{
	set("icon",young_man4);
	set_name("盛皮罗客商", "ke shang");
	set("gender", "男性" );
	set("age", 32);
	set("long","这是一位从印度来的客商，皮肤黝黑，白布包头，大理把印度人叫作盛皮罗。");
	set("combat_exp", 7000);
        set("str", 17);
        set("dex", 25);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");

	carry_object("cloth")->wear();
//	add_money("silver", 10);
}

NPC_END;