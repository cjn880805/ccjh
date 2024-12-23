//pub_zueijiaoshi.h 明教任务失败追剿使

NPC_BEGIN(CNpub_zueijiaoshi);

virtual void create()
{
	set_name("六派弟子", "zhueijiao shi");
 	set("gender", "男性");
    set("age", 45);
    set("attitude", "friendly");
	set("icon",young_man3);
	set("no_kill",1);
	call_out(do_die, 3600);
};

void init(CChar * me)
{
	CNpc::init(me);
	if(! is_fighting() && userp(me))
	{
		if(EQUALSTR(me->querystr("party/party_name"), "明教")) 
		{
			message_vision("$HIR$n一把扭住$N喝道：魔教余孽，哪里走！", me, this);
			message_vision("$N惊慌之间，顿时被四周围上的六派弟子给绑了个正着。\n", me);
			me->set("mj/zuolao",1);
			double value = 3600;		//1小时
			time_t t;
			time(&t);
			t += (time_t)value;	
			struct tm * newtime;
			newtime = localtime( &t );
			me->set("mj/endtime",t);
			me->set("start_city", "大理城崇圣塔顶");
			me->move(load_room("大理城崇圣塔顶"));
		}
	}	
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n向$N斜眼看了看，皱了皱眉，丢了一句“懒的理你”就转过身去。", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	destruct(me);
}

NPC_END;




