//houdian.h

//Sample for room: 衡山后殿
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_houdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山后殿");


	add_door("衡山大殿", "衡山大殿", "衡山后殿");
	add_door("衡山正北门", "衡山正北门", "衡山后殿");

    set("long","后殿是南岳大庙的第八进，也是南岳大帝的寝宫。" );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"dadian",
           "north"  : __DIR__"beimen",
        ]));
********************************************/
};


ROOM_END;
