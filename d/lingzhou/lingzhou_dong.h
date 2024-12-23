//lingzhoucity.h

//Sample for room:  灵州东
//coded by zwb
//data: 2000-11-16

RESIDENT_BEGIN(CRLingZhou_dong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州东");


	set("resident", "灵州");
	set("capacity", 25);
	
	add_npc("pub_boy");
	add_npc("pub_xiaowei");       //add by zdn 2001-07-14


	add_door("灵州衙门", "灵州衙门", "灵州东");

	add_door("灵州大将军府", "灵州大将军府", "灵州东");
	add_door("灵州西", "灵州西", "灵州东");

	add_door("灵州落日林1", "灵州落日林1", "灵州东");


};


RESIDENT_END;
