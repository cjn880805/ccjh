//kongdi.h

//Sample for room: ���пյ�
//coded by zouwenbin
//data: 2000-11-21

ROOM_BEGIN(CRLingZhou_kongdi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���пյ�");

	//add npcs into the room
//	add_npc("animal_wolfdog");/////////////////////////

        add_npc("animal_dushe");        //add by zdn 2001-07-14

	add_door("����������·", "����������·", "�������пյ�");
	add_door("�������д���", "�������д���", "�������пյ�");
	add_door("��������Ȫ", "��������Ȫ", "�������пյ�");

};


ROOM_END;
