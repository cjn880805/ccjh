//suti2.h

//Sample for room: 杭州苏堤2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州苏堤2");
	
	add_npc("pub_bing");        // add by zdn 2001-07-14


	add_door("杭州苏堤1", "杭州苏堤1", "杭州苏堤2");
	add_door("杭州苏堤3", "杭州苏堤3", "杭州苏堤2");
	add_door("杭州曲院风荷", "杭州曲院风荷", "杭州苏堤2");

	set("long"," 苏堤上，游客们有的林荫大道上漫步吟诗，高谈阔论；有的随机就石，临水而坐；有的伶立湖边，静享湖景。北边是跨虹桥，南面是东浦桥，西面是去曲园风荷。");

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
