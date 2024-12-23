//shulin.h

//Sample for room: 逍遥林树林
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_shulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "逍遥林树林");

	add_npc("xiaoyao_suxingh");

	add_door("逍遥林小道1", "逍遥林小道1", "逍遥林树林");
	add_door("襄阳草地", "襄阳草地", "逍遥林树林");	

	set("long", "这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼天大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出的声响");

/*****************************************************

********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp