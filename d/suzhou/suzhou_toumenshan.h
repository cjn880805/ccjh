//toumenshan.h

//Sample for room: ͷ��ɽ
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_toumenshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ͷ��ɽ");

	//add npcs into the room
	add_npc("pub_jianke");/////////////////////////

	add_door("���ݻ���ɽ", "���ݻ���ɽ", "����ͷ��ɽ");
	add_door("������ɽׯ", "������ɽׯ", "����ͷ��ɽ");


/*****************************************************
	set("exits", ([
		"north" : __DIR__"huqiu",
		"west"  : __DIR__"wanjing",
	]));
        set("objects", ([
		"/d/taishan/npc/jian-ke" : 1,
	]));
********************************************/
};


ROOM_END;
