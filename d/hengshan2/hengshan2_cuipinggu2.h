//cuipinggu2.h

//Sample for room: 恒山翠屏谷2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_cuipinggu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山翠屏谷2");


	add_door("恒山翠屏谷1", "恒山翠屏谷1", "恒山翠屏谷2");
	add_door("恒山翠屏山道1", "恒山翠屏山道1", "恒山翠屏谷2");

    set("long","这里峡谷幽深，石壁陡直，两崖壁立，一涧中流。就在这地势绝险的恒山山谷中，却有数十殿堂悬挂在翠屏山腰。它们上载危岩，下临深谷，错落有致，如玉宇琼楼自空中冉冉降落。那就是悬空寺了。 " );
    

/*****************************************************
	set("exits", ([
		"up"         : __DIR__"cuiping1",
		"northwest"  : __DIR__"cuipinggu1",
	]));

********************************************/
};


ROOM_END;
