//liangong.h

//Sample for room:  重阳宫练功房
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_liangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫练功房");

	add_npc("quanzhen_li");

	add_door("重阳宫", "重阳宫", "重阳宫练功房");
	add_door("重阳宫禅房", "重阳宫禅房", "重阳宫练功房");

	set("long", "这里是全真教弟子练功的房间。这座房间形状甚是奇特，前窄後宽，成为梯形，东边半圆，西边却作三角形状，原来这是全真教独有的练功室，前窄练掌，後宽使指，东圆研剑，西角发镖。房间中央立着几个练功用的木人，吊着几个沙袋(bag)和纸册(paper)。");

/******************************************************************************
         set("exits", ([
                "south" : __DIR__"houtang2",
                "north" : __DIR__"chanfang2",
        ]));
        set("item_desc", ([
                "paper" : "这是一摞厚厚的牛皮纸册，用铁钉钉在墙上。好象可以
用来练掌法的，打打(da paper)试试看。\n",
                "bag"   : "这是一个大沙袋，看起来非常结实。好象是用来练指法
的，你可以打打(chi bag)看。\n",
        ]));
        set("objects", ([
                __DIR__"npc/mu-ren" : 5,
        ]));
******************************************************************************/

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