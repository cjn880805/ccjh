//beijing_dongnan.h

//Sample for room:  北京东南
//coded by Fisho
//data: 2000-11-2


RESIDENT_BEGIN(CRbeijing_dongnan);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "北京东南");

	set("resident", "北京");
	//add npcs into the room

	add_npc("pub_boy");
	add_npc("pub_lady1");
	add_npc("pub_playboy");


	add_door("北京钱庄", "北京钱庄", "北京东南");
	add_door("北京怡红院", "北京怡红院", "北京东南");
	add_door("北京打铁铺", "北京打铁铺", "北京东南");
	add_door("北京鳌府", "北京鳌府", "北京东南");
				
	add_door("北京东北", "北京东北", "北京东南");
	add_door("北京皇城", "北京皇城", "北京东南");
	add_door("北京大驿道1", "北京大驿道1", "北京东南");


};


RESIDENT_END;