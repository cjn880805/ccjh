//mozhenjing.h

//Sample for room: 武当磨针井
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_mozhenjing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当磨针井");

	add_npc("wudang_yu");

	add_door("武当山路1", "武当山路1", "武当磨针井");

    
    set("resource/water", 1);

/*****************************************************
      set("exits",([ 
          "west"     : __DIR__"shanlu1",
      ]));
      set("item_desc",([ 
          "jing"     : "井沿古朴，水色悠蓝，可以装瓶饮用。\n",
      ]));
      set("outdoors", "wudang");
*****************************************************/
};


ROOM_END;
