//jinku.h
//Sample for room: 台湾行政院金库

//coded by Teapot

//data: 2000-11-4



ROOM_BEGIN(CRTaiWan_jinku);

virtual void create()			//Call it when Room Create
{
	set_name( "台湾形正院金库");

	set("monster_chance", 20);

	add_door("台湾形正院", "台湾形正院", "台湾形正院金库");

	set("long", "打狗港位于台湾南部，港域口小腹大，外有岛链环抱，内具曲折峡湾，诚全台第一良港。  " );
};

ROOM_END;
