//GaoCang_mg_6.h 地狱第二层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_6);

virtual void create()			
{
	set_name("刀山地狱");

	CDoor * a = add_yewaidoor("west", 7, 20);
	CDoor * b = add_yewaidoor("north", 7, 20);
	CDoor * c = add_yewaidoor("east", 7, 20);
	CDoor * d = add_yewaidoor("south", 7, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("泥犁地狱", "高昌泥犁地狱", "高昌刀山地狱");
	add_npc("dy_master");

	set("long", "五座山形似尖刀，恰以五指神掌。远处显目的尖山上，数鬼将无数受刑者押上尖刀上，再将罪人从尖刀上推下；漫山遍野竖满无数尖刀，刀山上卧钉、仰钉着受刑者，另一山头受刑者跪地，鬼卒举石将受刑者砸下悬崖，使受刑者受刀山之苦；近处一拇指尖刀山上，二鬼差执叉拿刀按压二受刑者跪地，作欲推状，无数受刑者翻仰悬空嚎叫。 ");

};

virtual int do_look(CChar * me)
{
	say("五座山形似尖刀，恰以五指神掌。远处显目的尖山上，数鬼将无数受刑者押上尖刀上，再将罪人从尖刀上推下；漫山遍野竖满无数尖刀，刀山上卧钉、仰钉着受刑者，另一山头受刑者跪地，鬼卒举石将受刑者砸下悬崖，使受刑者受刀山之苦。", me);
	say("近处一拇指尖刀山上，二鬼差执叉拿刀按压二受刑者跪地，作欲推状，无数受刑者翻仰悬空嚎叫。", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
