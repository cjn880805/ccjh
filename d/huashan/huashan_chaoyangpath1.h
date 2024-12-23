//chaoyangpath1.h

//Sample for room: 朝阳峰小路1
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_chaoyangpath1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "朝阳峰小路1");
	
	add_npc("pub_jianke");   //add by zdn 2001-07-20


	add_door("华山练武场", "华山练武场", "华山朝阳峰小路1");
	add_door("华山朝阳峰小路2", "华山朝阳峰小路2", "华山朝阳峰小路1");

	set("long", "这里是朝阳峰小路，山势陡峭，两边下临深谷，一不小心都会掉了下去。西面有一条小路，长草没径。");  
 
/*****************************************************
      set("outdoors", "xx");
      
      set("exits",([  
          "northeast": __DIR__"chaopath2",
          "southeast": __DIR__"square",
      ]));
********************************************/
};


ROOM_END;
