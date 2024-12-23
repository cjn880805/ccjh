//jiulou.h

//Sample for room: 味中味
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_jiulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "味中味");

	//add npcs into the room
//	add_npc("pub_xiaoer3");
	
	add_door("福州南", "福州南", "福州味中味");

    set("long", "提起“楼外楼”方圆百里无人不知。这里各式闽菜均是福州一绝。来游湖的人们都一定会来这里尝尝。整个大堂闹哄哄的挤满了各式人等。店小儿跑来跑去，忙着招呼客人。墙上挂着价格牌子(paizi)。" );
	
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
