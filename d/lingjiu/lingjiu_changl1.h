//changl1.h

//Sample for room: ÁéğÕ»­ÀÈ1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÁéğÕ»­ÀÈ1");


	add_door("ÁéğÕ»­ÀÈ5", "ÁéğÕ»­ÀÈ5", "ÁéğÕ»­ÀÈ1");
	add_door("ÁéğÕ»¨Ô°", "ÁéğÕ»¨Ô°", "ÁéğÕ»­ÀÈ1");


	

/*****************************************************
  set("exits",([
      "west" : __DIR__"changl5",
      "east" : __DIR__"huayuan",
     ]));
********************************************/
};


ROOM_END;
