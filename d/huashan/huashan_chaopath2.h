//chaopath2.h

//Sample for room: 朝阳峰小路2
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_chaopath2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "朝阳峰小路2");
	
	add_npc("pub_daoke");        //add by zdn 2001-07-17


	add_door("华山朝阳峰小路1", "华山朝阳峰小路1", "华山朝阳峰小路2");
	add_door("华山朝阳峰", "华山朝阳峰", "华山朝阳峰小路2");
	add_door("华山紫气台", "华山紫气台", "华山朝阳峰小路2");

	set("long", "这里是朝阳峰小路，山势陡峭，两边下临深谷，一不小心都会掉了下去。西面有一条小路，长草没径。");  
 
/*****************************************************
      set("outdoors", "xx");
      set("exits",([  
          "southwest": __DIR__"chaopath1",
          "eastup"   : __DIR__"chaoyang",
          "westup"   : __DIR__"ziqitai",
      ]));
//      
      set("objects", ([
          __DIR__"npc/shi-daizi" : 1,
      ]));
********************************************/
};


ROOM_END;
