//chufang.h

//Sample for room: ��ɽ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	//add npcs into the room
	add_npc("pub_girldizi");

	add_door("��ɽ��԰", "��ɽ��԰", "��ɽ����");

    set("long","���ǻ�ɽ�ɵĳ�����һλ��ɽСʦ�������շ����������������ŷ����㡣�������Сʦ��Ҫ(serve) Щ�Եĺȵġ�ǽ������һ������(note)��");
	set("ricewater", 5);
	set("no_fight","1");

/*****************************************************
	set("exits",([
		"east" : __DIR__"garden",
	]));
	set("item_desc",([
		"note" : "һ��һ������˼��֮���ס�\n",
	]));
	set("objects",([
		__DIR__"npc/girldizi" : 1,
	]));
//	
********************************************/
};


ROOM_END;
