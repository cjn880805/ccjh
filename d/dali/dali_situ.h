//situ.h

//Sample for room: 司徒堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_situ);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "司徒堂");

	add_npc("dali_huahegen");	

	add_door("大理城王府总理处", "大理城王府总理处", "大理城王府司徒堂");

	set("long", "这里是大理国司徒堂。大理君臣勤政爱民，三公劳作自不带言。堂内无余物，奇怪的是地上角落还摆了些铁铲，孔明灯之类的物事。" );

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
