//qinglong3.h

//Sample for room: 泉州青龙会侧庭3
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRQuanZhou_qinglong3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州青龙会侧庭3");
	
	add_npc("pub_jianke");       //add by zdn 2001-07-14


	add_door("泉州青龙会前庭", "泉州青龙会前庭", "泉州青龙会侧庭3");

	set("long", "这是一片密密的竹林。这里人迹罕至，惟闻足底叩击路面，有僧敲木鱼声；微风吹拂竹叶，又如簌簌禅唱。令人尘心为之一涤，真是绝佳的禅修所在。" );
	set("no_clean_up", 1);
	
/*****************************************************
	set("exits", ([
		"south" : __DIR__"qinglong",
	]));
//	set("objects",([
//		__DIR__"npc/tang1" : 1,
//	]));
********************************************/
};


ROOM_END;
