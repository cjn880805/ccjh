//shuzhuangtai.h

//Sample for room: 衡山梳妆台
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shuzhuangtai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山梳妆台");

	add_npc("hengshan1_liuhong");
	add_door("衡山藏经殿", "衡山藏经殿", "衡山梳妆台");

    set("long","藏经殿有一泓碧泉如镜，向称美容泉。相传为南陈后主妃在此避乱时，对碧水照容颜梳妆打扮的地方。殿前胜迹有灵日，昔时夜间常见飞光，或如繁星点点，或若万萤乱飞，煞是壮观。" );
    

/*****************************************************
        set("exits", ([ 
           "north"   : __DIR__"cangjingdian",
        ]));
********************************************/
};


ROOM_END;
