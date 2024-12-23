// pub_jinhua.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_jinhua);

virtual void create()
{
	set_name("金花","jin hua");

	set("icon", young_woman5);
	set("gender", "女性" );
	set("age", 24);
	set("long", "一个年少貌美的姑娘。");
	set("shen_type", 1);
	set("combat_exp", 800);
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 18);
	set("gold_times", 1);
	set("attitude", "friendly");
	set("chat_chance",20);
	set_inquiry("张妈","金花睁大了眼睛：你知道我娘？你可有她给你的信物？快给我看看！");
	set_inquiry("绣花鞋","金花吃惊地看着你：你真有绣花鞋吗？快给我看看！");
	set("no_huan",1);
}

virtual char *	chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "金花哭泣着：我的命怎么这么苦哟￣";
	case 1:
		return "金花抹着眼泪：娘呀，我好想你呀！";
	case 2:
		return "金花叹口气说道：不知今生今世能否再见到我娘￣";
	}
	return "";
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"金花一见有人进来急忙说：这位%s，我娘是『白驼山庄』的老佣人。你可有她的消息？",query_respect(ob) );
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	
	if (query("gold_times") < 1) return notify_fail("金花有绣花鞋了。");

	if ( DIFFERSTR(ob->querystr("base_name"), "shoe"))
		return notify_fail("金花不需要这件东西。");
	
	say( "金花双手捧着绣花鞋，泪如雨下： 娘，您还健在，您还挂着女儿啊！我还以为￣￣呜￣", who);
	
	say( snprintf(msg,255,"这位%s见笑了。 我也没什么东西报答你，我只知道山贼头有个钱箱藏在床下。 我这就给你搬出来。",query_respect(who)), who);

	CMoney::Pay_Player(who,10000);
	set("gold_times",0l);
	return 1;
}

NPC_END;