//fuzhoucity.h

//Sample for room:  福州
//coded by Fisho
//data: 2000-11-4


ROOM_BEGIN(CRfuzhoucity);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "福州");

	//add npcs into the room

	add_door("福州南门", "福州南门", "福州");
	add_door("福州闽中大道", "福州闽中大道", "福州");

	add_door("福州西禅寺", "福州西禅寺", "福州");
	add_door("福州涌泉寺", "福州涌泉寺", "福州");
	add_door("福州向阳巷", "福州向阳巷", "福州");
	add_door("福州无相庵", "福州无相庵", "福州");
	add_door("福州榕城驿", "福州榕城驿", "福州");
	add_door("福州味中味", "福州味中味", "福州");
	add_door("福州提督衙门", "福州提督衙门", "福州");
	add_door("福州福威镖局", "福州福威镖局", "福州");

};


ROOM_END;
