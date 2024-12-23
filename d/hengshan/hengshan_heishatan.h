//heishatan.h

//Sample for room: 衡山黑沙潭
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_heishatan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山黑沙潭");

	add_door("衡山山涧", "衡山山涧", "衡山黑沙潭");

    set("long","黑沙潭又称黑龙潭，深不见底，水色苍黑，瀑布流急，水中黑泡共白沫徜徉，幽幽可怖。石壁上 '海南龙湫' 四字据载为大宋徽宗赵佶所留。瘦金字体，一如往昔。" );
    

/*****************************************************
        set("exits", ([ 
            "up"  : __DIR__"shanjian",
        ]));
********************************************/
};


ROOM_END;
