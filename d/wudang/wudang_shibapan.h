//shibapan.h

//Sample for room: 武当十八盘
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_shibapan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当十八盘");


	add_door("武当石梁", "武当石梁", "武当十八盘");
	add_door("武当紫霄宫大门", "武当紫霄宫大门", "武当十八盘");

    	

/*****************************************************
      set("exits",([  
          "northdown"  : __DIR__"shiliang",
          "southup"    : __DIR__"shijie2",
      ]));
*****************************************************/
};


ROOM_END;
