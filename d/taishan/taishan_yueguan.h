//yueguan.h

//Sample for room: 泰山月观峰
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_yueguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山月观峰");
	
	set("monster_chance", 10);

	add_door("泰山南天门", "泰山南天门", "泰山月观峰");
	add_door("泰山西天门", "泰山西天门", "泰山月观峰");

	set("long","这里是位于南天门西面的山岭，怪石攒簇，最高的地方一石卓立，名为君子峰。往北走便是泰山的西天门。");
	

/*****************************************************
	set("exits", ([
		"east" : __DIR__"nantian",
		"northup" : __DIR__"xitian",
	]));
*****************************************************/
};


FIELD_END;
