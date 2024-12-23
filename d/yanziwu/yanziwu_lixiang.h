//lixiang.h

//Sample for room: 燕子坞梨香苑
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_lixiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞梨香苑");

	add_door("燕子坞龙凤厅", "燕子坞龙凤厅", "燕子坞梨香苑");
	add_door("燕子坞长廊", "燕子坞长廊", "燕子坞梨香苑");
	add_door("燕子坞穿堂", "燕子坞穿堂", "燕子坞梨香苑");

    set("long", "慕容家的后院也与众不同，圆形院门上刻有梨香苑三字，院中雪白的梨花开满了枝头。西侧就是接待贵宾的龙凤厅了，东侧有一条精美的长廊。" );
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
//last, register the room into ../server/RoomSetup.cpp