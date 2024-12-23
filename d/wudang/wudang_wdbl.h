//wdbl.h

//Sample for room: 武当柏林
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_wdbl);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当柏林");
	
//	add_npc("tiezhang_heiyi");             //zdd by zdn 2001-07-20


	add_door("武当遇真宫", "武当遇真宫", "武当柏林");
	add_door("武当好汉坡", "武当好汉坡", "武当柏林");

 
/*****************************************************
      set("objects", ([
          __DIR__"npc/yetu" : 2,
      ]));
      set("outdoors", "wudang");
      set("exits",([  
          "northdown": __DIR__"yuzhengong",
          "southup"  : __DIR__"haohanpo",
      ]));
*****************************************************/
};


ROOM_END;
