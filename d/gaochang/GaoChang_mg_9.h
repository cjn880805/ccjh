//GaoCang_mg_9.h 地狱第5层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_9);

virtual void create()			
{
	set_name("黑身地狱");

	CDoor * a = add_yewaidoor("west", 10, 20);
	CDoor * b = add_yewaidoor("north", 10, 20);
	CDoor * c = add_yewaidoor("east", 10, 20);
	CDoor * d = add_yewaidoor("south", 10, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("沸屎地狱", "高昌沸屎地狱", "高昌黑身地狱");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("牢房边一厉鬼执鞭猛抽戴枷锁的受刑者，将其驱赶至黑身泥潭去受刑。近处一深不可测的巨大黑泥潭内盛满黑色污水，无数受刑者在潭内挣扎。右侧潭边二鬼正架一受刑者欲推向黑潭之中。 ", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
