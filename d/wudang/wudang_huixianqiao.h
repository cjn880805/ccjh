//huixianqiao.h

//Sample for room: 武当会仙桥
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_huixianqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当会仙桥");

	add_npc("pub_yuzhuzi");
	add_door("武当朝天宫", "武当朝天宫", "武当会仙桥");
	add_door("武当头天门", "武当头天门", "武当会仙桥");

    

/*****************************************************
      set("exits",([  
          "north"    : __DIR__"chaotiangong",
          "south"    : __DIR__"toutiangate",
      ]));
*****************************************************/
};


ROOM_END;
