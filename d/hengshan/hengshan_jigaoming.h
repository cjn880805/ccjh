//jigaoming.h



//Sample for room: 衡山极高明台

//coded by zouwenbin

//data: 2000-11-29



ROOM_BEGIN(CRHengShan_jigaoming);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "衡山极高明台");


	add_door("衡山三生塔", "衡山三生塔", "衡山极高明台");




    set("long","这里是福严寺最高处。唐邺侯李泌手书 '极高明' 三个大字于此，意即佛相极高 (高无见顶相) ，佛光极明 (明不借他光) ，佛是至高无上的，故曰极高明台。" );

    



/*****************************************************

        set("exits", ([ 

           "northdown"  : __DIR__"sansheng",

        ]));

********************************************/

};





ROOM_END;
