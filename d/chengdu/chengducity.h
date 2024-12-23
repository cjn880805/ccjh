//chengducity.h


ROOM_BEGIN(CRchengducity);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "成都");

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_seller1");
	add_npc("pub_playboy");
	add_npc("helpnpc011");		//add by qzj 2001-08-13

	add_door("成都南河桥", "成都南河桥", "成都");
	add_door("成都府河桥", "成都府河桥", "成都");
	add_door("成都东府河桥", "成都东府河桥", "成都");

	add_door("成都济世堂药店", "成都济世堂药店", "成都");
	add_door("成都武侯祠大门", "成都武侯祠大门", "成都");
	add_door("成都金牛武馆", "成都金牛武馆", "成都");
	add_door("成都望江楼", "成都望江楼", "成都");
	add_door("成都提督府", "成都提督府", "成都");
	add_door("成都锦城驿", "成都锦城驿", "成都");
	add_door("成都兵器铺", "成都兵器铺", "成都");
	add_door("成都蜀都酒楼", "成都蜀都酒楼", "成都");

};


ROOM_END;
