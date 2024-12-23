//jindian.h

//Sample for room: 金殿
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_jindian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "金殿");


	add_door("武当紫金城", "武当紫金城", "武当金殿");


/*****************************************************
      set("exits",([ 
          "north"     : __DIR__"zijincheng",
      ]));
      
*****************************************************/
};


ROOM_END;
