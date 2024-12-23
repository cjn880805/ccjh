//lichunyuan2.h

//Sample for room: 丽春院
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRYangZhou_lichunyuan2);

virtual void create()			//Call it when Room Create
{
	set_name( "扬州丽春院二楼");
	
	//set("wench_room", 1);
	set("no_fight", 1);

	add_door("扬州丽春院", "扬州丽春院", "扬州丽春院二楼");

};


ROOM_END;
