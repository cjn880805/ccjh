//huanyuan.h

//Sample for room: 灵鹫花园
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_huanyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫花园");

	//add npcs into the room
	add_npc("lingjiu_zhang");
	add_npc("lingjiu_lu");
	add_npc("lingjiu_yu");
	add_npc("wuji");
	add_item("jiashan");

	add_door("灵鹫画廊15", "灵鹫画廊15", "灵鹫花园");
	add_door("灵鹫画廊1", "灵鹫画廊1", "灵鹫花园");
	add_door("灵鹫画廊2", "灵鹫画廊2", "灵鹫花园");
	add_door("灵鹫小道1", "灵鹫小道1", "灵鹫花园");


/*****************************************************
  set("exits",([
      "west" : __DIR__"changl1",
      "north" : __DIR__"xiaodao1",
      "east" : __DIR__"changl2",
      "south" : __DIR__"changl15",
  ]));
  set("outdoors", "lingjiu");
  set("item_desc", ([
      "jiashan" : "这座假山看起来不算太大，你应该可以搬动(move)它.\n",
  ]));
  set("objects",([
      __DIR__"npc/lu" : 1,
      __DIR__"npc/zhang" : 1,
  ]));
********************************************/
};


ROOM_END;
