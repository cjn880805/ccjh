//chiling.h

//Sample for room: ���ݳ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_chiling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݳ���");
	
	add_npc("pub_xixiabing");       //add by zdn 2001-07-14


//	add_door("������������", "������������", "���ݳ���");
//	add_door("���ݵ���", "���ݵ���", "���ݳ���");


};


ROOM_END;
