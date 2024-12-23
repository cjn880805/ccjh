//请帖
//18qing_tie.h
//2001-12-10

ITEM_BEGIN(CI18qing_tie);

virtual void create(int nFlag = 0)		
{
	set_name("请帖","qing tie");

	set_weight(5000);
	set("value", 0l);
	set("duration", 2);
	
	set("no_drop", 1);
	set("no_give", 1);
	set("no_get", 1);
};

int query_autoload()
{
	return 1;
}

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->is_fighting())
		return notify_fail("你正在战斗。");

	AddMenuItem("十八地狱", "$0trans $1 0", me); 
	AddMenuItem("回到现实", "$0trans $1 1", me);  
	
	SendMenu(me);

    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "trans") == 0)
		return do_go(me, atol(arg));

	if(me->query("grant") > CChar::GRANT_PLAYER && strcmp(comm, "goto") == 0)
	{
		return do_goto(me, arg);
	}

	return CItem::handle_action(comm, me, arg);
}

int do_goto(CChar * me, char * arg)
{
	char msg[255];

	if(! strlen(arg))
		return notify_fail("你想去哪里？");

	CRoom * env = load_room(arg);
	
	message_vision("只见$N拿出请贴，向上面吹了一口气，请帖爆出一团光雾包围了$N。", me);
	me->delete_temp("pending");
	me->move(env);
	tell_room(env, snprintf(msg, 255, "%s从光雾中走了出来。", me->name()), me);
		
	return 1;
}

int do_go(CChar * me , int dest)
{
	char msg[255];

	static char goal[][20]={
		"地狱之门1",
		"泉州",
	};
	
	const char * ro;

	if(me->is_fighting())
		return notify_fail("你正在战斗。");

	if(dest < 0 || dest > 2) return 0;
	ro = goal[dest];

	if(me->query("mp") < 30)
		return notify_fail("你的法力不足！");

	me->add("mp", -30);
	me->delete_temp("pending");

	message_vision("$YEL$N走入了一片光雾之中。" , me);

	CRoom * r = load_room(ro);
	tell_room(r, snprintf(msg, 255, "$HIB地上出现一团光雾，%s从中走了出来。", me->name()), me);
	me->move(r);	    

	if(add("duration", -1) <= 0)
	{
		message_vision("$HIC只见$N手中$n裂成片片碎块，转瞬不见了。", me, this);
		destruct(this);
	}

	return 1;
}

ITEM_END;
