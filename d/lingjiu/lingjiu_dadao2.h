//dadao2.h

//Sample for room: 灵鹫青石大道2
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_dadao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫青石大道2");

	//add npcs into the room
	add_npc("lingjiu_songshu");/////////////////////////

	add_door("灵鹫青石大道1", "灵鹫青石大道1", "灵鹫青石大道2");
	add_door("灵鹫独尊厅大门", "灵鹫独尊厅大门", "灵鹫青石大道2");



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
