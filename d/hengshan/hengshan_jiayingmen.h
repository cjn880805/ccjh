//jiayingmen.h

//Sample for room: 衡山嘉应门
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_jiayingmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山嘉应门");


	add_door("衡山御碑亭", "衡山御碑亭", "衡山嘉应门");
	add_door("衡山御书楼", "衡山御书楼", "衡山嘉应门");

    set("long","这里是地方官迎接京师御史官来祭南岳的地方，是南岳大庙第五进门了。门上雕塑也较精细些，悬彩灯笼时时换新。 " );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"yubeiting",
           "north"  : __DIR__"yushulou",
        ]));
********************************************/
};


ROOM_END;
