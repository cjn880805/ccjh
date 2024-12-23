//jilong.h
//Sample for room: 台湾鸡笼港
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRTaiWan_jilong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "台湾鸡笼港");
	set("resident", "鸡笼");
	set("capacity", 5);
	
	add_npc("pub_yufu");       //add by zdn 2001-07-16
	add_npc("pub_liudingguo");
	add_door("台湾荒地", "台湾荒地", "台湾鸡笼港");
	add_door("泉州澎湖岛", "泉州澎湖岛", "台湾鸡笼港");

	set("long", "鸡笼为台湾北部良港。群山环抱的港口腹地广大，人烟稠密，有“台湾诸葛亮”之称的陈永华先生在此垦田养桑，修养生息，遗爱甚长。  " );

};





RESIDENT_END;
