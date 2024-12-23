//road2.h

//Sample for room: 长安大官道2
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安大官道2");
	
	//add npcs into the room   2001-07-12-zdn add
	add_npc("pub_huanu");
	add_npc("pub_daoke");
	add_npc("pub_lanlinlaoren");

	add_door("武功", "武功", "长安大官道2");
	add_door("终南山大官道", "终南山大官道", "长安大官道2");
	add_door("长安函谷关", "长安函谷关", "长安大官道2");
	add_door("长安大官道4", "长安大官道4", "长安大官道2");
	add_door("华山村青石大道", "华山村青石大道", "长安大官道2");	


};


CHANGAN_END;
