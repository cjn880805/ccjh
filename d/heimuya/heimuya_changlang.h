//changlang.h

//Sample for room: 黑木崖长廊
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_changlang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖长廊");

	//add npcs into the room
	add_npc("heimuya_jiaotu");

	add_door("黑木崖白虎堂", "黑木崖白虎堂", "黑木崖长廊");
	add_door("黑木崖白虎堂大厅", "黑木崖白虎堂大厅", "黑木崖长廊");

	set("long", "这里是白虎堂的长廊。两边一片狼籍，看样子刚被洗劫一场，遍地横尸，残不忍睹。 ");
    

/*****************************************************
  set("exits",([
      "east" : __DIR__"dating2",
      "south" : __DIR__"baistep2",
  ]));
  set("objects",([
     __DIR__"npc/jiaotu"   :1,
  ]));
********************************************/
};


ROOM_END;
