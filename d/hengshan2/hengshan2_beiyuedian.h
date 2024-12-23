//beiyuedian.h

//Sample for room: 恒山北岳殿
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_beiyuedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山北岳殿");


	add_door("恒山北岳庙", "恒山北岳庙", "恒山北岳殿");
	add_door("恒山见性峰山道1", "恒山见性峰山道1", "恒山北岳殿");

    set("long","北岳殿上负绝壁，下临宫廨，下云级插天，庑门上下，穹碑森立。殿正中悬风字形匾，上书“贞元之殿”，殿内北岳恒山之神全身塑像，高可丈余。 " );
    

/*****************************************************
        set("exits", ([ 
           "westup"    : __DIR__"huixiantai",
           "eastup"    : __DIR__"yuyang",
           "northup"   : __DIR__"shandao1",
           "southdown" : __DIR__"beiyuemiao",
        ]));
********************************************/
};


ROOM_END;
