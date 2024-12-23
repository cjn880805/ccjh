//wuwei.h

//Sample for room: 黄河武威
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_wuwei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河武威");

	//add npcs into the room
	add_npc("pub_xixiabing");

	add_door("黄河乌鞘岭", "黄河乌鞘岭", "黄河武威");
	add_door("黄河土门子", "黄河土门子", "黄河武威");

	set("long","武威是西夏国的西南重镇，驻有重兵，城楼高达三丈，门口有两排官兵正在认真的盘查过往行人，城门口的告示上画着最近通缉的江洋大盗的图形，城里头看上去还挺热闹。东南就是去永登的方向了，西南面就是祁连山脉。");

/*****************************************************
	set("exits", ([
		"southeast" : __DIR__"wuqiao",
		"north"     : __DIR__"tumenzi",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" : 3,
	]));
********************************************/
};


CHANGAN_END;
