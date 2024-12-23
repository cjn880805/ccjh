//huima.h

//Sample for room: 泰山回马岭
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_huima);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山回马岭");

	set("monster_chance", 20);
	//add npcs into the room
	add_npc("pub_jianke");/////////////////////////
	add_npc("pub_tiaofu");

				

	add_door("泰山石经峪", "泰山石经峪", "泰山回马岭");
	add_door("泰山二天门", "泰山二天门", "泰山回马岭");

	

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"ertian",
		"southdown" : __DIR__"shijin",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/jian-ke" : 1,
	]));
*****************************************************/
};


FIELD_END;
