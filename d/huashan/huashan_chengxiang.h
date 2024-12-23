//chengxiang.h

//Sample for room: 华山沉香劈山处
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_chengxiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山沉香劈山处");
	
	add_npc("pub_girldizi");         //add by zdn 2001-07-17
	add_npc("pub_baixin");

	add_door("华山莲花峰小路", "华山莲花峰小路", "华山沉香劈山处");
	add_door("华山莲花峰", "华山莲花峰", "华山沉香劈山处");

	set("long", "传说华山三圣母爱上了一个叫刘彦昌的书生，结为夫妇，其兄二郎神反对他们结合，将她压在华山下，她的儿子沉香长大后用斧子劈开华山，救出了母亲。旁边有一块中间裂开的大石，象用斧子劈开的一般，叫做斧劈石。传说就是沉香劈山救母的地方。");  
    
 
/*****************************************************
        set("exits", ([  
            "westup"   : __DIR__"lianhua",
            "eastdown" : __DIR__"lianpath2",
        ]));
********************************************/
};


ROOM_END;
