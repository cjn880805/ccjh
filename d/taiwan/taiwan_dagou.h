//dagou.h
//Sample for room: 台湾打狗港
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRTaiWan_dagou);

virtual void create()			//Call it when Room Create
{

	set_name( "台湾打狗港");
	set("monster_chance", 20);

	add_npc("pub_wokou");
	add_npc("taiwan_scavenger");
	add_npc("pub_panjianke");

	add_door("台湾荒地", "台湾荒地", "台湾打狗港");
	add_door("泉州澎湖岛", "泉州澎湖岛", "台湾打狗港");

	set("long", "打狗港位于台湾南部，港域口小腹大，外有岛链环抱，内具曲折峡湾，诚全台第一良港。  " );
};

ROOM_END;
