//landmeiyuan.h

//Sample for room: Œ‰µ±¿∆√∑‘∞
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_landmeiyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Œ‰µ±¿∆√∑‘∞");

	add_npc("wudang_shouyuan");	

	add_door("Œ‰µ±Ã´◊”—“", "Œ‰µ±Ã´◊”—“", "Œ‰µ±¿∆√∑‘∞");
	add_door("Œ‰µ±ƒœ—“∑Â", "Œ‰µ±ƒœ—“∑Â", "Œ‰µ±¿∆√∑‘∞");
	add_door("Œ‰µ±Œ⁄—ª¡Î", "Œ‰µ±Œ⁄—ª¡Î", "Œ‰µ±¿∆√∑‘∞");

    

/*****************************************************
      set("objects", ([
            CLASS_D("wudang") +"/shouyuan": 1,

      ]));
      set("exits",([  
          "northup"  : __DIR__"taiziyan",
          "southup"  : __DIR__"wuyaling",
          "westup"   : __DIR__"nanyanfeng",
      ]));
      ]));
*****************************************************/
};


ROOM_END;
