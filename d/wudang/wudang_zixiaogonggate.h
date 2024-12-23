//zixiaogonggate.h

//Sample for room: 武当紫霄宫大门
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_zixiaogonggate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当紫霄宫大门");


	add_door("武当十八盘", "武当十八盘", "武当紫霄宫大门");
	add_door("武当广场", "武当广场", "武当紫霄宫大门");

    

/*****************************************************
      set("exits",([  
          "northdown"  : __DIR__"shijie2",
          "southup"    : __DIR__"guangchang",
      ]));
      set("outdoors", "wudang");
*****************************************************/
};


ROOM_END;
