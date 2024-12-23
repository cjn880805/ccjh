//xingyunhu.h

//Sample for room: 大理城星云湖畔
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_xingyunhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城星云湖畔");

	set("resident", "步雄部");

	add_npc("pub_playboy");
	add_npc("pub_boy");       //add by zdn 2001-07-12

	add_door("大理城步雄部", "大理城步雄部", "大理城星云湖畔");
	add_door("大理城玉霞山", "大理城玉霞山", "大理城星云湖畔");

	set("long", "星云湖又名小镜湖，方圆有十数里。东靠玉霞山，碧水清澈，风光妩媚，乃是大理东部名景。明月之夜，皎洁的月光映照湖面，风拂水波，摇曳生姿，如繁星落入湖中，晶亮如云，故名之。在此远眺湖之东南岸，可见青青翠竹，似有房舍隐在其中。" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	CContainer * yinyue_si;
	yinyue_si=me->present("yingyue si");
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->querymap("xy") && !me->query("xy/renwu1") && yinyue_si)
	{
		say("你看到湖边泊着一叶小舟。", me);
		AddMenuItem("泛舟", "$0huachuan $1", me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	CContainer * yinyue_si;
	yinyue_si=me->present("yingyue si");
	if(me->querymap("xy") && !me->query("xy/renwu1") && yinyue_si)
	{
		if(strcmp(comm, "huachuan") == 0)
			return do_huachuan(me, arg);
		if(strcmp(comm, "you") == 0)
			return do_you(me, arg);
	}
	return 0;
}

int do_huachuan(CChar *me, char * arg)
{
	say("此时已届中秋，明月当空，泛舟湖上，只见玉霞山峦随带左右，情意绵绵，碧波红叶相互映衬，也真应了“玉霞仙子素手纤，锦带轻罗碧镜前”的意境，就不知后面两句有和所指。", me);
	say("你仰卧舟中，想着想着，竟朦胧睡去。", me);
	say("睡梦间，忽觉一股寒意直攻心田，你旋即醒转，睁开双眼，这一惊非同小可，发现自己竟置身于湖水之中。", me);
	if(me->query_skill("beiming_shengong",1))
		say("好在有北冥神功护体，否则早已命丧湖中。", me);
	else
		me->set("hp",100);
	AddMenuItem("游", "$0you $1", me);
	SendMenu(me);
	return 1;
}

int do_you(CChar *me, char * arg)
{
	tell_object(me,"\n$HIC其时正好湖水清澈月光透底，你辨明方向往上游去。");
	tell_object(me,"$HIC就在此时，你怀中的「银月之匙」在月光的映射之下竟发出一道明亮的白光，向湖底射去。");
	tell_object(me,"$HIC忽然间，湖底竟似裂开般发出轰鸣之声，旋即产生了一个巨大的漩涡，将你硬生生的卷了下去。");
	tell_object(me,"$HIC在湖水的冲击之下，你眼前一黑，就此晕昏过去。\n");
	me->unconcious();
	me->set("hp",me->query("eff_hp"));
	me->move(load_room("逍遥谷小溪边"));
	me->set_temp("xy/renwu2_1",1);//进入逍遥谷
	me->set_temp("no_fei_1",1);//任务期间，禁止飞行
	return 1;
}

RESIDENT_END;
