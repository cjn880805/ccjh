//yzjw_jiaowai11.h

//Sample for room:  扬州密林11
//coded by zwb
//data: 2000-11-22
ROOM_BEGIN(CRYZJW_jiaowai11);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州密林11");

	add_npc("animal_dushe");
	add_npc("gaibang_yu_hx");
	
	CBox * box = Add_Box();
	box->add_object("shitou", 1);	
	box->set_name( "铁柜");		

	add_door("扬州密林10","扬州密林10","扬州密林11");
	add_door("扬州密林12","扬州密林12","扬州密林11");
 
};


ROOM_END;
