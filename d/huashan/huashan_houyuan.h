//houyuan.h

//Sample for room: 华山后院
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_houyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山后院");
	
	add_npc("pub_lady3");           //add by zdn 2001-07-17

	add_door("华山花园", "华山花园", "华山后院");
	add_door("华山假山小池", "华山假山小池", "华山后院");

	set("long", "这里是华山派的后院，里面是华山弟子的居室和练功房。华山派总所倚山而建，地势险峻，往东便是悬崖。西面是另一个小花院，有假山小池，景色怡人，颇有江南林园的特色。");  
    
 
/*****************************************************
	set("exits",([
		"northeast"  : __DIR__"garden",
		"west"       : __DIR__"jiashan",
		"east"       : __DIR__"xuanya",
	]));
********************************************/
};


ROOM_END;
