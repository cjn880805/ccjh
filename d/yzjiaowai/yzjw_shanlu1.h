//yzjw_shanlu1.h

//Sample for room:  ����ɽ·1
//coded by zwb
//data: 2000-11-20

ROOM_BEGIN(CRYZJW_shanlu1);


virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "����ɽ·1");
	//add npcs into the room
	add_npc("pub_jianke");      // add by zdn 2001-07-16

	add_door("��������","��������","����ɽ·1");

	add_door("����������2","����������2","����ɽ·1");


};


ROOM_END;
