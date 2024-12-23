//minadian.h

//Sample for room: 蜜纳甸
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiWest_minadian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "蜜纳甸");

	set("resident", "镇雄");

	//add npcs into the room
	add_npc("pub_shaonu");
	
	add_door("大理城葛鲁城", "大理城葛鲁城", "大理城蜜纳甸");

	set("long", "这里是乌夷分支乌蒙族阔部聚居的镇子，阔部领蜜纳甸和阔州。附近有溪流汇入泸水，灌溉颇便利，因而农业相对谷中其他地区较发达。镇中尽是些简陋的民居，也无甚客商过往。" );

};

RESIDENT_END;
