//northgate.h

//Sample for room: 佛山北门
//coded by zwb
//data: 2000-11-23

RESIDENT_BEGIN(CRFoShan_northgate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "佛山北门");

	set("resident", "佛山");

	//add npcs into the room
	add_npc("pub_bing");
	
	add_door("佛山", "佛山", "佛山北门");
	add_door("佛山南岭山口", "佛山南岭山口", "佛山北门");

	set("long", "这里是佛山镇的北门。出北门向北，翻过南岭可达中原。南面一条东西向的大街是佛山镇的主要街道。" );
	
};

RESIDENT_END;
