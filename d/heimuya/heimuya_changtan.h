//changtan.h

//Sample for room: ºÚÄ¾ÑÂ³¤Ì²
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_changtan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ºÚÄ¾ÑÂ³¤Ì²");
	
	add_npc("heimuya_jiaotu");  //add by zdn 2001-07-20


	add_door("ºÚÄ¾ÑÂÐÉÐÉÌ²", "ºÚÄ¾ÑÂÐÉÐÉÌ²", "ºÚÄ¾ÑÂ³¤Ì²");
	add_door("ºÚÄ¾ÑÂÉ½µÀ", "ºÚÄ¾ÑÂÉ½µÀ", "ºÚÄ¾ÑÂ³¤Ì²");

};


ROOM_END;
