//santiangate.h

//Sample for room: 武当三天门
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_santiangate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当三天门");


	add_door("武当二天门", "武当二天门", "武当三天门");
	add_door("武当金顶", "武当金顶", "武当三天门");

    

/*****************************************************
      set("exits",([  
          "northdown": __DIR__"ertiangate",
          "southup"  : __DIR__"jinding",
      ]));
*****************************************************/
};


ROOM_END;
