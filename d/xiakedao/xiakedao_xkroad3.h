//xkroad3.h

//Sample for room: ƽԭС·
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRXiaKeDao_xkroad3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�ƽԭС·");
	
	add_npc("pub_bing");    //add by zdn 2001-07-16


	add_door("��ɽ����", "��ɽ����", "���͵�ƽԭС·");
	add_door("���͵���̲", "���͵���̲", "���͵�ƽԭС·");

	

/*****************************************************
    set("outdoors", "xiakedao");
	set("exits", ([
		"north"   : "/d/foshan/southgate",
		"south"   : __DIR__"xkroad4",
	]));
********************************************/
};



ROOM_END;
//last, register the room into ../server/RoomSetup.cpp