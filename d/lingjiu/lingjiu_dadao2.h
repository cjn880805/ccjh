//dadao2.h

//Sample for room: ������ʯ���2
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_dadao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���2");

	//add npcs into the room
	add_npc("lingjiu_songshu");/////////////////////////

	add_door("������ʯ���1", "������ʯ���1", "������ʯ���2");
	add_door("���ն���������", "���ն���������", "������ʯ���2");



/*****************************************************
   set("outdoors", "lingjiu");
  set("exits",([
      "north" : __DIR__"damen",
      "south" : __DIR__"dadao1",
  ]));
  set("objects",([
      __DIR__"npc/songshu" : 2,
  ]));
********************************************/
};


ROOM_END;
