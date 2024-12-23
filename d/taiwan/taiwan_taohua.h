//taohua.h
//Sample for room: 台湾桃花院

//coded by Teapot

//data: 2000-11-4



ROOM_BEGIN(CRTaiWan_taohua);



virtual void create()			//Call it when Room Create
{
	set_name( "台湾桃花院");

	set("monster_chance", 20);
	
//	add_npc("pub_lady3");    //add by zdn 2001-07-16

	add_door("台湾忠通府", "台湾忠通府", "台湾桃花院");

	set("long", "打狗港位于台湾南部，港域口小腹大，外有岛链环抱，内具曲折峡湾，诚全台第一良港。  " );
};

ROOM_END;
