//shandao5.h

//Sample for room: ɽ��5
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_shandao5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ��5");
	
	add_npc("pub_caiyaoren");         //add by zdn 2001-07-15


	add_door("��ɽ������", "��ɽ������", "��ɽɽ��5");
	add_door("��ɽ����Ͽ", "��ɽ����Ͽ", "��ɽɽ��5");
	add_door("��ɽ������", "��ɽ������", "��ɽɽ��5");

	

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"chaotian",
		"southwest" : __DIR__"fawangsi",
		"southdown" : __DIR__"tieliang",
	]));
********************************************/
};


ROOM_END;
