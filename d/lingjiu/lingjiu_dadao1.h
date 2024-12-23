//dadao1.h

//Sample for room: 灵鹫青石大道1
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_dadao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫青石大道1");

	//add npcs into the room
	add_npc("lingjiu_songshu");/////////////////////////

	add_door("灵鹫仙愁门", "灵鹫仙愁门", "灵鹫青石大道1");
	add_door("灵鹫青石大道2", "灵鹫青石大道2", "灵鹫青石大道1");


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
