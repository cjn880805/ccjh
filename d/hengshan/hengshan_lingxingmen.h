//lingxingmen.h

//Sample for room: 衡山棂星门
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_lingxingmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山棂星门");


	add_door("衡山奎星阁", "衡山奎星阁", "衡山棂星门");
	add_door("衡山黄土路", "衡山黄土路", "衡山棂星门");

    set("long","这里是南岳大庙的第一道门，由汉白玉，花岗石打就的石牌坊。南岳衡山是祝融游息之地，道教奉为第三小洞天。在此远望衡山，山势如飞，如云雾中凌空的大鸟。 " );
    

/*****************************************************
        set("exits", ([  
           "north"  : __DIR__"kuixingge",
           "south"  : __DIR__"hengyang",
        ]));
********************************************/
};


ROOM_END;
