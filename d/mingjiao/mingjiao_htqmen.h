//htqmen.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_htqmen);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "明教厚土旗门");

	add_door("天微堂", "明教天微堂", "明教厚土旗门");
	add_door("天微堂", "明教天微堂", "明教厚土旗门");

	set("long", "这是厚土旗的洞门，门洞里进进出出的厚土旗众，身上挂满了锹，铲，短刀，谁也不理你。门边两面短杆镶黄边飞龙旗，绣着厚土二字。");
    

/*****************************************************
	set("exits", ([
		"enter" : __DIR__"htqdating",
		"south" : __DIR__"tohtq7",
	]));
********************************************/

};



ROOM_END;
