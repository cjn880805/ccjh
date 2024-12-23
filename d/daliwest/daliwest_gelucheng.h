//gelucheng.h

//Sample for room: 葛鲁城
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiWest_gelucheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "葛鲁城");

	set("resident", "镇雄");

	//add npcs into the room
//	add_npc("animal_shanyang");/////////////////////////
	add_npc("pub_muyangren");
	add_npc("baiyang");
	
	add_door("大理城镇雄", "大理城镇雄", "大理城葛鲁城");
//	add_door("大理城梯田", "大理城梯田", "大理城葛鲁城");
	add_door("大理城山林", "大理城山林", "大理城葛鲁城");

	set("long", "此城是乌蛮族屈部的治府，屈部领葛鲁、昌州、德昌，面积颇大。附近多山地丛林，居民多狩猎为生，河谷内低地也多草皮，适合放牧牛羊。此去北和西皆入深山，东边平原上另有村镇。" );
};

RESIDENT_END;
