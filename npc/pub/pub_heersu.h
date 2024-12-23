// pub_heersu.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_heersu);

virtual void create()
{
	set_name("赫尔苏",  "heersu" );

	set("icon", old_man2);
	set("gender", "男性");
	set("age", 65);
	set("long", "他是一个老参客，可是一贫如洗。 ");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);
	
	set_inquiry("人参",ask_me);
	set_inquiry("首乌",ask_he);
	set("item_count",1);
	carry_object("cloth")->wear();
	set("no_huan",1);
}

static char * ask_me(CNpc *who,CChar *me)
{
 	if( (me->query("repute")<0)) 
		return "你又来抢参啦，早被抢光了，没有了。";
	
	me -> set_temp("人参",1);
	return "那你就拿出钱来吧。";
}

static char * ask_he(CNpc *who,CChar *me)
{
 	if( (me->query("repute")<0)) 
		return "你又来抢首乌啦，早被抢光了，没有了。";

	me -> set_temp("首乌",1);
	return "那你就拿出钱来吧。";
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	char msg[255];
	CContainer * obj;

    if (! me->query_temp("人参") && ! me->query_temp("首乌"))
    {
		say("我不敢要您老的钱。", me);
		SendMenu(me);
		return 0 ;
    }

    if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 50000)
    {
		if ( me->query_temp("首乌"))
		{
			if (query("item_count")>0)
			{
				say(snprintf(msg,255,"好！既然这位%s如此看得起我老头子，这棵首乌我留了很久了，就送给你吧！" , query_respect(me) ),me);
				me->delete_temp("首乌");
				obj = load_item("shouwu");//何首乌
				obj -> move(me);
				add("item_count", -1);
			}
			else
				say("钱我先收着，有首乌时再说吧！", me);
		} 
		else
		{
			if (query("item_count")>0)
			{
				say(snprintf(msg,255,"好！既然这位%s如此看得起我老头子，这棵参我留了很久了，就送给你吧！" ,query_respect(me)), me);
				me->delete_temp("人参");
				obj = load_item("shanshen");//老山叁
				obj -> move(me);
				add("item_count", -1);
			}
			else
				say("钱我先收着，我一定找个最大的老山参给您！", me);
		}
    }
    else  
		say("您给的也太少了吧？", me);

	SendMenu(me);
	destruct(ob);
    return 1;
}

NPC_END;