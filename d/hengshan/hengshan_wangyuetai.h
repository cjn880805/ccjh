//wangyuetai.h

//Sample for room: 衡山望月台
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_wangyuetai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山望月台");


	add_door("衡山祝融殿", "衡山祝融殿", "衡山望月台");

    set("long","  望月台是祝融殿后一高耸巨石。每当夜籁，皓月当空，犹如玉盘冰轮，漫洒万里清辉，清冷月色，辉映低昂的群峰。此时 '浩然万里，举七十二峰，峰峰贮冰壶中，始信下方无此月也。' 前人因此有诗: 人间朗魄已皆尽，此地清光犹未低。 " );
    

/*****************************************************
        set("exits", ([ 
           "southup"    : __DIR__"zhurongdian",
        ]));
********************************************/
};


ROOM_END;
