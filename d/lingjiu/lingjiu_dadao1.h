//dadao1.h

//Sample for room: ������ʯ���1
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_dadao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���1");

	//add npcs into the room
	add_npc("lingjiu_songshu");/////////////////////////

	add_door("�����ɳ���", "�����ɳ���", "������ʯ���1");
	add_door("������ʯ���2", "������ʯ���2", "������ʯ���1");


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
