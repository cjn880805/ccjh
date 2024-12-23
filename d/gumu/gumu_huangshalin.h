//huangshalin.h

//Sample for room: 古墓黄沙岭
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_huangshalin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓黄沙岭");

	add_npc("pub3_huangyishizhe");   //add by zdn 2001-07-13 
	add_npc("pub_shenmike");

	add_door("古墓墓门", "古墓墓门", "古墓黄沙岭");

	set("long","此处位於终南山西部。只见远处王曲原上，孤立着一座由荒沙堆积而成的山岭，波纹为奇特。据当地人说，这是在商朝，一位名叫陆亚仙的人，用法力遣来一股黄沙而成。往东是一片密林。" );
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
