//dazhulou.h

//Sample for room: 大竹楼
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLisouth_dazhulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大竹楼");

	add_npc("pub_jisi");            // add by zdn 2001-07-13

	add_door("大理城南", "大理城南", "大理城南大竹楼");
	add_door("大理城南议事堂", "大理城南议事堂", "大理城南大竹楼");

	set("long", "这是一座普通样式的台夷竹楼，建在鲁望镇中心，与四周其它竹楼比占地广大得多，也特别高大，似有三层，正是普麽部的祭祀大屋。此处下层也不养牲畜，打扫得干干净净。宽大的竹梯直通上层。" );
	
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
