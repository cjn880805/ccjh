#include "../../../server/Room.h"

ROOM_BEGIN(CRxinyuedian);

void create()	
{
	set_name("新月大殿", "xin yue dian");	
	
	set("sleep_room", 1);
	
	set("saveobjects", 1);
	set("valid_startroom", 1);
	
	if(_M.undefinedp("level_num"))
	{
		set("rank/level_num", 7);
		set("rank/1", "宫主");
		set("rank/2", "副宫主");
		set("rank/3", "长老");
		set("rank/4", "阁主");
		set("rank/5", "护法");
		set("rank/6", "使者");
		set("rank/7", "宫众");
	}
	set("long","月色如梦照九州，天边新月如钩。");

}

void setup()
{
	char msg[255];
	CDoor * door;
	CRoom * corps = load_room(querystr("corps_id"));
	
	switch(corps->query("level"))
	{		
	case 1:
		door =add_door(querystr("area"), querystr("corps_id"), "新月大殿");
		door->set_name(querystr("area"));
		break;
	case 2:
		sprintf(msg, "g2_玉虚门_%s", querystr("corps_id"));
		door =add_door("玉虚门",msg, "新月大殿");
		door->set_name("玉虚门");
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		sprintf(msg, "g3_天仙阁_%s", querystr("corps_id"));
		door =add_door("天仙阁", msg, "新月大殿");
		door->set_name("天仙阁");
		break;
	case 8:
		sprintf(msg, "g8_紫香亭_%s", querystr("corps_id"));
		door =add_door("紫香亭", msg, "新月大殿");
		door->set_name("紫香亭");
		break;	
	case 9:
		sprintf(msg, "g9_摘星宫_%s", querystr("corps_id"));
		door =add_door("摘星宫", msg, "新月大殿");
		door->set_name("摘星宫");
		break;
	}
	make_shizhe(load_room(querystr("corps_id"))->querymap("shizhe"));
}


void reset()
{
	CNpc * npc = find_npc(query_temp("shizhe"));
	if(! npc) 
	{
		make_shizhe(load_room(querystr("corps_id"))->querymap("shizhe"));
	}
}

void make_shizhe(CMapping * yongren)
{
	CContainer * where = load_room(querystr("corps_id"));
	if(!where->query("end"))
	{
		CNpc * npc = find_npc(query_temp("shizhe"));
		if(! npc) 
			npc = load_npc("corps_xinyunhun");
		
		if(yongren)
			npc->set("welcome", yongren->querystr("welcome"));	
		
		if(!where->query("fail_ob"))
		{
			npc->set("combat_exp",where->query("新月大殿/sh_combat_exp"));
			npc->set("max_hp",where->query("新月大殿/sh_hp"));
			npc->set("max_mp",where->query("新月大殿/sh_mp"));
			npc->set("level",where->query("新月大殿/sh_level"));
			npc->set("str",where->query("新月大殿/sh_str"));
			npc->set("dex",where->query("新月大殿/sh_dex"));
			npc->set("con",where->query("新月大殿/sh_con"));
			npc->set("int",where->query("新月大殿/sh_int"));
			npc->set("per",where->query("新月大殿/sh_per"));
			npc->set("mp_factor",2*where->query("新月大殿/sh_level"));
			npc->set("corps_name",where->querystr("area"));
			npc->set("tm_day",where->querystr("day"));
			
			npc->set("eff_hp",npc->query("max_hp"));
			npc->set("hp",npc->query("max_hp"));
			npc->set("mp",npc->query("max_mp"));
			npc->set("corps_id",querystr("corps_id"));
		}
		
		npc->move(this);
		set_temp("shizhe", npc->object_id());
	}
}

ROOM_END;
