//jiuguan.h

//Sample for room: �ƹ�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_jiuguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƹ�");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////

	add_door("������", "������", "���ݾƹ�");

};


ROOM_END;
