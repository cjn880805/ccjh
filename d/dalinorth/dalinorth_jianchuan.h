//jianchuan.h

//Sample for room: 大理城剑川镇
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_jianchuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城剑川镇");

	set("resident", "剑川镇");

	//add npcs into the room
	add_npc("pub_lieren");
	add_npc("pub_pihuoshang");

	add_door("大理城剑川山口", "大理城剑川山口", "大理城剑川镇");
	add_door("大理城苍山中部", "大理城苍山中部", "大理城剑川镇");

	set("long", "这里是剑川的镇中心，镇子不大，居民绝大部分是乌夷族，几乎全都以狩猎为生。由于山高地寒，附近山林的野兽大多皮粗毛厚，有不少皮货商在这里和当地猎人交易。北出山口则属大理北疆，也是入蜀之途，南穿苍山则可抵大理内陆。");
};

RESIDENT_END;
