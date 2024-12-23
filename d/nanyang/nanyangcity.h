//nanyangcity.h

//Sample for room:  南阳城
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
RESIDENT_BEGIN(CRnanyangcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "南阳城");

	if(random(2))
		add_npc("pub_playboy");

	set("resident", "南阳");
	set("capacity", 5);
				
	add_npc("pub_hongxian");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");

	add_door("黄河岸边5", "黄河岸边5", "南阳城");
	add_door("北京汝州城", "北京汝州城", "南阳城");

	add_door("南阳迎宾楼", "南阳迎宾楼", "南阳城");
	add_door("南阳悦来客栈", "南阳悦来客栈", "南阳城");
/********************************************************
	set("long", @LONG
这里便是当年诸葛先生的故居。南阳城不大，因为地出要冲，
南来北往的客人特别多，所以也五脏俱全，酒楼，客栈，马店，
满城子都是。本地人口甚少，到处都是行色匆匆的江湖客人。
LONG );
	set("exits", ([
		"south" : __DIR__"hanshui2",
		"north" : __DIR__"yidao3",
		"east" : __DIR__"kedian1",
		"west" : __DIR__"jiulou1",
	]));
	set("objects",([
		__DIR__"npc/xiao-fan" : 1,
	]));
	set("outdoors", "shaolin");
****************************************************************/
};


RESIDENT_END;
