//tyroad1.h

//Sample for room: �䵱ʯ��
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_tyroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱ʯ��");
	
	add_npc("tiezhang_gu");             //zdd by zdn 2001-07-20


	add_door("�䵱�㳡", "�䵱�㳡", "�䵱ʯ��");
	add_door("�䵱��԰С·8", "�䵱��԰С·8", "�䵱ʯ��");

    

/*****************************************************
	set("outdoors", "wudang");
	set("exits", ([
		"westup" : __DIR__"guangchang",
		"east" : __DIR__"tyroad8",
	]));
*****************************************************/
};


ROOM_END;
