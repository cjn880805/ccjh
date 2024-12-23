//dadian.h

//Sample for room: 衡山大殿
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_dadian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山大殿");


	add_door("衡山御书楼", "衡山御书楼", "衡山大殿");
	add_door("衡山后殿", "衡山后殿", "衡山大殿");

    set("long","这里是南岳大殿，供祭祀炎帝之用。大殿结构为重檐歇山顶，顶覆七彩琉璃。殿高七十二尺，正面七间，有石柱七十二根，合南岳七十二峰之数。殿中南岳圣帝宝相庄严。南岳庙之雄为衡山小四绝之一。 " );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"yushulou",
           "north"  : __DIR__"houdian",
        ]));
********************************************/
};


ROOM_END;
