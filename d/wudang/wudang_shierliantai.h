//shierliantai.h

//Sample for room: 武当十二莲台
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_shierliantai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当十二莲台");


	add_door("武当金顶", "武当金顶", "武当十二莲台");

    

/*****************************************************
      set("exits",([  
          "east"     : __DIR__"jinding",
      ]));
*****************************************************/
};


ROOM_END;
