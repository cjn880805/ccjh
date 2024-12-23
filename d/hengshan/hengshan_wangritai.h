//wangritai.h

//Sample for room: 衡山望日台
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_wangritai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山望日台");


	add_door("衡山狮子岩", "衡山狮子岩", "衡山望日台");
	add_door("衡山祝融殿", "衡山祝融殿", "衡山望日台");

    set("long","  望日台紧邻祝融殿。鸡鸣夜起，登台东望，遥见海门，云水皆赤，倏忽异彩，日轮荡漾，若沉若浮，稍之奋涌而起，光耀夺目 " );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"shiziyan",
           "northup"    : __DIR__"zhurongdian",
        ]));
********************************************/
};


ROOM_END;
