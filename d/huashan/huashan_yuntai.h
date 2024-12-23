//yuntai.h

//Sample for room: 华山云台峰
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_yuntai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山云台峰");
	
	add_npc("huashan_liangfa");     //add by zdn 2001-07-20


	add_door("华山苍龙岭", "华山苍龙岭", "华山云台峰");

	set("long", "太华北峰又名云台峰，它和南面的诸峰连成一条崎岖的长岭，构成了一条鱼椎脊似的登峰天梯。香炉峰和梁张峰拱立左右，峥嵘兀突。云台四面都是悬崖绝壁，十分险峻。峰顶建有真武宫，朝南通道上立着石牌楼两座，高镶“北峰顶”三字。");  
    
 
/*****************************************************
        set("exits", ([  
            "southdown" : __DIR__"canglong",
        ]));
********************************************/
};


ROOM_END;
