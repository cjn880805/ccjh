//tianroad1.h

//Sample for room: ���޺���ɽɽ·1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_tianroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���޺���ɽɽ·1");

	//add npcs into the room
	add_npc("pub_herdsman");/////////////////////////
	add_npc("helpnpc021");		//add by qzj 2001-08-13
	add_npc("pub_dingqi");
	add_npc("baiyang");

	add_door("������ɽɽ·2", "������ɽɽ·2", "���޺���ɽɽ·1");
	add_door("���޺���ɽɽ·2", "���޺���ɽɽ·2", "���޺���ɽɽ·1");


};


ROOM_END;
