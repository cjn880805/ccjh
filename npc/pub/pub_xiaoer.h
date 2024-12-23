// pub_xiaoer.c
//code by Fisho
//date : 2000-12-14

VENDOR_BEGIN(CNpub_xiaoer);

virtual void create()
{
	set_name("店小二","xiaoer");

	set("icon", waiter);
	set("gender", "男性" );
	set("age", 22);
	set("long","这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。");
	set("combat_exp", 100);
	set("nkgain", 30);

	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");

	carry_good("jitui", 50);
	carry_good("jiudai", 50);
	carry_good("huicheng_juanzhou", 10);
	carry_good("jinchuang", 20);
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	char msg[255];
	if (!(ob->query_temp("welcome100")) || ob->query("mud_age")<1000)
	{
		ob->set_temp("welcome100","1");
		say(snprintf(msg,255,"这位%s，欢迎来到 纵横天下。如果您对这个游戏的设计和管理有什么建议或意见请 mailto lanwood ，我们一定会认真考虑的。",query_respect(ob) ));
	}
	switch( random(2) ) 
	{
	case 0:
		return snprintf(msg,255, "店小二笑咪咪地说道：这位%s，进来喝杯茶，歇歇腿吧。",query_respect(ob) );
	case 1:
		return snprintf(msg,255, "店小二用脖子上的毛巾抹了抹手，说道：这位%s，请进请进。", query_respect(ob) );
	}
	return "";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 2000) 
	{
		tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。");
		who->set_temp("rent_paid",1);
		destruct(ob);
		return 1;
	}
	return 0;
}
VENDOR_END;