//chaoyang.h

//Sample for room: 朝阳峰
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_chaoyang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "朝阳峰");

	add_npc("yinchang_ailaozhe");	
	add_npc("huashan_gao_laozhe");	

	add_door("华山朝阳峰小路2", "华山朝阳峰小路2", "华山朝阳峰");

	set("long", "这里就是华山的东峰，也称朝阳峰，是华山看日出的绝佳处。於此俯瞰，黄河隐显东迤如带，南望小孤峰背倚山河。小孤峰上有一小亭，覆以铁瓦，亭中有铁棋盘一局，那就是华山著名的“博台”了。东壁悬崖上，更有一个巨型掌印，相传为「河神巨灵」劈山时所留下的，李白诗中“巨灵咆哮劈两山，洪波喷流射东海”就是指这个上古传说。");  
 
/*****************************************************
        set("exits", ([  
           "westdown" : __DIR__"chaopath2",
        ]));
        set("objects", ([
            CLASS_D("huashan")+"/gao-laozhe": 1,
            CLASS_D("huashan")+"/ai-laozhe": 1,
        ]));
********************************************/
};


ROOM_END;
