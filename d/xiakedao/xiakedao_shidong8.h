//shidong8.h

//Sample for room: ���͵�ʯ��8
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_shidong8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�ʯ��8");
	
	add_npc("wudang_lisi");        //add by zdn 2001-07-20


	add_door("���͵�ʯ��7", "���͵�ʯ��7", "���͵�ʯ��8");
	add_door("���͵�ɽ·6", "���͵�ɽ·6", "���͵�ʯ��8");

    

/*****************************************************

********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp