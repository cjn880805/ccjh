//yingbin.h

//Sample for room: ою©м╣╨с╜╠Ж╧щ
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRXiaKeDao_yingbin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ою©м╣╨с╜╠Ж╧щ");
	
	add_npc("pub_lady3");         //add by zdn 2001-07-16


	add_door("ою©м╣╨╤╢це", "ою©м╣╨╤╢це", "ою©м╣╨с╜╠Ж╧щ");
	add_door("ою©м╣╨п║Ёт╣Й", "ою©м╣╨п║Ёт╣Й", "ою©м╣╨с╜╠Ж╧щ");
	add_door("ою©м╣╨пщо╒йр", "ою©м╣╨пщо╒йр", "ою©м╣╨с╜╠Ж╧щ");
	add_door("ою©м╣╨й╞╤╢2", "ою©м╣╨й╞╤╢2", "ою©м╣╨с╜╠Ж╧щ");

	

/*****************************************************
    set("exits", ([
    "east" : __DIR__"xiaodian",
    "west" : __DIR__"xiuxis",
	"south" : __DIR__"shidong2",
    "out" : __DIR__"dongmen",
	]));
********************************************/
};


ROOM_END;
