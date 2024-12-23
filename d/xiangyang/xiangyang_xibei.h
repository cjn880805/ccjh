//XiangYang_xibei.h


RESIDENT_BEGIN(CRXiangYang_xibei);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "襄阳西北");

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
	add_door("襄阳北兵营", "襄阳北兵营", "襄阳西北");
	add_door("襄阳客栈", "襄阳客栈", "襄阳西北");
	add_door("襄阳西兵营", "襄阳西兵营", "襄阳西北");
	add_door("襄阳郭府大门", "襄阳郭府大门", "襄阳西北");
	add_door("襄阳聚义馆", "襄阳聚义馆", "襄阳西北");
	add_door("襄阳书店", "襄阳书店", "襄阳西北");
//	add_door("襄阳大校场", "襄阳大校场", "襄阳西北");
	add_door("襄阳当铺", "襄阳当铺", "襄阳西北");
	add_door("襄阳新罗坊", "襄阳新罗坊", "襄阳西北");
	add_door("襄阳安抚使衙门", "襄阳安抚使衙门", "襄阳西北");
	
	add_door("襄阳西南", "襄阳西南", "襄阳西北");
	add_door("襄阳东北", "襄阳东北", "襄阳西北");
	add_door("襄阳草地1", "襄阳草地1", "襄阳西北");
	add_door("长安函谷关", "长安函谷关", "襄阳西北");
	set("no_cast",  1);
};


RESIDENT_END;
