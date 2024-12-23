//bingying1.h

//Sample for room: 北兵营
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_bingying1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "北兵营");

	//add npcs into the room
	add_npc("pub_pian");
	add_npc("pub_zuo");
	add_npc("pub_bing");
	add_npc("pub_pi");        //add by zdn 2001-07-20
	add_npc("pub_liguishou");

	add_door("襄阳西北", "襄阳西北", "襄阳北兵营");

};


ROOM_END;
