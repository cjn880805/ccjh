//shanlu4.h

//Sample for room: 武当山路4
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_shanlu4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当山路4");
	
//	add_npc("tiezhang_qqzhang");        //add by zdn 2001-07-20


	add_door("武当", "武当", "武当山路4");
	add_door("武当", "武当", "武当山路4");

    

/*****************************************************
      set("exits",([  
          "northdown": __DIR__"guangchang",
          "southup"  : __DIR__"taiziyan",
      ]));
*****************************************************/
};


ROOM_END;
