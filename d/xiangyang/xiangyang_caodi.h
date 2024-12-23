//caodi.h

//Sample for room: 襄阳草地
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_caodi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "襄阳草地");

	add_npc("pub_dinxiucai");

	add_door("襄阳西南", "襄阳西南", "襄阳草地");
	add_door("逍遥林树林", "逍遥林树林", "襄阳草地");
	add_door("武当黄土路2", "武当黄土路2", "襄阳草地");

	set("long", "这是襄阳城外的草地。蒙古兵进犯以来，这里的百姓全进城了，虽然蒙古兵没来到南门，但肃杀氛围丝毫不减。" );
	

/*****************************************************
        set("outdoors", "xiangyang");
	set("exits", ([
		"north"  : __DIR__"southgate2",
		"south"  : "/d/wudang/wdroad5",
	]));
********************************************/
};


ROOM_END;
