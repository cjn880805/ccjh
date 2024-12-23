//taizipo.h

//Sample for room: 武当太子坡
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_taizipo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当太子坡");


	add_door("武当山路1", "武当山路1", "武当太子坡");
//	add_door("武当复真观", "武当复真观", "武当太子坡");
	add_door("武当石梁", "武当石梁", "武当太子坡");

	set("long","此处地处坡陀之隘，形势险要，相传净乐国太子(少年真武)入山修道时，曾在此留住读书，故名叫太子坡，好象一朵出水芙蓉，涌出绿波，瓣萼历历可数。远处峰回路转，忽明忽灭，尽在云雾之中。");
    

/*****************************************************
      set("exits",([  
          "northdown"  : __DIR__"shanlu1",
          "southdown"  : __DIR__"shiliang",
          "east"       : __DIR__"fuzhenguan",
      ]));
*****************************************************/
};


ROOM_END;
