//zushidian.h

//Sample for room: 祖师殿
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_zushidian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "祖师殿");
	
	add_npc("pub_youke");  //add by zdn 2007-07-14


	add_door("青城古龙桥", "青城古龙桥", "青城祖师殿");
	add_door("青城朝阳洞", "青城朝阳洞", "青城祖师殿");

	set("long","祖师殿又名真武宫。祖师殿背靠轩辕峰，面向白云溪，十分清幽。附近轩皇台，相传为黄帝受道处。");
    

/*****************************************************
	set("exits", ([
		"eastup"    : __DIR__"chaoyangdong",
		"southdown" : __DIR__"gulongqiao",
	]));
*****************************************************/
};


ROOM_END;
