//luorilin1.h

//Sample for room: ����������1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_luorilin1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������1");
	
	add_npc("monster_8k");        //add by zdn 2001-07-14


	add_door("���ݶ�", "���ݶ�", "����������1");
	add_door("�������д�·1", "�������д�·1", "����������1");

};


ROOM_END;
