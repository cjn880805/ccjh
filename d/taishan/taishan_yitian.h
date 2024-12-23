//yitian.h

//Sample for room: 泰山一天门
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_yitian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山一天门");
	add_npc("pub_daoke");

	set("monster_chance", 40);

	add_door("泰山白鹤泉", "泰山白鹤泉", "泰山一天门");
	add_door("泰山斗母宫", "泰山斗母宫", "泰山一天门");


/*****************************************************
	set("exits", ([
		"northup" : __DIR__"doumo",
		"southdown" : __DIR__"baihe",
	]));
	set("objects",([
		__DIR__"npc/dao-ke" : 1,
	]));
*****************************************************/
};


FIELD_END;
