//shanlu7.h

//Sample for room: 大理城山路7
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_shanlu7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城山路7");

	set("resident", "阳宗镇");

	add_npc("pub_jianke");   // 2001-07-12 zdn add

	add_door("大理城农田3", "大理城农田3", "大理城山路7");
	add_door("大理城山路8", "大理城山路8", "大理城山路7");

	set("long", "行进在南诏崎岖的山林中。高山耸立，雨林茂密繁盛，树木大都枝杈横生，给行路带来额外困难。附近山民经常行走才开出这样的道路来，尽管如此，行旅仍然需要挟带砍刀，随时准备砍除路边树木横出的障碍。" );
	
};

RESIDENT_END;
