//duchang.h

//Sample for room: �ĳ�
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_duchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ĳ�");

	add_npc("pub_baoqinguang");

	add_door("��������", "��������", "�����ĳ�");

};


ROOM_END;
