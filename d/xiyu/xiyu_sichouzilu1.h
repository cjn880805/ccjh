//sichouzilu1.h

//Sample for room: 丝绸之路1
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_sichouzilu1);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "丝绸之路1");
				
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
		add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}
	add_door("西域草原", "西域草原", "西域丝绸之路1");
	add_door("西域大漠", "西域大漠", "西域丝绸之路1");
	add_door("西域天山脚下", "西域天山脚下", "西域丝绸之路1");
	add_door("西域丝绸之路2", "西域丝绸之路2", "西域丝绸之路1");
	
};


XIYU_END;
