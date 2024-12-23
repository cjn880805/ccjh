//yangzhou_xinan.h

//Sample for room:  扬州西南
//coded by Fisho
//data: 2000-11-2


RESIDENT_BEGIN(CRyangzhou_xinan);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州西南");

	set("resident", "扬州");

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_bing");
	add_npc("pub3_xunbu");
	add_npc("pub_liumang");
	add_npc("pub_liumangtou");


	add_door("扬州春来茶馆", "扬州春来茶馆", "扬州西南");
	add_door("扬州赌场", "扬州赌场", "扬州西南");
	add_door("扬州兵营", "扬州兵营", "扬州西南");
	add_door("扬州武馆", "扬州武馆", "扬州西南");

	add_door("扬州东南", "扬州东南", "扬州西南");
	add_door("扬州西北", "扬州西北", "扬州西南");
	add_door("扬州西门", "扬州西门", "扬州西南");
	add_door("扬州南门", "扬州南门", "扬州西南");
	

};


RESIDENT_END;
