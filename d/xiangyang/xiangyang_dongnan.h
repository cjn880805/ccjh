//XiangYang_dongnan.h

RESIDENT_BEGIN(CRXiangYang_dongnan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "襄阳东南");

	set("resident", "襄阳");


	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");	//add by zdn 2001-07-20
	}
	add_door("襄阳民居1", "襄阳民居1", "襄阳东南");
	add_door("襄阳民居2", "襄阳民居2", "襄阳东南");
	add_door("襄阳木匠铺", "襄阳木匠铺", "襄阳东南");
	add_door("襄阳铁匠铺", "襄阳铁匠铺", "襄阳东南");
	add_door("襄阳学堂", "襄阳学堂", "襄阳东南");
	add_door("襄阳药铺", "襄阳药铺", "襄阳东南");
	add_door("襄阳觅香楼", "襄阳觅香楼", "襄阳东南");

	
	add_door("襄阳东北", "襄阳东北", "襄阳东南");
	add_door("襄阳西南", "襄阳西南", "襄阳东南");
	set("no_cast",  1);
};


RESIDENT_END;
