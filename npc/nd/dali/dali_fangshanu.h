// fangshanu.c
//sound 2001-07-16

NPC_BEGIN(CNdali_fangshanu);

virtual void create()
{
	set_name("纺纱女", "fangsha nu");
        set("gender", "女性" );
        set("age", 17);
        set("long", "一个年轻的摆夷村妇，心灵手巧，专擅纺纱。\n");
 	set_temp("apply/defense", 5);
	set("combat_exp", 2000);
	set("shen_type", 1);
        set("per", 18);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
	set("icon",young_woman7);	
        set("attitude", "friendly");

        carry_object("bduanqun")->wear();
}

NPC_END;