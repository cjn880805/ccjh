//liangong.h

//Sample for room: ÁéðÕÏ··ï¸ó
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_liangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÁéðÕÏ··ï¸ó");

	//add npcs into the room
	add_npc("lingjiu_fu");/////////////////////////

	
	add_door("ÁéðÕ»­ÀÈ4", "ÁéðÕ»­ÀÈ4", "ÁéðÕÏ··ï¸ó");



/*****************************************************
  set("exits",([
      "west" : __DIR__"changl4",
  ]));
  set("objects",([
          "/d/shaolin/npc/mu-ren" : 5
  ]));
********************************************/
};


ROOM_END;
