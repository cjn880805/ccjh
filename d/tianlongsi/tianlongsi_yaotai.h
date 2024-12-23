//yaotai.h

//Sample for room:  天龙寺清都瑶台
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_yaotai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺清都瑶台");
				
	add_door("天龙寺晃天门", "天龙寺晃天门", "天龙寺清都瑶台");
	add_door("天龙寺无无境", "天龙寺无无境", "天龙寺清都瑶台");

	set("long","这是出入前后寺的必经之路。往南望去，可见后寺中亭台楼阁规模宏大，构筑精丽，宅地连云，其气势之盛更胜于五台，普陀等诸处佛门胜地的名山大寺。");
    

/******************************************************************************
	set("outdoors","tianlongsi");
        set("exits", ([
		"south": __DIR__"wuwujing", 
		"north": __DIR__"huangtianmen",   			
        ]));
******************************************************************************/
};


ROOM_END;
