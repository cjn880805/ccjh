//beiyidao.h

//Sample for room:  扬州北驿道
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_beiyidao);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州北驿道");

	//add npcs into the room
	add_npc("pub_poorman"); 
	add_npc("pub_playboy");       //add by zdn 2001-07-16

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("扬州北门","扬州北门","扬州北驿道");
	add_door("黄河树林1","黄河树林1","扬州北驿道");

    set("long","你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，赶着大车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。看来扬州快到了。");
	

/********************************************************
	set("exits", ([
		"south" : "/d/city/beimen",
		"north" : __DIR__"yidao1",
	]));
	set("outdoors", "shaolin");
*******************************************************/
 
};


ROOM_END;
