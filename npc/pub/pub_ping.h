// pub_ping.c 平一指
//code by Fisho
//date : 2000-12-14
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_ping);

virtual void create()
{
	set_name("平一手", "ping yizhi" );

	set("icon", drugstore_boss);
	set("title", "药铺老板");
	set("gender", "男性");
	set("long", "他就是医术高超的「杀人神医」平一手。医术精湛，但在他手上也已死了不少人。");
	set("age", 65);
	set("int", 30);
	set("hp", 3000);
	set("max_hp", 3000);
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("attitude", "heroism");
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);
	add_money( 1000 );
	carry_object("cloth")->wear();

//	set_inquiry ("何首乌" , ask_wu );
	carry_good("shouwu", 50);
	carry_good("yuchandan", 20);
	set("no_huan",1);
}

static char * ask_wu(CNpc *who,CChar *me)
{
 	who->say("什么！何首乌？拿十万金来！", me);
	me->set_temp ("何首乌" , 1 );
	who->SendMenu(me);
	return "";
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if (! me->query_temp("何首乌"))
	{
        say("医一人，杀一人，老夫不收钱！", me);
		SendMenu(me);
		return 0 ;
	}

	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 100000)
	{
		message_vision("平一手给了$N何首乌！" , me);
		me->delete_temp("何首乌" );
		ob=load_item("shouwu");//何首乌
		ob->move(me);
	}
	destruct(ob);
	return 1;
}

VENDOR_END;