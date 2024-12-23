//sansheng.h



//Sample for room: 衡山三生塔

//coded by zouwenbin

//data: 2000-11-29



ROOM_BEGIN(CRHengShan_sansheng);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "衡山三生塔");


	add_door("衡山福严寺", "衡山福严寺", "衡山三生塔");

	add_door("衡山极高明台", "衡山极高明台", "衡山三生塔");



    set("long","三生塔是福严寺开山禅师慧思埋骨处，据说慧思禅师的三生均埋骨这里，故称三生塔。不远处有棵银杏，据说曾受戒于慧思禅师，树龄千年，仍亭亭华盖，岁岁青苍。" );

    



/*****************************************************

        set("exits", ([ 

           "southup"   : __DIR__"jigaoming",

           "eastdown"  : __DIR__"fuyansi",

        ]));

********************************************/

};





ROOM_END;
