//guolaoling.h

//Sample for room: 恒山果老岭
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_guolaoling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山果老岭");
	
	add_npc("pub_yuanziyi"); 

	add_door("恒山虎风口", "恒山虎风口", "恒山果老岭");
	add_door("恒山北岳庙", "恒山北岳庙", "恒山果老岭");
	add_door("恒山通元谷", "恒山通元谷", "恒山果老岭");

    set("long","光滑的岩面上断续分布着行行马蹄形凹坑，坑径三四寸，深寸许。传说这就是当年八仙中的张果老在恒山修道时，骑小毛驴由此登天。由于路陡坡滑，他不得不牵驴步行，留下这些脚印。后人诗云:  '盘跚云路岭头那，凹石相传果老过，想是婆心来度世，故留遗迹使人摩。' "   );
    

/*****************************************************
        set("exits", ([ 
           "northup"   : __DIR__"beiyuemiao",
           "westdown"  : __DIR__"tongyuangu",
           "southwest" : __DIR__"hufengkou",
        ]));
********************************************/
};


ROOM_END;
