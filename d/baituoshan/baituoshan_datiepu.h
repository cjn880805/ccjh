//datiepu.h

//Sample for room: 打铁铺
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_datiepu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山打铁铺");
	add_npc("pub_tiejiang");

	add_door("白驼山东街", "白驼山东街", "白驼山打铁铺");

	set("long", "这里是一家打铁铺，铁匠忙着打制铁制兵器，卖给江湖侠客。");

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
