//yzjw_jiaowai1.h

//Sample for room:  扬州草地1
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_jiaowai1);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州草地1");

	//add npcs into the room
	add_npc("pub_liumang");
	add_npc("pub_girl1");           //add by zdn 2001-07-16
	add_npc("helpnpc022");

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("扬州东门","扬州东门","扬州草地1");
	add_door("扬州树林2","扬州树林2","扬州草地1");

    set("long","这是扬州郊外的一片芳草地，落英缤纷，蜂歌蝶舞，朝露夕光，沁人心脾。真是好时光。偶有几对小男女结伴踏青，莺声丽影，嬉闹动人.");
	

/********************************************************
    set("exits", ([
        "north" : __DIR__"dongmen",
        "south" : __DIR__"jiaowai2",
        "west"  : __DIR__"course",
        "east"  : __DIR__"bite",
    ]));

    set("outdoors", "yangzhou");
    create_door("east", "垂花小门", "west", DOOR_CLOSED);
    create_door("west", "垂花小门", "east", DOOR_CLOSED);
*********************************************************/
};


ROOM_END;
