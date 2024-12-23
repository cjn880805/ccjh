//zhonglou1.h

//Sample for room: 钟楼一层
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_zhonglou1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "钟楼一层");

	add_npc("shaolin_qing_xiao");

	add_door("少林寺精进场", "少林寺精进场", "少林寺钟楼一层");


	set("long", "这里是塔楼的底层，一缕缕阳光从墙上的花砖缝隙里透射进来，在青砖地上投下别致的光影，如同一格格棋盘相似。往上看，长长的木楼梯盘绕而上，似乎永无尽头。墙角，梯级都相当洁净，看来经常有僧人打扫。" );

/*****************************************************
	set("exits", ([
		"up" : __DIR__"zhonglou2",
		"out" : __DIR__"zhonglou",
	]));
	set("item_desc",([
		"floor"		:	(: look_floor :),
	]));
	set("objects",([
		__DIR__"npc/saodi-seng" : 1,
	]));
//	
********************************************/
};


ROOM_END;
