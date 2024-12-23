//canglong.h

//Sample for room: 华山苍龙岭
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_canglong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山苍龙岭");
	
	add_npc("huashan_gaogenming");     //add by zdn 2001-07-20

	add_door("华山上天梯", "华山上天梯", "华山苍龙岭");
	add_door("华山舍身崖", "华山舍身崖", "华山苍龙岭");
	add_door("华山云台峰", "华山云台峰", "华山苍龙岭");

	set("long", "华山五峰中最惊险的是北峰，北峰之上最陡峭的则是苍龙岭。此岭高约百米，宽仅一米，而登山之路则在其山脊之上，两侧脊坡光滑挺拔，其下悬崖深邃，云涛隐伏，岭体蜿蜒逶迤，体青背黑，如苍龙腾空，故有是名。岭侧有一石碑(shibei)。    从这里往东是下山的路，再往南是上其它四峰的路，西面是华山极险处之一，叫做“舍身崖”。");  
    
 
/*****************************************************
        set("exits", ([  
            "eastdown"  : __DIR__"shangtianti",
            "northup"   : __DIR__"yuntai",
            "westup"    : __DIR__"sheshen",
        ]));
        set("item_desc", ([
		"shibei" :
"石碑刻着几个大字：「韩退之投书处」，据说当年韩愈爬上此岭之后，再\n"
"也不敢下来，自以为要死在山上，就在山上写信投下来，和家人诀别。后\n"
"来还是华阴县的县官派人上山拿绳子把他捆着吊下来的。\n"
])  ) ;
        set("objects", ([
            __DIR__"npc/liang-fa" : 1,
        ]));
********************************************/
};


ROOM_END;
