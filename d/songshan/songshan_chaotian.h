//chaotian.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_chaotian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("pub_jianke");           //add by zdn 2001-07-15 
	add_npc("songshan_sha");         //add by zdn 2001-07-20 


	add_door("��ɽɽ��5", "��ɽɽ��5", "��ɽ������");
	add_door("��ɽɽ��6", "��ɽɽ��6", "��ɽ������");

	

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"shandao6",
		"southdown" : __DIR__"shandao5",
	]));
********************************************/
};


ROOM_END;
