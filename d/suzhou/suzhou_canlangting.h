//canlangting.h

//Sample for room: ����ͤ
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_canlangting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ͤ");
	
	add_npc("pub_jianke");         //add by zdn 2001-07-16


	add_door("����", "����", "���ݲ���ͤ");

	set("outdoors", "suzhou");
	
/*****************************************************
	set("item_desc", ([
		"lian" :
"������±��޼� ��ˮԶɽ������\n",
	]));
	set("exits", ([
		"southeast" : __DIR__"dongdajie1",
		"southwest" : __DIR__"xidajie1",
		"north"     : __DIR__"beidajie1",
		"south"     : __DIR__"baodaiqiao",
	]));

********************************************/
};


ROOM_END;
