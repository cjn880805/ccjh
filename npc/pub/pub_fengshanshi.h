//pub_fengshanshi.h 封山使者
//秦波 2002、4、25

NPC_BEGIN(CNpub_fengshanshi);

void create()
{
	set_name("封山使者",  "fenshan shizhe" );
    set("gender", "男性");
	set("icon", young_monk);
    set("age", 60);
	set("per", 18 + random(15));
    set("combat_exp", 20000);
	set("str", 40);
	set("no_kill", 1);
	call_out(do_die, 900);
}

void init(CChar * me)
{
	CNpc::init(me);
	char msg[255];
	if (DIFFERSTR(me->querystr("party/party_name"), "明教")) 
	{
			message_vision(snprintf(msg, 255, "$HIR封山使者伸手拦住了%s,说道：“六大门派正在围攻光明顶，非我明教弟子不得入内。”\n", me->name()), this);
			me->move(load_room("西域丝绸之路3"));
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
	me->move(load_room("pk"));
	CContainer * env = me->environment();
	if(env->query("mj/start"))
	{
		me->move(load_room("明教昆仑山下"));
		me->call_out(do_die, 900);
	}
	else
		destruct(me);
}
NPC_END;




