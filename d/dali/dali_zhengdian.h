//zhengdian.h

//Sample for room: 正殿
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_zhengdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "正殿");

	add_npc("pub_shinu1");   // zdn 2001-07-12 add
	add_npc("pub_zhaojunzhu");

	add_door("大理城皇宫前殿", "大理城皇宫前殿", "大理城皇宫正殿");

	set("long", "这里是大理国皇宫的正殿，大理皇帝通常都在这里处理国事，但现在皇帝不在，所以显得不那么拘谨，往南是长廊。" );

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
