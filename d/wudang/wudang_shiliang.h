//shiliang.h

//Sample for room: 武当石梁
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_shiliang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当石梁");


	add_door("武当太子坡", "武当太子坡", "武当石梁");
	add_door("武当小吃店", "武当小吃店", "武当石梁");
	add_door("武当十八盘", "武当十八盘", "武当石梁");

   	

/*****************************************************
      set("exits",([  
          "northup"    : __DIR__"taizipo",
          "southup"    : __DIR__"shibapan",
          "east"       : __DIR__"shop",
      ]));
*****************************************************/
};


ROOM_END;
