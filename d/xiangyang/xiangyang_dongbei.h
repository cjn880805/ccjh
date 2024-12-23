//XiangYang_dongbei.h


RESIDENT_BEGIN(CRXiangYang_dongbei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "襄阳东北");

	set("resident", "襄阳");
	set("capacity", 30);

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	add_npc("helpnpc_jhlz");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}

	add_door("襄阳福威镖局", "襄阳福威镖局", "襄阳东北");
	add_door("襄阳东兵营", "襄阳东兵营", "襄阳东北");
	add_door("襄阳茶馆", "襄阳茶馆", "襄阳东北");
	add_door("襄阳将军府大门", "襄阳将军府大门", "襄阳东北");
	add_door("襄阳忠烈祠", "襄阳忠烈祠", "襄阳东北");
	
	add_door("襄阳东南", "襄阳东南", "襄阳东北");
	add_door("襄阳西北", "襄阳西北", "襄阳东北");
	set("no_cast",  1);
};


RESIDENT_END;
