//时空传送贴
//transfer_tie.h
//2001-02-03

ITEM_BEGIN(CItransfer_tie);

virtual void create(int nFlag = 0)		
{
	set_name("时空传送贴","tie");

	set_weight(5000);
	set("value", 1000);
	set("duration", 40);	
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->is_fighting())
		return notify_fail("你正在战斗。");

	if(me->query_temp("no_fei"))
		return notify_fail("以你目前的情形，无法使用“时空传送贴”。");

	if(me->query_temp("no_fei_1"))
		return notify_fail("以你目前的情形，无法使用“时空传送贴”。");

//	if(me->querymap("corps"))
//		AddMenuItem("回总舵", "$0trans $1 8", me); 

	if(me->querystr_temp("start_obj")[0])
		AddMenuItem("再入地狱", "$0trans $1 9", me); 
	AddMenuItem("北京城", "$0trans $1 0", me); 
	AddMenuItem("扬州城", "$0trans $1 1", me); 
	AddMenuItem("少林寺", "$0trans $1 2", me); 
	AddMenuItem("白陀山", "$0trans $1 3", me); 
	AddMenuItem("星宿海", "$0trans $1 4", me); 
	AddMenuItem("大理城", "$0trans $1 5", me); 
	AddMenuItem("泉  州", "$0trans $1 6", me); 
	AddMenuItem("武陵春", "$0trans $1 7", me); 
	
	SendMenu(me);

    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "trans") == 0 && !me->query_temp("no_fei" )&& !me->query_temp("no_fei_1" ))
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
	
	message_vision("只见$N拿出时空传送贴，口中念念有词。一阵烟雾过后，$P的身影不见了。", me);
	me->delete_temp("pending");
	me->move(env);
	tell_room(env, snprintf(msg, 255, "%s架着一朵祥云，落了下来。", me->name()), me);
		
	return 1;
}

int do_go(CChar * me , int dest)
{
	char msg[255];

	static char goal[][20]={
		"北京东北",
		"扬州西北",
		"少林寺石阶",
		"白驼山东街",
		"星宿海天山山路1",
		"大理城东",
		"泉州",
		"武陵春正厅",
	};
	
	const char * ro;

	if(me->is_fighting())
		return notify_fail("你正在战斗。");

/*	if(dest == 8)	//回总舵
	{
		ro = me->querystr("corps/id");
		if(! ro[0]) return 0;		
	}
*/	if(dest == 9)	//回地狱
	{
		ro = me->querystr_temp("start_obj");
		if(! ro[0]) return 0;
		DTItemList * list = me->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;
		while(p)
		{
			obj = list->GetNext(p);
			if(userp(obj) )
				obj->move(me->environment());
			else if(EQUALSTR(obj->querystr("id"), "fight_room"))
				obj->move(me->environment());
		}
	}
	else
	{
		if(dest < 0 || dest > 7) return 0;
		ro = goal[dest];
	}

	if(me->query("mp") < 30)
		return notify_fail("你的法力不足！");

	me->add("mp", -30);
	me->delete_temp("pending");

	message_vision("$YEL$N在空中划出一道门，抬腿跨了进去。" , me);

	CRoom * r = load_room(ro);
	tell_room(r, snprintf(msg, 255, "$HIB空中现出一道门，%s从中走了下来。", me->name()), me);
	me->move(r);

	if(add("duration", -1) <= 0)
	{
		message_vision("$HIC只见$N手中$n化成一团烟雾渐渐消散。", me, this);
		destruct(this);
	}

	return 1;
}

ITEM_END;
