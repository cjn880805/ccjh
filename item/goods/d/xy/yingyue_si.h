//yingyue_si.h 银月之匙

ITEM_BEGIN(CIyingyue_si);

virtual void create(int nFlag = 0)		
{
	set_name("银月之匙","yingyue si");
	set("long","一块月牙形的玉石，通体散发着银白色的莹光，握在手中只觉寒气逼人，又丝毫没有冻手的感觉，有如其中隐有魔力般。");
	
	set("value", 0l);
	
	set("no_drop", 1);
	set("no_sell", 1);
	set("no_give", 1);
	set("no_get", 1);
		
};

//设置主人
void init()
{
	CContainer * env = environment();
	
	if(! querystr("owner")[0] && userp(env) )
	{
		set("owner", env->querystr("id"));
		if(env->query("xy/save"))
			env->set_temp("no_fei_1",1);
		return;
	}
}

int query_autoload()
{
	return 1;
}


virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->is_fighting())
		return notify_fail("你正在战斗中，无法使用银月之匙。");
	
	DTItemList * list = me->Get_ItemList();
	POSITION p = list->GetHeadPosition();
	CContainer * obj;
	while(p)
	{
		obj = list->GetNext(p);
		if(userp(obj) )
			obj->move(me->environment());
		else if(EQUALSTR(obj->querystr("id"), "fight_room"))
			obj->move(me->environment());
	}
	
	if(me->querymap("xy") && !me->query("xy/renwu1") && !me->query("xy/renwu2") )
	{
		if(!me->query("xy/save"))
			AddMenuItem("银月筑梦", "$0ru $1 1", me);
		else
			AddMenuItem("逍遥梦醒", "$0chu $1 0", me);
	}
	SendMenu(me);
	
    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(!strcmp(comm, "chu")  && me->query("xy/save") && me->querymap("xy") 
		&& !me->query("xy/renwu1") && !me->query("xy/renwu2")
		&& EQUALSTR(querystr("owner"),me->id(1)))
		return do_chu(me, arg);
	
	if( !strcmp(comm, "ru") && !me->query("xy/save") && me->querymap("xy") 
		&& !me->query("xy/renwu1") && !me->query("xy/renwu2")
		&& EQUALSTR(querystr("owner"),me->id(1)))
		return do_ru(me, arg);
	
	return CItem::handle_action(comm, me, arg);
}

int do_ru(CChar *me, char * arg)
{
	message_vision("\n$HIR只见$N拿出银月之匙，默默祈祷。一道金光闪过，$N消失在空气中。", me);
	me->move(load_room("逍遥谷小溪边"));
	me->set_temp("no_fei_1",1);//任务期间，禁止飞行
	message_vision("$HIR光芒逐渐散去，$N的身影露了出来。\n", me);
	return 1;
}

int do_chu(CChar *me, char * arg)
{
	message_vision("\n$HIR只见$N拿出银月之匙，默默祈祷。一道金光闪过，$N消失在空气中。", me);
	me->move(load_room("佛山北帝庙"));
	me->del("xy/save");
	me->set("start_city", START_ROOM);
	me->delete_temp("no_fei_1");
	message_vision("$HIR光芒逐渐散去，$N的身影露了出来。\n", me);
	if(me->query("xy/renwu8_1"))
	{
		me->set_temp("xy/renwu8_1",1);//为了治疗李秋痕，出谷寻医
	}
	return 1;
}
ITEM_END;
