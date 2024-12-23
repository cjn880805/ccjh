//xingzheng.h
//Sample for room: 台湾行政院

//coded by Teapot

//data: 2000-11-4



ROOM_BEGIN(CRTaiWan_xingzheng);

virtual void create()			//Call it when Room Create
{
	set_name( "台湾形正院");

	set("monster_chance", 20);


	add_door("台湾疯人院", "台湾疯人院", "台湾形正院");
	add_door("台湾正药居民区", "台湾正药居民区", "台湾形正院");
	add_door("台湾形正院金库", "台湾形正院金库", "台湾形正院");

	set("long", "打狗港位于台湾南部，港域口小腹大，外有岛链环抱，内具曲折峡湾，诚全台第一良港。  " );
};

ROOM_END;
