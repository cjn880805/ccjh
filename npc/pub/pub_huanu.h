NPC_BEGIN(CNpub_huanu);

virtual void create()
{
	set_name("����Ů","huanu");

	set("icon", young_woman6);
    set("gender", "Ů��" );
    set("age", 17);
    set("long", "һλ������Ů����ÿ������չ�����Ҳ������Ĳ軨��");
 	set_temp("apply/defense", 5);
	set("combat_exp", 7000);
	set("shen_type", 1);
	set("per", 28);
    set("str", 14);
    set("dex", 15);
    set("con", 16);
    set("int", 15);
    set("attitude", "friendly");

    carry_object("wchangqun")->wear();

};



NPC_END;
