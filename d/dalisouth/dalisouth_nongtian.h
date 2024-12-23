//nongtian.h

//Sample for room: 农田
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_nongtian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "农田");

	set("resident", "喜州");

	//add npcs into the room
	add_npc("pub_nongfu1");
	add_item("daotian");
	
	add_door("大理城武定镇", "大理城武定镇", "大理城农田");


	set("long", "一小片在山坡下的竹林里开垦出来的农田，临有溪流，种植着水稻。台夷生活很大程度上依靠农业，从事农业的却基本上是妇女。男子大都专司狩猎和捕鱼。" );
	
};

RESIDENT_END;
