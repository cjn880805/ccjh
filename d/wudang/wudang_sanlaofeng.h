//sanlaofeng.h

//Sample for room: 武当三老峰
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_sanlaofeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当三老峰");
	add_npc("pub_xucong");

	add_door("武当乌鸦岭", "武当乌鸦岭", "武当三老峰");
	add_door("武当五老峰", "武当五老峰", "武当三老峰");

    

/*****************************************************
      set("exits",([  
          "northdown": __DIR__"wuyaling",
          "southup"  : __DIR__"wulaofeng",
      ]));
*****************************************************/
};


ROOM_END;
