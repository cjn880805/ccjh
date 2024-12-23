//zhanshu.h
ITEM_BEGIN(CIzhanshu)

virtual void create(int nFlag = 0)		
{
	set_name("战书", "zhan shu");
	set("long",	"这就是呼那两斤随手抓来的皱巴巴的白纸，上面大书三个字：“我要战”。");
	set("unit", "封");
	set_weight(1000);
};


virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	char msg[255];
	if(query("use"))
	{
		return notify_fail("这张战书已经使用过了！");
	}
	if(who == me)
	{
		return notify_fail("难道你想自己去挑战？别自不量力了！");
	}
	else if(!who->Query(CChar::IS_LIVING) )
	{
		return notify_fail("很明显对方现在已经无法接受战书！");
	}
	else if(!who->Query(CChar::IS_NPC))
	{
		return notify_fail("很明显对方现在无法接受战书！");
	}
	else
	{
		if(EQUALSTR(who->id(1),"hu na") && !userp(who))
			return notify_fail("呼那两斤以一种奇怪的眼光看着你。");

		if(DIFFERSTR(who->id(1),"haju ba") || userp(who))
			return notify_fail(snprintf(msg, 255,"%s头连连直甩：“呼那两斤？没有弄错吧，我这种身形，怎么能和他角力呢。”",who->name(1)));
		else if(!me->query_temp("zhang/renwu6_3"))
		{
			tell_object(me, "\n$HIR哈巨霸低头一扫战书，喝道：“好气魄，不愧是名震天下的呼那两斤。”");
			tell_object(me, "$HIR随即挥毫在原纸上回书：“你要战，那便战。”\n");
			destruct(this);
			CContainer * zhanshu=load_item("baozi");
			zhanshu->set_name("战书","zhan shu");
			zhanshu->set("use",1);
			zhanshu->set("owner1",me->id(1));
			zhanshu->set("long","这就是呼那两斤随手抓来的皱巴巴的白纸，上面大书三个字：“我要战”，下面回复道：“你要战，那便战”，看来约战双方都是不世豪杰。");
			zhanshu->move(me);
			me->set_temp("zhang/renwu6_3",1);
		}
		else
			return notify_fail("你已经拿过了战书，还想做什么？");
	}
	return 1;
}

ITEM_END;




