//qulan1.h

//Sample for room: 后宫小道


ROOM_BEGIN(CRLingZhou_qulan1);

virtual void create()		
{
	set_name( "画廊");

	add_door("灵州皇宫后宫小道", "灵州皇宫后宫小道", "灵州皇宫后宫画廊");
	add_door("灵州皇宫后宫曲栏2", "灵州皇宫后宫曲栏2", "灵州皇宫后宫曲栏1");

	set("no_fight",1);
	set("no_cast",1);
	add_npc("lj_gongnv");
	add_npc("lj_gongnv");

};

ROOM_END;
