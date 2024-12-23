//huandi1.h
//Sample for room: 荒路1
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_huandi1);

virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "荒路1");

	set("resident", "关外宁远");
	
	add_npc("guanwai_wan");    //// add by zdn 2001-07-13
	
	add_door("关外宁远", "关外宁远", "关外荒路1");

	add_door("关外荒路2", "关外荒路2", "关外荒路1");

    set("long","这是城东的一条荒路，路旁杂乱的长着齐膝的荒草，远近荒无一人。两旁干枯的老树上落满了成群的乌鸦，凄凉的鸣叫声在荒野上远远传去，一派凄凉的景象。" );


};


RESIDENT_END;
