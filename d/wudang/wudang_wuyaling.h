//wuyaling.h

//Sample for room: 武当乌鸦岭
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_wuyaling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当乌鸦岭");


	add_door("武当榔梅园", "武当榔梅园", "武当乌鸦岭");
	add_door("武当三老峰", "武当三老峰", "武当乌鸦岭");

    

/*****************************************************
      set("objects", ([
                __DIR__"npc/wuya" : 5,
      ]));
      set("exits",([  
          "northdown": __DIR__"langmeiyuan",
          "southup"  : __DIR__"sanlaofeng",
      ]));
*****************************************************/
};


ROOM_END;
