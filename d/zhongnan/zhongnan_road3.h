//road3.h

//Sample for room: 大官道
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_road3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大官道");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_jianke");
	add_npc("pub_youngwoman");
	add_npc("pub_baifangxiao");
	add_npc("pub_linhongyin");

	add_door("终南山山路2", "终南山山路2", "终南山大官道");
	add_door("长安大官道2", "长安大官道2", "终南山大官道");

};


ROOM_END;
