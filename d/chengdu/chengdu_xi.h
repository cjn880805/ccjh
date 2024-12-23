//chengdu_xi.h


RESIDENT_BEGIN(CRchengdu_xi);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "成都西");

	set("resident", "成都");

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_seller1");
	add_npc("pub_playboy");
	add_npc("pub_wuxing");

	add_door("成都中", "成都中", "成都西");
	add_door("成都南河桥", "成都南河桥", "成都西");

	add_door("成都兵器铺", "成都兵器铺", "成都西");
	add_door("成都武侯祠大门", "成都武侯祠大门", "成都西");
	add_door("成都济世堂药店", "成都济世堂药店", "成都西");

};


RESIDENT_END;



