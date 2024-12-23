//piandian.h

//Sample for room: 偏殿
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_piandian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "偏殿");

	add_npc("pub_shinu1");  //zdn 2001-07-12 add

	add_door("大理城皇宫前殿", "大理城皇宫前殿", "大理城皇宫偏殿");

	set("long", "这里是大理国皇宫的偏殿，大理皇帝常在这里接见心腹大臣，但现在显得空空荡荡的，往西是长廊。" );

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
