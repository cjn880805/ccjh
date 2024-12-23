//shanlu8.h

//Sample for room: 大理城山路8
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_shanlu8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城山路8");

	set("resident", "阳宗镇");

	add_npc("pub_daoke");     // 2001-07-12 zdn add

	//the seventh param: to next door id of next room
	add_door("大理城山路7", "大理城山路7", "大理城山路8");
	add_door("大理城阳宗镇", "大理城阳宗镇", "大理城山路8");

	set("long", "道路在山林中蜿蜒继续，从西面的山岭通向东面的低洼地带。这里山势较为平缓，山丛中偶有人烟，透过丛林的缝隙中向东望去，隐约可见一汪碧水和些许人烟。" );
	
};

RESIDENT_END;
