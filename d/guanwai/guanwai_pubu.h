//pubu.h

//Sample for room: 长白瀑布
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_pubu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长白瀑布");
	
	add_npc("pub_bing");     // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("关外小天池", "关外小天池", "关外长白瀑布");
	add_door("关外达门", "关外达门", "关外长白瀑布");

    set("long","天池水从两百余尺高飞流跌落，轰鸣之声远传数里，水花直落大嶂谷，与天然屏障玉壁、金壁相映，恰似白练当空，水柱扑向深深的谷底，溅起几丈高的飞浪，犹如仙女散花，阳光照射下，虹飞氤跃，璀灿壮观之极。" );

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
