//road1.h

//Sample for room: 大理城官道1
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城官道1");

	set("resident", "南诏");

	add_npc("pub_girl1");
	add_npc("pub_jianke");          //add by zdn 2001-07-13

	add_door("大理城官道2", "大理城官道2", "大理城官道1");
	add_door("峨嵋青石阶", "峨嵋青石阶", "大理城官道1");

	set("long", "这是一条蜿蜒崎岖的山间土路，是由中原通向大理的官道。此处属川南，向西南去的盘山路通上云贵山区，继而可达南昭大理国，此去向北不远就是蜀中名川--峨嵋山。");
};

RESIDENT_END;
