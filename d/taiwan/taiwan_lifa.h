//lifa.h
//Sample for room: 台湾立法院

//coded by Teapot

//data: 2000-11-4



ROOM_BEGIN(CRTaiWan_lifa);



virtual void create()			//Call it when Room Create
{
	set_name( "台湾力伐院");

	set("monster_chance", 20);

	add_door("台湾疯人院", "台湾疯人院", "台湾力伐院");
	add_door("台湾力伐院私刑房", "台湾力伐院私刑房", "台湾力伐院");
	add_door("台湾正药居民区", "台湾正药居民区", "台湾力伐院");

	set("long", "打狗港位于台湾南部，港域口小腹大，外有岛链环抱，内具曲折峡湾，诚全台第一良港。  " );
};

ROOM_END;
