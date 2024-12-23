//shizhu.h

//Sample for room: 武当石柱
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_shizhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当石柱");


	add_door("武当南岩峰", "武当南岩峰", "武当石柱");
	add_door("武当南岩宫", "武当南岩宫", "武当石柱");

    	

/*****************************************************
      set("exits",([  
          "northup"  : __DIR__"nanyanfeng",
          "enter"    : __DIR__"nanyangong",
      ]));
*****************************************************/
};


ROOM_END;
