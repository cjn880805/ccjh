//path1.h

//Sample for room: 青城盘山磴道
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_path1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青城盘山磴道");
	
	add_npc("qingcheng_hong");      //add by zdn 2001-07-14


	add_door("青城盘建福宫", "青城盘建福宫", "青城盘山磴道");
	add_door("青城天然图画", "青城天然图画", "青城盘山磴道");


    

/*****************************************************
    set("outdoors","qingcheng");
	set("exits", ([
		"southeast" : __DIR__"jianfugong",
		"westup"    : __DIR__"tianran",
	]));
*****************************************************/
};


ROOM_END;
