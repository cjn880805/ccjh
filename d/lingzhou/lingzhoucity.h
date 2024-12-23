//lingzhoucity.h

//Sample for room:  灵州
//coded by zwb
//data: 2000-11-16


ROOM_BEGIN(CRLingZhoucity);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州");
	
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");             //add by zdn 2001-07-14
	add_npc("helpnpc018");		//add by qzj 2001-08-13

	add_door("灵州衙门", "灵州衙门", "灵州");

	add_door("灵州大将军府", "灵州大将军府", "灵州");

	add_door("灵州落日林1", "灵州落日林1", "灵州");


};


ROOM_END;
