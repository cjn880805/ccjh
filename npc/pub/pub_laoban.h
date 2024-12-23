// pub_laoban.c
//code by Fisho
//date : 2000-12-14
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_laoban);

virtual void create()
{
	set_name("酒馆老板", "lao ban" );

	set("icon", pub_boss);
	set("gender", "男性" );
	set("age", 32);
	set("long","这位酒馆老板满身狗肉香，点头哈腰着对你笑着。");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("no_get", "1");
	carry_object("cloth")->wear();
	carry_good("gourou",500);
	carry_good("gouroutang",500);
	carry_good("map",500);
}

virtual void init(CChar *ob)
{	
	CNpc::init(ob);
	if( userp(ob) && !is_fighting() ) 
	{
		if ( EQUALSTR(ob->querystr("family/family_name"), "丐帮") 
			&& ob->query_skill("begging",1) > 10 )
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
		return "酒馆老板得意的说道：这么冷的天，喝碗狗肉汤是最能暖和身子的！";
	case 1:
		return snprintf(msg,255,"酒馆老板搓了搓手，说道：这位%s，狗肉大补啊，尝尝吧。",query_respect(ob));
	}
	return "";
}

static void saying(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *) (me->environment())->Present(param1);

	if (! who) return ;
	
	message_vision("$N大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！", me);
	me->remove_call_out(kicking);
	me->call_out(kicking, 1, param1);
}

static void kicking(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if (! who) return;
	
	who->move(load_room("关外宁远"));//没有该场景
	tell_room(who->environment(),snprintf(msg,255,"只听“乒”地一声，%s被人从香肉馆里一脚踢了出来，狼狈万状的逃开了。",who->name() ),who);
}
VENDOR_END;