//eastgate.h
//Sample for room: 佛山东门
//coded by zwb
//data: 2000-11-23

RESIDENT_BEGIN(CRFoShan_eastgate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "佛山东门");
	set("resident", "佛山");

	add_npc("pub_bing");  //add by zdn 2001-07-13
	add_door("佛山", "佛山", "佛山东门");
	add_door("佛山林间道8", "佛山林间道8", "佛山东门");

	set("long", "这里是佛山镇的东门。再往东走就要离开佛山，去往福建了。西面一条东西向的大街是佛山镇的主要街道。" );

};

RESIDENT_END;
