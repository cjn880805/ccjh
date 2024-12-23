//haohanpo.h

//Sample for room: 武当好汉坡
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_haohanpo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当好汉坡");
	add_npc("pub_songlingong");

	add_door("武当柏林", "武当柏林", "武当好汉坡");
	add_door("武当山路1", "武当山路1", "武当好汉坡");

	
    set("resource/water", 1);

/*****************************************************
      set("exits",([  
          "northdown": __DIR__"wdbl",
          "southdown": __DIR__"shanlu1",
      ]));
*****************************************************/
};


ROOM_END;
