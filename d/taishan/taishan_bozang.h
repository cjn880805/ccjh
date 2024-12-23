//bozang.h

//Sample for room: 泰山宝藏岭
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_bozang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山宝藏岭");

	set("monster_chance", 40);
	add_door("泰山碧霞祠", "泰山碧霞祠", "泰山宝藏岭");

	set("long","这里是泰山的一个名胜。岭上有一座状似狮子的巨石，称为狮子崖。最出名的还是要数在东北面的东岳庙，也称上岳庙，是古代封禅的地方，那里有一块唐玄宗的纪泰山铭。");
	

/*****************************************************
	set("exits", ([
		"westup" : __DIR__"bixia",
	]));
*****************************************************/
};


FIELD_END;
