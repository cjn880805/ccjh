//sixing.h
//Sample for room: 台湾立法院私刑房

//coded by Teapot

//data: 2000-11-4



ROOM_BEGIN(CRTaiWan_sixing);



virtual void create()			//Call it when Room Create
{
	set_name( "台湾力伐院私刑房");

	set("monster_chance", 20);

	add_door("台湾力伐院", "台湾力伐院", "台湾力伐院私刑房");

	set("long", "打狗港位于台湾南部，港域口小腹大，外有岛链环抱，内具曲折峡湾，诚全台第一良港。  " );
};

ROOM_END;
