//fuzhou_xi.h

//Sample for room:  福州西
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRfuzhou_xi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "福州西");

	set("resident", "福州");

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_wujiang");
	add_npc("pub_playboy");

	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}

	add_door("福州南", "福州南", "福州西");
	add_door("福州闽中大道", "福州闽中大道", "福州西");

	add_door("福州西禅寺", "福州西禅寺", "福州西");

	add_door("福州福威镖局正厅", "福州福威镖局正厅", "福州西");

};


RESIDENT_END;
