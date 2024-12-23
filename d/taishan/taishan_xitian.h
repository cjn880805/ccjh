//xitian.h

//Sample for room: 泰山西天门
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_xitian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山西天门");

	set("monster_chance", 30);

	add_door("泰山月观峰", "泰山月观峰", "泰山西天门");

	set("long","这里有两块巨石壁立，有如给人斩削过似的，正是岱顶的西面出口。");
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"yueguan",
	]));
*****************************************************/
};


FIELD_END;
