//fangheting.h

//Sample for room: 杭州放鹤亭
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_fangheting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州放鹤亭");
	
	add_npc("pub_playboy");        // add by zdn 2001-07-14

	add_door("杭州孤山", "杭州孤山", "杭州放鹤亭");
	add_door("杭州平湖秋月", "杭州平湖秋月", "杭州放鹤亭");

	set("long"," 亭四周种满了梅花。一到冬末春初，梅花盛放，蔚然可观。此亭是为了纪念北宋隐逸诗人林和靖而建。他酷爱梅花。“疏影横斜水清浅，暗香浮动月黄昏”就是他的咏梅名句。据传说，诗人还养鹤一只，取名：“鸣苯”每逢自己外出散步而恰有客人来访时，童子就开笼放鹤，诗人见鹤，便回家接客，故流传有“梅妻鹤子”的故事。朝东南走便是平湖秋月。西南边则是孤山。");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
