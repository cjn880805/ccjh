//yuzhengong.h

//Sample for room:  重阳宫遇真宫
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_yuzhengong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫遇真宫");

	add_npc("quanzhen_ma");
	add_npc("quanzhen_qi");
	add_npc("quanzhen_shen");

	add_door("重阳宫", "重阳宫", "重阳宫遇真宫");

	set("long", "这里是重阳宫以前的旧址，是王重阳王真人参悟大道之前清修的地方。后来手创全真教后，此地的布局实在太小，就将重阳宫迁到东面山上，将此地重新改名为遇真宫，以纪念得道之意。这里很久没有人来过了，桌椅上都积满了灰尘。");

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
//last, register the room into ../server/RoomSetup.cpp