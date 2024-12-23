//feilaifeng.h

//Sample for room: 杭州飞来峰
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_feilaifeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州飞来峰");
	
	add_npc("pub_daoke");
	add_npc("pub_oldwoman");    //add by zdn 2001-07-14


	add_door("杭州清林洞", "杭州清林洞", "杭州飞来峰");
	add_door("杭州龙泓洞", "杭州龙泓洞", "杭州飞来峰");
	add_door("杭州青石大道1", "杭州青石大道1", "杭州飞来峰");

	set("long","飞来峰又名灵鹫峰。延着盘山小道往上走，只见溪盘岩石壁间雕着一尊袒腹露胸，喜笑自若的弭勒佛。旁边是一座气魄胸伟的多闻天王。北边是下山的路。小路往上延伸向东西两边。" );

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
