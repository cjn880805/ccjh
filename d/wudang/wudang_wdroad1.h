//wdroad1.h

//Sample for room: ��ʯ���1
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_wdroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ʯ���1");
	
//	add_npc("tiezhang_mayi");             //zdd by zdn 2001-07-20


	add_door("�䵱������", "�䵱������", "�䵱��ʯ���1");
	add_door("�䵱����", "�䵱����", "�䵱��ʯ���1");


    

/*****************************************************
    set("outdoors", "wudang");
	set("exits", ([
		"south"     : __DIR__"wdroad2",
		"north"     : "/d/city/nanmen",
	]));
*****************************************************/
};


ROOM_END;
