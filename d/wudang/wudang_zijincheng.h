//zijincheng.h

//Sample for room: 武当紫金城
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_zijincheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当紫金城");


	add_door("武当金顶", "武当金顶", "武当紫金城");
	add_door("武当金殿", "武当金殿", "武当紫金城");

    

/*****************************************************
       set("exits",([  
          "north"     : __DIR__"jinding",
          "south"     : __DIR__"jindian",
      ]));
*****************************************************/
};


ROOM_END;
