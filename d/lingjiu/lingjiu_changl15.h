//changl15.h

//Sample for room: ÁéğÕ»­ÀÈ15
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl15);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÁéğÕ»­ÀÈ15");


	add_door("ÁéğÕ»¨Ô°", "ÁéğÕ»¨Ô°", "ÁéğÕ»­ÀÈ15");
	add_door("ÁéğÕ¶À×ğÌü", "ÁéğÕ¶À×ğÌü", "ÁéğÕ»­ÀÈ15");
	add_door("ÁéğÕ»­ÀÈ7", "ÁéğÕ»­ÀÈ7", "ÁéğÕ»­ÀÈ15");
	add_door("ÁéğÕ»­ÀÈ8", "ÁéğÕ»­ÀÈ8", "ÁéğÕ»­ÀÈ15");

	

/*****************************************************
  set("exits",([
      "west" : __DIR__"changl7",
      "east" : __DIR__"changl8",
      "south" : __DIR__"dating",
      "north" : __DIR__"huayuan",
  ]));
********************************************/
};


ROOM_END;
