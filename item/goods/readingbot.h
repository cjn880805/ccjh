//纸人系统。自动练功
//原创：teapot
//修改：lanwood 2001-03-27

ITEM_BEGIN(CIreadingbot);

void create(int nFlag = 0)		
{
	set_name("纸符人","paperman");
	set_weight(10000);
	set("value",1500);

	set("destruct_msg", "纸符人冒出一阵青烟，化成一堆纸灰飞散了。");
};

int Can_Use()
{
	return 1;
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
	
	//有主人
	if(DIFFERSTR(querystr("owner"), env->id(1)))
	{
		CChar * me = (CChar *)env->Present(query("working"));
		
		if(me) stop_working(this, me);

		call_out(destruct_me, 1);
	}		
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
	char cmd[40], msg[80];

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

	say("使用纸人读书，请先指定书本。", me);
	
	DTItemList * list = me->Get_ItemList();
	CContainer * book;
	POSITION p;
									
	p = list->GetHeadPosition();
	while(p)
	{
		book = list->GetNext(p);

		char verb[20];
		
		strncpy(verb, book->querystr("book_verb"), 20)[19] = 0;

		if(book->querystr("skill/name")[0] || verb[0])	//隐藏的书，如葵花
		
			AddMenuItem(snprintf(msg, 80, "研读%s", book->name()),
			snprintf(cmd, 40, "$0prs $1 %s %ld", verb[0] ? verb : "study", book->object_id()),	me);		
	}
	
	SendMenu(me);
	return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "burn") == 0)
		return do_seek(me, arg);

	if(strcmp(comm, "prs") == 0)
		return do_selec(me, arg);

	if(strcmp(comm, "stopwork") == 0)
	{
		del("working");
		say("你熄灭了纸人。", me);
		SendMenu(me);

		return 1;
	}

	return CItem::handle_action(comm, me, arg);
}

int do_selec(CChar * me, char * arg)
{
	say("你在纸符人上歪歪扭扭的画了两个圈子。", me);
	set("prs", arg);

	AddMenuItem("焚烧纸人", "$0burn $1", me);
	AddMenuItem("重选书籍", "$0use $1", me);

	SendMenu(me);
	return 1;
}

int do_seek(CChar * me , char  * dest)
{

	char msg[255];

	message_vision("$N拿出一个$n焚烧。", me, this);

	if(query("work") > 1800)
	{
		tell_object(me,"符纸人冒出一阵青烟，化成一堆纸灰飞散了。");	
		destruct(this);
		return 1;
	}

	if( me->query_temp("teapot/bot") )	//已经有纸人在用了。
	{
		tell_object(me, "已经有纸人在工作了。");
		return 1;
	}
		
	CContainer * env = me->environment();
	if (!env->query("sleep_room") || ! querystr("prs")[0])
	{
		tell_object(me,"符纸人冒出一阵青烟，一动也不动了。");	
		return 1;
	}

	me->set_temp("teapot/bot",1);
	
	add("work",1);
	set("working", me->object_id());
	set("owner", me->id(1));

	strncpy(msg, querystr("prs"), 40)[40] = 0;
	me->command(msg);

	call_out(seeki, 2, 0);

	return 1;
}

static void stop_working(CContainer * ob, CChar * me)
{	
	tell_object(me,"纸符人冒出一阵青烟，一动也不动了。");
	me->delete_temp("teapot/bot");
	ob->del("working");			
}


static void seeki(CContainer *ob, LONG need_sleep, LONG param2)
{
	char msg[255];
	CContainer * obx = ob->environment();

	if(! userp(obx)) return;	//不在玩家身上

	CUser * me=(CUser *) obx;

	if(ob->query("work") > 1800)
	{
		tell_room(obx, "符纸人冒出一阵青烟，化成一堆纸灰飞散了。");
		me->delete_temp("teapot/bot");
		destruct(ob);
		return;
	}
	
	CContainer * env = me->environment();
	if (!env->query("sleep_room")  || ! ob->query("working"))
	{
		stop_working(ob, me);
		return ;
	}

	if(! living(me))	//in sleeping
	{
		ob->call_out(seeki, 2);
		return;
	}

	//这里有个bug! 因为体力恢复的太快.容易导致混乱
	if(need_sleep)	// Sleeping.
	{
		if(me->query("hp") == me->query("eff_hp"))	//练不了 lanwood 2001-03-27
		{
			stop_working(ob, me);
			return;
		}

		me->command("sleep");
		ob->call_out(seeki, 2, 0);
		return ;
	}

	me->set_temp("teapot/hp", me->query("hp"));
	ob->add("work",1);

	strncpy(msg, ob->querystr("prs"), 40)[40] = 0;
	 
	int succ = me->command(msg);

	me->DoActive();
	ob->call_out(seeki, 2, ! succ);

	return;
}

ITEM_END;