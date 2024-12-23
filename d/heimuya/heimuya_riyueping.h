//riyueping.h

//Sample for room: 黑木崖日月坪
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_riyueping);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖日月坪");
	
	add_npc("heimuya_fansong");       //add by zdn 201-07-20


	add_door("黑木崖石门", "黑木崖石门", "黑木崖日月坪");
	add_door("黑木崖成德殿", "黑木崖成德殿", "黑木崖日月坪");

};


ROOM_END;
