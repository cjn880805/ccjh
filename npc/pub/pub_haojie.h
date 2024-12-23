// pub_haojie.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_haojie);

virtual void create()
{
	set_name("太湖豪杰","taihu haojie" );

	set("icon", young_man2);
	set("gender", "男性");
	set("age", 25);
	set("long", "这是归云庄属下的在太湖劫富济贫的太湖豪杰。");
	set("combat_exp", 100000);
	set_skill("dodge", 50);
	set_skill("lingxu_bu", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("changquan", 50);
	map_skill("unarmed", "changquan");
	map_skill("parry", "changquan");
	map_skill("dodge", "lingxu_bu");
	set("shen_type", 1);
	set_inquiry("返航",ask_back);
 	carry_object("cloth")->wear();
}

virtual char * chat_msg()
{
	return 	"要返航，就告诉我....";
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"这位%s，要返航，就告诉我....",query_respect(ob) );
}


static char * ask_back(CNpc * who,CChar *me)
{
	message_vision("船上群盗齐声应道：扯帆，回去庆功喽！\n船夫升起帆，船就向归云庄航行。", me);
	
//	who->call_out(rguiyun, 10 , me->object_id());
	me->move(load_room("苏州运河码头"));

	return  "";
}

/*
static void rguiyun( CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

//	CRoom * ship;
//	ship = load_room("/d/guiyun/ship");//没有该场景
	
//	tell_object(who , "战船在一阵阵风浪声中靠上了码头。" ) ;
//	ship->add_door("出口", "苏州运河码头",  "码头");
}
*/

NPC_END;