//qianzhuang.h

//Sample for room: 钱庄
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_qianzhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "钱庄");

	//add npcs into the room
	add_npc("pub_huangzhen");////////////////////////////
				

	add_door("襄阳西南", "襄阳西南", "襄阳钱庄");

	set("no_fight", 1);
/*****************************************************
	set("item_desc", ([
		"paizi" : @TEXT
     本钱庄提供以下服务：
      存钱        deposit或者cun
      取钱        withdraw或者qu
      钱币兑换    convert或者duihuan
      查帐        check或者chazhang
TEXT
	]));
	set("exits", ([
		"east" : __DIR__"southjie1",
	]));
	set("objects", ([
		__DIR__"npc/huangzhen" : 1,
	]));
********************************************/
};


ROOM_END;
