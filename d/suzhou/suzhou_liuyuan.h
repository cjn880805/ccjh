//liuyuan.h

//Sample for room: 留园
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_liuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "留园");

	//add npcs into the room
	add_npc("pub_lady1");/////////////////////////
	CContainer * env = load_room("pk");
	if(env->query("活动")==1)
		add_npc("wiz_101");

	add_door("苏州南", "苏州南", "苏州留园");
	add_door("苏州荷花厅", "苏州荷花厅", "苏州留园");	

	set("long", "留园是苏州的一大名景之一，它以结构布局紧密、厅堂华丽宏敝、装饰精美典雅而享有“吴中第一名园”之誉。  " );

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
