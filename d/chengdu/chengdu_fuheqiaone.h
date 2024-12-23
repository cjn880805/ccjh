//fuheqiaone.h

//Sample for room: 东府河桥
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_fuheqiaone);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "东府河桥");

	add_npc("pub_girl1");
	add_npc("pub_playboy");        //zdn 2001-07-12  add

	add_door("成都东", "成都东", "成都东府河桥");
	add_door("武当三不管", "武当三不管", "成都东府河桥");

	set("long",	"这里是成都北门外府河桥。成都虽是川中首府，却无险可守，一旦敌方兵至成都平原，即使府南两河水涨，也就只有祷告对方慈悲的选择了。"	);

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
