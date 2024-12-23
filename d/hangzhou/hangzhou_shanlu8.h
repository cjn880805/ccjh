//shanlu8.h

//Sample for room: 杭州山路8
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州山路8");
	
	add_npc("pub_punk");              // add by zdn 2001-07-14


	add_door("杭州青石大道7", "杭州青石大道7", "杭州山路8");
	add_door("杭州黄龙洞", "杭州黄龙洞", "杭州山路8");

	set("long"," 山上林木茂密，就是炎夏这里还是清凉依旧。朝北走便到了黄龙洞。南边则是下山的路。");

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
