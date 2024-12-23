//lushui.h

//Sample for room: 泸水沿岸
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_lushui);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泸水沿岸");
	
	add_npc("pub_cunfu");    //add by zdn 2001-07-13

	add_door("大理城巴的甸", "大理城巴的甸", "大理城泸水沿岸");
	add_door("大理城阿头部", "大理城阿头部", "大理城泸水沿岸");

	set("long", "一条土路沿着泸水纵贯谷地南北，脚下泸水滔滔流去，长年累月冲刷着谷中大地，东面碧罗雪山、西面的高黎山皆高耸蔽日。土路北通此谷中心大镇巴的甸，南连数个乌夷小部落。" );
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
