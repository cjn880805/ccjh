//yanan2.h

//Sample for room: 大理城沿池小路2
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_yanan2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城沿池小路2");

	set("resident", "碧鸡山");

	add_npc("pub_bing");   //add zdn 2001-07-12

	add_door("大理城碧鸡山顶", "大理城碧鸡山顶", "大理城沿池小路2");
	add_door("大理城滇池沿岸1", "大理城滇池沿岸1", "大理城沿池小路2");

	set("long", "这是一条沿着滇池南岸的小路，柳荫夹岸，清风袭人。远望滇池湖面，碧波荡漾，飞鸟戏水，遥遥可见游船、渔船轻帆浮云。端地是人间仙境。此路向西直上滇池西岸的群山。" );
};


RESIDENT_END;
