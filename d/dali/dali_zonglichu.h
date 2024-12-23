//zonglichu.h

//Sample for room: 总理处
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_zonglichu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "总理处");

	add_npc("pub_shiwei");
	add_npc("pub_shiwei2");  //zdn 2001-07-12 add

	add_door("大理城王府司空堂", "大理城王府司空堂", "大理城王府总理处");
	add_door("大理城王府司马堂", "大理城王府司马堂", "大理城王府总理处");
	add_door("大理城王府司徒堂", "大理城王府司徒堂", "大理城王府总理处");
	add_door("大理城王府大厅", "大理城王府大厅", "大理城王府总理处");

	set("long", "总理处是镇南王皇太弟总理国务之处，满桌的奏章整理得井井有条。四周摆了很多茶花，争奇斗艳。茶花是大理国花，看来主人对它也是钟爱有加。" );
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
