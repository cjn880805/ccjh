//caodi1.h

//Sample for room: 襄阳草地1
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_caodi1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "襄阳草地1");
	
	add_npc("xiangyang_menggubing");        //add by zdn 2001-07-20

	add_door("襄阳西北", "襄阳西北", "襄阳草地1");
	add_door("扬州密林12", "扬州密林12", "襄阳草地1");

	

/*****************************************************
        set("outdoors", "xiangyang");
	set("exits", ([
		"north"  : __DIR__"southgate2",
		"south"  : "/d/wudang/wdroad5",
	]));
********************************************/
};


ROOM_END;
