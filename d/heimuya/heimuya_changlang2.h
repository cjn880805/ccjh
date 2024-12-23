//changlang2.h

//Sample for room: 黑木崖长廊2
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_changlang2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖长廊2");
	
	add_npc("heimuya_jiaotu");  //add by zdn 2001-07-20


	add_door("黑木崖青龙堂", "黑木崖青龙堂", "黑木崖长廊2");
	add_door("黑木崖青龙堂大厅", "黑木崖青龙堂大厅", "黑木崖长廊2");

	set("long", "这里是非常气派的长廊。但是却没什么人在这里，南边是青龙堂的大厅。 ");
    set("no_fight",0l);
    set("no_steal",0l);
    
 
/*****************************************************
  set("exits",([
      "north" : __DIR__"chlang1",
      "south" : __DIR__"qing",
  ]));			   
  set("objects",([
      __DIR__"npc/shinu1"   :1,
  ]));
********************************************/
};


ROOM_END;
