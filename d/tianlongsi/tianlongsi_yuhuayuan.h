//yuhuayuan.h

//Sample for room:  天龙寺雨花院
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_yuhuayuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺雨花院");
				
	add_door("天龙寺无无境", "天龙寺无无境", "天龙寺雨花院");
	add_door("天龙寺斗母宫", "天龙寺斗母宫", "天龙寺雨花院");

    

/******************************************************************************
        set("exits", ([
                "west" : __DIR__"wuwujing",
		"south" : __DIR__"doumugong",
	]));
******************************************************************************/
};


ROOM_END;
