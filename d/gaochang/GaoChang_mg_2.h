//GaoCang_mg_2.h 十八地狱入口一
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_2);

virtual void create()			
{
	set_name("黄泉之路");

	CDoor * a = add_yewaidoor("west", 3, 20);
	CDoor * b = add_yewaidoor("north", 3, 20);
	CDoor * c = add_yewaidoor("east", 3, 20);
	CDoor * d = add_yewaidoor("south", 3, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("高昌迷宫", "高昌迷宫", "高昌黄泉之路");
	add_npc("dy_master");

	set("long", "这里是通往十八地狱的“黄泉”，四周的亡魂被一种莫名的力量引导着，走向一个巨大的地下洞穴边缘，并不断的跳了下去。");


};

YEWAIDOOR_END;
