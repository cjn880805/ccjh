//daziling.h

//Sample for room: 恒山大字岭
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_daziling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山大字岭");


	add_door("恒山云阁虹桥", "恒山云阁虹桥", "恒山大字岭");
	add_door("恒山虎风口", "恒山虎风口", "恒山大字岭");

    set("long","大字岭是入恒山必由之路。石壁上镌有 '恒宗' 二字，高可两丈，笔力遒劲，气势雄浑。"   );
    

/*****************************************************
        set("exits", ([ 
           "west"      : __DIR__"yunge",
           "northeast" : __DIR__"hufengkou",
        ]));
********************************************/
};


ROOM_END;
