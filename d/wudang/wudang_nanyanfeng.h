//nanyanfeng.h

//Sample for room: 武当南岩峰
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_nanyanfeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当南岩峰");

	add_npc("wudang_mo");
	add_npc("wudang_xiaosong");

	add_door("武当石柱", "武当石柱", "武当南岩峰");
	add_door("武当舍身崖", "武当舍身崖", "武当南岩峰");
	add_door("武当榔梅园", "武当榔梅园", "武当南岩峰");

    

/*****************************************************
      set("objects", ([
           CLASS_D("wudang") +"/mo": 1,
      ]));

      set("exits",([  
          "eastdown" : __DIR__"langmeiyuan",
          "southdown": __DIR__"shizhu",
          "west"     : __DIR__"sheshenya",
      ]));
*****************************************************/
};


ROOM_END;
