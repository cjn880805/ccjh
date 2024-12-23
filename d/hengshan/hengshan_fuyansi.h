//fuyansi.h



//Sample for room: 福严寺

//coded by zouwenbin

//data: 2000-11-17



ROOM_BEGIN(CRHengShan_fuyansi);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "福严寺");


	add_door("衡山山路8", "衡山山路8", "衡山福严寺");

	add_door("衡山三生塔", "衡山三生塔", "衡山福严寺");

	add_door("衡山山路9", "衡山山路9", "衡山福严寺");



    set("long","福严寺为禅宗七祖怀让的道场，怀让在此宏扬顿悟法门。山门上匾额 '天下法院' 正是当年写照，两边门联 '六朝古刹' '七祖道场' 字迹剥落，颜色极古。山门墙山有古人留字(zi)，年代古远，犹历历可辩。寺内石柱有一对联(lian)，字迹圆润回转，不露机锋。" );

    



/*****************************************************

        set("exits", ([ 

           "southdown"  : __DIR__"shanlu9",

           "westup"     : __DIR__"sansheng",

           "northdown"  : __DIR__"shanlu8",

        ]));

        set("item_desc", ([

            "zi":

"\n

诸峰翠少中峰翠  五寺名高此寺名

石路险盘岚霭滑  僧窗高倚济寥明

凌空殿阁由天设  遍地松杉是自生

更有上方难上处  紫苔红藓远峥嵘

\n",

            "lian":

"\n

     福      般

     严      若

     为      是

     南      老

     山      祖

     第      不

     一      二

     古      法

     刹      门

\n",

        ]));

        set("outdoors", "henshan");

********************************************/

};





ROOM_END;
