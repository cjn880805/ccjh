//chahuashan2.h

//Sample for room: 大理城茶花山2
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_chahuashan2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城茶花山2");

	add_npc("dali_huanu");  
	add_npc("pub_youke");   // add by zdn 2001-07-12

	add_door("大理城茶花山5", "大理城茶花山5", "大理城茶花山2");
	add_door("大理城茶花山4", "大理城茶花山4", "大理城茶花山2");
	add_door("大理城茶花山1", "大理城茶花山1", "大理城茶花山2");
	add_door("大理城茶花山3", "大理城茶花山3", "大理城茶花山2");

	set("long", "你走在茶花山上，这里遍地是生长茂盛的茶花。当然，大部分是凡品，但偶尔也会有一两株佳品藏匿其中。北望不远是大理城的西门，东边不远是城墙。" );

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
