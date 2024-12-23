//dali_chongshengtading.h ����ǳ�ʥ����

ROOM_BEGIN(CRDali_chongshengtading);

virtual void create()		
{
	set_name("����ǳ�ʥ����");
	add_npc("wiz_yutou");
	set("wiz_room", 1);	
	set("time",3600);
	set("sleep_room", 1);
};

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(me->query("grant") < 50)
	{
		if(me->query_temp("jy/no_say")||!strcmp(comm, "kill")||!strcmp(comm, "look")||!strcmp(comm, "fight")||!strcmp(comm, "cast")||!strcmp(comm, "use")||!strcmp(comm, "go")||!strcmp(comm, "expell")||!strcmp(comm, "get")||!strcmp(comm, "ad")||!strcmp(comm, "give")||!strcmp(comm, "makelove")||!strcmp(comm, "rumor"))
		{
			tell_object(me, "�����ˣ����ڶ׼��������ǹԵ�ɡ�");
			return 1;
		}
		return 0;
	}

	if(strcmp(comm, "chblk") == 0)
	{
		CContainer * obj = Present(atol(target));
		if(! obj) return notify_fail("��ѡ�е�ǰ����Ŀ��.");
		obj->set_temp("jy/no_say", 1);
		message_vision("$N����һ�齺����ž��һ������$n���ϡ�", me, obj); 
		return 1;
	}

	if(strcmp(comm, "free") == 0)
	{
		CContainer * obj = Present(atol(target));
		if(! obj) return notify_fail("��ѡ�е�ǰ����Ŀ��.");

		message_vision("$Nһ�Ű�$n���˳�ȥ��", me, obj);

		obj->del("mj/zuolao");
		obj->delete_temp("jy/no_say");
		obj->move(load_room(START_ROOM));
		obj->set("start_city", START_ROOM);
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
		if(obj->query("mj/zuolao"))
		{
			obj->del("mj/zuolao");
			obj->move(r);
			obj->set("start_city", START_ROOM);
		}
	}
}

ROOM_END;




