//yaofang.h

//Sample for room: 药房
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWanJie_yaofang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "药房");

	CBox * box = Add_Box();
	box->add_object("coin", 100);	
	box->set_name( "铁柜");	

	add_door("万劫谷小厅", "万劫谷小厅", "万劫谷药房");


/*****************************************************
        set("exits", ([ 
            "south" : __DIR__"right_room",
        ]));
        set("item_desc", ([ 
            "架子" : "架子上摆满了药瓶。\n",
        ]));
        set("objects", ([
            __DIR__"obj/mortar" : 1,
        ]));
*****************************************************/
};


ROOM_END;
