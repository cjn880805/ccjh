// pub_dizi1.c 弟子
//code by Fisho
//date : 2000-12-13

//inherit F_MASTER;

NPC_BEGIN(CNpub_dizi1);

virtual void create()
{
	set_name("侠客岛弟子","di zi1");
	set("long", "这是三十多岁的壮汉，膀大腰圆，是岛主从中原招募来的。");
	
	set("icon", triggerman1);
	set("gender", "男性");
	set("age", 30);
	set("shen_type",1);
	set("attitude", "peaceful");
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("hp", 500);
	set("max_hp", 1500);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 30);
	
	set("combat_exp", 30000);
	set("score", 10);
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("hand", 70);
	set_skill("staff", 50);
	
	create_family("侠客岛", 2, "弟子");
	carry_object("cloth")->wear();
}

virtual char * greeting(CChar * ob)
{
	CContainer * room;
	char msg[255];
	room = load_room("侠客岛洞门");
	
	if( !ob || environment() != room)
		return "";
	switch( random(2) )
	{
	case 0:
		return snprintf(msg,255,"这位%s，快请到迎宾馆中歇歇脚吧。",query_respect(ob)) ;

	case 1:
		return snprintf(msg,255,"这位%s，岛主正在等你呢。",query_respect(ob)) ;

	}
	return "";
}

NPC_END;