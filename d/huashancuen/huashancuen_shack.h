//shack.h

//Sample for room: 草棚
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_shack);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "草棚");

	//add npcs into the room
	add_npc("pub_seller1");

	add_door("华山村", "华山村", "华山村草棚");

  	set("long","这是一个简单的草棚，地上摆著一堆堆的货物，上山的游客可以在这买些上山用品。草棚的墙上贴着个牌子，是个价目表(sign)。" );

/*****************************************************
        set("exits", ([ 
            "north" : __DIR__"eroad1",
        ]));
        set("objects", ([
                __DIR__"npc/seller": 1 ]) );
        set("item_desc", ([ 
        "sign" : "牌子上写道：
	手杖(stick)	一百文
	麻鞋(shoes)	一百五十文
	水壶(bottle)	一百文

		兼售 皮蛋(egg) 五十文，茶水(not yet) xx。 \n"
        ]));
//        
*****************************************************/
};


ROOM_END;
