//beitian.h

//Sample for room: 泰山北天门
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_beitian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山北天门");

	set("monster_chance", 20);

	add_door("泰山丈人峰", "泰山丈人峰", "泰山北天门");

	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"zhangren",
	]));
*****************************************************/
};


FIELD_END;
