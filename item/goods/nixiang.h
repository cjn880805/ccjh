ITEM_BEGIN(CInixiang);

virtual void create(int nFlag = 0)		
{
	set_name( "倒下的泥像");	
	set("no_get", "似乎你的力气小了一点！");
	set_weight(1);

	call_out(do_die, 1200);
};

virtual int do_look(CChar * me)
{
	say("它看上去青面獠牙，眼大如斗，高有丈余，犹如庙中泥鬼般模样！", me);
	if(me->query_temp("wei/renwu8_5"))
	{
		AddMenuItem("推泥像","$9tuei $1",me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(EQUALSTR(environment()->querystr("base_name"),"杭州毒液地道左岸" ))
	{
		if(me->query_temp("wei/renwu8_6"))
		{
			if(!strcmp(comm, "tuei"))
			{
				if(me->query("mp_factor")<50)
					tell_object(me,"你使出吃奶的力气使劲推泥像，泥像依然纹丝不动，似乎你的力气小了一点！");
				else
				{
					tell_object(me,"你卯足力气，大喝一声“走”，双掌用力拍在泥像上。");
					tell_object(me,"泥像呼的一声向前飞去，正好落在水坑中央。毒液直没至泥像颈部，只露出一个泥像头在毒液之上。");
					tell_object(me,"你笑了笑，正好合用。");
					me->set_temp("wei/renwu8_8",1);//推动泥像进入毒液地道水坑
					destruct(this);
				}
				return 1;
			}
		}
	}
	else if(me->query_temp("wei/renwu8_5"))
	{
		if(!strcmp(comm, "tuei"))
		{
			if(me->query("mp_factor")<50)
				say("你使出吃奶的力气使劲推泥像，泥像依然纹丝不动，似乎你的力气小了一点！", me);
			else
			{
				say("你用力推着泥像缓缓向前走去。", me);
				me->set_temp("wei/renwu8_6",1);//推动泥像进入毒液地道左岸
				me->move(load_room("杭州毒液地道左岸"));
				move(load_room("杭州毒液地道左岸"));
			}
			SendMenu(me);
			return 1;
		}
	}
	return CItem::handle_action(comm, me, arg);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}
ITEM_END;

