//hutouyan.h

//Sample for room: 武当虎头岩
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_hutouyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当虎头岩");


	add_door("武当五老峰", "武当五老峰", "武当虎头岩");
	add_door("武当朝天宫", "武当朝天宫", "武当虎头岩");


/*****************************************************
      set("objects", ([
          __DIR__"npc/laohu" : 1,
      ]));
      set("exits",([  
          "northdown": __DIR__"wulaofeng",
          "southup"  : __DIR__"chaotiangong",
      ]));
*****************************************************/
};


ROOM_END;
