//cuiping1.h

//Sample for room: 恒山翠屏山道1
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_cuiping1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山翠屏山道1");
	
	add_npc("guiyun_luzhengping");    //add by zdn 2001-07-20


	add_door("恒山翠屏谷2", "恒山翠屏谷2", "恒山翠屏山道1");
	add_door("恒山翠屏山道2", "恒山翠屏山道2", "恒山翠屏山道1");

    set("long","你爬在翠屏山道上，石阶陡峭，近在目前。回头外望，恒山重峦叠嶂，林木幽深，倍感静谧。 " );
    

/*****************************************************
	set("exits", ([
		"westup"  : __DIR__"cuiping2",
		"down"    : __DIR__"cuipinggu2",
	]));
********************************************/
};


ROOM_END;
