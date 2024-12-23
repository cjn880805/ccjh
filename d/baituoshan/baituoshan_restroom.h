//restroom.h

//Sample for room: 休息室
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_restroom);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "休息室");


	add_door("白驼山长廊", "白驼山长廊", "白驼山休息室");

	set("long", "这里是间休息室，里面有张大床。在这里睡觉非常舒服，没人能打扰。南面是气派的长廊。");  
    set("sleep_room", 1);
    set("no_fight",1);
    set("no_steal",1);
    set("no_clean_up", 0l);

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
