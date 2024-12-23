//shanlu1.h

//Sample for room: 武当山路1
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_shanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当山路1");
	
//	add_npc("tiezhang_sgjn");        //add by zdn 2001-07-20


	add_door("武当好汉坡", "武当好汉坡", "武当山路1");
	add_door("武当磨针井", "武当磨针井", "武当山路1");
	add_door("武当太子坡", "武当太子坡", "武当山路1");

	
    set("resource/water", 1);

/*****************************************************
      set("exits",([  
          "northup"  : __DIR__"haohanpo",
          "southup"  : __DIR__"taizipo",
          "east"     : __DIR__"mozhenjing",
      ]));
*****************************************************/
};


ROOM_END;
