//weipin.h

//Sample for room: 泰山围屏山
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_weipin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山围屏山");

	set("monster_chance", 40);

	add_door("泰山天街", "泰山天街", "泰山围屏山");
	add_door("泰山碧霞祠", "泰山碧霞祠", "泰山围屏山");

	set("long","这里是泰山的其中一座山峰。山的东面有一个虎头崖，其形状有如一头伏虎。南面有避风崖，崖上大大地刻着「振衣冈」三字于上面。北边则有北斗坛。从这里往东走，便可到达伺奉泰山之神碧霞元君的碧霞祠。");
	

/*****************************************************
	set("exits", ([
		"westdown" : __DIR__"tianjie",
		"east" : __DIR__"bixia",
	]));
*****************************************************/
};

FIELD_END;
