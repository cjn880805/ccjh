// lin.c 林朝英
//code by sound
//2001-07-19

NPC_BEGIN(CNgumu_lin);

virtual void create()
{
	set("icon",young_woman3);
	set_name("林暮明", "lin chaoying");
	set("gender", "女性");
	set("age", 42);
	set("long",	"她就是古墓派的开山祖师林暮明，虽然已经是四十许人，望之却还如同三十出头。当年她与全真教主王重阳本是一对痴心爱侣，只可惜有缘无份，只得独自在这古墓上幽居。");
	set("attitude", "friendly");
	
	set("per", 30);
	set("str", 37);
	set("int", 42);
	set("con", 45);
	set("dex", 42);
	
	set("chat_chance_combat", 6);
	set("chat_chance", 1);
	set("no_kill",1);

	set("hp", 8000);
	set("max_hp", 8000);
	set("mp", 9000);
	set("max_mp", 9000);
	set("mp_factor", 100);
	
	set("combat_exp", 3000000);
	set("shen_type", 1);
	
	set_skill("force", 300);
	set_skill("yunv_xinfa", 280);    //玉女心法
	set_skill("yunv_xinjing", 300);	 //玉女心经
	set_skill("sword", 300);
	set_skill("yunv_jian", 300);     //玉女剑
	set_skill("quanzhen_jian",300);  //全真剑
	set_skill("dodge", 280);
	set_skill("yunv_shenfa", 280);   //玉女身法
	set_skill("parry", 280);
	set_skill("unarmed",280);
	set_skill("meinv_quan", 280);    //美女拳法
	set_skill("literate",180);
	set_skill("taoism",220);
	set_skill("music",400);
	
	map_skill("force", "yunv_xinjing");
	map_skill("sword", "yunv_jian");
	map_skill("dodge", "yunv_shenfa");
	map_skill("parry", "meinv_quan");
	map_skill("unarmed", "meinv_quan");
	
	create_family("古墓派", 1, "开山祖师");
	set("chat_chance",  80);
	
	set_inquiry("王重阳","大胆后辈小子，也敢直呼重阳祖师之名？");
	set_inquiry("重阳祖师","重阳是全真教的掌教，自号“活死人”。");
	set_inquiry("古墓派","是啊，这里就是我一手创下的古墓派");
	set_inquiry("重阳剑",do_jian);

	carry_object("changjian")->wield();
	carry_object("qingyi")->wear();

}

virtual char * chat_msg()				
{
	if (DIFFERSTR(environment()->querystr("base_name"), "终南山翠屏谷底" ))
		destruct(this);
	return 0;
}

static char * do_jian(CNpc * who , CChar * me)
{	
	CContainer  * obj;

    if(!me->query_temp("gumu/ask"))
		return "你问重阳剑做什么？";
	if(me->query_temp("gumu/cyjian"))
		return "还没有把剑送给他吗？";
	if (DIFFERSTR((who->environment())->querystr("base_name"), "终南山翠屏谷底" ))
		return"你把我绑到这里，还指望我会给你东西吗？";
	me->set_temp("gumu/cyjian", 1);
    obj=load_item("cyjian");
    obj->move(me);
	me->delete_temp("gumu/ask");
	return "这柄重阳剑是王重阳当年放在我这里的，现在你帮我去还给他吧！";
}

virtual char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("force recover", 0);
		break;
	case 1:
		perform_action("sword he", 1);
		break;
	case 2:
		perform_action("unarmed you", 1);
		break;
	case 3:
		perform_action("force roar", 1);
		break;
	}
	return "";
}

void init(CChar * me)
{
	CNpc::init(me);
	char msg[255];
	if(! is_fighting() && userp(me))
	{
		DTItemList * list = me->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;
		while(p)
		{
			obj = list->GetNext(p);
			if(userp(obj))
			{
				message_vision(snprintf(msg, 255, "$HIR林暮明看了一眼%s,哼道：“我最不喜欢看见鬼鬼祟祟的小人，你和%s给我出去！”\n", me->name(), obj->name()), this);
				message_vision(snprintf(msg, 255, "$HIR只见林暮明长袖一挥，%s和%s身上携带的%s一起被拂了出去。\n", me->name(),me->name(), obj->name()), this);
				obj->move(load_room("终南山翠屏谷"));
				me->move(load_room("终南山翠屏谷"));
			}
		}
	}	
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[40];

	if (DIFFERSTR(me->querystr("family/family_name"), "古墓派"))
	{
		say("你与我毫无瓜葛，这话从何说起？",me);
		return;
	}

	if (DIFFERSTR(environment()->querystr("base_name"), "终南山翠屏谷底" ))
	{
		say("就你这种做法，也能算的上是有诚心吗？",me);
		return;
	}

	if (me->query_int() < 30) 
	{
		say("我古墓派的功夫最讲一个悟字，你的资质不够。", me);
		SendMenu(me);
		return;
	}

	if ( me->query_skill("yunv_xinfa",1) < 70 ) 
	{
		say("你的玉女心法火候不足,难以领略更高深的武功。", me);
		SendMenu(me);
		return;
	}
	
	if (me->query("repute")<80000) 
	{
		say("行侠仗义是我辈学武人的基本品质，你若能多做些狭义之事，我一定收你为徒。",me);
		SendMenu(me);
		return;
	}
	if(!me->query("gumu/jq"))
	{
		say("你我无缘。。。。",me);
		SendMenu(me);
		return;
	}	
	say("好吧，看你也是性情中人，我就收下你这个徒弟了。",me);
	command(snprintf(msg, 40, "recruit %ld", me->object_id()));
}

NPC_END;



