//tianzhongge.h

//Sample for room: ���и�
//coded by zouwenbin
//data: 2000-11-

ROOM_BEGIN(CRShongShan_tianzhongge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���и�");

	//add npcs into the room
	add_npc("songshan_lu");         //add by zdn 2001-07-20

	add_door("��ɽ̫����", "��ɽ̫����", "��ɽ���и�");
	add_door("��ɽ��ʥ��", "��ɽ��ʥ��", "��ɽ���и�");

	set("long", "���и���������Ĵ��ţ�ԭ�ƻ��и������йŰ��������꣬��ʯ���ٰ���������ǰʯ���٣����ƹ��ӡ���������ɽ�ĳ���̫���ڡ� " );
	

/*****************************************************
	set("outdoors","songshan");
	set("exits", ([
		"north" : __DIR__"chongsheng",
		"south" : __DIR__"taishique",
	]));
	setup();
********************************************/
};


ROOM_END;
