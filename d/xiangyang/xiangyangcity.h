//XiangYangCity.h

//Sample for room: Xiang Yang City
//coded by Lanwood
//data: 2000-10-25

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXiangYangCity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "襄阳城");

	//add npcs into the room
//	add_npc("animal_lion");
//	add_npc("animal_laofu");

	add_npc("honghua_lilishi");
	add_npc("gaibang_wuxiuwen");
	add_npc("gaibang_shitianjing");
	add_npc("xiangyang_wusantong");  
	add_npc("xiangyang_guofu");        //add by zdn 2001-07-20

	add_door("襄阳草地1", "襄阳草地1", "襄阳城");
	add_door("襄阳草地", "襄阳草地", "襄阳城");
	add_door("长安函谷关", "长安函谷关", "襄阳城");

	add_door("襄阳安抚使衙门", "襄阳安抚使衙门", "襄阳城");
	add_door("襄阳福威镖局", "襄阳福威镖局", "襄阳城");
	add_door("襄阳东兵营", "襄阳东兵营", "襄阳城");
	add_door("襄阳南兵营", "襄阳南兵营", "襄阳城");
	add_door("襄阳西兵营", "襄阳西兵营", "襄阳城");
	add_door("襄阳北兵营", "襄阳北兵营", "襄阳城");
	add_door("襄阳茶馆", "襄阳茶馆", "襄阳城");
	add_door("襄阳当铺", "襄阳当铺", "襄阳城");
//	add_door("襄阳大校场", "襄阳大校场", "襄阳城");
	add_door("襄阳赌场", "襄阳赌场", "襄阳城");
	add_door("襄阳郭府大门", "襄阳郭府大门", "襄阳城");
	add_door("襄阳将军府大门", "襄阳将军府大门", "襄阳城");
	add_door("襄阳聚义馆", "襄阳聚义馆", "襄阳城");
	add_door("襄阳客栈", "襄阳客栈", "襄阳城");
	add_door("襄阳民居1", "襄阳民居1", "襄阳城");
	add_door("襄阳民居2", "襄阳民居2", "襄阳城");
	add_door("襄阳觅香楼", "襄阳觅香楼", "襄阳城");
	add_door("襄阳木匠铺", "襄阳木匠铺", "襄阳城");
	add_door("襄阳新罗坊", "襄阳新罗坊", "襄阳城");
	add_door("襄阳钱庄", "襄阳钱庄", "襄阳城");
	add_door("襄阳书店", "襄阳书店", "襄阳城");
	add_door("襄阳铁匠铺", "襄阳铁匠铺", "襄阳城");
	add_door("襄阳学堂", "襄阳学堂", "襄阳城");
	add_door("襄阳药铺", "襄阳药铺", "襄阳城");
	add_door("襄阳忠烈祠", "襄阳忠烈祠", "襄阳城");
	set("no_cast",  1);
};


ROOM_END;
