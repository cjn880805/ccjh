// 接引令
// Lanwood 2001-06-04
char * check_legal_name(const char * name);

ITEM_BEGIN(CIjieyinling1);

void create(int nFlag = 0)
{
    set_name("接引令", "jie yin ling");
    set_weight(100);
    
	set("long", "这是宫主或副宫主用来提拔弟子的令牌。");        
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
	CRoom * r;

	if(target == me)
	{
		const char * corps_id = querystr("join");
		if(! corps_id[0]) return notify_fail("不能对自己使用。");

		CContainer * env=load_room(corps_id);
		env->add("corps/member_count",1);
		env->set(snprintf(msg, 255,"list/%s",me->id(1)),me->name(1));

		if(env->query("index")==1)
			r = load_room(snprintf(msg, 255,"g1_新月大殿_%s",corps_id));
		me->set("corps/id", corps_id);
		me->set("corps/level", 7);
		me->set("corps/rank", r->querystr("rank/7"));
		me->setup();
		
		message_vision(
			snprintf(msg, 255, "$HIC$N恭恭敬敬的跪下扣头，应声道：%s这条命就是%s的了！$COM",
				query_self(me), load_room(corps_id)->name()), me);

		me->UpdateMe();

		//通报
		CChar * who = find_online(querystr("owner"));
		if(who)
			g_Channel.do_channel(who, NULL, "corps", 
				snprintf(msg, 255, "恭喜%s(%s)加入我「%s」。", me->name(),me->id(), load_room(corps_id)->name()));
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

		if(load_room(corps_id)->query("index")==1)
			r = load_room(snprintf(msg, 255,"g1_新月大殿_%s",corps_id));
		int count = r->query("rank/level_num");

		for(int i=lv; i < count-1; i++)
		{
			char rank[80];
			const char * ptr;
			ptr = r->querystr(snprintf(rank, 10, "rank/%ld", i + 1));
			snprintf(rank, 80, "提拔为%s", ptr);
			
			AddMenuItem(rank, snprintf(msg, 80, "$0promote %ld %ld %ld $1", object_id(), who->object_id(), i+1), me);
		}
		
		SendMenu(me);
		return 1;
	}
	else
	{	
		if(load_room(corps_id)->query("index")==1)
			r = load_room(snprintf(msg, 255,"g1_新月大殿_%s",corps_id));
		if(lv > 3)
			return notify_fail(snprintf(msg, 255,"只有%s和%s才有权接收新人。",r->querystr("rank/1"),r->querystr("rank/2")));

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

	CRoom * r=load_room(corps_id);
	int count=r->query("corps/member_count");

	switch(lv)
	{
	case 2:
		if(who->query("corps/contribute")<200000)
			return notify_fail("对方没有足够的帮派贡献度（大于20万），不能出任此职！");
		if(r->query(snprintf(msg, 255,"repute/%s",who->id(1)))<10000)
			return notify_fail("对方没有贡献帮会足够的声望（大于1万），不能出任此职！");
		if(r->query(snprintf(msg, 255,"money/%s",who->id(1)))<100000)
			return notify_fail("对方没有贡献帮会足够的财富（大于10万），不能出任此职！");
		if(r->query("corps/rank2") >= 2+count/100)
			return notify_fail("此职暂无空缺！");
		if(!EQUALSTR(who->querystr("gender"),"女性"))
			return notify_fail("只有女性才可以担任此职！");
		break;
	case 3:
		if(who->query("corps/contribute")<100000)
			return notify_fail("对方没有足够的帮派贡献度（大于10万），不能出任此职！");
		if(r->query(snprintf(msg, 255,"repute/%s",who->id(1)))<5000)
			return notify_fail("对方没有贡献帮会足够的声望（大于5000），不能出任此职！");
		if(r->query(snprintf(msg, 255,"money/%s",who->id(1)))<80000)
			return notify_fail("对方没有贡献帮会足够的财富（大于8万），不能出任此职！");
		if(r->query("corps/rank3") >= 4+count/70)
			return notify_fail("此职暂无空缺！");
		break;
	case 4:
		if(who->query("corps/contribute")<80000)
			return notify_fail("对方没有足够的帮派贡献度（大于8万），不能出任此职！");
		if(r->query(snprintf(msg, 255,"repute/%s",who->id(1)))<4000)
			return notify_fail("对方没有贡献帮会足够的声望（大于4000），不能出任此职！");
		if(r->query(snprintf(msg, 255,"money/%s",who->id(1)))<50000)
			return notify_fail("对方没有贡献帮会足够的财富（大于5万），不能出任此职！");
		if(r->query("corps/rank4") >= 8+count/50)
			return notify_fail("此职暂无空缺！");
		if(!EQUALSTR(who->querystr("gender"),"女性"))
			return notify_fail("只有女性才可以担任此职！");
		break;
	case 5:
		if(who->query("corps/contribute")<50000)
			return notify_fail("对方没有足够的帮派贡献度（大于5万），不能出任此职！");
		if(r->query(snprintf(msg, 255,"repute/%s",who->id(1)))<3000)
			return notify_fail("对方没有贡献帮会足够的声望（大于3000），不能出任此职！");
		if(r->query(snprintf(msg, 255,"money/%s",who->id(1)))<30000)
			return notify_fail("对方没有贡献帮会足够的财富，不能出任此职！");
		if(r->query("corps/rank5") >= 16+count/30)
			return notify_fail("此职暂无空缺！");
		break;
	case 6:
		if(who->query("corps/contribute")<30000)
			return notify_fail("对方没有足够的帮派贡献度（大于3万），不能出任此职！");
		if(r->query(snprintf(msg, 255,"repute/%s",who->id(1)))<1000)
			return notify_fail("对方没有贡献帮会足够的声望（大于1000），不能出任此职！");
		if(r->query(snprintf(msg, 255,"money/%s",who->id(1)))<10000)
			return notify_fail("对方没有贡献帮会足够的财富（大于1万），不能出任此职！");
		if(r->query("corps/rank6") >= 32+count/15)
			return notify_fail("此职暂无空缺！");
		if(!EQUALSTR(who->querystr("gender"),"女性"))
			return notify_fail("只有女性才可以担任此职！");
		break;
	}

	if(strlen(rank) > 14) return notify_fail("头衔过长。");
	
	if(load_room(corps_id)->query("index")==1)
		r = load_room(snprintf(msg, 255,"g1_新月大殿_%s",corps_id));
	
	if(lv < 1 || lv > r->query("rank/level_num")) 
		return notify_fail("没有这个级别。");
	
	strcpy(rank, r->querystr(snprintf(rank, 20, "rank/%ld", lv)) );

	who->set("corps/level", lv);
	who->set("corps/rank", rank);
	who->setup();

	who->UpdateMe();
	
	g_Channel.do_channel(me, NULL, "corps", 
		snprintf(msg, 255, "本座正式册封%s(%s)为本宫%s！", who->name(),who->id(), rank));
	g_Channel.do_channel(who, NULL, "corps", snprintf(msg, 255, "感谢%s%s错爱！", me->querystr("corps/rank"), me->name()));

	load_room(corps_id)->add(snprintf(rank, 20, "corps/rank%ld", lv),1);
	
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "promote") == 0)
	{
		return do_promote(me, arg);
	}

	return CItem::handle_action(comm, me, arg);
}

ITEM_END;