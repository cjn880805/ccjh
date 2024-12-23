//qianting.h

//Sample for room: 古墓前厅
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_qianting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓前厅");


	add_door("古墓墓门", "古墓墓门", "古墓前厅");
	add_door("古墓小厅", "古墓小厅", "古墓前厅");
	add_door("古墓休息室", "古墓休息室", "古墓前厅");

    set("long","这里是古墓的前厅，黑黝黝的，你几乎什么也看不清。全靠大厅正中间的梁上悬挂着一颗夜明珠，映射出淡淡的黄光。厅柱都是由硕大的石柱砌成的，上面似乎还写着一些什么字--你怎么也看不清楚了。" );
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
