//changl3.h

//Sample for room: ÁéğÕ»­ÀÈ3
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÁéğÕ»­ÀÈ3");


	add_door("ÁéğÕ»­ÀÈ2", "ÁéğÕ»­ÀÈ2", "ÁéğÕ»­ÀÈ3");
	add_door("ÁéğÕ»­ÀÈ4", "ÁéğÕ»­ÀÈ4", "ÁéğÕ»­ÀÈ3");
	add_door("ÁéğÕí¬·ï¸ó", "ÁéğÕí¬·ï¸ó", "ÁéğÕ»­ÀÈ3");
	add_door("ÁéğÕ»­ÀÈ10", "ÁéğÕ»­ÀÈ10", "ÁéğÕ»­ÀÈ3");


	

/*****************************************************
   set("exits",([
      "east" : __DIR__"restroom",
      "west" : __DIR__"changl2",
      "north" : __DIR__"changl10",
      "south" : __DIR__"changl4",
  ]));
********************************************/
};


ROOM_END;
