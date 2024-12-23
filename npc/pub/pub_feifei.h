//pub_feifei.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_feifei);

virtual void create()
{
	set_name("肥肥","fei fei" );

	set("icon", triggerman2);
	set("gender", "男性" );
	set("age", 35);
	set("long", "一个肥头大耳的厨师，两只小眼睛不停地眨巴着。");
	set("shen_type", -1);
	set("combat_exp", 10000);
	set("str", 20);
	set("dex", 22);
	set("con", 20);
	set("int", 21);
	set("attitude", "friendly");
	carry_object("cloth")->wear();
	add_money(500);
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	char msg[255];

	if(( EQUALSTR(ob->querystr("family/family_name"), "白驼山派"))&&(random(3)==1))
	{
		return snprintf(msg,255,"肥肥笑吟吟地说道：这位%s您饿了吧，请用餐。",query_respect(ob));
	}
	 
	return snprintf(msg,255,"肥肥小眼一眨，笑吟吟地说道：这位%s，欢迎来参观，可不要偷吃哟。",query_respect(ob));
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[40];

//	if ( !(who->Present(ob)) ) return notify_fail("你没有这件东西。");

	if ( DIFFERSTR(ob->querystr("base_name"), "mu_chai") )
	   return notify_fail("肥肥不要这件东西。");

	command(snprintf(msg, 40, "smile %ld", who->object_id() ));
	if (random(3)==1)
	{
		CMoney::Pay_Player(who, 1200);
		tell_object(who,"我多给你二两银子，不要声张！");
	}
	else
	{
		CMoney::Pay_Player(who, 1000);
		tell_object(who,"再接再励，以后我会给你好处的！");
	}
	return 1;
}


NPC_END;