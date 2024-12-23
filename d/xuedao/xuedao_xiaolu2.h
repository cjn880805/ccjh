//xiaolu2.h
//Sample for room:  血刀门小路2
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_xiaolu2);

virtual void create()			//Call it when Room Create

{
	//set name of our room
	set_name( "血刀门小路2");
	add_npc("pub_shenjia");
	add_door("血刀门小路1", "血刀门小路1", "血刀门小路2");
	add_door("血刀门小路3", "血刀门小路3", "血刀门小路2");

};
ROOM_END;
