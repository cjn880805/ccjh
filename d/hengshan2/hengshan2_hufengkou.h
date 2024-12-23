//hufengkou.h

//Sample for room: 恒山虎风口
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_hufengkou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山虎风口");


	add_door("恒山大字岭", "恒山大字岭", "恒山虎风口");
	add_door("恒山果老岭", "恒山果老岭", "恒山虎风口");

    set("long","过 '步云桥' ， '望仙亭' ，就到了一个峰回路转的陡峭路口，这里是一处风口，大风来处，声如虎啸，比别处强劲多多，故有是名。:  '盘跚云路岭头那，凹石相传果老过，想是婆心来度世，故留遗迹使人摩。"   );
    

/*****************************************************
        set("exits", ([ 
           "southwest" : __DIR__"daziling",
           "west"      : __DIR__"xuangengsong",
           "northeast" : __DIR__"guolaoling",
        ]));
********************************************/
};


ROOM_END;
