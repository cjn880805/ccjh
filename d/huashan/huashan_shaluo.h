//shaluo.h

//Sample for room: 华山莎萝坪
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_shaluo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山莎萝坪");

	//add npcs into the room
	add_npc("pub_youke");

	add_door("华山脚下", "华山脚下", "华山莎萝坪");
	add_door("华山云门", "华山云门", "华山莎萝坪");
	add_door("华山山洪瀑布", "华山山洪瀑布", "华山莎萝坪");

	set("long", "沿着玉泉，踏过累累石涧，由山径迤逦而上，就来到了莎萝坪。从这里山路开始陡峭，南面一条迂回盘旋的山道，称作「十八盘」，通往山上。");  
    
 
/*****************************************************
        set("exits", ([  
            "northwest" : __DIR__"path1",
            "northeast" : __DIR__"shanhongpb",
            "southup" : __DIR__"yunmen",
        ]));
        set("objects", ([
            __DIR__"npc/haoke": 2,
        ]));
********************************************/
};


ROOM_END;
