//18hell_10.h
//十八地狱第六层火海地狱BOSS房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_10);

virtual void create()			//Call it when Room Create
{
	set_name("火海狱底");
	
	add_npc("shuizhizi");
	add_npc("diyu_shizhe10");

};

virtual int do_look(CChar * me)
{
	say("梯形状的火海熊熊燃烧，烈烟滚滚，一望无际，近处被火焚烧的残尸隐约可见。中间区一巨大的悬崖边上，数鬼差押着受刑者前往岩边，有的受刑者跪着、躺着，有的被拖着在作垂死挣扎，一巨鬼差正高举一受刑者怒吼着将其抛入火海。", me);
	say("近处的石岩上，数鬼分推着双轮的、独轮火车，车上有受刑者，将其倾入火海。", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
