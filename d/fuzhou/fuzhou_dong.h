//fuzhou_dong.h

//Sample for room:  福州东
//coded by Fisho
//data: 2000-11-4


RESIDENT_BEGIN(CRfuzhou_dong);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "福州东");

	set("resident", "福州");
	set("capacity", 15);

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");


	if (random(2)==0)
	{
	add_npc("pub_boy");
	add_npc("pub_playboy");
	}

	add_door("福州南", "福州南", "福州东");

	add_door("福州涌泉寺", "福州涌泉寺", "福州东");
	add_door("福州无相庵", "福州无相庵", "福州东");
	add_door("福州榕城驿", "福州榕城驿", "福州东");


};


RESIDENT_END;
