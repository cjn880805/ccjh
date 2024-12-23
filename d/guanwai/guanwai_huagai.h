//huagai.h

//Sample for room: 华盖峰
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_huagai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华盖峰");

	set("monster_chance", 50);
	
	add_npc("pub_youke");    // add by zdn 2001-07-13

	add_door("关外天豁峰", "关外天豁峰", "关外华盖峰");
	add_door("关外白头山天池1", "关外白头山天池1", "关外华盖峰");

    set("long","长白东侧最高峰，自古以来，华盖峰就是风雨云雾的故道。云雾起处，恰似掀开锅盖一般，雾气翻滚，池水云天，一脉相连，气壮华夏，故名华盖峰。" );

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
