//yangzhou_xibei.h

//Sample for room:  扬州西北
//coded by Fisho
//data: 2000-11-2


RESIDENT_BEGIN(CRyangzhou_xibei);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州西北");

	set("resident", "扬州");

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_bing");
	add_npc("pub_gongsundanang");
	add_npc("btshan_ouyangke");


	add_door("扬州武庙", "扬州武庙", "扬州西北");
	add_door("扬州钱庄", "扬州钱庄", "扬州西北");
	add_door("扬州财主大门", "扬州财主大门", "扬州西北");
	add_door("扬州衙门大门", "扬州衙门大门", "扬州西北");

	add_door("扬州西南", "扬州西南", "扬州西北");
	add_door("扬州东北", "扬州东北", "扬州西北");
	add_door("扬州北门", "扬州北门", "扬州西北");
	

};


RESIDENT_END;
