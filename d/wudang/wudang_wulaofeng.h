//wulaofeng.h

//Sample for room: 武当五老峰
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_wulaofeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当五老峰");


	add_door("武当三老峰", "武当三老峰", "武当五老峰");
	add_door("武当虎头岩", "武当虎头岩", "武当五老峰");

    

/*****************************************************
      set("exits",([  
          "northdown": __DIR__"sanlaofeng",
          "southup"  : __DIR__"hutouyan",
      ]));
      set("outdoors", "wudang");
*****************************************************/
};


ROOM_END;
