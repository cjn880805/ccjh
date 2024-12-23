//husun.h

//Sample for room: 华山猢狲愁
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_husun);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山猢狲愁");

	//add npcs into the room
//	add_npc("animal_monkey");
//	add_npc("animal_monkey");

	add_door("华山老君沟", "华山老君沟", "华山猢狲愁");
	add_door("华山上天梯", "华山上天梯", "华山猢狲愁");

	set("long", "前面又是一处十分陡峭的山岭，上面有四只铁猿，盘踞台畔，据说以前从华山水帘洞出来的猿猴，每到这里就要返回去，连它们也感到难于超越，此岭因而得名。");  
    
 
/*****************************************************
        set("exits", ([  
            "northdown" : __DIR__"laojun",
            "southup"   : __DIR__"shangtianti",
        ]));
        set("objects", ([  
            "/d/wudang/npc/monkey": 1,
            "/d/wudang/npc/little_monkey": 2,
        ]));
********************************************/
};


ROOM_END;
