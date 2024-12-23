//shulin7.h

//Sample for room: 终南山树林7
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shulin7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山树林7");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("animal_dog");

	add_door("终南山神禾原", "终南山神禾原", "终南山树林7");
	add_door("终南山老妪岩", "终南山老妪岩", "终南山树林7");
	add_door("终南山黑凤洞", "终南山黑凤洞", "终南山树林7");

	set("long","这位於终南山间的一大片树林，生的颇为茂密。走在其间，只听得脚下沙沙的落叶声，四周昏昏暗暗的，不时几道日光穿过浓密的枝头，投射而下。偶而远处几声兽吼声，更添了一份神密感。往北、南、和东各有一条小径。" );

/*****************************************************
        set("exits", ([
                "south"    : __DIR__"shenheyuan",
                "northup"  : __DIR__"juyan",
                "eastdown" : __DIR__"heifengdong",
        ]));
*******************************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
