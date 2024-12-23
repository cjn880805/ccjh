//pub_baoguanyuan.h　保管员
// dieer 2002 9.9

NPC_BEGIN(CNpub_baoguanyuan);

virtual void create()
{
	set_name("保管员","baoguanyuan");
	
	set("gender", "男性");
	set("age", 40);
	set("long","这是转移物品保管员，你从别的服务器转移过来的物品可以向他领回。”");
	set("attitude", "friendly");
	set("icon", 17);
	
	set("per", 22);
	set("str", 11);
	set("int", 30);
	set("con", 15);
	set("dex", 11);
	
	set("max_hp", 10000000);
	set("hp", 9000000);
	set("max_mp", 1000);
		
	set_skill("force", 50);
	set_skill("unarmed",50);

	set_inquiry("领取物品", ask_wuping );
}
	
static char * ask_wuping(CNpc * me, CChar * who)
{
	char msg[255];
	
	int longret = who->query("item/count");
	
	if(!longret)
	{
		me->say("你没有转移什么物品，或者已经领完了。", who);
		who->del("item");
	}
	else
	{
		snprintf(msg,255, "你共转移了%d件物品。我会一次交给你一件物品，要记得随时查看自己的负重，别已经拿不动了还向我要东西。",who->query("item/count"));
		me->say(msg, who);
		snprintf(msg,255,"item/item%d",who->query("item/count"));
		CContainer * bot=load_item(who->querystr(msg));
		who->add("item/count",-1);
		snprintf(msg,255, "这是你的%s，您还剩%d件物品没有领取！",bot->querystr("name"),who->query("item/count"));
		me->say(msg,who);
		who->del(msg);
		bot->move(who);
	}
	me->SendMenu(who);
	return 0;
}
	
NPC_END;
