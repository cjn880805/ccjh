// pub_dizi2.c 弟子
//code by Fisho
//date : 2000-12-13

//inherit F_MASTER;

NPC_BEGIN(CNpub_dizi2)

virtual void create()
{
	set_name("黄衣弟子", "di zi2");
	set("long", "这是三十多岁的壮汉，膀大腰圆，是岛主从中原招募来的。");
	
	set("icon", triggerman2);
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
 
	carry_object("ycloth")->wear();
}

virtual char * greeting(CChar * ob)
{
	char msg[255];
	
	if( !ob || EQUALSTR(environment()->querystr("base_name"), "侠客岛山门"))
		return "";
	
	switch( random(2) )
	{
	case 0:
		return snprintf(msg, 255, "这位%s，欢迎欢迎。", query_respect(ob)) ;

	case 1:
		return snprintf(msg, 255, "这位%s，小弟这厢有礼了。",query_respect(ob)) ;
	}
	return "";
}

NPC_END;