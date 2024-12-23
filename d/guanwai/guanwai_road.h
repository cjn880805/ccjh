//road.h

//Sample for room: 关外官道
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_road);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "关外官道");

	set("resident", "关外宁远");
	
	add_npc("pub_playboy");
	add_npc("pub_punk");    // add by zdn 2001-07-13  

	set("monster_chance", 50);

	add_door("关外山海关", "关外山海关", "关外官道");
	add_door("关外宁远", "关外宁远", "关外官道");

    set("long","这里是通往关外的官道，几米宽的大道，全部由黄土铺成，可并行三四辆马车而不显拥挤。这里是进出关口的必经之路，路上三俩成群的行人都是往来贩运皮货，药材的生意人。偶尔有身着官兵骑马飞驰而过。" );
	

/*****************************************************
	set("exits", ([
		"north"     : __DIR__"ningyuan",
		"southwest" : __DIR__"road2",
	]));
********************************************/
};


RESIDENT_END;
