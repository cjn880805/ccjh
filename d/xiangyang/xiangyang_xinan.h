//XiangYang_xinan.h


RESIDENT_BEGIN(CRXiangYang_xinan);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "襄阳西南");

	set("resident", "襄阳");

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}

	add_door("襄阳钱庄", "襄阳钱庄", "襄阳西南");
	add_door("襄阳南兵营", "襄阳南兵营", "襄阳西南");
	add_door("襄阳赌场", "襄阳赌场", "襄阳西南");


	
	add_door("襄阳东南", "襄阳东南", "襄阳西南");
	add_door("襄阳西北", "襄阳西北", "襄阳西南");
	add_door("襄阳草地", "襄阳草地", "襄阳西南");
	set("no_cast",  1);
};


RESIDENT_END;
