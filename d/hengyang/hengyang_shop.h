//shop.h

//Sample for room: С��
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRHengYang_shop);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "С��");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	add_npc("pub3_xiejian");

	add_door("������", "������", "����С��");

/*****************************************************
	set("long", "�����Ǻ����سǵ�һ��С�꣬��Щ�򵥵���ʳ��ר��׬��Щ�ο͵�Ǯ�� " );
 	set("exits", ([
		"north" : __DIR__"hengyang1",
		"up"    : __DIR__"huiyan",
	]));
	set("objects", ([
	      __DIR__"npc/xiaoer2" : 1,
	]));

********************************************/
};


ROOM_END;
