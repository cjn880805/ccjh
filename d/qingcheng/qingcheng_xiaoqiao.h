//xiaoqiao.h

//Sample for room: 青城小桥
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_xiaoqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青城小桥");
	
	add_npc("pub_poorman");
	add_npc("pub_boy");          //add by zdn 2001-07-14


	add_door("青城青石大道", "青城青石大道", "青城小桥");
	add_door("青城盘建福宫", "青城盘建福宫", "青城小桥");


    

/*****************************************************
    set("outdoors","qingcheng");
	set("exits", ([
		"south" : __DIR__"qcroad3",
		"north" : __DIR__"jianfugong",
	]));
*****************************************************/
};


ROOM_END;
