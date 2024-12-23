//changl6.h

//Sample for room: ÁéğÕ»­ÀÈ6
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÁéğÕ»­ÀÈ6");


	add_door("ÁéğÕ»­ÀÈ7", "ÁéğÕ»­ÀÈ7", "ÁéğÕ»­ÀÈ6");
	add_door("ÁéğÕ»­ÀÈ5", "ÁéğÕ»­ÀÈ5", "ÁéğÕ»­ÀÈ6");
	add_door("ÁéğÕÅºÏãé¿", "ÁéğÕÅºÏãé¿", "ÁéğÕ»­ÀÈ6");


	

/*****************************************************
  set("exits",([
      "north" : __DIR__"changl5",
      "west" : __DIR__"chufang",
      "east" : __DIR__"changl7",
  ]));
********************************************/
};


ROOM_END;
