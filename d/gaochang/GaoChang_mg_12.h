//GaoCang_mg_12.h 地狱第8层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_12);

virtual void create()			
{
	set_name("铁床地狱");

	CDoor * a = add_yewaidoor("west", 13, 20);
	CDoor * b = add_yewaidoor("north", 13, 20);
	CDoor * c = add_yewaidoor("east", 13, 20);
	CDoor * d = add_yewaidoor("south", 13, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("镬汤地狱", "高昌镬汤地狱", "高昌铁床地狱");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("岩层中有围城，围城吸巨石，巨石间有木柱、石柱、木质串斗房架、铁栏、木栏等。巨型石拱内置一巨的铁钉床，床头有兽型浮雕，滚烫的铁钉床上躺着烧焦若干罪人。", me);
	say("鬼差们举起铁锤击打罪人，有的用铁叉叉制罪人受刑，铁床边二鬼卒用铁铲向床下添加着燃料，还有数鬼卒强抢押着受罪者的拖往铁床，床的另一边吹火加柴鬼若干。", me);
	SendMenu(me);
	return 1;
}
YEWAIDOOR_END;
