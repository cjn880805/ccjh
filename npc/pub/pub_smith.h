// pub_smith.c

// code by Fisho
// date:2000-12-17
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_smith);

virtual void create()
{
	set_name("冯铁匠", "feng");

	set("icon", smith_boss);
	set("gender", "男性" );
	set("age", 53);
	set("long","冯铁匠想是常年弯腰打铁，背已驼了，双眼被烟火薰的又红又细，左腿残废，肩窝下撑著一根拐杖。");
	set("combat_exp", 50000);
	
	set("str", 24);
	set("dex", 17);
	set("con", 28);
	set("int", 27);
	set("shen_type", 1);
	
	set("attitude", "friendly");
	set_skill("dodge", 70);
	set_skill("hammer", 40);
	set_skill("parry", 60);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	carry_good("hammer",500);

 	set_inquiry("name","小人姓冯，村里人都叫我冯铁匠。");
 	set_inquiry("here","这里是小人糊口的铺子，小人就住在後边的屋子。");
 	set_inquiry("锄头","锄头... 抱歉，锄头已经卖光了...");
 	set_inquiry("铁锤","铁锤？小人做的铁锤坚固又耐用，一把只要三百文钱。");
 	set_inquiry("剑","哦，那是给华山派岳掌门打的，小人用了三个月，总算没浪费那块好铁。嗯，岳掌门前不久率门徒下山去了，不知什麽时候才会派人来取剑。");
 	set_inquiry("取剑","小人一定要见了岳掌门的手信才能给剑。");
 	set_inquiry("冯默风","唉～，这个名字好像在哪本小说里看过...");
 	set_inquiry("奇门遁甲","那都是小时候学的，平时没事解解闷罢了。");

	add_money(50);
	carry_object("hothammer")->wield();
	set("no_huan",1);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( EQUALSTR(ob->querystr("base_name"), "letter"))
	{
		if(!query("yl_trigger")) 
		{
			say("这把剑虽不起眼，可也是小人的心血，总算对得起岳掌门。", who);
			load_item("youlongsword")->move(who);
			set("yl_trigger", 1);
		}
		else 
			say("要剑自己进去拿。", who);

		destruct(ob);
//      call_out(destroy, 1, ob);
		SendMenu(who);
		return 1;
	}

	return 0;
}
/*
void destroy(CContainer * ob)
{
	destruct(ob);
	return;
}
*/
VENDOR_END;