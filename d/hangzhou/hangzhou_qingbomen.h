//qingbomen.h

//Sample for room: 杭州清波门
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_qingbomen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州清波门");

	//add npcs into the room
	add_npc("pub_girl");
	
	add_door("杭州聚景园", "杭州聚景园", "杭州清波门");
	add_door("杭州青石大道14", "杭州青石大道14", "杭州清波门");

	set("long"," 园门口有一大门楼，大匾上刻着“清波门”。门楼下站着几个嬉嬉哈哈的少女，惹人坠步相观。在往西就进了聚景，往东便回到大路。    过桥往西走便是白堤了。东北边可通往青石大道");

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
