//nantaisi.h

//Sample for room: 衡山
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan_nantaisi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山");

	add_door("衡山山路9", "衡山山路9", "衡山南台寺");

    set("long","南台寺为禅宗七祖怀让的弟子石头希迁的道场，寺下紫云峰上是石头和尚墓。寺周林荫夹道，曲径通幽，泉流叮咚，蜂蝶纷飞，山风吹过时万叶悉索，真好去处。" );
    

/*****************************************************
        set("exits", ([ 
           "northdown"  : __DIR__"shanlu9",
        ]));
        set("outdoors", "henshan");
********************************************/
};


ROOM_END;
