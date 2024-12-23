//road4.h

//Sample for room: 长安大官道4
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_road4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安大官道4");

	//add npcs into the room   2001-07-13  zdn  add
	add_npc("pub_girl1");
	add_npc("pub_playboy");

	add_door("长安", "长安", "长安大官道4");
	add_door("长安大官道2", "长安大官道2", "长安大官道4");


};


CHANGAN_END;
