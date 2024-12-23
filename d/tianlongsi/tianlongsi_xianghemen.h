//xianghemen.h

//Sample for room:  ÌìÁúËÂÏèº×ÃÅ
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_xianghemen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÌìÁúËÂÏèº×ÃÅ");
				
	add_door("ÌìÁúËÂÎÞÀÖ¸ó", "ÌìÁúËÂÎÞÀÖ¸ó", "ÌìÁúËÂÏèº×ÃÅ");
	add_door("ÌìÁúËÂÎÞ¾»¸ó", "ÌìÁúËÂÎÞ¾»¸ó", "ÌìÁúËÂÏèº×ÃÅ");

    

/******************************************************************************
        set("outdoors","tianlongsi");
        set("exits", ([
            "south": __DIR__"wulege",
            "north": __DIR__"wujingge",
        ]));
******************************************************************************/
};


ROOM_END;
