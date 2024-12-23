//zuixianlou.h

//Sample for room: ����¥
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_zuixianlou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����¥");

	//add npcs into the room
	add_npc("pub_xiaoer");
	add_npc("pub_xian");
	
	add_npc("pub3_taozhixian");
	add_npc("pub3_taoyexian");
	add_npc("pub3_taoshixian");
	add_npc("pub3_taohuaxian");
	add_npc("pub3_taogenxian");
	add_npc("pub3_taoganxian");

			

	add_door("���ݶ���", "���ݶ���", "��������¥");

/*****************************************************
	set("exits", ([
		"west" : __DIR__"beidajie2",
		"up" : __DIR__"zuixianlou2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
********************************************/
};


ROOM_END;
