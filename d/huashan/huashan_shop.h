//shop.h

//Sample for room: ɽ��С��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_shop);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ��С��");

	//add npcs into the room
	add_npc("pub_xiaoer2");

	add_door("��ɽ���䳡", "��ɽ���䳡", "��ɽɽ��С��");

	set("long", "�����ǻ�ɽɽ����һ��С�꣬��Щ�򵥵���ʳ��ר��׬��Щ�ο͵�Ǯ��");  

/*****************************************************
	set("exits", ([
		"east" : __DIR__"square",
	]));
//	
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));
********************************************/
};


ROOM_END;
