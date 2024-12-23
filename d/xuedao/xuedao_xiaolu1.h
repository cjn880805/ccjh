//xiaolu1.h
//Sample for room:  血刀门小路1
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_xiaolu1);

virtual void create()			//Call it when Room Create

{
	//set name of our room
	set_name( "血刀门小路1");
	add_npc("pub_yuanyanggang");

	add_door("血刀门圣湖", "血刀门圣湖", "血刀门小路1");

	add_door("血刀门小路2", "血刀门小路2", "血刀门小路1");

};

ROOM_END;
