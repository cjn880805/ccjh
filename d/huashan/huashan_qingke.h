//qingke.h

//Sample for room: 华山青柯坪
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_qingke);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山青柯坪");
	add_npc("pub_tumengping");

	add_door("华山云门", "华山云门", "华山青柯坪");
	add_door("华山回心石", "华山回心石", "华山青柯坪");

	set("long", "走过崎岖的十八盘，穿过云门，就到了青柯坪。青柯坪是一山间盆地，地势略为平坦。从这里开始，上山的路都是由原地凿出的石阶。远远望见一个小小石亭，便是赌棋亭了。相传宋太祖与华夷先生曾弈棋于此，将华山作为赌注，宋太祖输了，从此华山上的土地就不须缴纳钱粮。");  
    
 
/*****************************************************
        set("exits", ([  
            "northdown" : __DIR__"yunmen",
            "eastup"    : __DIR__"huixinshi",
        ]));
********************************************/
};


ROOM_END;
