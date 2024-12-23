//yidao.h

//Sample for room: 泰山大驿道
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRTaiShan_yidao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山大驿道");
	
	add_npc("taishan_yuyinzi");       //add by zdn 2001-07-20
	add_npc("helpnpc016");

	add_door("泰山山脚", "泰山山脚", "泰山大驿道");
	add_door("扬州东驿道", "扬州东驿道", "泰山大驿道");
	add_door("泉州山路1", "泉州山路1", "泰山大驿道");

	

/*****************************************************
	set("exits", ([
		"south" : __DIR__"yidao2",
		"north" : __DIR__"taishanjiao",
	]));
	set("objects",([
		__DIR__"npc/dao-ke" : 1,
	]));
*****************************************************/
};


ROOM_END;
