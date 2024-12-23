//yzjw_jiaowai12.h

//Sample for room:  扬州密林12
//coded by zwb
//data: 2000-11-22

ROOM_BEGIN(CRYZJW_jiaowai12);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州密林12");

	add_npc("animal_dushe");
	add_npc("gaibang_li_sh");

	CBox * box = Add_Box();
	box->add_object("shuzhi", 1);	
	box->set_name( "铁柜");	
	
	add_door("扬州密林11","扬州密林11","扬州密林12");
	add_door("襄阳草地1","襄阳草地1","扬州密林12");
 
};


ROOM_END;
