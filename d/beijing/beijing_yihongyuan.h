//yihongyuan.h

//Sample for room: 怡红院
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_yihongyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "怡红院");

	//add npcs into the room
	add_npc("pub_guigong");
	
	add_door("北京东南", "北京东南", "北京怡红院");
	add_door("北京怡红院二楼", "北京怡红院二楼", "北京怡红院");

	set("long", "你一走进来，一眼就看到大厅的墙上挂着一幅幅春宫图(tu)，一下子就明白了这是什么地方。厅内到处张灯结彩，香气扑鼻。几名打扮得妖里妖气的女人分站两旁对你发出媚笑。一个老鸨婆连忙上前招呼客人。从楼上传来了阵阵打情骂俏的声音。" );
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
