//yzjw_jiaowai7.h

//Sample for room:  扬州草地7
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_jiaowai7);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州草地7");

	//add npcs into the room
	add_npc("pub_playboy");          //add by zdn 2001-07-16

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("扬州树林6","扬州树林6","扬州草地7");
	add_door("扬州南门","扬州南门","扬州草地7");

    set("long","这是扬州郊外的一片芳草地，落英缤纷，蜂歌蝶舞，朝露夕光，沁人心脾。真是踏青远足好时光。");
    

/********************************************************
    set("exits", ([
        "east" : __DIR__"jiaowai6",
        "west" : __DIR__"nanmen",
        "north": __DIR__"hnme",
    ]));
    set("outdoors", "yangzhou");
    create_door("north", "雕花小门", "south", DOOR_CLOSED);
********************************************************/
 
};


ROOM_END;
