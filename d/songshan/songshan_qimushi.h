//qimushi.h

//Sample for room: ��ĸʯ
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_qimushi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ĸʯ");
	
	add_npc("pub_caishiren");      //zdd by zdn 2001-07-15


	add_door("��ɽɽ��1", "��ɽɽ��1", "��ɽ��ĸʯ");
	add_door("��ɽ��ĸ��", "��ɽ��ĸ��", "��ɽ��ĸʯ");
	add_door("��ɽɽ��2", "��ɽɽ��2", "��ɽ��ĸʯ");

	

/*****************************************************
	set("exits", ([
		"southeast" : __DIR__"shandao1",
		"west"      : __DIR__"qimuque",
		"northup"   : __DIR__"shandao2",
	]));
********************************************/
};


ROOM_END;
