//shandao4.h

//Sample for room: ɽ��4
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_shandao4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ��4");
	
	add_npc("pub_xianghuo");              // add by zdn 2001-07-15


	add_door("��ɽ������", "��ɽ������", "��ɽɽ��4");
	add_door("��ɽ������", "��ɽ������", "��ɽɽ��4");

	

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"fawangsi",
		"southeast" : __DIR__"songyuesi",
	]));
********************************************/
};


ROOM_END;
