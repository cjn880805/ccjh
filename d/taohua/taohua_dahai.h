//dahai.h

//Sample for room: �һ�����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_dahai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�һ�����");
	add_npc("taohua_jiguan");        //add by zdn 2001-07-20

			
	add_door("�һ���", "�һ���", "�һ�����");
	add_door("��������", "��������", "�һ�����");


/*****************************************************
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp