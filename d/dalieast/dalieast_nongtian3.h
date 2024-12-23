//nongtian3.h

//Sample for room: 大理城农田3
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_nongtian3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城农田3");

	set("resident", "阳宗镇");

	//add npcs into the room
	add_npc("pub_nongfu2");
	
	add_door("大理城农田2", "大理城农田2", "大理城农田3");
	add_door("大理城山路7", "大理城山路7", "大理城农田3");

	set("long", "这里已经是平原的尽头，对面就是险峻的山岭了，一些的农田和罗伽部村民的房屋零星地分布在山脚下，一些村民正在田里耕作。有条道路向东南的山上蜿蜒而去。" );
	
};

RESIDENT_END;
