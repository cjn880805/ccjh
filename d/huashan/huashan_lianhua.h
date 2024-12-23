//lianhua.h

//Sample for room: 华山莲花峰
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_lianhua);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山莲花峰");

	add_door("华山沉香劈山处", "华山沉香劈山处", "华山莲花峰");

	set("long", "太华西峰－又名莲花峰，也叫芙蓉峰，峰顶有一块巨石，状如莲花，覆盖崖巅。该处由此得名。这里悬崖陡峭，壁立千仞，登临远眺，秦川莽莽，渭、洛二水盘屈如带。峰顶有石名“摘星石”，取“手可摘星辰”之意，以状西峰之高。");  
    
 
/*****************************************************
        set("exits", ([  
             "eastdown" : __DIR__"chengxiang",
        ]));
********************************************/
};


ROOM_END;
