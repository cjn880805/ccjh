//guenchao.h

//Sample for room:  Ñªµ¶ÃÅ¹÷³²
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_guenchao);


virtual void create()			//Call it when Room Creat
{
	//set name of our room
	set_name( "Ñªµ¶ÃÅ¹÷³²");
	add_npc("hero_oho");
	add_door("Ñªµ¶ÃÅÊ¥ºþ", "Ñªµ¶ÃÅÊ¥ºþ", "Ñªµ¶ÃÅ¹÷³²");
	set("no_fight", 1);
	set("no_beg", 1);

/******************************************************************************
******************************************************************************/
};


ROOM_END;
