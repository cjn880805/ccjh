// pub_fengqi.c
//code by Fisho
//date : 2000-12-14
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_fengqi);

virtual void create()
{
	set_name("凤七","feng qi"  );

	set("icon", pub_boss);
	set("gender", "男性" );
	set("title", "酒楼老板" );
	set("age", 42);
	set("long","凤七是凤东南的远房祖弟，在这英雄楼当掌柜。武功没有什么，为人却极是机灵。");
	set("combat_exp", 100);
	set("nkgain", 30);

	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "七哥");

	carry_good("jitui",500);
	carry_good("jiudai",500);
	carry_good("baozi",500);
	carry_good("zongzi",500);
	carry_good("mizhitianou",500);
 
	carry_object("cloth")->wear();

	add_money(500);
	set("no_huan",1);
}

virtual void init(CChar *ob)
{	
	CNpc::init(ob);
	if( userp(ob) && !is_fighting() ) 
	{
		if ( (ob->querymap("family")) && EQUALSTR(ob->querystr("family/family_name"), "丐帮")
			&& ob->query_skill("begging",1) > 10 && !ob->query_temp("apply/no_禁入")  )
		{
			remove_call_out(saying);
			call_out(saying, 1, ob->object_id());
		}
		else
		{
			remove_call_out(do_greeting);
			call_out(do_greeting, 1, ob->object_id());
		}

	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

	switch( random(2) ) 
	{
		case 0:
			snprintf(msg,255, "$N笑咪咪地说道：这位%s，进来喝杯茶，歇歇腿吧。",query_respect(who) );
		case 1:
			snprintf(msg,255, "$N笑咪咪地说道：这位%s，快请进。",query_respect(who));
	}
	message_vision(msg, me);
}

static void saying(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *) (me->environment())->Present(param1);

	if (! who) return ;

	me->say("凤七大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！");
	me->remove_call_out(kicking);
	me->call_out(kicking, 1, who->object_id() );
}

static void kicking(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if (! who) return;
	
	who->move(load_room("佛山") );//没有该场景
	tell_room(who->environment(),snprintf(msg,255,"只听“乒”地一声，%s被人从英雄楼里一脚踢了出来，狼狈万状的逃开了。",who->name()),who);
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	int i;
	int o;

	if (ob->query("is_task")==1)
	{
		i=ob->query("valued");
		o=random(i)+1;
		o=random(i)+1;
		if (who->query("repute")==0)
			o=0;
		if (who->query("repute")<0)
			o=-o;

		snprintf(msg, 255, "%s完成了红烧鸡翅的任务，获得%d点经验，%d点声望！", who->name(1),i,o);

		g_Channel.do_channel(&g_Channel, 0, "sys", 	msg);

		tell_object(who,msg);

		who->add("combat_exp",i);
		who->add("repute", o);

		destruct(ob);
		return 1;
	}

return 0;
}




VENDOR_END;



