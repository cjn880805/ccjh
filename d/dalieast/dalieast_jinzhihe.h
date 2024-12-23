//jinzhihe.h

//Sample for room: 大理城金汁河畔
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jinzhihe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城金汁河畔");

	add_npc("pub_bing");   // add by zdn 2001-07-12 

	add_door("大理城经幢1", "大理城经幢1", "大理城金汁河畔");
	add_door("大理城山区小径", "大理城山区小径", "大理城金汁河畔");
	add_door("大理城沿池堤岸1", "大理城沿池堤岸1", "大理城金汁河畔");

	set("long", "这里位处金汁河畔，原本建有一座地藏寺，如今寺院早废。唯有一座石刻经幢(jingzhuang)半埋土中。此幢为方锥状，七层石雕。高约丈五尺，基座为八角形的磐石，边上刻有莲花；层与层之间有界石。即是本层之盖檐，又是上层之基石。" );
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
