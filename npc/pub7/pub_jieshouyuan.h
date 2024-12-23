//pub_jieshouyuan.h　接收员
// dieer 2002 9.9

NPC_BEGIN(CNpub_jieshouyuan);

virtual void create()
{
	set_name("接收员","jieshouyuan");
	
	set("gender", "男性");
	set("age", 26);
	set("long","这是一个精壮结实的小伙子，因为长年做力气活，胳膊上隆起了两块如铁块一般的肌肉。他专门负责搬运转移服务器的物品。");
	set("attitude", "friendly");
	set("icon", 40);
	
	set("per", 15);
	set("str", 30);
	set("int", 20);
	set("con", 30);
	set("dex", 10);
	
	set("max_hp", 1000000);
	set("hp", 900000);
	set("max_mp", 1000);
	
	set_skill("force", 50);
	set_skill("unarmed",50);

	set("coin",50000);
	
	set_inquiry("转移东西", "要转移什么物品，就直接给我吧，不过我气力就那么大，一次顶多给你搬20样东西！");
	set_inquiry("价格", ask_jiage);
	set("no_huan",1);
}

virtual void init(CChar * me)
{
	CNpc::init(me);
	
	char msg[255];
	switch(random(2))
	{
	case 0 :
		say(snprintf(msg,255,"这位%s，您是否要将此服务器的物品转移到别的服务器去？",query_respect(me)),me);
	case 1:
		say("交给我为您转移物品，收费非常便宜，而且又安全，您可以尽管放心！",me);		
	}
	SendMenu(me);
}

static char * ask_jiage(CNpc * me, CChar * who)
{
	char msg[255];
	if(me->query("coin"))
		snprintf(msg,255,"我为您转移物品，收费非常便宜,每件就收你%d吧！",me->query("coin"));
	else
		snprintf(msg,255,"这次就不收你的钱了吧！");
	me->say(msg,who);
	me->SendMenu(who);
	return 0;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	
	//收费搬运
	if (EQUALSTR(ob->querystr("id"), "coin") && !query("coin") )
	{
		say("钱您就自己留着吧！", who);
		SendMenu(who);
		return 0;
	}
	else if (EQUALSTR(ob->querystr("id"), "coin") )
	{
		if(ob->query("value") >= query("coin"))
		{
			destruct(ob);
			say("好，钱已经收到了，我就帮你搬一件物品吧。", who);
			who->add("item/coin",1);
			SendMenu(who);
			return 1;
		}
		else
		{
			say("这么点钱就想让我给你搬东西？", who);
			SendMenu(who);
			return 0;
		}
	}
	//有生命的物品不要
	if(ob->is_character())
	{
		say("活的东西我可不要！", who);
		SendMenu(who);
		return 0;
	}

	//搬运
	if(who->query("item/count") < 20)
	{
		if((who->query("item/coin") && query("coin")) || !query("coin"))
		{
			who->add("item/coin",-1);
			if(who->query("item/coin")<=0)
				who->del("item/coin");
			who->add("item/count",1);
			snprintf(msg,255,"item/item%d",who->query("item/count"));
			who->set(msg,ob->querystr("base_name"));
			snprintf(msg,255, "好，已经收到你的%s了，总共已经收了%d件物品,您还需要转移什么？",ob->querystr("name"),who->query("item/count"));
			say(msg, who);
			SendMenu(who);
			destruct(ob);
			return 1;
		}
	}
	else
	{
		say("您已经交给我了20样东西，再多我可搬不动了！", who);
		SendMenu(who);
	}
	return 0;
}


NPC_END;