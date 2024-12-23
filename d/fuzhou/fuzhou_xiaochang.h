//xiaochang.h

//Sample for room: 校场
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_xiaochang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "校场");

	add_npc("pub_jianke");
	add_npc("pub_daoke");      //add by zdn 2001-07-13

	add_door("福州南", "福州南", "福州校场");

	set("long", "福州校场为福建水师校场。场中点将楼上高挂“施”字黑锈金边帅旗，刀枪耀日生辉。水师提督施琅施大人亲率十万雄兵，隔海相望，壮心不已。" );
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
