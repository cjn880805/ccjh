//shandao.h

//Sample for room: ºÚÄ¾ÑÂÉ½µÀ
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shandao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ºÚÄ¾ÑÂÉ½µÀ");
	
	add_npc("heimuya_jiaotu");  //add by zdn 2001-07-20


	add_door("ºÚÄ¾ÑÂ³¤Ì²", "ºÚÄ¾ÑÂ³¤Ì²", "ºÚÄ¾ÑÂÉ½µÀ");
	add_door("ºÚÄ¾ÑÂÊ¯½×", "ºÚÄ¾ÑÂÊ¯½×", "ºÚÄ¾ÑÂÉ½µÀ");
	add_door("ºÚÄ¾ÑÂ·çÀ×ÌÃ´óÌü", "ºÚÄ¾ÑÂ·çÀ×ÌÃ´óÌü", "ºÚÄ¾ÑÂÉ½µÀ");

};


ROOM_END;
