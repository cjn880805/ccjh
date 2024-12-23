//zhurongfeng.h

//Sample for room: 衡山祝融峰
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_zhurongfeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山祝融峰");
	
	add_npc("pub_jianke");      // add by zdn 2001-07-14


	add_door("衡山祝融殿", "衡山祝融殿", "衡山祝融峰");

    set("long"," '祝融峰之高' 为衡山大四绝之首。在此俯瞰群峰，尽收眼底。东望湘江，南及五岭，北瞰洞庭，西视雪山。杜甫望岳诗中有 '祝融五峰尊，峰峰次低昂.' 韩愈亦以 '祝融万丈拔地起，欲见不见轻烟里' 极言其高。" );
    

/*****************************************************
        set("exits", ([ 
           "eastdown"   : __DIR__"zhurongdian",
        ]));
********************************************/
};


ROOM_END;
