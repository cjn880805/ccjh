//yanchi3.h

//Sample for room: 大理城沿池堤岸3
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_yanchi3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城沿池堤岸3");

	set("resident", "罗伽甸");

	//add npcs into the room
	add_npc("pub_guigongzi");
	add_npc("pub_enu");

	add_door("大理城罗伽甸", "大理城罗伽甸", "大理城沿池堤岸3");
	add_door("大理城沿池堤岸2", "大理城沿池堤岸2", "大理城沿池堤岸3");

	set("long", "这里是滇池游客聚集之处，演鄯候高生世就时时承舟优胜于烟水缈蔼的滇池，欣赏“梵刹于滇波向仰抑”的美景，并常停舟官渡，饮酒赋诗，被称之为“停舟烟会”。这里的东浦彩虹、西山白雨、空中鹭鸶、晚霞潮红、归帆远影、无不给人以美的享受。" );

};


RESIDENT_END;
