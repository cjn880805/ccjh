//fuzhou_nan.h

//Sample for room:  福州南
//coded by Fisho
//data: 2000-11-4


RESIDENT_BEGIN(CRfuzhou_nan);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "福州南");

	set("resident", "福州");

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_wujiang");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}

	add_door("福州南门", "福州南门", "福州南");
	add_door("福州东", "福州东", "福州南");
	add_door("福州西", "福州西", "福州南");
	add_door("福州校场", "福州校场", "福州南");
	add_door("福州向阳老宅", "福州向阳老宅", "福州南");

	add_door("福州杂货铺", "福州杂货铺", "福州南");
	add_door("福州味中味", "福州味中味", "福州南");
	add_door("福州提督衙门", "福州提督衙门", "福州南");

};


RESIDENT_END;
