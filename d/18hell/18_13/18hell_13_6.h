//18hell_13.h
//十八地狱第九层嵯山地狱第6房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_13_6);

virtual void create()			//Call it when Room Create
{
	set_name("嵯山地狱");
	
	add_npc("diyu_shizhe13");

};

virtual int do_look(CChar * me)
{
	say("远处阴山重叠，此起彼伏，山下涧溪，中由远至近恰似流入无底深渊，远中近分布一座险峻奇特的山巅，山巅之间有铁索相连，罪人们被鬼差押着、驱赶着被迫向上攀登，强逼过铁索。", me);
	say("有的爬到半山，有的爬到山顶被鬼差推跌山下，有的过铁索被打下深渊。中右两大山间的铁索旁分站两巨鬼差，右边的持叉，左边的持狼牙锤怒视着过索的罪鬼，罪鬼们纷纷掉入溪涧，左边前的两山间有铁索 ", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
