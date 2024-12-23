//qinglong2.h

//Sample for room: 泉州青龙会侧庭2
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRQuanZhou_qinglong2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州青龙会侧庭2");
		
	add_door("泉州青龙会前庭", "泉州青龙会前庭", "泉州青龙会侧庭2");
	add_npc("quanzhou_lse");
	add_npc("quanzhou_shuimm");
	
	set("no_fight", 1);
/*****************************************************
	set("exits", ([
		"north" : __DIR__"qinglong",
	]));
********************************************/
};


ROOM_END;
