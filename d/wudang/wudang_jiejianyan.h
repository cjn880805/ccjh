//jiejianyan.h

//Sample for room: 武当解剑岩
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_jiejianyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当解剑岩");

	add_npc("wudang_shan");
	add_npc("zm_wudang");

	add_door("武当松林", "武当松林", "武当解剑岩");
	add_door("武当玄岳门", "武当玄岳门", "武当解剑岩");

	set("long","这是武林中极负盛名的武当解剑岩，岩下解剑池水明澈照人。武林人士经此都自觉解剑，以示对武当派的尊敬。千百年来，概无例外。"); 
 
/*****************************************************
      set("objects", ([
           CLASS_D("wudang") +"/shan": 1,
      ]));
      set("outdoors", "wudang");
      set("exits",([  
          "eastdown"  : __DIR__"slxl2",
          "westup"    : __DIR__"slxl3",
      ]));
*****************************************************/
};


ROOM_END;
