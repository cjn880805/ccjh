// huanu.c
//sound 2001-07-16

NPC_BEGIN(CNdali_huanu);

virtual void create()
{
	set_name("����Ů","yanghua nu");
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
	set("icon",young_woman8);	
        set("attitude", "friendly");

//	carry_object("wchangqun")->wear();
}

NPC_END;