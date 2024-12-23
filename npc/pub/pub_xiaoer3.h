// pub_xiaoer3.c 酒店小二
//code by Fisho
//date : 2000-12-14
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_xiaoer3);

virtual void create()
{
	set_name("店小二",  "waiter"  );

	set("icon", waiter);
	set("gender", "男性" );
	set("age", 22);
	set("long","这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。");
	set("combat_exp", 100);
	set("nkgain", 30);

	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("no_get", "1");
	carry_object("cloth")->wear();

	carry_good("fotiaoqiang");	
}

virtual void init(CChar *ob)
{	
	CNpc::init(ob);
	if( userp(ob) && !is_fighting() )
	{
		if ( EQUALSTR(ob->querystr("family/family_name"), "丐帮") 
			&& ob->query_skill("begging", 1) > 10 )
		{
			remove_call_out(saying);
			call_out(saying, 1, ob->object_id());
		}
	}
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	switch( random(2) )
	{
		case 0:
			return snprintf(msg,255,"店小二笑咪咪地说道：这位%s，进来喝杯茶，歇歇腿吧。",query_respect(ob));
		case 1:
			return snprintf(msg,255,"店小二用脖子上的毛巾抹了抹手，说道：这位%s，请进请进。",query_respect(ob));
	}
	return "";
}

static void saying(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *) ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if (!who) return;
	
	me->say("店小二大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！");

	me->remove_call_out(kicking);
	me->call_out(kicking, 1, param1);
}

static void kicking(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *) ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if (!who) return;
	
	who->move(load_room("福州"));//没有该场景
	tell_room(who->environment(),snprintf(msg,255, "只听“乒”地一声，%s被人从味中味里一脚踢了出来，狼狈万状的逃开了。", who->name() ), who);
}

VENDOR_END;