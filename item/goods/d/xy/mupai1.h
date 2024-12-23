//anjinmenkey.h
ITEM_BEGIN(CImupai1)

virtual void create(int nFlag = 0)		
{
	set_name("石碑","shi bei");
	set("no_get", "这是一块巨石。");

};

virtual int do_look(CChar * me)
{
	say("飞凌九霄阁。要过此阁须解此题：", me);
	say("阁分九室，九宫排布，室内均有一秤，阁前取珠四十又五，分放诸室秤上，使得各室纵、横、斜排重量之和均为十五，则可触动机关，过得此阁。", me);
	say("如失败三次，则与此阁无缘，请君早回。", me);
	if(me->query("xy/renwu6") && !me->query("xy/renwu7") )
	{
		AddMenuItem("推", "$0tuei $1", me);
		AddMenuItem("拍", "$0pai $1", me);
	}
	SendMenu(me);

	return 1;
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(!strcmp(comm, "tuei")  && me->query("xy/renwu6") && !me->query("xy/renwu7") )
		return do_tuei(me);
	else if(!strcmp(comm, "pai")  && me->query("xy/renwu6") && !me->query("xy/renwu7") )
		return do_pai(me);
	return 0;
}

int do_tuei(CChar * me)
{
	CContainer * env=me->environment();
	CContainer * XyNpc;
	if(me->query_temp("xy/renwu6_5"))
		XyNpc=env->present("li qiou heng");
	else
		XyNpc=env->present("li cang hai");
	if(XyNpc && me->query_temp("xy/renwu6_1"))
	{
		if(EQUALSTR(XyNpc->querystr("owner"),me->id(1)) && me->query_temp("xy/renwu6_2"))
		{
			message_vision("$N用力一推石碑，只听周围响起一阵“嘎嘎”之声，$N脚下一空，便掉了下去。", me);
			me->move(load_room("逍遥谷飞凌之心"));
			XyNpc->move(load_room("逍遥谷飞凌之心"));
			return 1;
		}
	}
	message_vision("$N用力一推石碑，只听周围响起一阵“嘎嘎”之声，许久之后，慢慢的又恢复了平静。", me);
	return 1;
}

int do_pai(CChar * me)
{
	CContainer * env=me->environment();
	CContainer * XyNpc;
	if(me->query_temp("xy/renwu6_5"))
		XyNpc=env->present("li qiou heng");
	else
		XyNpc=env->present("li cang hai");
	if(XyNpc && me->query_temp("xy/renwu6_1"))
	{
		if(EQUALSTR(XyNpc->querystr("owner"),me->id(1)) && !me->query_temp("xy/renwu6_2"))
		{
			message_vision("$N凝神聚气，举起右掌，“啪”的一声拍到石碑上。石碑一阵摇晃，慢慢的又恢复了平静。", me);
			message_vision("$N放眼一看，地下已经脱落了一地碎小的石珠子。", me);
			me->set_temp("xy/renwu6_2",1);//取得了四十五个石珠子
			CContainer * shikuei=load_item("shikuei");
			shikuei->set_amount(45);
			if(shikuei)shikuei->move(env);
			return 1;
		}
	}
	message_vision("$N凝神聚气，举起右掌，“啪”的一声拍到石碑上。石碑晃了一晃，慢慢的又恢复了平静。", me);
	return 1;
}

ITEM_END;




