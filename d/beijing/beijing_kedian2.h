//kedian2.h

//Sample for room: 客店
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_kedian2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "客店2");


	add_door("北京西南", "北京西南", "北京客店2");

	set("long", "这是一家价钱低廉的客店，因为地方偏僻，房客很少。不时有打斗之声从东南边传来。掌柜早不知躲哪儿去了，屋里见不到一个人。南边是后院，通往各厢房。" );
    set("sleep_room",1);

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
