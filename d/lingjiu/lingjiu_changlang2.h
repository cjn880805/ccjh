//changlang2.h

//Sample for room: ÁéğÕ»­ÀÈ2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changlang2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÁéğÕ»­ÀÈ2");


	add_door("ÁéğÕ»­ÀÈ3", "ÁéğÕ»­ÀÈ3", "ÁéğÕ»­ÀÈ2");
	add_door("ÁéğÕ»¨Ô°", "ÁéğÕ»¨Ô°", "ÁéğÕ»­ÀÈ2");


	

/*****************************************************
  set("exits",([
      "east" : __DIR__"changl3",
      "west" : __DIR__"huayuan",
  ]));
********************************************/
};


ROOM_END;
