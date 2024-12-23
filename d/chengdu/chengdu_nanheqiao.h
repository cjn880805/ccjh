//nanheqiao.h

//Sample for room: 南河桥
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_nanheqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "南河桥");

	add_npc("pub_huanu");
	add_npc("pub_jianke");   //zdn 2001-07-12 add

	add_door("成都西", "成都西", "成都南河桥");
	add_door("成都溪岸小路", "成都溪岸小路", "成都南河桥");
	add_door("血刀门雪山路1", "血刀门雪山路1", "成都南河桥");

	set("long",	"这里是成都西门外南河桥。府河和南河夹城流过，呵护着这个天府之国的首府之地。河水清新碧透。东面是西城门，往西就是浣花溪了。"	);

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
