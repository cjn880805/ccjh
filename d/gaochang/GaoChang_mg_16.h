//GaoCang_mg_16.h 地狱第12层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_16);

virtual void create()			
{
	set_name("畜性地狱");

	CDoor * a = add_yewaidoor("west", 17, 20);
	CDoor * b = add_yewaidoor("north", 17, 20);
	CDoor * c = add_yewaidoor("east", 17, 20);
	CDoor * d = add_yewaidoor("south", 17, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("剥皮地狱", "高昌剥皮地狱", "高昌畜性地狱");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("洞口前一巨鬼手提一罪人，从一巨石上将罪人扔进狱中，四周高墙耸立，高墙下是木桩栏成的畜圈，圈中，牛、羊、猪、狗、狼、虎、貂、狮等动物正在撕咬吞食罪人，残肢、断腿、破头、裂肚，罪人痛苦异常。", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
