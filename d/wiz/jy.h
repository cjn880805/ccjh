
ROOM_BEGIN(CRwiz_jy);

void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "监狱");	
	set("time", 18000);
	set("wiz_room", 1);	

	time_t t;	
	struct tm * newtime;
	time(&t);
	newtime = localtime(&t); 
	int month = newtime->tm_mon + 1;
	int day = newtime->tm_mday;

	if(month==1 && day<15)
		set("活动",1);

	add_npc("wiz_yutou");
};

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(me->query("grant") < 50)
	{
		if( (strcmp(comm, "say") == 0 && ! me->query_temp("jy/no_say")) || me->query_temp("jy/free"))
			return 0;
		tell_object(me, "别忘了，你在蹲监狱！还是乖点吧。");
		return 1;
	}

	if(strcmp(comm, "summon") == 0)
	{
		if(! strlen(arg)) return 0;
		CUser * obj = find_online(arg);
		if(! obj) return notify_fail("summon <目标id>");
		obj->move(this);		
		obj->set_temp("jy/time", current_time + query("time"));
		return 1;
	}

	if(strcmp(comm, "chblk") == 0)
	{
		CContainer * obj = Present(atol(target));
		if(! obj) return notify_fail("请选中当前房间目标.");
		obj->set_temp("jy/no_say", 1);
		message_vision("$N丢出一块胶布，啪的一声贴在$n嘴上。", me, obj); 
		return 1;
	}

	if(strcmp(comm, "leave") == 0)
	{
		me->move(load_room("佛山"));
		return 1;
	}

	if(strcmp(comm, "free") == 0)
	{
		CContainer * obj = Present(atol(target));
		if(! obj) return notify_fail("请选中当前房间目标.");

		message_vision("$N一脚把$n踢了出去。", me, obj);

		obj->del("jy");
		obj->delete_temp("no_say");
		obj->move(load_room(START_ROOM));
		obj->set("start_city", START_ROOM);
		return 1;
	}

	return CRoom::handle_action(comm, me, arg, target);
}

void reset()
{
	time_t t;	
	struct tm * newtime;
	time(&t);
	newtime = localtime(&t); 
	int month = newtime->tm_mon + 1;
	int day = newtime->tm_mday;
	if(month==1 && day<15 && !query("活动") && !query("stop"))
		set("活动",1);

	DTItemList list;
	CopyList(&list, &m_ItemList);
	POSITION p = list.GetHeadPosition();

	CRoom * r = load_room(START_ROOM);
	while(p)
	{
		CContainer * obj = list.GetNext(p);
		if(obj->query("jy") && current_time > obj->query("jy"))
		{
			obj->del("jy");
			obj->move(r);
			obj->set("start_city", START_ROOM);
		}
	}
}

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp



