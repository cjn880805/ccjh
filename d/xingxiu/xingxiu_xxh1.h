//xxh1.h

//Sample for room: 星宿海
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_xxh1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "星宿海");

	add_npc("xingxiu_zhaixing");	

	add_door("星宿海天山山路2", "星宿海天山山路2", "星宿海");
	add_door("星宿海日月洞", "星宿海日月洞", "星宿海");
	add_door("星宿海石道", "星宿海石道", "星宿海");

    set("long","这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。东面石壁上一道裂缝通到一个山洞。南面有一条捷径可通往白驼山。" );


};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp