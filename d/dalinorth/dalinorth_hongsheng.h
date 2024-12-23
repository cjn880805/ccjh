//hongsheng.h

//Sample for room: 宏圣寺塔
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLiNorth_hongsheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "宏圣寺塔");

	add_npc("pub_jianke");    // add by zdn 2001-07-13
	add_npc("dali_poyi");        //add by zdn 2001-07-20

	add_door("大理城苍山", "大理城苍山", "大理城宏圣寺塔");
	add_door("天龙寺大门", "天龙寺大门", "大理城宏圣寺塔");

	set("long", "宏圣寺塔又名“一塔”，屹立于苍山之麓，面向洱海，为云南著名唐塔之一。宏圣寺塔为四方形空心砖石塔，塔身各层之间用砖砌出跌涩椽，使其四角飞翘。整个塔身轮廓呈抛物线，优美流畅。" );
	
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
