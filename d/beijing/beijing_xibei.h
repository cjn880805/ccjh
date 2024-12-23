//beijing_xibei.h

//Sample for room:  北京西北
//coded by Fisho
//data: 2000-11-2


RESIDENT_BEGIN(CRbeijing_xibei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "北京西北");

	set("resident", "北京");
	set("capacity", 50);

	//add npcs into the room

	add_npc("pub_boy");
	add_npc("pub_lady1");
	add_npc("mingjiao_baiguishou");

	add_door("北京书院", "北京书院", "北京西北");
	add_door("北京文庙", "北京文庙", "北京西北");
	add_door("北京赌场", "北京赌场", "北京西北");
	add_door("北京西厂大门", "北京西厂大门", "北京西北");
	
	add_door("北京西南", "北京西南", "北京西北");
	add_door("北京东北", "北京东北", "北京西北");


};


RESIDENT_END;