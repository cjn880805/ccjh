//gulou.h

//Sample for room: 鼓楼小院
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_gulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "鼓楼小院");

	add_npc("shaolin_qing_wen");

	add_door("少林寺精进场", "少林寺精进场", "少林寺鼓楼小院");

	set("long", "这是一座砖木结构的宝塔，塔高七层，塔身作八角形，飞檐翘翎，檐角上挂满了一串串小铜铃，随风叮叮作响。塔身墙上镂空雕绘着无数佛陀们的坐像。一个个形态维肖，看来出自名匠之手。塔底入口处开了一扇拱形的小木门，门扇两侧用彩漆涂绘，画的是释祖在灵山对诸天众佛讲经时的情形。" );

};


ROOM_END;
