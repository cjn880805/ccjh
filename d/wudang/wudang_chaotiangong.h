//chaotiangong.h

//Sample for room: 武当朝天宫
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_chaotiangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当朝天宫");

	add_npc("wudang_qingxu");	

	add_door("武当虎头岩", "武当虎头岩", "武当朝天宫");
	add_door("武当会仙桥", "武当会仙桥", "武当朝天宫");


/*****************************************************
      set("objects", ([
           CLASS_D("wudang") +"/qingxu": 1,
      ]));

      set("exits",([  
          "northdown": __DIR__"hutouyan",
          "south"    : __DIR__"huixianqiao",
      ]));
*****************************************************/
};


ROOM_END;
