ITEM_BEGIN(CIwas_mache);

virtual void create(int nFlag = 0)		
{
	set_name( "大型马车");	
	set("no_get", "");
	set_weight(1);
};

virtual int do_look(CChar * me)
{
	say("这是一辆能载十人的大型马车。", me);
	CContainer * menpiao=me->present("guan guang piao");
	if(wizardp(me)||
		(me->query_temp("was/renwu2_2") && menpiao && EQUALSTR(menpiao->querystr("owner"),me->id(1))))
	{
		AddMenuItem("使用门票", "$9menpiao $1", me);
	}
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "menpiao") && !me->query_temp("was/renwu2_3"))
	{
		CContainer * menpiao=me->present("guan guang piao");
		if(wizardp(me)||(me->query_temp("was/renwu2_2") && menpiao && EQUALSTR(menpiao->querystr("owner"),me->id(1))))
			return do_menpiao(me, arg);
	}
	return 0;
}

int do_menpiao(CChar *me, char * arg)
{
	CContainer * env;
	CContainer * env1;
	char msg[255];
	if(EQUALSTR(querystr("family/family_name"),me->querystr("family/family_name")))
	{
		tell_object(me,"\n$HIC你不能进入这辆马车，请等下一辆吧！\n");
		return 1;
	}
	if(me->query_temp("was/renwu2_4"))
	{
		tell_object(me,"\n$HIC你不能进入这辆马车，请回去吧！\n");
		return 1;
	}
	CContainer * menpiao=me->present("guan guang piao");
	if(wizardp(me)||(me->query_temp("was/renwu2_2") && menpiao && EQUALSTR(menpiao->querystr("owner"),me->id(1))))
	{
		if(menpiao)
			destruct(menpiao);
		tell_object(me,"\n$HIC车夫大喊到：“客倌，请上车！”\n");
		env = load_room("明教山门");
		env->add("count",1);

		env1 = load_room(snprintf(msg, 255, "大型马车-%d",env->query("count")/2));
		env1->set("name","大型马车");
		env1->add("count",1);
		env1->set("family/family_name",me->querystr("family/family_name"));
		((CRoom *)env1)->remove_all_doors();
		((CRoom *)env1)->add_door("明教山门", "明教山门", snprintf(msg, 255, "大型马车-%d",env->query("count")/2));
		//这里有个问题，玩家进去后又出来的话就会有错误发生了
		if(env1->query("count")>1)
		{
			message_vision("$YEL车夫大喊道：“各位客倌坐稳咯，开车了……驾~~~！”", me);
			((CRoom *)env1)->remove_all_doors();
			((CRoom *)env1)->reset();
		}

		me->move(env1);
		me->set_temp("was/renwu2_3",1);//进入马车
	}
	return 1;
}

ITEM_END;


