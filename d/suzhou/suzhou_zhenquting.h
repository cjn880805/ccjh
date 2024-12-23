//zhenquting.h

//Sample for room: ’Ê»§Õ§
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_zhenquting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "’Ê»§Õ§");
	
	add_npc("pub_youke");         //add by zdn 2001-07-16


	add_door("À’÷›—‡”˛Ã√", "À’÷›—‡”˛Ã√", "À’÷›’Ê»§Õ§");
	add_door("À’÷›Œ √∑∏Û", "À’÷›Œ √∑∏Û", "À’÷›’Ê»§Õ§");

	
/*****************************************************
	set("exits", ([
		"east"      : __DIR__"wenmeige",
		"northwest" : __DIR__"yanyutang",
	]));
********************************************/
};


ROOM_END;
