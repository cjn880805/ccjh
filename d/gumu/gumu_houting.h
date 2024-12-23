//houting.h

//Sample for room: 古墓后厅
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_houting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓后厅");

	add_npc("zm_gumu");

	add_door("古墓正厅", "古墓正厅", "古墓后厅");

    set("long","这里是古墓的后厅，密封得严严实实，没有一丝的缝隙。在昏暗的灯光下，你发现墙上悬挂着一幅画 (picture)，似乎是一幅人物的肖像。在厅的中央，摆放着几具棺材(coffin)，其中只有一具棺材的棺板没有合上，棺材中好象空空如也。" );
    set("getbook",1);

/*****************************************************
        set("exits", ([
                "north" : __DIR__"zhengting",
        ]));

        set("item_desc", ([
        "picture": "画中是一个中年道士的背影，看不出什么相貌，画中人一手指天，画
角题着‘"+MAG"活死人像"NOR+"’几个大字。\n",
        "coffin": "用厚厚的石板做成的棺材，棺板合上后，就没有一丝的缝隙了。\n"
        ]) );
********************************************/
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
