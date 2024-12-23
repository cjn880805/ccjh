//GaoCang_mg_13.h 地狱第9层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_13);

virtual void create()			
{
	set_name("嵯山地狱");

	CDoor * a = add_yewaidoor("west", 14, 20);
	CDoor * b = add_yewaidoor("north", 14, 20);
	CDoor * c = add_yewaidoor("east", 14, 20);
	CDoor * d = add_yewaidoor("south", 14, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("铁床地狱", "高昌铁床地狱", "高昌嵯山地狱");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("远处阴山重叠，此起彼伏，山下涧溪，中由远至近恰似流入无底深渊，远中近分布一座险峻奇特的山巅，山巅之间有铁索相连，罪人们被鬼差押着、驱赶着被迫向上攀登，强逼过铁索。", me);
	say("有的爬到半山，有的爬到山顶被鬼差推跌山下，有的过铁索被打下深渊。中右两大山间的铁索旁分站两巨鬼差，右边的持叉，左边的持狼牙锤怒视着过索的罪鬼，罪鬼们纷纷掉入溪涧，左边前的两山间有铁索 ", me);
	SendMenu(me);
	return 1;
}
YEWAIDOOR_END;
