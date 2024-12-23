//GaoCang_mg_17.h 地狱第13层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_17);

virtual void create()			
{
	set_name("刀兵地狱");

	CDoor * a = add_yewaidoor("west", 18, 20);
	CDoor * b = add_yewaidoor("north", 18, 20);
	CDoor * c = add_yewaidoor("east", 18, 20);
	CDoor * d = add_yewaidoor("south", 18, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("畜性地狱", "高昌畜性地狱", "高昌刀兵地狱");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("狱中怪石林立，狂风怒号。石柱、石壁狭窄浑暗，透过隙缝可隐现狱外的围城钢亭，怪石中随时伸出鬼头魔爪。", me);
	say("右侧一雄狮怒吼着从半空中向一罪人猛扑过去，恶人被吓得惊恐万状，另一罪人吓得抱头鼠串，藏头不顾尾，还有一个被吓得晕倒在地；左侧一猛虎以猛虎下山之势从山上向一女罪人猛扑下来，女罪人当场晕倒，另两恶人也吓得魂飞魄散。", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
