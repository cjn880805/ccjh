//datiepu.h

//Sample for room: 打铁铺
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_datiepu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "打铁铺");

	//add npcs into the room
	add_npc("pub_tiejiang");
	
	add_door("北京东南", "北京东南", "北京打铁铺");

	set("long", "这是一家简陋的打铁铺，中心摆着一个火炉，炉火把四周照得一片通红，你一走进去就感到浑身火热。墙角堆满了已完工和未完工的菜刀、铁锤、铁棍、匕首、盔甲等物。一位铁匠满头大汗挥舞着铁锤，专心致志地在打铁。" );

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
