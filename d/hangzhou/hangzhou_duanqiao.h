//duanqiao.h
//Sample for room: 杭州断桥
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_duanqiao);

virtual void create()
{
	set_name( "杭州断桥");

	add_npc("pub_poorman");
	
	add_door("杭州青石大道9", "杭州青石大道9", "杭州断桥");
	add_door("杭州白堤", "杭州白堤", "杭州断桥");

	set("long"," 断桥正好在外湖和里湖的分水点上。这里亭轩错落，掩映在绿树佳荫之下。“山明水秀轩扉启，落日渔歌过里湖”，就是描述这里傍晚的景色。在断桥上可浏览环湖诸山和湖中诸岛的风光。每当雪後，站在桥头，只见一切都被覆上白雪，玉琢银楼的湖山风貌就是西湖十景之一的“断桥残雪”。民间神话“白蛇传”中的白娘娘和许仙就在这里相会的。    过桥往西走便是白堤了。东北边可通往青石大道");
	call_out(do_thing, 5);	

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

static void do_thing(CContainer * ob, LONG param1, LONG param2)
{
	switch(ob->query_temp("thing"))
	{
	case 0:
		tell_room(ob,"\n$HIC一阵凉风拂面，片刻，小雨淅沥沥下了起来。\n");
		ob->add_temp("thing",1);
		ob->set("index",1);
		ob->call_out(do_thing, 60);	
		break;
	case 1:
		tell_room(ob,"\n$HIC风越刮越急，漫空洒下的雨点落在地上溅起一朵朵晶莹的水花。");
		tell_room(ob,"$HIC远眺群山，烟雨迷朦，犹如一幅水墨长卷。\n");
		ob->add_temp("thing",1);
		ob->call_out(do_thing, 60);	
		break;
	case 2:
		tell_room(ob,"\n$HIC雨渐渐停了，澄碧的天边出现一道美丽的彩虹。微风吹过，清新的气息扑面而来。\n");
		ob->delete_temp("thing");
		ob->del("index");
		ob->call_out(do_thing, 3600);	
		break;
	}
}

ROOM_END;
