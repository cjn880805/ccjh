//qianzhuang.h

//Sample for room: 钱庄
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRYangZhou_qianzhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "钱庄");

	//add npcs into the room
	add_npc("pub_banker");
	add_npc("pub_qian");
	
	add_door("扬州西北", "扬州西北", "扬州钱庄");

	set("long", "这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发行的银票信誉非常好，通行全国。    在对面的墙上挂了块牌子(paizi)。" );
	
	set("no_fight", 1);
	set("no_beg", 1);
/*****************************************************
	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));
	set("item_desc", ([
		"paizi" : @TEXT
     本钱庄提供以下服务：
      存钱        deposit或者cun
      取钱        withdraw或者qu
      钱币兑换    convert或者duihuan
      查帐        check或者chazhang
TEXT
	]) );

	set("objects", ([
		__DIR__"npc/qian" : 1
	]));
********************************************/
};


ROOM_END;
