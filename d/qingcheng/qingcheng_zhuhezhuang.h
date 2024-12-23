//zhuhezhuang.h

//Sample for room: 青城驻鹤庄
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_zhuhezhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青城驻鹤庄");
	
	add_npc("qingcheng_luo");       //add by zdn 2001-07-20


	add_door("青城天然图画", "青城天然图画", "青城驻鹤庄");


/*****************************************************
	set("exits", ([
		"south"    : __DIR__"tianran",
	]));
*****************************************************/
};


ROOM_END;
