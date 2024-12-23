//road3.h

//Sample for room: 大理城官道3
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_road3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城官道3");

	set("resident", "南诏");

	//add npcs into the room
	add_npc("pub_girl1");
	
	add_door("大理城南诏德化碑", "大理城南诏德化碑", "大理城官道3");
	add_door("大理城官道2", "大理城官道2", "大理城官道3");

	set("long", "你走在一条青石官道上，这里已经是南诏境内了，路上时时可以看到各色各样的商人来来往往，络驿不绝。路边站了些个衣饰华艳的摆夷女子，其中一个身穿白衣的显得格外秀丽。此去向南即是大理国北关口太和城，沿官道向东北可达中原。(mountain)，和联绵不绝的大森林(forest)。--峨嵋山。");
	
};


RESIDENT_END;
