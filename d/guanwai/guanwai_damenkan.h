//damenkan.h

//Sample for room: 大门坎子
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_damenkan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大门坎子");
	
	set("resident", "关外");


	add_npc("guanwai_yanji");      //add by zdn 2001-07-20

	add_door("关外冰面", "关外冰面", "关外大门坎子");
	add_door("关外二门坎子", "关外二门坎子", "关外大门坎子");

    set("long","这里是沿江向东的古道，多为进山采参的参客所走，因此也称“参路”。前面一座小山截断去路，因其行似门坎，且为东去采参的第一道屏障，故被称为大门坎子。西面是宽阔的松花江。松花江在冬春时结冰可通行，夏秋化冻你只好找船家帮忙了。" );
    

/*****************************************************
	set("exits", ([
		"northeast"  : __DIR__"ermenkan",
		"west"       : __DIR__"bingmian",
	]));
********************************************/
};


RESIDENT_END;
