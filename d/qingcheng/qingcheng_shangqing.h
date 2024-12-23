//shangqing.h

//Sample for room: 青城上清宫
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_shangqing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青城上清宫");
	
	add_npc("qingcheng_yuyan");          //add by zdn 2001-07-20


	add_door("青城三弯九倒", "青城三弯九倒", "青城上清宫");
	add_door("青城呼应亭", "青城呼应亭", "青城上清宫");
	add_door("青城松风观", "青城松风观", "青城上清宫");


    

/*****************************************************
	set("exits", ([
		"westdown" : __DIR__"sanwanjiudao",
		"westup"   : __DIR__"huyingting",
		"west"     : __DIR__"yuanyangjing",
		"east"     : __DIR__"maguchi",
		"south"    : __DIR__"songfengguan",
	]));
*****************************************************/
};


ROOM_END;
