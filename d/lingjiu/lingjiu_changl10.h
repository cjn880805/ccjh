//changl10.h

//Sample for room: ÁéğÕ»­ÀÈ10
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÁéğÕ»­ÀÈ10");

	add_npc("pub_yejun");
	add_door("ÁéğÕ»­ÀÈ3", "ÁéğÕ»­ÀÈ3", "ÁéğÕ»­ÀÈ10");
	add_door("ÁéğÕ»­ÀÈ13", "ÁéğÕ»­ÀÈ13", "ÁéğÕ»­ÀÈ10");
	add_door("ÁéğÕäìÏæ¹İ", "ÁéğÕäìÏæ¹İ", "ÁéğÕ»­ÀÈ10");
	add_door("ÁéğÕ»­ÀÈ14", "ÁéğÕ»­ÀÈ14", "ÁéğÕ»­ÀÈ10");


	

/*****************************************************
  set("exits",([
      "east" : __DIR__"changl14",
      "west" : __DIR__"changl13",
      "south" : __DIR__"changl3",
      "north" : __DIR__"caifeng",
  ]));
********************************************/
};


ROOM_END;
