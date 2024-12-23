//huagang.h

//Sample for room: 杭州花港观鱼
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_huagang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州花港观鱼");
	
	add_npc("pub_flowerg");            // add by zdn 2001-07-14
	add_npc("helpnpc013");
	CContainer * env = load_room("pk");
	if(env->query("活动")==1)
		add_npc("wiz_203");


	add_door("杭州苏堤6", "杭州苏堤6", "杭州花港观鱼");

	set("long"," 只见湖中有一小岛，一座曲桥横跨湖面。曲桥上人群熙攘，倚栏投饵。桥下红鱼，争食欢跳。谢觉哉游园时曾作诗一首“鱼国群粼乐有余，观鱼才觉我非鱼。虞诈两忘欣共处，鱼犹如此况人乎。");

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
