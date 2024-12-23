//hengshan_yafu.h
//code by sound
//2001-07-11

NPC_BEGIN(CNhengshan_yafu);

virtual void create()
{
	set_name("哑妇", "yafu");
        set("gender", "女性" );
        set("age", 37);
        set("long", "这是个终年不开口的哑妇");
        set("combat_exp", 50000);
	set("shen_type", 0l);
	set("str", 21);
	set("per", 20);
	set("dex", 21);
	set("con", 21);
	set("int", 21);
 	set("icon",old_woman);
        set("attitude", "friendly");
        
	carry_object("cloth")->wear();
}

NPC_END;