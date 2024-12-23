
ROOM_BEGIN(CRwiz_pk);

void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "PK场");	
	set("PK", 1);
	set("valid_startroom", 1);
	set("sleep_room", 1);
	set("wiz_room", 1);
	add_npc("wiz_charge");
	add_npc("wiz_mingjiaokill");
	set("warning",random(10000)+1);

//	time_t t;	
//	struct tm * newtime;
//	time(&t);
//	newtime = localtime(&t); 
//	int month = newtime->tm_mon + 1;

//	if(month==2)
//		set("活动",1);
};

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(me->query("grant") < 50)
	{
		if(strcmp(comm, "leave") == 0)
		{
			me->set("start_city", START_ROOM);
			me->move(load_room(START_ROOM));
			return 1;
		}

		else if(strcmp(comm, "join") == 0)
		{
			tell_object(me, "这里不准加入别人的战斗");
			return 1;
		}

		else if(strcmp(comm, "guard") == 0)
		{
			tell_object(me, "这里不欢迎观战.");
			return 1;
		}

		return 0;
	}

	if(strcmp(comm, "summon") == 0)
	{
		if(! strlen(arg)) return 0;
		CUser * obj = find_online(arg);
		if(! obj) return notify_fail("summon <目标id>");
		obj->move(this);
		obj->set("start_city", "pk");
		tell_object(obj, "PK完毕，请用/leave指令离开PK场。");
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

	if(month==2 && !query("活动") && !query("stop"))
		set("活动",1);
}

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp



