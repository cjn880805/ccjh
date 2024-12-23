//zhangfang.h

//Sample for room: 帐房
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_zhangfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "帐房");

	//add npcs into the room
	add_npc("pub_huo");
	
	add_door("大理城王府大厅", "大理城王府大厅", "大理城王府帐房");

	set("long", "这里是镇南王府的帐房，王府每天的银米出入，往来消耗，全由这里经手，包括家丁下人的薪俸赏赐，在在都是麻烦多多。这里却从来没出过差错。" );

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
