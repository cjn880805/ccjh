//ertiangate.h

//Sample for room: 武当二天门
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_ertiangate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当二天门");


	add_door("武当头天门", "武当头天门", "武当二天门");
	add_door("武当三天门", "武当三天门", "武当二天门");

    

/*****************************************************
      set("exits",([  
          "northdown": __DIR__"toutiangate",
          "southup"  : __DIR__"santiangate",
      ]));
*****************************************************/
};


ROOM_END;
