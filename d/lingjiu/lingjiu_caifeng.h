//caifeng.h

//Sample for room: äìÏæ¹İ
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_caifeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "äìÏæ¹İ");

	add_npc("lingjiu_fu");

	add_door("ÁéğÕ»­ÀÈ10", "ÁéğÕ»­ÀÈ10", "ÁéğÕäìÏæ¹İ");

	

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
