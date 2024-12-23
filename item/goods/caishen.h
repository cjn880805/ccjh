ITEM_BEGIN(CIcaishen);

virtual void create(int nFlag = 0)		
{
	set_name( "木雕泥塑　财神爷");	
	set("no_get", "把财神爷偷走？……你也太异想天开了吧。");
	set_weight(1);
};

virtual int do_look(CChar * me)
{
	say("木雕泥塑的一尊财神爷。因为年代久远而漆皮剥落。", me);
	AddMenuItem("对财神爷磕头", "$9kneel $1", me);
	AddMenuItem("转身离开", "", me);
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "kneel") == 0)
		return do_kneel(me, arg);
	return 0;
}

int do_kneel(CChar *me, char * arg)
{
	CContainer * obj;

	if (me->query("age")>14)
	{
		return notify_fail("是该自食其力的时候了。");
	}	
	
	
	if (me->query("level")>5)
	{
		return notify_fail("是该自食其力的时候了。");
	}	
	
	if(me->query("hp") < 30)
		return notify_fail("你已经头晕眼花了。");

	me->receive_damage("hp", 30);	
	tell_object(me, "你恭恭敬敬的给财神爷磕了个头。");   

	if(me->query("guest"))	//访客不给。
		return 1;

	//记录IP地址。lanwood 2001-02-28
	//begin---------
	char site[255];
	snprintf(site, 255, "site/%s", GetIP(me));
	if(query(site) > 29)
		return notify_fail("做人嘛……不要太贪心哦！");
		
	add(site, 1);
	//end-----------

	if (me->query("balance")>10000 || ( (obj=me->present("coin")) && obj->query("value")>10000) || current_time < me->query("teapot/kneel_mcg") )
	//最多有存款１００００，携带钱１００００。
		return 1;	
	
	me->del("teapot/kneel_mcg");
	obj = load_item("coin");
	me->add_temp("teapot/kneel",1);	
	if (me->query_temp("teapot/kneel")>20)
	{
		me->set_temp("teapot/kneel",20);
		me->set("teapot/kneel_mcg", current_time + 86400);
	}
	obj->set_amount(me->query_temp("teapot/kneel") * 10);

	obj->move(me);

	tell_object(me, "香火烟雾缭绕中你似乎看见财神爷冲你微微一笑。");   
	return 1;
}

ITEM_END;
