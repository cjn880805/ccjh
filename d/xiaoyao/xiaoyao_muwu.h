//muwu.h

//Sample for room: ľ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_muwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ľ��");

	//add npcs into the room
	add_npc("xiaoyao_kanggl");

	add_door("��ң��С��2", "��ң��С��2", "��ң��ľ��");


/*****************************************************
	set("exits", ([
		"north" : __DIR__"xiaodao5",
	]));
 	set("objects", ([
		__DIR__"npc/kanggl": 1,
	]));
//	
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp