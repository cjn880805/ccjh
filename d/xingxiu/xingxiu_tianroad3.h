//tianroad3.h

//Sample for room: 星宿海天山山路3
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_tianroad3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "星宿海天山山路3");

	add_npc("zm_xingxiu");

	add_door("星宿海小路", "星宿海小路", "星宿海天山山路3");	
	add_door("星宿海天山山路2", "星宿海天山山路2", "星宿海天山山路3");
	add_door("星宿海天山山路4", "星宿海天山山路4", "星宿海天山山路3");


};


ROOM_END;
