//GaoCang_mg_20.h 地狱第16层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_20);

virtual void create()			
{
	set_name("蛆虫地狱");

	CDoor * a = add_yewaidoor("west", 21, 20);
	CDoor * b = add_yewaidoor("north", 21, 20);
	CDoor * c = add_yewaidoor("east", 21, 20);
	CDoor * d = add_yewaidoor("south", 21, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("冰地狱", "高昌冰地狱", "高昌蛆虫地狱");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("狱中一巨大的岩石中间有一圆形深坑，深坑内，一大鬼、四小鬼毒蛇缠身，罪人正被毒蛇、毒蝎、蛆虫等钻咬叮食。坑外高高的岩石边，一罪人正被二鬼差揪押着欲推入坑中。", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
