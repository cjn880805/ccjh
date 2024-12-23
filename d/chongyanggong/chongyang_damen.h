//damen.h

//Sample for room:  重阳宫大门
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫大门");

	add_npc("quanzhen_zhike");
	add_npc("zm_quanzhen");

	add_door("重阳宫", "重阳宫", "重阳宫大门");
	add_door("终南山教碑", "终南山教碑", "重阳宫大门");

	set("long", "你已走到了终南山半山腰，前面就是全真教的总部重阳宫了。殿宇依山而筑，高低错落有致。周围古木森森，翠竹成林，景色清幽。正前方黄墙碧瓦，飞檐翘檩，正中一道二丈来宽，三丈来高的朱红杉木包铜大门(gate)，气势不凡。门上挂着一块匾(bian)，门前的石柱上挂着一副对联(duilian)。");

/******************************************************************************
        set("exits", ([
//                "east" : __DIR__"datang1",
                "westdown" : __DIR__"jiaobei",
        ]));
        set("outdoors", "quanzhen");
        set("item_desc", ([
            "gate":
"一道三丈来高的"HIR"朱红杉木"HIY"包铜"NOR"大门。\n",
            "bian": HIG"
＊＊＊＊＊＊＊＊＊＊＊＊＊
＊＊　　　　　　　　　＊＊
＊＊　全　真　古　教  ＊＊
＊＊　　　　　　　　　＊＊
＊＊＊＊＊＊＊＊＊＊＊＊＊
\n"NOR,
            "duilian": BLINK+HIW"
一生二二生三三生万物\n
地法天天法道道法自然
\n"NOR
        ]) );
        set("objects",([
                __DIR__"npc/zhike" : 1,
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