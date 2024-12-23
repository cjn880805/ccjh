//wuhalou2.h

//Sample for room: 五华楼二楼
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLisouth_wuhalou2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "五华楼二楼");

	add_npc("pub_xiaoer2");   // add by zdn 2001-07-13

	add_door("大理城南五华楼", "大理城南五华楼", "大理城南五华楼二楼");

	set("long", "这是一间贵宾室，这里窗明几亮，用具考究。单是窗边一架紫竹软榻已是价值不菲。凭窗眺望，隐隐于淡烟之中可见苍山的玉局峰，只见山势清秀，翠碧欲滴，令人心旷神怡。" );
	
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
