//sikong.h

//Sample for room: 司空堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_sikong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "司空堂");

	add_npc("dali_batianshi");

	add_door("大理城王府总理处", "大理城王府总理处", "大理城王府司空堂");

	set("long", "这里是大理国司空堂。堂内无余物，四壁却堆满了书籍。想来主人爱书如命，即便工余亦手不释卷。" );

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
