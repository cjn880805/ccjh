// 接引令
// Lanwood 2001-06-04
char * check_legal_name(const char * name);

ITEM_BEGIN(CIjieyinling);

void create(int nFlag = 0)
{
    set_name("接引令", "jie yin ling");
    set_weight(100);
    
	set("long", "这是教主或接引使者用来提拔弟子的令牌。");        
}

void init()
{
	CContainer * me = environment();

	if(userp(me) && _M.undefinedp("owner"))
	{
		set("owner", me->id(1));		
	}
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	char msg[255];

	if(target == me)
	{
		if(me->querymap("corps"))
		{
			if(me->query("corps/level") == 1)
			{
				AddMenuItem("改换帮主称谓", "$2chgrank $1 $2", me);
				SendMenu(me);
				return 1;
			}		

			return notify_fail("你已经加入其他帮会。");
		}

		const char * corps_id = querystr("join");
		if(! corps_id[0]) return notify_fail("不能对自己使用。");

		me->set("corps/id", corps_id);
		me->set("corps/level", 7);
		me->set("corps/rank", "帮众");
		me->setup();

		message_vision(
			snprintf(msg, 255, "$HIC$N恭恭敬敬的跪下扣头，应声道：%s这条命就是%s的了！$COM",
				query_self(me), load_room(corps_id)->name()), me);

		me->UpdateMe();

		//通报
		CChar * who = find_online(querystr("owner"));
		if(who)
			g_Channel.do_channel(who, NULL, "corps", 
				snprintf(msg, 255, "恭喜%s加入我%s。", me->name(), load_room(corps_id)->name()));
		return 1;
	}

	if(! target->is_character()) return notify_fail("你要对谁使用？");
	CChar * who = (CChar *)target;

	int lv = me->query("corps/level");
	
	const char * corps_id = me->querystr("corps/id");

	if(who->querymap("corps"))
	{
		if( DIFFERSTR(corps_id, who->querystr("corps/id")) )
			return notify_fail("对方不属于你的帮会。");
		
		if(lv >= who->query("corps/level"))
			return notify_fail("你的权利不够。");

		CRoom * r = load_room(corps_id);
		int count = r->query("level_num");

		for(int i=lv; i < count; i++)
		{
			char rank[80];
			const char * ptr;
			ptr = r->querystr(snprintf(rank, 10, "%ld", i + 1));
			if(ptr[0])
				snprintf(rank, 80, "提拔为%s", ptr);
			else
				snprintf(rank, 80, "提拔为%ld级教众", i + 1);

			AddMenuItem(rank,  snprintf(msg, 80, "$2promote %ld %ld %ld $2", object_id(), who->object_id(), i+1), me);
		}
		
		SendMenu(me);
		return 1;
	}
	else
	{	
		if(lv > 2)
			return notify_fail("只有帮主有权接收新人。");

		set("join", corps_id);		
		message_vision(snprintf(msg, 255, 
			"$HIC$N高举令牌，朗声道：%s听令，今日可否愿意加入我%s，为我主效忠？$COM", who->name(), load_room(corps_id)->name()), me);
		AddMenuItem("我愿意！", snprintf(msg, 40, "$0use %ld", object_id()), who);
		AddMenuItem("我不想！", "", who);
		SendMenu(who);
		move(who);
		remove_call_out(do_return);
		call_out(do_return, 20, me->object_id());
	}

	return 1;
}

static void do_return(CContainer * ob, LONG param1, LONG param2)
{
	CChar * who = find_player(param1);
	if(! who)
	{
		destruct(ob);
	}
	else
	{		
		ob->del("join");
		ob->move(who);
	}
}

int do_promote(CChar * me, char * arg)
{
	char rank[40], level[40], msg[255];
	int lv;
	analyse_string(arg, level, 40);
	analyse_string(level, rank, 40);

	lv = atol(level);
	
	CChar * who = find_player(atol(arg));
	if(! who ) return notify_fail("你要提拔谁？");

	const char * corps_id = me->querystr("corps/id");

	if(DIFFERSTR(corps_id, who->querystr("corps/id")) )
		return notify_fail("不是你帮会的成员！");

	if(me->query("corps/level") >= who->query("corps/level"))
		return notify_fail("你的级别不够！");

	if(me->query("corps/level") >= lv)
		return notify_fail("你不够资格！");

	if(lv < 3 && who->query("level") < 60)
		return notify_fail("对方没有足够的威信出任此职！");

	const char * ptr;
	if(strlen(rank) > 14) return notify_fail("头衔过长。");
	if(! strlen(rank))
	{
		CRoom * r = load_room(corps_id);

		if(lv < 1 || lv > r->query("level_num")) 
			return notify_fail("没有这个级别。");

		strcpy(rank, r->querystr(snprintf(rank, 20, "%ld", lv)) );
	}
	else
	{
		ptr = check_legal_name(rank);
		if(ptr[0])	return notify_fail(ptr);
	}
	
	who->set("corps/level", lv);
	who->set("corps/rank", rank);
	who->setup();

	who->UpdateMe();

	g_Channel.do_channel(me, NULL, "corps", 
		snprintf(msg, 255, "本座正式册封%s为%s！", who->name(), rank));
	g_Channel.do_channel(who, NULL, "corps", snprintf(msg, 255, "感谢%s%s错爱！", me->querystr("corps/rank"), me->name()));
	return 1;
}

int do_chgrank(CChar * me, char * rank)
{	
	char msg[255];
	const char * ptr;
	
	if(me->query("corps/level") != 1)
		return notify_fail("你不是帮主！");

	ptr = check_legal_name(rank);
	if(ptr[0])	return notify_fail(ptr);
	
	if(strlen(rank) > 14) return notify_fail("头衔过长。");
	if(! strlen(rank)) return notify_fail("头衔过短。");

	me->set("corps/rank", rank);
	me->setup();
	me->UpdateMe();

	g_Channel.do_channel(me, 0, "corps", snprintf(msg, 255, "从今日起，你们都要叫我%s。", me->querystr_temp("c_title")));
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "promote") == 0)
	{
		return do_promote(me, arg);
	}
	else if(strcmp(comm, "chgrank") == 0)
	{
		return do_chgrank(me, arg);
	}

	return CItem::handle_action(comm, me, arg);
}

ITEM_END;