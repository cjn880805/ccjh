//chengdu_zhong.h


RESIDENT_BEGIN(CRchengdu_zhong);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "成都中");

	set("resident", "成都");

	//add npcs into the room
	add_npc("pub_tangruei");
	add_npc("pub_seller1");
	add_npc("pub_playboy");
	add_npc("pub_guanbing1");
	add_npc("pub_weiziyi");

	add_door("成都西", "成都西", "成都中");
	add_door("成都东", "成都东", "成都中");
	add_door("成都府河桥", "成都府河桥", "成都中");

	add_door("成都提督府", "成都提督府", "成都中");

};


RESIDENT_END;



