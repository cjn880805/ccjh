//hengyangcity.h

//Sample for room:  衡阳城
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRhengyangcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡阳城");

	//add npcs into the room
	add_npc("wudang_lu");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}
	add_door("衡山黄土路", "衡山黄土路", "衡阳城");

	add_door("衡阳茶馆", "衡阳茶馆", "衡阳城");
	add_door("衡阳刘府大院", "衡阳刘府大院", "衡阳城");
	add_door("衡阳回雁楼", "衡阳回雁楼", "衡阳城");
	add_door("衡阳小店", "衡阳小店", "衡阳城");
    set("outdoors", "henshan");
/********************************************************
	set("long", @LONG
这里就是衡阳县城。衡阳地处偏远，显见远不如中原繁华了。
LONG );
	set("exits", ([
		"east"   : __DIR__"hsroad3",
		"west"   : __DIR__"hengyang1",
		"south"  : __DIR__"chaguan",
		"north"  : __DIR__"lingxingmen",
	]));
	set("objects", ([
		__DIR__"npc/lu" : 1,
	]));
****************************************************************/
};


ROOM_END;
