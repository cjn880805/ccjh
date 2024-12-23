
ROOM_BEGIN(CRwiz_bw1);

void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武道场");	
	set("time", 18000);
};

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(me->query("grant") < 50)
	{
		return 0;
	}

	if(strcmp(comm, "summon") == 0)
	{
		if(! strlen(arg)) return 0;
		CUser * obj = find_online(arg);
		if(! obj) return notify_fail("summon <目标id>");
		obj->move(this);
		obj->set("start_city", "jy");
		obj->set("jy", current_time + query("time"));
		return 1;
	}

	return CRoom::handle_action(comm, me, arg, target);
}

void reset()
{
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