//shizilin.h

//Sample for room: 狮子林
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_shizilin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "狮子林");
	
	add_npc("animal_snake");        //add by zdn 2001-07-16

	add_npc("pub_qianwanguan"); 
	add_door("苏州南", "苏州南", "苏州狮子林");
	add_door("苏州揖峰指柏轩", "苏州揖峰指柏轩", "苏州狮子林");
	add_door("苏州燕誉堂", "苏州燕誉堂", "苏州狮子林");
	
 	set("outdoors", "suzhou");
	
/*****************************************************
	set("exits", ([
		"east"      : __DIR__"yanyutang",
		"west"      : __DIR__"nandajie1",
		"northeast" : __DIR__"zhipoxuan",
	]));

********************************************/
};


ROOM_END;
