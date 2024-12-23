//wuwujing.h

//Sample for room:  天龙寺无无境
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_wuwujing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺无无境");

			
	add_door("天龙寺清都瑶台", "天龙寺清都瑶台", "天龙寺无无境");
	add_door("天龙寺慈悲院", "天龙寺慈悲院", "天龙寺无无境");
	add_door("天龙寺清心阁", "天龙寺清心阁", "天龙寺无无境");
	add_door("天龙寺雨花院", "天龙寺雨花院", "天龙寺无无境");

	set("long","一片水池静卧眼前，一座精雕木桥横跨其上，与其倒影恰成一圆，映着空灵的水面，使你心中似有所动。仿佛体会到了众生之源，万物之本的真谛。");
    

/******************************************************************************
        set("outdoors","tianlongsi");
        set("exits", ([
            "north": __DIR__"yaotai",
            "south": __DIR__"qingxinge",    			
            "west" : __DIR__"cibeiyuan",
            "east" : __DIR__"yuhuayuan",
        ]));
******************************************************************************/
};


ROOM_END;
