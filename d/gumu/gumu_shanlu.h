//shanlu.h

//Sample for room: 古墓山路
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRGuMu_shanlu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓山路");

	add_npc("pub_daoke");   //add by zdn 2001-07-13

	add_door("古墓终南山主峰", "古墓终南山主峰", "古墓山路");
	add_door("古墓空地", "古墓空地", "古墓山路");

	set("long","这条山路盘终南山主峰而上，山路贴着石璧凿出，只容一人可过，形势极为险峻。往远处望去。群山环绕，列於脚下，百里美景尽收眼底，顿时令人豪气陡声，想要长啸一声。往南下是一片空地。往北上就是终南山主峰。" );

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
