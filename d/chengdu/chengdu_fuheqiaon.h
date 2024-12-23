//fuheqiaon.h

//Sample for room: 府河桥
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_fuheqiaon);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "府河桥");

	add_npc("pub_nieyinnang");
	add_npc("pub_daoke");
	add_npc("pub_punk");         //zdn 2001-07-12  add
	add_npc("pub_simingtoutuo");

	add_door("成都中", "成都中", "成都府河桥");
	add_door("青城青石大道", "青城青石大道", "成都府河桥");

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
