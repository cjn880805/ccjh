//yulin.h

//Sample for room: 榕树雨林
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_yulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "榕树雨林");

	add_npc("pub_nongfu2");   // add by zdn 2001-07-13

	add_door("大理城鲁望镇", "大理城鲁望镇", "大理城榕树雨林");

	set("long", "这是一片湿润的雨林，脚下水汪汪的无路可行，十数丈高的巨大榕树盘根错节，树干粗得几个人合抱也围不住。榕树的树枝下垂到泥水中反过来扎根，成为特意的景致。雨林虽然少有走兽，却是飞禽聚居的乐土，身手零活的台夷猎人攀越在大榕树浮露的根枝上，用短弩射猎飞鸟。" );
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
