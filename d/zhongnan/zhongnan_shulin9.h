//shulin9.h

//Sample for room: 终南山树林9
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shulin9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山树林9");

	//add npcx into the room    2001-07-10 zdn add
	add_npc("pub_playboy");
	add_npc("pub_daoke");

	add_door("终南山山道9", "终南山山道9", "终南山树林9");
	add_door("终南山抱子岩", "终南山抱子岩", "终南山树林9");

	set("long","这位於终南山间的一大片树林，生的颇为茂密。走在其间，只听得脚下沙沙的落叶声，四周昏昏暗暗的，不时几道日光穿过浓密的枝头，投射而下。偶而远处几声兽吼声，更添了一份神密感。往北和往南各有一条小径。" );

/*****************************************************
        set("exits", ([
                "north"      : __DIR__"baoziyan",
                "southdown"  : __DIR__"shanlu9",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
