//xiaoting.h

//Sample for room: 古墓小厅
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_xiaoting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓小厅");


	add_door("古墓前厅", "古墓前厅", "古墓小厅");
	add_door("古墓正厅", "古墓正厅", "古墓小厅");
	add_door("古墓小屋", "古墓小屋", "古墓小厅");
	add_door("古墓蜂屋", "古墓蜂屋", "古墓小厅");

    set("long","这里是一个小小的厅堂，也许是为了连接前厅与正厅用的。你走到这里，周围的光线亮了一些，你发觉壁上燃点着一些油灯。厅里的布置整洁而不简陋，一桌一椅都收拾的井井有条。" );

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
