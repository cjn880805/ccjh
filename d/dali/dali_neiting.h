//neiting.h

//Sample for room: 内厅
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_neiting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "内厅");

	add_npc("dali_duanzc");	
	add_npc("dali_guducheng");	
	add_npc("zm_dali");	

	add_door("大理城王府大厅", "大理城王府大厅", "大理城王府内厅");
	add_door("大理城王府厨房", "大理城王府厨房", "大理城王府内厅");
	add_door("大理城王府书房", "大理城王府书房", "大理城王府内厅");

	set("long", "这里是镇南王府的内厅。整个大厅十分宽阔。虽说是王府，但摆设很简单，正中间有两张太师椅，边上摆满了各种各样的山茶花。" );
	

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
