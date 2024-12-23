//cuiping2.h

//Sample for room: 恒山翠屏山道2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_cuiping2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山翠屏山道2");
	
	add_npc("pub_punk");      //add by zdn 2001-07-20


	add_door("恒山翠屏山道1", "恒山翠屏山道1", "恒山翠屏山道2");
	add_door("恒山悬空寺", "恒山悬空寺", "恒山翠屏山道2");

    set("long","你爬在翠屏山道上，树木遮天，难见天日。山林静谧，隐隐晨钟轻敲，一切尘俗尽皆洗尽，山深有静气，恒山本色。 " );
    

/*****************************************************
	set("exits", ([
		"eastup"   : __DIR__"xuankong1",
		"eastdown" : __DIR__"cuiping1",
	]));
********************************************/
};


ROOM_END;
