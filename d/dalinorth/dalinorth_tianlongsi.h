//tianlongsi.h

//Sample for room: 天龙寺
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLiNorth_tianlongsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺");
	
	add_npc("pub_youke");
	add_npc("pub_jianke");     //add by zdn 2001-07-13
	add_npc("dali_pochen");    //add by zdn 2001-07-20

	add_door("大理城宏圣寺塔", "大理城宏圣寺塔", "大理城北天龙寺");

//	set("long", "带着火折进入洞内，迂回蛇行，不久，即见一厅豁然开朗，石钟乳，石笋，石柱，玲珑剔透，斗奇争胜。光照壁影，如月穿晓岩，溪云接水，壁气侵寒，石光滴翠，清幽可爱。" );
//	

/*****************************************************
	set("outdoors", "dali");
	set("exits",([ 
	    "out"      : __DIR__"changhu",
	]));

********************************************/
};


ROOM_END;
