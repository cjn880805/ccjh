// pub_puyi.c
// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_puyi);

virtual void create()
{
	set_name("仆役",  "pu yi");

	set("icon", waiter);
	set("gender", "男性" );
	set("age", 25);
	set("int", 28);
	set("long","这是个仆役打扮的年青人，两眼乱转，四处看个不停,好象害怕什么。");
	set("attitude", "peaceful");
    set("combat_exp",10000+random(5000));
	set("chat_chance", 3);
	carry_object("cloth")->wear();
	
	set_inquiry("魅力" ,ask_meili);
	set_inquiry("当官","要想当官得进京见皇上去。");
	set_inquiry("佛堂","你也知道佛堂里有书？");
	set_inquiry("四十二章经",ask_shu);
	set("no_huan",1);
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "仆役突然说道: 魅力很重要，魅力值高可以追到MM。";
	case 1: 
		return "仆役得意的说: 等我魅力再高些了就去追灵蓝。";
	case 2:
		return "仆役对你道：你太丑了。";
	}
	return "";
}

static char * ask_meili(CNpc * who, CChar *me)
{
	char msg[255];
	who->say(snprintf(msg,255,"你现在的魅力值是%ld ", me->query("per") ), me);
	who->say("如果你魅力值很高，出入官府都不会有人拦你。你还可以进宫去见皇上，如果他封你个官儿，你就可以带兵啦 。。。。。", me);
	who->say("不过当了官会有任务，搞不好会杀头的。", me);
	who->SendMenu(me);
	return "";
}

static char * ask_shu(CNpc * who,CChar *me)
{
	if (me->query_temp("money2_paid"))
	{
		me->delete_temp("money2_paid");
		who->say("就在巫师的身上。", me);
		who->say("货真价实，不会骗你的。实在不行你回头来找我。", me);
		who->SendMenu(me);
		return "";
	}

	who->say("干什么也得先交钱啊。", me);
	who->say("我花了一年多时间才查到这件物事的所在，你这一百万金，可不是好赚的。", me);
	who->SendMenu(me);
	return "";
} 

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 1000000) 
	{
		who->set_temp("money2_paid",1);
		destruct(ob);
		return 1;
	}
	return 0;
}

NPC_END;