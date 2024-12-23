//cangshanzhong.h

//Sample for room: 苍山中部
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_cangshanzhong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "苍山中部");

	set("resident", "下关城");

	add_npc("pub_liumang");
	add_npc("pub_liumang");       //add by zdn 2001-07-13

	add_door("大理城下关城", "大理城下关城", "大理城苍山中部");
	add_door("大理城剑川镇", "大理城剑川镇", "大理城苍山中部");
	add_door("大理城苍山山路", "大理城苍山山路", "大理城苍山中部");

	set("long", "你行走在苍山中部山颠，此间地形极险，两边山高入云，中间一条崎岖不平的山路。路西不远一条大河自北略偏西方向南流过，隆隆水声遥遥可闻，正是南诏名川--泸水。此路是自西川和土番入大理的必经之途，时有客商过往。由此向南穿越苍山可抵下关城，北面不远则是出苍山的山口。" );
	
};


RESIDENT_END;
