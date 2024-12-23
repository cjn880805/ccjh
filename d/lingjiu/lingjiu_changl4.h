//changl4.h

//Sample for room: ÁéðÕ»­ÀÈ4
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÁéðÕ»­ÀÈ4");


	add_door("ÁéðÕ»­ÀÈ8", "ÁéðÕ»­ÀÈ8", "ÁéðÕ»­ÀÈ4");
	add_door("ÁéðÕ»­ÀÈ3", "ÁéðÕ»­ÀÈ3", "ÁéðÕ»­ÀÈ4");
	add_door("ÁéðÕÏ··ï¸ó", "ÁéðÕÏ··ï¸ó", "ÁéðÕ»­ÀÈ4");


	

/*****************************************************
  set("exits",([
      "north" : __DIR__"changl3",
      "east" : __DIR__"liangong",
      "west" : __DIR__"changl8",
  ]));
********************************************/
};


ROOM_END;
