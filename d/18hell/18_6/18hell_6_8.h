//18hell_6.h
//十八地狱第二层刀山地狱第8房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_6_8);

virtual void create()			//Call it when Room Create
{
	set_name("刀山地狱");
	set("long", "五座山形似尖刀，恰以五指神掌。远处显目的尖山上，数鬼将无数受刑者押上尖刀上，再将罪人从尖刀上推下；漫山遍野竖满无数尖刀，刀山上卧钉、仰钉着受刑者，另一山头受刑者跪地，鬼卒举石将受刑者砸下悬崖，使受刑者受刀山之苦；近处一拇指尖刀山上，二鬼差执叉拿刀按压二受刑者跪地，作欲推状，无数受刑者翻仰悬空嚎叫。 ");
	
	add_npc("diyu_shizhe6");

};

virtual int do_look(CChar * me)
{
	say("五座山形似尖刀，恰以五指神掌。远处显目的尖山上，数鬼将无数受刑者押上尖刀上，再将罪人从尖刀上推下；漫山遍野竖满无数尖刀，刀山上卧钉、仰钉着受刑者，另一山头受刑者跪地，鬼卒举石将受刑者砸下悬崖，使受刑者受刀山之苦。", me);
	say("近处一拇指尖刀山上，二鬼差执叉拿刀按压二受刑者跪地，作欲推状，无数受刑者翻仰悬空嚎叫。", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
