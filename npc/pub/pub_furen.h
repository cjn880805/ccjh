// pub_furen.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_furen);

virtual void create()
{
	set_name("庄夫人", "zhang furen");

	set("icon", young_woman4);
	set("title", "庄家三少奶奶" );
	set("nickname",  "未亡人" );
	set("long",  "只见她约莫二十六七年纪,全身缟素,不施脂粉,脸色苍白。");
	set("gender", "女性");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 100000);
	set("score", 50000);
	
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("unarmed", 90);
	set_skill("sword", 90);
	set_skill("taiji_jian", 80);
	set_skill("tiyunzong",90);
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "tiaji_jian");
	map_skill("sword", "tiaji_jian");
	
	set_temp("apply/attack", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/damage", 35);
 	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
	set_inquiry("鳌拜" , "鳌拜是我家的大仇人。");
	set_inquiry("吴秋荣" ,"我一定要手刃了这个奸贼。");
	set_inquiry("礼物" ,  "这样礼物可不一般,她就是我的好丫环双双。");
	set_inquiry("双双" ,  "这小丫头跟随我多年,做事也还妥当。");

	add_money(250);
	set("no_huan",1);
}

virtual void init(CChar *me)
{
	char msg[255];
	if( userp(me) && !is_fighting() ) 
		say( snprintf (msg,255,"很久没有人来了,这位%s，可知道我相公的下落吗?", query_respect(me) ));
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	int i;
	char msg[255];

	if ( ob->is_character() && EQUALSTR(ob->querystr("base_name"), "wu_zhi_rong") )
	{
		i= me->query("weiwang");

        if(i >= 50 && i < 70)
		{
			i += 10;
			me->set("weiwang", i);
			message_vision( "$N的江湖威望提高了！" , me);
			tell_object(me, snprintf(msg, 255, "你现在的江湖威望是%ld", i));
			say("狗贼,看打!想不到你也有今天!!!");
			((CChar *)ob)->die();
		}

		if(me->query("weiwang")>=70)
		{
			say(snprintf(msg,255, "这位%s,如此大恩大德,妾身实不知何以为报.",query_respect(me) ), me);
			say("我想送恩公一件礼物,务请勿却是幸.", me);
		}
	}
	
	if (  EQUALSTR(ob->querystr("name"), "明史辑略") )
	{
		say(snprintf(msg,255, "这位%s,多谢了.",query_respect(me) ), me);
		say("唉,你要能帮我找到吴秋荣这狗贼就好了.", me);
	}		

	if (  EQUALSTR(ob->querystr("name"), "庄允城") )
	{
		say(snprintf(msg,255,"这位%s,多谢了.",query_respect(me) ), me);
		say("唉,你要能帮我找到吴秋荣这狗贼就好了.", me);
	}		

	SendMenu(me);
	return 1;
}

NPC_END;