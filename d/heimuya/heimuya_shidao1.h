//shidao1.h

//Sample for room: ��ľ��ʯ��1
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shidao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ��ʯ��1");
	
	add_npc("heimuya_zishan");     // add by zdn 2001-07-20


	add_door("��ľ��ʯ��2", "��ľ��ʯ��2", "��ľ��ʯ��1");
	add_door("��ľ��ɽ��", "��ľ��ɽ��", "��ľ��ʯ��1");

};


ROOM_END;
