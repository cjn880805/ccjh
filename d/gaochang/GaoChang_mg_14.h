//GaoCang_mg_14.h 地狱第10层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_14);

virtual void create()			
{
	set_name("寒冰地狱");

	CDoor * a = add_yewaidoor("west", 15, 20);
	CDoor * b = add_yewaidoor("north", 15, 20);
	CDoor * c = add_yewaidoor("east", 15, 20);
	CDoor * d = add_yewaidoor("south", 15, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("嵯山地狱", "高昌嵯山地狱", "高昌寒冰地狱");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("狱中，冰山雪地，寒风呼啸，远处重叠的围城积淀着恺恺白雪，从兽形的围城大门内喷射出雪花和寒风，形状各异的冰柱上，冻结了无数的罪人骷髅残躯。", me);
	say("稍后，冰川侧的冰山下罪人们蜷伏冰窟雪地之中，有的赤身裸体，有的只穿裤衩，个个冻得直打哆嗦，真是“路有冻死骨，冰川尸骨寒”。鬼差们持刀操棒，戒备森严，唯有冰山冰塔中有微火闪烁。 ", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
