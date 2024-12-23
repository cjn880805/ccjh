//shanlu1.h

//Sample for room: 终南山山路1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山路1");
	add_npc("pub_chenfeng");
	add_npc("pub_linlin");

	add_door("终南山山路2", "终南山山路2", "终南山山路1");
	add_door("终南山脚", "终南山脚", "终南山山路1");

    set("long","这里是山路的尽头，南面好象有一片小树林，折而向东，就是终南山的山脚了。" );

};

ROOM_END;
