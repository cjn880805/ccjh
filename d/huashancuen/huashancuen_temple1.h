//temple1.h

//Sample for room: 玄坛庙
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_temple1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "玄坛庙");
	
	add_npc("pub_dibao");          //add by zdn 2001-07-14


	add_door("华山村", "华山村", "华山村玄坛庙");

  	set("long","这是一间十分破旧的小庙，庙里供的神像是赵玄坛，神像已经很残破了，神案上也积了很多尘土，看来已有很久没人来上香进供了。大概村民贫困的太久，已不再寄望於财神爷降福给他们了。神像後面的墙上有个半人多高的洞(hole)。" );
    

/*****************************************************
        set("exits", ([ 
            "southwest" : __DIR__"nwroad1",
        ]));
        set("item_desc", ([
                "hole": "看来这个大洞被人凿开不久，洞那边好象有个小棚子。\n"
        ]) );
********************************************/
};


ROOM_END;
