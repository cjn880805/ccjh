#include "../server/Room.h"

ROOM_BEGIN(CRcorps_1);

void create()	
{
	if(_M.undefinedp("name"))
		set_name("宫", "gong");
}

void setup()
{
	const char * enter = querystr("door");
	if(enter[0])
	{		
		CDoor * door =add_door("宫外", enter, querystr("name"));
		door->set_name("宫外");
		
		CRoom * room = load_room(enter);
		room->add_door(querystr("area"),querystr("corps_id"), enter);

		//区域增加一个帮派
		char msg[255];
		load_room("pk")->add(snprintf(msg, 255,"corps/%s",room->querystr("area")),1);

		char corps_id[40];
		CRoom * corps;
		switch(query("level"))
		{
		case 2:
			sprintf(corps_id, "g2_玉虚门_%s", querystr("corps_id"));
			corps = load_room(corps_id);
			
			corps->set_name("玉虚门", corps_id);
			corps->set("area", querystr("area"));
			corps->set("corps_id",querystr("corps_id"));
			corps->set("corps",1);
			corps->set("level",query("玉虚门/level"));
			corps->set("sh/hp",query("玉虚门/sh_hp"));
			corps->set("sh/mp",query("玉虚门/sh_mp"));
			corps->set("sh/level",query("玉虚门/sh_level"));
			corps->del("fail_ob");
			
			corps->remove_all_doors();
			corps->setup();
			
			if(query("level")==2)
			{
				door =add_door("玉虚门",corps_id, querystr("corps_id"));
				door->set_name("玉虚门");
			}
		case 1:
			sprintf(corps_id, "g1_新月大殿_%s", querystr("corps_id"));
			corps = load_room(corps_id);
			
			corps->set_name("新月大殿", corps_id);
			corps->set("door", querystr("name"));
			corps->set("area", querystr("area"));
			corps->set("corps_id",querystr("corps_id"));
			corps->set("corps",1);
			corps->set("level",query("新月大殿/level"));
			corps->del("fail_ob");
			
			corps->remove_all_doors();
			corps->setup();
			
			if(query("level")==1)
			{
				door =add_door("新月大殿",corps_id, querystr("corps_id"));
				door->set_name("新月大殿");
			}
			break;
			
		}
	}
}

virtual LONG Query(int nAttr)
{
	if(nAttr == CAN_SAVE)
		return 1;
	
	return CRoom::Query(nAttr);
}


int valid_leave(CChar * me, const char * dir)
{
	switch(query("level"))
	{
	case 1:
		if(EQUALSTR(dir,"新月大殿"))
		{
			if(!me->querymap("corps") || DIFFERSTR(me->querystr("corps/id"),querystr("corps_id")))
				return notify_fail("帮派重地，测试期间，非本宫弟子不得入内。");
		}
		break;
	case 2:
		if(EQUALSTR(dir,"玉虚门"))
		{
			if(!me->querymap("corps") || DIFFERSTR(me->querystr("corps/id"),querystr("corps_id")))
				return notify_fail("帮派重地，测试期间，非本宫弟子不得入内。");
		}
		break;
	}
	return CRoom::valid_leave(me, dir);
	
}

ROOM_END;
