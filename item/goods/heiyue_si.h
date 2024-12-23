//heiyue_si.h 黑月之匙

ITEM_BEGIN(CIheiyue_si);

virtual void create(int nFlag = 0)		
{
	set_name("黑月之匙","heiyue si");
	set("long", "这是一块产自地狱的月牙形的玉石，通体散发着冷冷的萤光，握在手中只觉寒气逼人，又丝毫没有冻手的感觉，传说中它拥有着穿梭生死二界的神奇之效。");  
	set("value", 10000);
	set("duration",40);
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
		return notify_fail("以你目前的情形，无法使用“黑月之匙”。");

	if(me->query_temp("no_fei_1"))
		return notify_fail("以你目前的情形，无法使用“黑月之匙”。");

	if(!me->querymap("18dy"))
		return notify_fail("你尚未入过地狱，何以掌握“黑月之匙”的妙处？");

	if(userp(me) )
		return notify_fail("地狱已经无门，空有“黑月之匙”又有何用？");
	
	/*if(me->query("18dy/level1"))
		AddMenuItem("黄泉之路", "$0trans $1 1", me); 
	if(me->query("18dy/level2"))
		AddMenuItem("鬼 门 关", "$0trans $1 2", me); 
	if(me->query("18dy/level3"))
		AddMenuItem("奈 何 桥", "$0trans $1 3", me); 
	if(me->query("18dy/level4"))
		AddMenuItem("泥犁地狱", "$0trans $1 4", me); 
	if(me->query("18dy/level5"))
		AddMenuItem("刀山地狱", "$0trans $1 5", me); 
	if(me->query("18dy/level6"))
		AddMenuItem("沸沙地狱", "$0trans $1 6", me); 
	if(me->query("18dy/level7"))
		AddMenuItem("沸屎地狱", "$0trans $1 7", me); 
	if(me->query("18dy/level8"))
		AddMenuItem("黑身地狱", "$0trans $1 8", me); 
	if(me->query("18dy/level9"))
		AddMenuItem("火海地狱", "$0trans $1 9", me); 
	if(me->query("18dy/level10"))
		AddMenuItem("镬汤地狱", "$0trans $1 10", me); 
	if(me->query("18dy/level11"))
		AddMenuItem("铁床地狱", "$0trans $1 11", me); 
	if(me->query("18dy/level12"))
		AddMenuItem("嵯山地狱", "$0trans $1 12", me); 
	if(me->query("18dy/level13"))
		AddMenuItem("寒冰地狱", "$0trans $1 13", me); 
	if(me->query("18dy/level14"))
		AddMenuItem("剥皮地狱", "$0trans $1 14", me); 
	if(me->query("18dy/level15"))
		AddMenuItem("畜性地狱", "$0trans $1 15", me); 
	if(me->query("18dy/level16"))
		AddMenuItem("叫唤地狱", "$0trans $1 16", me); 
	if(me->query("18dy/level17"))
		AddMenuItem("铁磨地狱", "$0trans $1 17", me); 
	if(me->query("18dy/level18"))
		AddMenuItem("冰 地 狱", "$0trans $1 18", me); 
	if(me->query("18dy/level19"))
		AddMenuItem("蛆虫地狱", "$0trans $1 19", me); 
	if(me->query("18dy/level20"))
		AddMenuItem("烊铜地狱", "$0trans $1 20", me); 
	if(me->query("18dy/level21"))
		AddMenuItem("阿鼻地狱", "$0trans $1 21", me); 

	SendMenu(me);*/

    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "trans") == 0 && !me->query_temp("no_fei" )&& !me->query_temp("no_fei_1" ))
		return do_go(me, atol(arg));

	return CItem::handle_action(comm, me, arg);
}

int do_goto(CChar * me, char * arg)
{
	char msg[255];

	if(! strlen(arg))
		return notify_fail("你想去哪里？");
	//将玩家身上所携带的其他玩家清除
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

	CRoom * env = load_room(arg);
	
	message_vision("\n$HIR只见$N拿出黑月之匙，默默祈祷。一道金光闪过，$N消失在空气中。", me);
	me->move(env);
	tell_room(env, snprintf(msg, 255, "光芒逐渐散去，%s的身影露了出来。\n", me->name()), me);
		
	return 1;
}

int do_go(CChar * me , int dest)
{
	char msg[255];

	static char goal[][20]={
		"高昌黄泉之路",
		"高昌鬼门关",
		"高昌奈何桥",
		"高昌泥犁地狱",
		"高昌刀山地狱",
		"高昌沸沙地狱",
		"高昌沸屎地狱",
		"高昌黑身地狱",
		"高昌火海地狱",
		"高昌镬汤地狱",
		"高昌铁床地狱",
		"高昌嵯山地狱",
		"高昌寒冰地狱",
		"高昌剥皮地狱",
		"高昌畜性地狱",
		"高昌叫唤地狱",
		"高昌铁磨地狱",
		"高昌冰地狱",
		"高昌蛆虫地狱",
		"高昌烊铜地狱",
		"高昌阿鼻地狱",
	};
	
	const char * ro;

	if(me->is_fighting())
		return notify_fail("你正在战斗。");
	
	if(me->query("balance") < 10000)
		return notify_fail("囊中羞涩，你不好意思的摸了摸“黑月之匙”。");

	if(dest < 1 || dest > 21) return 0;

	if(!me->query(snprintf(msg, 255,"18dy/level%d",dest)))
		return notify_fail("以你目前的能力，尚未能凭借“黑月之匙”移动到这里。");
	
	ro = goal[dest-1];
	
	if(me->query("mp") < 30)
		return notify_fail("你的法力不足！");
	
	me->add("mp", -30);
	me->add("balance",-10000);

	if(!me->query("18dy/duration"))
		me->set("18dy/duration",40);

	//将玩家身上所携带的其他玩家清除
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

	message_vision("$YEL只见$N拿出黑月之匙，默默祈祷。一团黑雾顿时笼罩住$N，须臾之间$N消失在空气中。" , me);

	CRoom * r = load_room(ro);
	tell_room(r, snprintf(msg, 255, "黑雾逐渐散去，%s的身影露了出来。\n", me->name()), me);

	me->move(r);
	add("duration", -1);
	me->add("18dy/duration", -1);

	if(me->query("18dy/duration") <= 0)
	{
		message_vision("$HIC只见$N手中$n化成一团烟雾渐渐消散。", me, this);
		destruct(this);
		me->set("18dy/duration",40);
	}
	else if(query("duration") <= 0)
	{
		message_vision("$HIC只见$N手中$n化成一团烟雾渐渐消散。", me, this);
		destruct(this);
	}
	return 1;
}

ITEM_END;
