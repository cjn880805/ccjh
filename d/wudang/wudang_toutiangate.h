//toutiangate.h

//Sample for room: 武当头天门
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_toutiangate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当头天门");


	add_door("武当会仙桥", "武当会仙桥", "武当头天门");
	add_door("武当二天门", "武当二天门", "武当头天门");

    

/*****************************************************
      set("exits",([  
          "north"    : __DIR__"huixianqiao",
          "southup"  : __DIR__"ertiangate",
      ]));
*****************************************************/
};


ROOM_END;
