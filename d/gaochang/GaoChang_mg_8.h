//GaoCang_mg_8.h 地狱第4层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_8);

virtual void create()			
{
	set_name("沸屎地狱");

	CDoor * a = add_yewaidoor("west", 9, 20);
	CDoor * b = add_yewaidoor("north", 9, 20);
	CDoor * c = add_yewaidoor("east", 9, 20);
	CDoor * d = add_yewaidoor("south", 9, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("沸沙地狱", "高昌沸沙地狱", "高昌沸屎地狱");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("形成转角的围城高墙间有钢链，中间高墙上一铁锅内沸烟滚滚，二鬼分立锅旁，手持长柄瓢，将锅内烧得滚烫的污浆从高墙上倾泻到墙下的受刑者身上。。", me);
	say("无数受刑者挣扎在被木据、铁链困围的平台上，有少许受刑者晕趴于木桩上，不得动弹。右侧高高的石岩上，数鬼推押着受刑者到沸屎地狱受刑。", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
