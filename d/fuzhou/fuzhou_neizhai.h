//neizhai.h

//Sample for room: �����ھ���լ
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_neizhai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ھ���լ");

	add_npc("pub_lady3");   // add by zdn 2001-07-13
	add_npc("fuzhou_wang");   //add by zdn 2001-07-20

	add_door("���ݸ����ھ�����", "���ݸ����ھ�����", "���ݸ����ھ���լ");


};


ROOM_END;
