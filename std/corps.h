#include "../server/Room.h"

//corps.h
//军团总部
//lanwood 2001-03-12

//set_name( "闲人居");
//set("corps", "corps00011");
//set("belong", "佛山");
ROOM_BEGIN(CRcorps);

void create()	
{
	if(_M.undefinedp("name"))
		set_name("总部", "house");	

	set("sleep_room", 1);
	set("area", "house");
	
	set("saveobjects", 1);
	set("valid_startroom", 1);

	CBox * box = Add_Box();
	box->set_name("柜子", "box");
	box->set("max_items", 12);

	set("map", "军团总部");
	make_shizhe(querymap("shizhe"));

	if(_M.undefinedp("level_num"))
	{
		set("level_num", 7);
		set("1", "帮主");
		set("2", "副帮主");
		set("3", "长老");
		set("4", "堂主");
		set("5", "护法");
		set("6", "使者");
		set("7", "帮众");
	}
}

void setup()
{
	char msg[80];
	const char * enter = querystr("belong");

	if(enter[0])
	{		
		CDoor * door = add_door("出口", enter, querystr("name"), "out");
		door->set_name(enter);
		
		CRoom * room = load_room(enter);
		room->set(snprintf(msg, 80, "corps/%s", querystr("base_name")), 1);
	}
}

void reset()
{
	CNpc * npc = find_npc(query_temp("shizhe"));
	if(! npc) make_shizhe(querymap("shizhe"));
}

void make_shizhe(CMapping * yongren)
{
	CNpc * npc = load_npc("monster_shizhe");

	if(yongren)
	{
		npc->set_name( yongren->querystr("name"));
		npc->set("welcome", yongren->querystr("welcome"));			
	}

	npc->move(this);
	set_temp("shizhe", npc->object_id());
}

LONG Query(int nAttr)
{
	if(nAttr == CAN_SAVE)
		return 1;
	
	return CRoom::Query(nAttr);
}

ROOM_END;
