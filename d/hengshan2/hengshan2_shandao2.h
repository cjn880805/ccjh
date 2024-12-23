//shandao2.h

//Sample for room: 恒山见性峰山道2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_shandao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山见性峰山道2");
	
	add_npc("pub_tiaofu");           //add by zdn 2001-07-17


	add_door("恒山见性峰山道1", "恒山见性峰山道1", "恒山见性峰山道2");
	add_door("恒山见性峰广场", "恒山见性峰广场", "恒山见性峰山道2");

    set("long","你走在见性峰山脊小路上，听着山下庙宇的钟鼓，眼前白云漂荡，远远看到前面就是峰顶了。 " );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"beiyuedian",
           "eastup"     : __DIR__"square",
        ]));
********************************************/
};


ROOM_END;
