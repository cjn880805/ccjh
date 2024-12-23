//tianroad1.h

//Sample for room: 星宿海天山山路1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_tianroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "星宿海天山山路1");

	//add npcs into the room
	add_npc("pub_herdsman");/////////////////////////
	add_npc("helpnpc021");		//add by qzj 2001-08-13
	add_npc("pub_dingqi");
	add_npc("baiyang");

	add_door("西域天山山路2", "西域天山山路2", "星宿海天山山路1");
	add_door("星宿海天山山路2", "星宿海天山山路2", "星宿海天山山路1");


};


ROOM_END;
