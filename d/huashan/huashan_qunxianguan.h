//qunxianguan.h

//Sample for room: 群仙观
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_qunxianguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "群仙观");

	add_npc("huashan_yue_buqun");

	add_door("华山练武场", "华山练武场", "华山群仙观");
    add_door("华山有所不为轩", "华山有所不为轩", "华山群仙观");



    set("long","这里是华山派历来之根本重地，墙上挂着华山派历代掌门人的画像，华山派一切重大礼仪都在这里举行。这里也是华山弟子讲武习剑之地。北边就是华山掌门岳不群的居所「有所不为轩」。");

/*****************************************************
        set("exits", ([ 
             "south": __DIR__"square",
             "north": __DIR__"buwei1",
        ]));
        set("objects", ([
             CLASS_D("huashan") + "/yue-buqun": 1,
        ]));
//        
********************************************/
};


ROOM_END;
