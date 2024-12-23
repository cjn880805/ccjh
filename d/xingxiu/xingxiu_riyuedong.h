//riyuedong.h

//Sample for room: 星宿海日月洞
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_riyuedong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "星宿海日月洞");
	add_npc("xingxiu_gushou");/////////////////////////
	add_npc("xingxiu_haoshou");
	add_npc("xingxiu_boshou");
        add_npc("xingxiu_ding");
        add_npc("xingxiu_tianlang");
	//add npcs into the room
	CBox * box1 = Add_Box();
	box1->add_object("bilinzhen", 10);	
	box1->set_name( "漆柜");
		
	CBox * box2 = Add_Box();
	box2->add_object("lianxindan", 10);	
	box2->set_name( "漆柜");
		
	CBox * box3 = Add_Box();
	box3->add_object("xxqingxin_san", 5);	
	box3->set_name( "漆柜");	

	add_door("星宿海", "星宿海", "星宿海日月洞");


/*****************************************************
         set("exits", ([
             "south" : __DIR__"xxh2",
        ]));

        set("item_desc", ([
                "zihua" : "都是些吹捧星宿老仙的诗词和他的画像。\n

※※※※※※※※※※※※※※※※※
※※※※　　　　　　　　　※※※※
※※※※　古　威　德　星　※※※※
※※※※　今　震　配　宿　※※※※
※※※※　无　寰　天　老　※※※※
※※※※　比　宇　地　仙　※※※※
※※※※　　　　　　　　　※※※※
※※※※※※※※※※※※※※※※※
"
        ]) );

        set("objects", ([
                "/kungfu/class/xingxiu/ding" : 1,
                __DIR__"npc/obj/tiegun" : 1,
        ]) );
********************************************/
};


ROOM_END;
