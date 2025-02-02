// kanzhuren.c
//sound 2001-07-19

NPC_BEGIN(CNdali_kanzhuren);

virtual void create()
{
	set("icon",young_man6);
	set_name("砍竹人", "kanzhu ren");
        set("gender", "男性" );
        set("age", 22);
        set("long", "一个壮年村民，住在山下的村落里，是上山来砍伐竹子的。");
        set_temp("apply/defense", 15);
	set("combat_exp", 1700);
	set("shen_type", 1);
        set("per", 18);
        set("str", 24);
        set("dex", 25);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");

        carry_object("maotan")->wear();
        carry_object("kandao")->wield();
}

NPC_END;