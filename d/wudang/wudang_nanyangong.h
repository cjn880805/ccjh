//nanyangong.h

//Sample for room: 南岩宫
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_nanyangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "南岩宫");

	add_door("武当石柱", "武当石柱", "武当南岩宫");
	add_door("武当南岩宫高台", "武当南岩宫高台", "武当南岩宫");

    

/*****************************************************
      set("exits",([ 
          "out"    : __DIR__"shizhu",
          "southup": __DIR__"gaotai",
      ]));
      set("item_desc",([
          "三清坐像" :       (: look_xiang :),
      ]));
*****************************************************/
};


ROOM_END;
