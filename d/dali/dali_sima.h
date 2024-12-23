//sima.h

//Sample for room: 司马堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_sima);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "司马堂");

	add_npc("dali_fanye");	

	add_door("大理城王府总理处", "大理城王府总理处", "大理城王府司马堂");

	set("long", "这里是大理国司马堂。大理东北强宋，西北吐蕃，历年来边疆宁靖，皆司马劳顿之功。盖吐蕃垂涎大理已久，每每强辞胁迫，大理不得不重兵于西北。" );

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
