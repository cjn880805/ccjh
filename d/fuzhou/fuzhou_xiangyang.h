//xiangyang.h

//Sample for room: 向阳巷
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_xiangyang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "向阳巷");

	add_npc("pub_playboy");  // add by zdn 2001-07-13

	add_door("福州南", "福州南", "福州向阳巷");
	add_door("福州杂货铺", "福州杂货铺", "福州向阳巷");
	add_door("福州向阳老宅", "福州向阳老宅", "福州向阳巷");

    set("long", "这里是福州城西向阳巷。北面有一所破败的宅子。西面有一家杂货铺，专卖女人家用的东西，男人不可以进去。" );
	
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
