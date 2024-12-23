//suzhoubei.h

//Sample for room:  苏州北
//coded by Fisho
//data: 2000-11-3
RESIDENT_BEGIN(CRsuzhoubei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "苏州北");

	set("resident", "苏州");
	set("capacity", 35);

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}
	add_door("苏州青石官道2", "苏州青石官道2", "苏州北");
	add_door("苏州中", "苏州中", "苏州北");

	add_door("苏州客店", "苏州客店", "苏州北");
	add_door("苏州紫金庵", "苏州紫金庵", "苏州北");
	add_door("苏州戏园子", "苏州戏园子", "苏州北");
	add_door("苏州春在楼", "苏州春在楼", "苏州北");
};

RESIDENT_END;
