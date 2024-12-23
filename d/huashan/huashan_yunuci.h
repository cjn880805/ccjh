//yunuci.h

//Sample for room: 华山玉女祠
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_yunuci);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山玉女祠");


	add_door("华山玉女峰", "华山玉女峰", "华山玉女祠");

	set("long", "玉女祠里供奉的到底是哪位玉女，有许多不同的说法，现在所能看到的只一尊呆板的石像。祠中大石上有一处深陷，凹处积水清碧，这是玉女的洗脸盆，碧水终年不干。");  
    
    set("resource/water", 1);
 
/*****************************************************
        set("exits", ([  
            "east" : __DIR__"yunu",
        ]));
********************************************/
};


ROOM_END;
