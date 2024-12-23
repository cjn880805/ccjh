//shijie6.h

//Sample for room: 终南山石阶6
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shijie6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山石阶6");

	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_liumang");
	add_npc("pub_playboy");

	add_door("终南山教碑", "终南山教碑", "终南山石阶6");
	add_door("终南山石阶7", "终南山石阶7", "终南山石阶6");

	set("long","这是一条整齐的石板路，依山而建，随着山势的曲折蜿蜒曲折。由于山势陡了，当初修建这条石阶时肯定费了不小的功夫。走到这里，已经可以看见全真教重阳观的檐角了。" );
    

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"shijie7",
                "southdown" : __DIR__"jiaobei",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
