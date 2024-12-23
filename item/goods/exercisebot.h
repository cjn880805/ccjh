//纸人系统。自动练功
//原创：teapot
//修改：lanwood 2001-03-27


ITEM_BEGIN(CIexercisebot);

void create(int nFlag = 0)		
{
	set_name("纸偶人","paperman");
	set_weight(10000);
	set("value",1500);

	set("destruct_msg", "纸偶人冒出一阵青烟，化成一堆纸灰飞散了。");
};

int Can_Use()
{
	return 1;
}

int do_look(CChar * me)
{
	char msg[255];

	say(snprintf(msg, 255, "这个小纸人已经烧去了%d％。",(query("work")/18) ), me);
	SendMenu(me);
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	if(me->query_temp("teapot/bot"))
	{
		if(query("working"))
		{
			AddMenuItem("熄灭纸人。", "$0stopwork $1", me);			
		}
		else
			say("已经有纸人在工作了。", me);

		SendMenu(me);
		return 1;
	}

	return do_seek(me);    
}

void init()
{
	CContainer * env = environment();

	if(! querystr("owner")[0])	//无主人
	{
//		if( userp(env) )
//			set("owner", env->querystr("id"));
		return;
	}
	
	if(DIFFERSTR(querystr("owner"), env->id(1)))
	{
		CChar * me = (CChar *)env->Present(query("working"));
		
		if(me) stop_working(this, me);

		call_out(destruct_me, 1);
	}	
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "stopwork") == 0)
	{
		del("working");
		say("你熄灭了纸人。", me);
		SendMenu(me);

		return 1;
	}

	return CItem::handle_action(comm, me, arg);
}

int do_seek(CChar * me)
{
	message_vision("$N拿出一个$n焚烧。", me, this);
	
	if( query("work") > 1800 )
	{
		tell_object(me, "纸偶人冒出一阵青烟，化成一堆纸灰飞散了。");	
		destruct(this);
		return 1;
	}

	if( me->query_temp("teapot/bot") )	//已经有纸人在用了。
	{
		tell_object(me, "已经有纸人在工作了。");
		return 1;
	}

	CContainer * env = me->environment();
	if (!env->query("sleep_room") || !me->query("env/exercise") )
	{
		tell_object(me,"纸偶人冒出一阵青烟，一动也不动了。");	
		return 1;
	}

	me->set_temp("teapot/bot",3);
	
	add("work",1);
	set("working", me->object_id());

	me->command("exercise");
	me->set_temp("teapot/hp",1);
	
	set("owner", me->id(1));

	call_out(seeki, 2);

	return 1;
}

static void stop_working(CContainer * ob, CChar * me)
{	
	tell_object(me,"纸偶人冒出一阵青烟，一动也不动了。");
	me->delete_temp("teapot/bot");
	ob->del("working");			
}

static void seeki(CContainer *ob, LONG amount, LONG amount1)
{
	CContainer * obx = obx=ob->environment();

	if(! userp(obx)) return;	//不在玩家身上

	CUser * me=(CUser *) obx;

	if(ob->query("work") > 1800)
	{
		tell_object(me,"纸偶人冒出一阵青烟，化成一堆纸灰飞散了。");	
		me->delete_temp("teapot/bot");
		destruct(ob);
		return ;
	}

	CContainer * env = me->environment();
	if (!env->query("sleep_room")  || !me->query("env/exercise") || ! ob->query("working") )
	{
		stop_working(ob,me);
		return ;
	}

	if (me->query_temp("pending/exercising"))
	{
		ob->call_out(seeki, 2);
		return ;
	}

	if(! living(me))	//in sleeping
	{
		ob->call_out(seeki, 2);
		return;
	}

	if (me->query("hp")==me->query_temp("teapot/hp"))	// Sleeping.
	{
		if(me->query("hp") == me->query("eff_hp"))	//练不了 lanwood 2001-03-27
		{
			stop_working(ob, me);
			return;
		}

		me->command("sleep");
		ob->call_out(seeki, 2);
		return ;
	}

	me->set_temp("teapot/hp",me->query("hp"));
	ob->add("work",1);

	me->command("exercise");
	
	me->DoActive();
	ob->call_out(seeki, 2);
	return;
}

ITEM_END;