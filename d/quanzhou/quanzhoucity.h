//quanzhoucity.h

//Sample for room:  泉州
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
RESIDENT_BEGIN(CRQuanzhoucity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州");

	set("resident", "泉州");
	set("capacity", 10);

	add_npc("pub_wangjinhongpu");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	add_npc("helpnpc010");

	if (random(2)==0)
	{
		add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}

				

	add_door("泉州西门吊桥", "泉州西门吊桥", "泉州");
	add_door("泉州海港", "泉州海港", "泉州");

	add_door("泉州南门", "泉州南门", "泉州");
	add_door("泉州北门", "泉州北门", "泉州");
//	add_door("泉州海港", "泉州海港", "泉州");
 
};


RESIDENT_END;
