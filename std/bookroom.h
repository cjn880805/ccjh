//bookroom.h
//玩家书房

ROOM_BEGIN(CRbookroom);

void create()	
{
	set_name("书房", "shu fang");	

	set("sleep_room", 1);
	set("area", "house");
	
	set("saveobjects", 1);
	set("max_items", 20);

	CBox * box = Add_Box();
	box->set_name("柜子", "box");
	
	add_door("正厅", "正厅", "书房");
		
}

void setup()
{
	set("map", "玩家民居1");
}

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir, "正厅"))
	{
		CRoom * r = load_room(me->querystr("start_city"));
		me->move(r);
		return 0;
	}

	return CRoom::valid_leave(me, dir);
}

ROOM_END;




