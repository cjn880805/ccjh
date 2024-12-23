//jubaozhai.h

//Sample for room: 聚宝斋
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_jubaozhai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "聚宝斋");

	//add npcs into the room
	add_npc("pub_sun");/////////////////////////

	add_door("苏州南", "苏州南", "苏州聚宝斋");

	set("long", "这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发行的银票信誉非常好，通行全国。    在对面的墙上挂了块牌子(paizi)。  " );
 	
	
	set("no_fight", 1);
	set("no_beg", 1);
/*****************************************************
	set("item_desc", ([
		"paizi" : @TEXT
     本钱庄提供以下服务：
      存钱        deposit或者cun
      取钱        withdraw或者qu
      钱币兑换    convert或者duihuan
      查帐        check或者chazhang
TEXT
	]) );
	set("exits", ([
		"east"  : __DIR__"nandajie1",
	]));
	set("objects", ([
		__DIR__"npc/sun": 1,
	]));

********************************************/
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
