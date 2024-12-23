//jinding.h

//Sample for room: 武当金顶
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_jinding);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当金顶");


	add_door("武当三天门", "武当三天门", "武当金顶");
	add_door("武当十二莲台", "武当十二莲台", "武当金顶");
	add_door("武当紫金城", "武当紫金城", "武当金顶");

    

/*****************************************************
      set("exits",([ 
          "northdown": __DIR__"santiangate",
          "south"    : __DIR__"zijincheng",
          "west"     : __DIR__"shierliantai",
      ]));
*****************************************************/
};


ROOM_END;
