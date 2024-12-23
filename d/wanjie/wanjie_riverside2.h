//riverside2.h

//Sample for room: 江边小路2
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_riverside2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "江边小路2");
	
	add_npc("pub_poorman");      //add by zdn 2001-07-16


	add_door("万劫谷江边小路1", "万劫谷江边小路1", "万劫谷江边小路2");
	add_door("万劫谷江边小路3", "万劫谷江边小路3", "万劫谷江边小路2");


};


ROOM_END;
