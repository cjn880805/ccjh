//chengdu_dong.h


RESIDENT_BEGIN(CRchengdu_dong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "成都东");

	set("resident", "成都");
	set("capacity", 25);

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_seller1");
	add_npc("pub_playboy");


	add_door("成都中", "成都中", "成都东");
	add_door("成都东府河桥", "成都东府河桥", "成都东");

	add_door("成都金牛武馆", "成都金牛武馆", "成都东");
	add_door("成都望江楼", "成都望江楼", "成都东");
	add_door("成都锦城驿", "成都锦城驿", "成都东");
	add_door("成都蜀都酒楼", "成都蜀都酒楼", "成都东");
};


RESIDENT_END;
