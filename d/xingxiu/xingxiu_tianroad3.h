//tianroad3.h

//Sample for room: ���޺���ɽɽ·3
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_tianroad3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���޺���ɽɽ·3");

	add_npc("zm_xingxiu");

	add_door("���޺�С·", "���޺�С·", "���޺���ɽɽ·3");	
	add_door("���޺���ɽɽ·2", "���޺���ɽɽ·2", "���޺���ɽɽ·3");
	add_door("���޺���ɽɽ·4", "���޺���ɽɽ·4", "���޺���ɽɽ·3");


};


ROOM_END;
