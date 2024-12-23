//keshang.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_keshang);

virtual void create()
{
	set_name("盛皮罗客商","keshang");

	set("icon", pawnshop_boss);
	set("gender", "男性" );
	set("age", 32);
	set("long","这是一位从印度来的客商，皮肤黝黑，白布包头，大理把印度人叫作盛皮罗。");
	set("combat_exp", 7000);
    set("str", 17);
    set("dex", 25);
    set("con", 17);
    set("int", 22);
	set("attitude", "friendly");
	setup();
	carry_object("cloth")->wear();
	add_money(10);
};


NPC_END;
