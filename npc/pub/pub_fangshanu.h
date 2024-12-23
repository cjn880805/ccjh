NPC_BEGIN(CNPub_fangshanu);

virtual void create()
{
	set_name("纺纱女","fangshanu");

	set("icon", young_woman7);
    set("gender", "女性" );
    set("age", 17);
    set("long", "一个年轻的摆夷村妇，心灵手巧，专擅纺纱。");
 	set_temp("apply/defense", 5);
	set("combat_exp", 2000);
	set("shen_type", 1);
    set("per", 18);
    set("str", 14);
    set("dex", 15);
    set("con", 16);
    set("int", 15);
    set("attitude", "friendly");

    carry_object("bduanqun")->wear();
};

NPC_END;
