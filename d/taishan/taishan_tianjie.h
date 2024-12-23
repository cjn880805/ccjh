//tianjie.h

//Sample for room: 泰山天街
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRTaiShan_tianjie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山天街");
	
	add_npc("taishan_yuqingzi");      //add by zdn 2001-07-20

	add_door("泰山南天门", "泰山南天门", "泰山天街");
	add_door("泰山莲花峰", "泰山莲花峰", "泰山天街");
	add_door("泰山围屏山", "泰山围屏山", "泰山天街");

	

/*****************************************************
	set("exits", ([
		"westdown" : __DIR__"nantian",
		"eastup" : __DIR__"weipin",
		"eastdown" : __DIR__"lianhua",
	]));
	set("objects",([
		__DIR__"npc/xiao-fan" : 2,
		__DIR__"npc/tiao-fu" : 1,
	]));
*****************************************************/
};


ROOM_END;
