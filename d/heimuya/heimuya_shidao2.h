//shidao2.h

//Sample for room: ��ľ��ʯ��2
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shidao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ��ʯ��2");
	
	add_npc("heimuya_zishan");       //add by zdn 2001-07-20


	add_door("��ľ��ʯ��1", "��ľ��ʯ��1", "��ľ��ʯ��2");
	add_door("��ľ������̲", "��ľ������̲", "��ľ��ʯ��2");

};


ROOM_END;
