//shanlu4.h

//Sample for room: �䵱ɽ·4
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_shanlu4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱ɽ·4");
	
//	add_npc("tiezhang_qqzhang");        //add by zdn 2001-07-20


	add_door("�䵱", "�䵱", "�䵱ɽ·4");
	add_door("�䵱", "�䵱", "�䵱ɽ·4");

    

/*****************************************************
      set("exits",([  
          "northdown": __DIR__"guangchang",
          "southup"  : __DIR__"taiziyan",
      ]));
*****************************************************/
};


ROOM_END;
