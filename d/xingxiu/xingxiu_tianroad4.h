//tianroad4.h

//Sample for room: 星宿海天山山路4
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_tianroad4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "星宿海天山山路4");

	//add npcs into the room
	add_npc("pub_caiyaoren");
	add_npc("pub_xuemingfeng");
	
	CBox * box = Add_Box();
	box->add_object("xuelian", 1);	//put 100 coind into box
	box->set_name( "漆柜");		//set
	
	add_door("星宿海天山山路3", "星宿海天山山路3", "星宿海天山山路4");


/*****************************************************
         set("exits", ([
            "westup" : __DIR__"tianroad5"
        ]));
        set("objects", ([
                __DIR__"npc/caiyaoren"  : 1,
                __DIR__"npc/obj/xuelian" : 1
        ]));

        set("item_desc", ([
        "valley" : "深涧有三丈多宽，不过因为这边地势高，应该不难跳(jump)过去。\n"
        ]) );
********************************************/
};


ROOM_END;
