//hcaxiuxishi.h
//Sample for room:  峨嵋华藏庵休息室
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcaxiuxishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋华藏庵休息室");
	add_door("峨嵋华藏庵东廊1", "峨嵋华藏庵东廊1", "峨嵋华藏庵休息室");
	add_door("峨嵋万年庵", "峨嵋万年庵", "峨嵋华藏庵休息室");

	set("long","这里是峨嵋华藏庵的休息室。窗帘拉下来，房里整整齐齐放了很多木床。有几个夜晚守庵的小师太正在睡觉。休息室外就是禅房。");
    set("sleep_room", 1);

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
