//liuyunping.h

//Sample for room: 衡山流云坪
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_liuyunping);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山流云坪");


	add_door("衡山南天门", "衡山南天门", "衡山流云坪");

    set("long","每逢雨霁，在后山深壑中升腾起来的云山雾海，涌过南天门山脊，向前山倾泻，直如银河飞泻，蔚为壮观，这就是南天门的流云奇景。" );
    

/*****************************************************
        set("exits", ([ 
           "westdown"  : __DIR__"nantian",
        ]));
********************************************/
};


ROOM_END;
