//shanshang.h

//Sample for room:  ����ɽɽ��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_shanshang);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ��");


	add_door("����ɽɽ��", "����ɽɽ��", "����ɽɽ��");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp