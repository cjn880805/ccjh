//shandao1.h

//Sample for room: 恒山见性峰山道1
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_shandao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山见性峰山道1");
	
	add_npc("pub_jianke");      //add by zdn 2001-07-17


	add_door("恒山北岳庙", "恒山北岳庙", "恒山见性峰山道1");
	add_door("恒山见性峰山道2", "恒山见性峰山道2", "恒山见性峰山道1");

    set("long","你走在见性峰山脊小路上，听着山下庙宇的钟鼓，眼前白云漂荡，感觉幽逸极了。 " );
     

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"beiyuedian",
           "northup"    : __DIR__"shandao2",
        ]));
********************************************/
};


ROOM_END;
