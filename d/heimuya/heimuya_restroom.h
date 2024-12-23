//restroom.h

//Sample for room: 休息室
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_restroom);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "休息室");


	add_door("黑木崖成德殿", "黑木崖成德殿", "黑木崖休息室");

	set("long", "这里是间休息室，里面有张大床。在这里睡觉非常舒服，没人能打扰。南面是气派的长廊。 ");
    set("sleep_room", 1);
    set("no_fight",1);
    set("no_steal",1);
    

/*****************************************************
  set("exits",([
      "east" : __DIR__"huoting",
  ]));

********************************************/
};


ROOM_END;
