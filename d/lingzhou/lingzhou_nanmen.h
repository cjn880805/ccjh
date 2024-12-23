//nanmen.h

//Sample for room: 灵州南门
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_nanmen);

virtual void create()			//Call it when Room Create
{

	set_name( "灵州南门");

	//add npcs into the room
	add_npc("pub_xiaowei");/////////////////////////
	add_npc("pub_xixiabing");

	add_door("灵州西", "灵州西", "灵州南门");
	add_door("灵州黄羊滩", "灵州黄羊滩", "灵州南门");

};


ROOM_END;
