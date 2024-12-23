//jianchuankou.h

//Sample for room: 大理城剑川山口
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_jianchuankou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城剑川山口");

	set("resident", "剑川镇");

	//add npcs into the room
	add_npc("pub_wujiang");
	add_npc("pub_bing");

	add_door("大理城剑川镇", "大理城剑川镇", "大理城剑川山口");
	add_door("大理城川西山路", "大理城川西山路", "大理城剑川山口");

	set("long", "这里是苍山北麓的一个乌夷城镇。此地正处山口，两边崇山峻岭耸立，几乎无路可行，唯有穿此镇可入苍山，因此是从蜀中至大理的军事要冲，大理国在此修有刁楼箭塔，常年驻军。有官兵在镇口站岗巡逻，盘察过往行人。");
	
};

RESIDENT_END;
