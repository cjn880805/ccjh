//jiulou.h

//Sample for room: 楼外楼
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_jiulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "楼外楼");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	add_npc("pub_caozhangguei");

	set("no_fight",1);
	set("no_cast",1);
	set("no_beg",1);

	add_door("杭州青石大道10", "杭州青石大道10", "杭州楼外楼");
	add_door("杭州楼外楼二楼", "杭州楼外楼二楼", "杭州楼外楼");

	set("long","提起“楼外楼”方圆百里无人不知。这里各式名菜是杭州一绝。来游湖的人们都一定会来这里尝尝。整个大堂闹哄哄的挤满了各式人等。店小儿跑来跑去，忙着招呼客人。墙上挂着价格牌子(paizi)。" );


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
