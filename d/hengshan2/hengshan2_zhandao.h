//zhandao.h

//Sample for room: 恒山梯式栈道
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_zhandao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山梯式栈道");
	
	add_npc("pub_youke");       //add by zdn 20017-07-17


	add_door("恒山悬空寺", "恒山悬空寺", "恒山梯式栈道");
	add_door("恒山云阁虹桥", "恒山云阁虹桥", "恒山梯式栈道");

    set("long","栈道悬于壁，由无数的掾铺成，每节掾宽尺许，九节并排在一起，每根掾插入岩壁，上铺木板，长约十丈，下临深渊。人必须踏上悬空的木板，紧攀铁索，屏息静气，缓步挪动，才能过去。"   );
    

/*****************************************************
        set("exits", ([ 
           "southup"   : __DIR__"yunge",
           "northdown" : __DIR__"xuankong2",
        ]));
********************************************/
};


ROOM_END;
