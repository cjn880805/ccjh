ITEM_BEGIN(CIjiashan);

virtual void create(int nFlag = 0)		
{
	set_name( "假山");	
	set("no_get", "假山你也能扛的动？……你也太异想天开了吧。");
	set_weight(1);
};

virtual int do_look(CChar * me)
{
	say("花园中有一挺立的假山。", me);
	if(me->query("lj/jiangli_time"))
	{
		say("按照天山铁姥所说推开（push）假山就可以看见密道。", me);
		AddMenuItem("推开假山", "$9push $1", me);
	}
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "push") == 0)
		return do_push(me, arg);
	return 0;
}

int do_push(CChar *me, char * arg)
{
	if(me->query("lj/jiangli_time"))
	{
		tell_object(me, "\n你按照天山铁姥所说，在假山的东南方向推了一下，假山果然露出一个狭长的入口。"); 
		DTItemList * list = me->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;
		while(p)
		{
			obj = list->GetNext(p);
			if(userp(obj))
				obj->move(load_room("佛山北帝庙"));
			else if(EQUALSTR(obj->querystr("id"), "fight_room"))
			{
				me->move(load_room("佛山北帝庙"));
				me->del("lj/jiangli_time");
				return 1;
			}
		}
		double value = me->query("lj/jiangli_time");		
		time_t t;
		time(&t);
		t += (time_t)value;	
		me->set("lj/endtime",t);
		me->del("lj/jiangli_time");
		CContainer * env = load_room("灵鹫后山密道1");
		me->move(env);
	}
	return 1;
}

ITEM_END;

