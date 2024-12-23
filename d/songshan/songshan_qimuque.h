//qimuque.h

//Sample for room: ÆôÄ¸ãÚ
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_qimuque);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÆôÄ¸ãÚ");


	add_door("áÔÉ½ÆôÄ¸Ê¯", "áÔÉ½ÆôÄ¸Ê¯", "áÔÉ½ÆôÄ¸ãÚ");

	

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"qimushi",
	]));
********************************************/
};


ROOM_END;
