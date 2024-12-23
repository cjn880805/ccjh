//yushulou.h

//Sample for room: 御书楼
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan_yushulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "御书楼");
	
	add_npc("pub_shutong");          //add by zdn 2001-07-17


	add_door("衡山嘉应门", "衡山嘉应门", "衡山御书楼");
	add_door("衡山大殿", "衡山大殿", "衡山御书楼");

    set("long","御书楼为南岳庙历代藏书之处，天子御赐，贤达乐捐，这里早已洋洋大观。" );
    

/*****************************************************
         set("exits", ([ 
           "south"  : __DIR__"jiayingmen",
           "north"  : __DIR__"dadian",
        ]));
********************************************/
};


ROOM_END;
