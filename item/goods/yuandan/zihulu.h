//zihulu.h
ITEM_BEGIN(CIzihulu)

virtual void create(int nFlag = 0)		
{
	set_name("小紫葫芦", "zi hulu");
	set("long",	"一个油光发亮的紫色小葫芦，里面还装了一些美酒！");
	set("unit", "个");
	set_weight(1000);
	set("value", 1);
	set("count",100);

//	call_out(do_die, 100);	
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	if(who == me)
	{
		tell_object(me,"你喝了一小口葫芦中的酒，立即感觉精力源源不绝涌入体内。");
		add("count",-1);
		if(!query("count"))
		{
			set("long","小紫葫芦里空空如也，显然已经没有酒了。");
			return 0;
		}
		else if(query("count")<0)
		{
			tell_object(me,"你用力摇了摇小紫葫芦，希望能再摇出一两滴酒来，却听噼啪一声响，葫芦在你手中裂成了碎片。");
			destruct(this);
			return 0;
		}
		else
		{
			if(me->query("mp")<me->query("max_mp"))
				me->add("mp",1000);
			me->UpdateMe();

			double value = 20;		//20秒
			time_t t;
			time(&t);
			if(!me->query("yuandna/jiou/time"))
				me->set("yuandna/jiou/time",t);
			else
			{
				double time=t-me->query("yuandna/jiou/time");
				if(time<value)
				{
					me->add("yuandna/jiou/sos",1);
					if(me->query("yuandna/jiou/sos")>=3)
					{	
						if(me->query("yuandna/jiou/sos_level")<3)
							me->add("yuandna/jiou/sos_level",1);
						me->del("yuandna/jiou/sos");
						me->apply_condition("drunk1", 20 + random(20));

						if(me->query("yuandna/jiou/sos_level")==1)
						{
							tell_object(me,"\n$HIR你觉得头昏昏沉沉的！\n");
						}
						else if(me->query("yuandna/jiou/sos_level")==2)
						{
							tell_object(me,"\n$HIR你觉得头昏昏沉沉的，可能要醉了！\n");
						}
						else if(me->query("yuandna/jiou/sos_level")==3)
						{
							tell_object(me,"\n$HIR你就地一躺，大醉而眠。\n");
						}
					}
					me->set("yuandna/jiou/time",t);
				}
				else
				{
					me->del("yuandna/jiou/sos");
					me->del("yuandna/jiou/sos_level");
					me->set("yuandna/jiou/time",t);
				}
			}
			return 1;
		}
	}

	return notify_fail("酒只能自己喝。");
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	//检查系统时间
	time_t t;	
	struct tm * newtime;

	time(&t);
	newtime = localtime(&t); 

	int month = newtime->tm_mon + 1;
	int day = newtime->tm_mday;

	if(month!=1 ||day>13)
	{
		CContainer * env = load_room("jy");
		if(!env->query("活动"))
			destruct(ob);
	}
	else
		ob->call_out(do_die, 3600);
}
ITEM_END;
