// huanu.c
//sound 2001-07-16

NPC_BEGIN(CNdali_huanu);

virtual void create()
{
	set_name("养花女","yanghua nu");
        set("gender", "女性" );
        set("age", 17);
        set("long", "一位养花少女，她每天就是照顾这数也数不清的茶花。");
 	set_temp("apply/defense", 5);
	set("combat_exp", 7000);
	set("shen_type", 1);
        set("per", 28);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
	set("icon",young_woman8);	
        set("attitude", "friendly");

//	carry_object("wchangqun")->wear();
}

NPC_END;