//xiaodao.h

//Sample for room: 后宫小道


ROOM_BEGIN(CRLingZhou_xiaodao);

virtual void create()		
{
	set_name( "后宫小道");

	add_door("灵州皇宫幽兰涧东", "灵州皇宫幽兰涧东", "灵州皇宫后宫小道");
	add_door("灵州皇宫后宫曲栏1", "灵州皇宫后宫曲栏1", "灵州皇宫后宫小道");

	set("no_fight",1);
	set("no_cast",1);
	add_npc("lj_gongnv");
	add_npc("lj_gongnv");

};

ROOM_END;
