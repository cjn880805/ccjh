//xngxingtan.h

//Sample for room: ��ľ������̲
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_xngxingtan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ������̲");
	
	add_npc("pub_punk");               //add by zdn 2001-07-14


	add_door("��ľ��ʯ��2", "��ľ��ʯ��2", "��ľ������̲");
	add_door("��ľ�³�̲", "��ľ�³�̲", "��ľ������̲");

};


ROOM_END;
