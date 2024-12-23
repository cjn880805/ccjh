// pub_xizi.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_xizi);

virtual void create()
{
	set_name("戏子", "xi zi"  );

	set("icon", young_man4);
	set("gender", "男性" );
	set("age", 10+random(40));
	set("int", 28);
	set("long","这是个很英俊的男子。");
	set("attitude", "peaceful");
	set_skill("literate", 100);
	set("combat_exp",random(10000));
	set("chat_chance", 3);
	set("per", 40);

	set_inquiry("魅力", ask_meili );
	set_inquiry("旺财", "他的魅力实在太惊人了！");
	
	carry_object("zichoushan")->wear();
	carry_object("gao3")->wear();
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return 	"戏子突然说道: 魅力很重要，魅力高人人都喜欢。";
	case 1:
		return  "戏子得意地说: 我的魅力值是100。";
	case 2:
		return 	"戏子突然说道: 这年月，要想泡MM不容易啊，魅力值太低可不行。";
	}
	return "";
}

static char * ask_meili(CNpc * me, CChar * who)
{
	char msg[255];

	if(who->query("age") < 16)
	{
		if(! CMoney::Player_Pay(who, 1000000))
			me->say("想知道你的魅力是多少,先给100万再说吧.", who);
	}
	else
		me->say(snprintf(msg, 255, "你现在的魅力值是%d。", who->query("per")), who);

	me->say("如果你魅力值很高，当然就会很多MM都喜欢你啦。", who);
	me->say("而且有些师傅看你长得不漂亮还会不教你功夫", who);
	me->say("不过那些师父教的东西一般对泡MM都很有用。", who);
	
	me->SendMenu(who);
	return 0;
}

NPC_END;