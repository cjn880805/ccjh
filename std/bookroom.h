//bookroom.h
//����鷿

ROOM_BEGIN(CRbookroom);

void create()	
{
	set_name("�鷿", "shu fang");	

	set("sleep_room", 1);
	set("area", "house");
	
	set("saveobjects", 1);
	set("max_items", 20);

	CBox * box = Add_Box();
	box->set_name("����", "box");
	
	add_door("����", "����", "�鷿");
		
}

void setup()
{
	set("map", "������1");
}

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir, "����"))
	{
		CRoom * r = load_room(me->querystr("start_city"));
		me->move(r);
		return 0;
	}

	return CRoom::valid_leave(me, dir);
}

ROOM_END;




