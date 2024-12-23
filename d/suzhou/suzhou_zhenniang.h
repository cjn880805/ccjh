//zhenniang.h

//Sample for room: 真娘墓
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_zhenniang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "真娘墓");

	//add npcs into the room
	add_npc("pub_jianke");/////////////////////////

	add_door("苏州试剑石", "苏州试剑石", "苏州真娘墓");
	add_door("苏州孙武亭", "苏州孙武亭", "苏州真娘墓");

	set("long", "在山道东侧是试剑石，呈椭圆形，正中有条深而齐裂的裂缝，相传吴王得“干将”，“莫邪”剑后，为试其锋利，将石劈开。石旁刻着元代顾瑛的诗句“剑试一痕秋，崖倾水断流，如何百年后，不斩赵高头？”的诗句。" );

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
