//taiziyan.h

//Sample for room: 武当太子岩
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_taiziyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当太子岩");


	add_door("武当广场", "武当广场", "武当太子岩");
	add_door("武当榔梅园", "武当榔梅园", "武当太子岩");

    	

/*****************************************************
      set("exits",([  
           "northdown":__DIR__"shanlu4",
          "southdown": __DIR__"langmeiyuan",
      ]));
*****************************************************/
};


ROOM_END;
