//luojiadian.h

//Sample for room: 大理城罗伽甸
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_luojiadian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城罗伽甸");

	set("resident", "罗伽甸");

	add_npc("pub_nongfu");    // add by zdn 2001-07-12 

	add_door("大理城沿池堤岸3", "大理城沿池堤岸3", "大理城罗伽甸");
	add_door("大理城滇池沿岸1", "大理城滇池沿岸1", "大理城罗伽甸");
	add_door("大理城农田2", "大理城农田2", "大理城罗伽甸");

	set("long", "这里是滇池的东南，是么些蛮的罗伽部落聚居的地方。么些蛮族属摆夷。摆夷喜居平原沿水，（沿水的平原坝子，即为“甸”）。这里土壤肥沃，灌溉便易。罗伽是一个大部落，罗伽甸是个相当大的镇子，大理国在这里设有治府。" );
	
};


RESIDENT_END;
